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
int DNItoInt(string);

class MyHash {
    public:
        static unsigned hash(long const & clave, unsigned size)
        {
            std::cout<<"P";
            return clave%size;
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
    int curso;
    
    cout<<"Probando con claves strings y todo Default\n";
    
    Tabla<string,Alumno> tabla(400); 
    Alumno alumno,alumnoDentro;
    bool dentro,fuera;
    for(int i=0;i<200;i++)
    {
        curso=aleatorio1a4();
        alumno=Alumno(curso);
        tabla.insertar(alumno.getDNI(),alumno);
        if(i==100)
        {
            alumnoDentro=alumno;
        }
    }
    dentro=tabla.buscar(alumnoDentro.getDNI(), alumnoDentro); 
    curso=aleatorio1a4();
    alumno=Alumno(curso);
    fuera=tabla.buscar("DNInoExistente", alumno); 
    cout<<"\nBuscar existente: ";
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
    
    cout<<"Probando con claves ints y con una lista\n";
    
    Tabla<int,Alumno,list> tabla2(400); 
    for(int i=0;i<200;i++)
    {
        curso=aleatorio1a4();
        alumno=Alumno(curso);
        tabla2.insertar(DNItoInt(alumno.getDNI()),alumno);
        if(i==100)
        {
            alumnoDentro=alumno;
        }
    }
    dentro=tabla2.buscar(DNItoInt(alumnoDentro.getDNI()), alumnoDentro); 
    fuera=tabla2.buscar(0, alumno); 
    cout<<"\nBuscar existente: ";
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
    
    cout<<"Probando con mi funcion Hash, necesita ser suministrado el parametro 3\n";
    
    Tabla<int,Alumno,vector,MyHash> tabla3(400); 
    for(int i=0;i<200;i++)
    {
        curso=aleatorio1a4();
        alumno=Alumno(curso);
        tabla3.insertar(DNItoInt(alumno.getDNI()),alumno);
        if(i==100)
        {
            alumnoDentro=alumno;
        }
    }
    dentro=tabla3.buscar(DNItoInt(alumnoDentro.getDNI()), alumnoDentro); 
    fuera=tabla3.buscar(0, alumno); 
    cout<<"\nBuscar existente: ";
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

/**
 * Convierte string DNI a int DNI (mismo sin la letra)
 */
int DNItoInt(string DNI)
{
    DNI.resize(8);
    return atoi( DNI.c_str() );
}
