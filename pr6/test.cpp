#include "lista.h"
#include "tabla.h"
#include <algorithm>
using namespace std;

void testLista();
void testTabla();
void testStl();
template<typename It>
void out(It begin, It end);

int main()
{
    //testStl();
    testLista();
    for(int i=0;i<5;i++)
        cout<<endl;
    testTabla();
    return 0;
}


void testLista()
{
    Alumno al;
    Lista<Alumno> lista;
    vector<Alumno> vect;
    cout<<"INSERTANDO, COMIENZA POR EL FINAL:"<<endl;
    for(int i=0;i<10;i++)
    {
        
        al=Alumno(1);
        cout<<al<<endl;
        lista.push_front(al);
    }
    cout<<endl<<"RECORRIENDO OBJETO:"<<endl;
    out(lista.begin(),lista.end());
    /*
    copy(lista.begin(), lista.end(), vect.begin());    //<-Origen de errores
    
    cout<<"RECORRIENDO VECTOR:"<<endl;
    out(vect.begin(), vect.end());
    //min_element (funcion de algorithm)*/
}

void testTabla()
{
    Alumno al;
    Tabla tabla(20);
    vector<Alumno> vect;
    cout<<"INSERTANDO, SIN ORDEN:"<<endl;
    for(int i=0;i<10;i++)
    {
        
        al=Alumno(1);
        cout<<al<<endl;
        tabla.insertar(al.getDNI(),al);
    }
    cout<<endl<<"RECORRIENDO OBJETO:"<<endl;
    out(tabla.begin(),tabla.end());
    /*
    copy(tabla.begin(), tabla.end(), vect.begin());    //<-Origen de errores
    
    cout<<"RECORRIENDO VECTOR:"<<endl;
    out(vect.begin(), vect.end());
    //min_element (funcion de algorithm)*/
}

template<typename It>
void out(It begin, It end)
{
    for(It it=begin;it!=end;++it)
    {
        cout<<*it<<endl;
    }
}

void testStl()
{
    vector<int> orig;
    vector<int> dest;
    for(int i=0;i<10;i++)
    {
        orig.push_back(i);
    }
    cout<<"RECORRIENDO ORIG:"<<endl;
    out(orig.begin(),orig.end());
    copy(orig.begin(), orig.end(), dest.begin());    //<-Origen de errores
    
    cout<<"RECORRIENDO DEST:"<<endl;
    out(dest.begin(), dest.end());
    //min_element (funcion de algorithm)
}

