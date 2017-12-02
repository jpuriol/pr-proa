/**
 * test.cpp
 *
 * Main para probar el correcto funcionamiento de los iteradores en lista y tabla
 * 
 * @author Ignacio Gomis
 * @author Juan Pablo Uriol
 * a fecha de 27/12/2017
 * Programacion Avanzada
 */

#include "lista.h"
#include "tabla.h"
#include <algorithm>
#include <time.h>
using namespace std;

void testLista();
void testTabla();
template<typename It>
void out(It begin, It end);

/**
 * Funcion main
 */
int main()
{
    srand(time(NULL));
    testLista();
    for(int i=0;i<5;i++)
        cout<<endl;
    testTabla();
    return 0;
}

/**
 * Funcion para probar una lista
 * 1º Muestra por pantalla 10 alumnos generados al azar
 * 2º Muestra por pantalla los 10 alumnos introducidos en la lista
 * 3º Muestra por pantalla los 10 alumnos copiados al vector
 * 4º Muestra el menor alumno en la lista
 */
void testLista()
{
    Alumno al;
    Lista<Alumno> lista;
    vector<Alumno> vect(10);
    cout<<"INSERTANDO, COMIENZA POR EL FINAL:"<<endl;
    for(int i=0;i<10;i++)
    {
        
        al=Alumno(1);
        cout<<al<<endl;
        lista.push_front(al);
    }
    cout<<endl<<"RECORRIENDO OBJETO:"<<endl;
    out(lista.begin(),lista.end());
    
    copy(lista.begin(), lista.end(), vect.begin());
    
    cout<<"RECORRIENDO VECTOR:"<<endl;
    out(vect.begin(), vect.end());
    cout << "Mas Pequeno: "<< endl << *std::min_element(lista.begin(),lista.end())<<endl<<endl;
    
}

/**
 * Funcion para probar una tabla
 * 1º Muestra por pantalla 10 alumnos generados al azar
 * 2º Muestra por pantalla los 10 alumnos introducidos en la tabla
 * 3º Muestra por pantalla los 10 alumnos copiados al vector
 * 4º Muestra el menor alumno en la tabla
 */
void testTabla()
{
    Alumno al;
    Tabla tabla(20);
    vector<Tabla::Celda> vect(10);
    cout<<"INSERTANDO, SIN ORDEN:"<<endl;
    for(int i=0;i<10;i++)
    {
        
        al=Alumno(1);
        cout<<al<<endl;
        tabla.insertar(al.getDNI(),al);
    }
    cout<<endl<<"RECORRIENDO OBJETO:"<<endl;
    out(tabla.begin(),tabla.end());
    
    copy(tabla.begin(), tabla.end(), vect.begin());
    
    cout<<"RECORRIENDO VECTOR:"<<endl;
    out(vect.begin(), vect.end());
    cout << "Mas Pequeno: "<< endl << *std::min_element(tabla.begin(),tabla.end())<<endl<<endl;
    
}

/**
 * Funcion para imprimir por pantalla el contenido de un contenedor
 */
template<typename It>
void out(It begin, It end)
{
    for(It it=begin;it!=end;++it)
    {
<<<<<<< HEAD
        cout<<*it<<endl;        //<-Origen de errores
    }
}
=======
        cout<<*it<<endl;
    }
}


>>>>>>> d542a193b0ec88b8c298380ec128ac581ad08ae0
