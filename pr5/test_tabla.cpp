/**
* @file sort_tabla.cpp
*
* Practicas de PROA
* Previo Practica 5.
*
* @author Ignacio Gomis Lli
* @author Juan Pablo Uriol Balbin
* @date 11/11/2017
* @version 1.0
*/

#include <iostream>
#include <stdlib.h>
#include "alumno.h"
#include "tabla.h"
using namespace std;

int aleatorio1a4();

/**
*
* Main: Genera una tabla con 200 alumnos. Busca aquel que puso en la posición 100 y uno que no puede aparecer
*
*/
int main()
{
    srand (time(NULL));
    int curso;
    String DNIdentro;
    Tabla(200) tabla; 
    Alumno alumno,alumnoDentro;
    bool dentro,fuera;
    for(int i=0;i<200;i++)
    {
        curso=aleatorio1a4();
        alumno=Alumno(curso);
        tabla.insertar(alumno.getDNI(),alumno);
        if(i=100)
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
    cout<<"\n";
    
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
    num=rand();
    if(num&2==2)
    {
        if(num&1==1)
        {
            return 3;
        }
        else
        {
            return 2;
        }
    }
    else
    {
        if(num&1==1)
        {
            return 1;
        }
        else
        {
            return 4;
        }
    }    
    return 1;
}
