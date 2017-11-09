#include <iostream>

using namespace std;

const int NUMERO_EJECUCIONES = 100000;
const int N_ELEM = 10000;

struct Prueba
{
    float f1, f2;
    int i1, i2, i3;
};

void costeMem1();

int main()
{
    struct timespec ini_time, fin_time;
    clock_gettime(CLOCK_REALTIME, &ini_time);
    for(int i = 0; i < NUMERO_EJECUCIONES; i++)
        costeMem1();
    clock_gettime(CLOCK_REALTIME, &fin_time);
    cout << "Tiempo: " << (double)fin_time.tv_sec - (double) ini_time.tv_sec + fin_time.tv_nsec * 1e-9 - ini_time.tv_nsec * 1e-9 << endl;

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
