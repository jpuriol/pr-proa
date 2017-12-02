#include "lista.h"
#include "tabla.h"
using namespace std;

void testLista();
void testTabla();
template<typename It>
void out(It begin, It end);

int main()
{
    testLista();
    testTabla();
    return 0;
}


void testLista()
{
    
    Alumno al;
    Lista<Alumno> lista;
    vector<Alumno> vect;
    for(int i=0;i<10;i++)
    {
        al=Alumno(1);
        lista.push_front(al);
    }
    auto begin=lista.begin();
    auto end=lista.end();
    /*out(begin,end);
    std::copy(begin, end, vect.begin());    //<-Origen de errores
    out(vect.begin(), vect.end());
    //cout<<"Minimo: "<<endl<<getMin(begin, end)<<endl;*/
    
    cout<<"Lista aun sin hacer"<<endl;
}

void testTabla()
{
    cout<<"Tabla aun sin hacer"<<endl;
}

template<typename It>
void out(It begin, It end)
{
    for(It it=begin;it!=end;++it)
    {
        cout<<*it<<endl;        //<-Origen de errores
    }
}
