/**
* @file sort_tabla.cpp
*
* Practicas de PROA
*
* @author Ignacio Gomis Lli
* @author Juan Pablo Uriol Balbin
* @date 13/11/2017
* @version 1.0
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <list>
#include "alumno.h"
#include "tabla_t.h"
using namespace std;

int aleatorio1a4();
class MyHash {
    public:
        static unsigned hash(long const & clave)
        {
            std::cout<<"Personal"<<std::endl;
            return clave%400;
        }
};

/**
*
* Main: Genera una tabla con 200 alumnos, de 400 celdas de tamano. Busca aquel que puso en la posicion 100 y uno que no puede aparecer
*
*/
int main()
{
    srand (time(NULL));
    int curso, CursoDentro=1;
    string DNIdentro;
    Tabla<string,Alumno,list> tabla(400); 
    Alumno alumno,alumnoDentro;
    bool dentro,fuera;
    for(int i=0;i<200;i++)
    {
        curso=aleatorio1a4();
        alumno=Alumno(curso);
        tabla.insertar(alumno.getDNI(),alumno);
        if(i==100)
        {
            DNIdentro=alumno.getDNI();
            alumnoDentro=alumno;
        }
    }
    dentro=tabla.buscar(DNIdentro, alumnoDentro); 
    curso=aleatorio1a4();
    alumno=Alumno(curso);
    fuera=tabla.buscar("DNInoExistente", alumno); 
    cout<<"Buscar existente: ";
    if(dentro)
        cout<<"EXISTE";
    else
        cout<<"NO EXISTE";
    cout<<"\nBuscar no existente: ";
    if(fuera)
        cout<<"EXISTE";
    else
        cout<<"NO EXISTE";
    cout<<"\n\n\n";
    
    
    Tabla<int,Alumno,list> tabla2(400); 
    for(int i=0;i<200;i++)
    {
        curso=aleatorio1a4();
        alumno=Alumno(curso);
        tabla2.insertar(curso,alumno);
        if(i==100)
        {
            CursoDentro=curso;
            alumnoDentro=alumno;
        }
    }
    dentro=tabla2.buscar(CursoDentro, alumnoDentro); 
    fuera=tabla2.buscar(5, alumno); 
    cout<<"Buscar existente: ";
    if(dentro)
        cout<<"EXISTE";
    else
        cout<<"NO EXISTE";
    cout<<"\nBuscar no existente: ";
    if(fuera)
        cout<<"EXISTE";
    else
        cout<<"NO EXISTE";
    cout<<"\n";
    
    /*fin*/
    
    return 0;
}

/**
*
* Genera un numero entre 1 y 4
*
* @return entero generado
*/
int aleatorio1a4()
{
    int num=rand();
    num=num&3;
    ++num;
    return num;
}
