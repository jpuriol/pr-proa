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
    out(lista.begin(),lista.end());
    std::copy(lista.begin(), lista.end(), vect.begin());
    out(vect.begin(), vect.end());
    //cout<<"Minimo: "<<endl<<getMin(lista.begin(), lista.end())<<endl;
    
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
        cout<<*it<<endl;
    }
}
/*
Alumno getMin(iterador<Lista> begin, iterador<Lista> end)
{
    int min=100000000;
    Alumno minA;
    for(auto it=begin;it!=end;++it)
    {
        if(*it.GetDNInum()<min)
        {
            min=*it.GetDNInum();
            minA=*it;
        }
    }
    return minA;
}

Alumno getMin(iterador<Tabla> begin, iterador<Tabla> end)
{
    int min=100000000;
    Alumno minA;
    for(auto it=begin;it!=end;++it)
    {
        if(*it.GetDNInum()<min)
        {
            min=it->clave.GetDNInum();
            minA=*it;
        }
    }
    return minA;
}
*/
