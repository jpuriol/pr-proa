/**
 * Clase para representar alumnos
 * Curso 2014/2015
 * Programacion Avanzada
 *
 * Modificado por Ignacio Gomis y Juan Pablo Uriol
 * a fecha de 30/12/2017
 * Agregadas GetDNInum y operator <
 */

#ifndef _ALUMNO_H_
#define _ALUMNO_H_

#include <iostream>
#include <string>

using std::string;

class Alumno
{
    string dni;
    string nombre;
    string apellidos;
    unsigned curso;
    unsigned telefono;
    
    static const unsigned NUM_NOMBRE = 15;
    static string list_nombre[];
    static string list_apellido[];


public:
    Alumno() {};
    Alumno(unsigned );
    string getDNI() const 
        {return dni; };
    int GetDNInum() const;
    friend bool operator< (Alumno,Alumno);
    friend std::ostream & operator<<(std::ostream &, const Alumno &);
             
};

#endif
