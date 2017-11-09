#include <iostream>
#include <memory>
#include <new>
using namespace std;

const int NUMERO_EJECUCIONES = 10000;
const int N_ELEM = 10000;

struct Prueba
{
    float f1, f2;
    int i1, i2, i3;
    void* operator new(size_t tam)
    {
        void* m = malloc(tam);
        if(!m) throw bad_alloc();
        return m;
    };
    void operator delete(void* m)
    {
        free(m);
    };
};

void costeMem1();
void costeMem2();
void costeMem3();
void costeMem4();

int main()
{
    double tiempo1, tiempo2, tiempo3, tiempo4;
    struct timespec ini_time, fin_time;
    clock_gettime(CLOCK_REALTIME, &ini_time);
    for(int i = 0; i < NUMERO_EJECUCIONES; i++)
        costeMem1();
    clock_gettime(CLOCK_REALTIME, &fin_time);
    tiempo1 = (double)fin_time.tv_sec - (double) ini_time.tv_sec + fin_time.tv_nsec * 1e-9 - ini_time.tv_nsec * 1e-9;
    cout << "Tiempo estático: " << tiempo1 << endl;
    

    clock_gettime(CLOCK_REALTIME, &ini_time);
    for(int i = 0; i < NUMERO_EJECUCIONES; i++)
        costeMem2();
    clock_gettime(CLOCK_REALTIME, &fin_time);
    tiempo2 = (double)fin_time.tv_sec - (double) ini_time.tv_sec + fin_time.tv_nsec * 1e-9 - ini_time.tv_nsec * 1e-9;
    cout << "Tiempo dinámico (punteros básicos): " << tiempo2 << endl;
    cout << "-Diferencia: " << tiempo2 - tiempo1 << endl;
    
    clock_gettime(CLOCK_REALTIME, &ini_time);
    for(int i = 0; i < NUMERO_EJECUCIONES; i++)
        costeMem3();
    clock_gettime(CLOCK_REALTIME, &fin_time);
    tiempo3 = (double)fin_time.tv_sec - (double) ini_time.tv_sec + fin_time.tv_nsec * 1e-9 - ini_time.tv_nsec * 1e-9;
    cout << "Tiempo dinámico (unique_ptr): " << tiempo3 << endl;
    cout << "-Diferencia: " << tiempo3 - tiempo2 << endl;
    
    clock_gettime(CLOCK_REALTIME, &ini_time);
    for(int i = 0; i < NUMERO_EJECUCIONES; i++)
        costeMem4();
    clock_gettime(CLOCK_REALTIME, &fin_time);
    tiempo4 = (double)fin_time.tv_sec - (double) ini_time.tv_sec + fin_time.tv_nsec * 1e-9 - ini_time.tv_nsec * 1e-9;
    cout << "Tiempo dinámico (shared_ptr): " << tiempo4 << endl;
    cout << "-Diferencia: " << tiempo4 - tiempo2 << endl;

    return 0;
}

void costeMem1() 
{
    Prueba v[N_ELEM];
    volatile int suma = 0;
    for (int i = 0; i < N_ELEM; i++)
        v[i].i1 = i;
    for (int i = 0; i < N_ELEM; i++)
        suma += v[i].i1;
}

void costeMem2() 
{
    Prueba* v[N_ELEM];
    volatile int suma = 0;
    for (int i = 0; i < N_ELEM; i++)
    {
        v[i] = new Prueba;
        v[i]->i1 = i;
    }
    for (int i = 0; i < N_ELEM; i++)
    {
        suma += v[i]->i1;
        delete v[i];
    }
}

void costeMem3()
{
    unique_ptr<Prueba> v[N_ELEM];
    volatile int suma = 0;
    for (int i = 0; i < N_ELEM; i++)
    {
        v[i].reset(new Prueba); 
        v[i]->i1 = i;
    }
    for (int i = 0; i < N_ELEM; i++)
        suma += v[i]->i1;
}
    
void costeMem4()
{
    shared_ptr<Prueba> v[N_ELEM];
    volatile int suma = 0;
    for (int i = 0; i < N_ELEM; i++)
    {
        v[i].reset(new Prueba); 
        v[i]->i1 = i;
    }
    for (int i = 0; i < N_ELEM; i++)
        suma += v[i]->i1;
}
