/**
 * Implementación de la clase Alumno
 * Curso 2014/2015
 */

#include "alumno.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>


// Nombres de ejemplo
string Alumno::list_nombre[] = {
"Javier",
"Jorge",
"Angel",
"Raul",
"Jose",
"Iñigo",
"Jose Antonio",
"Julio",
"Beatriz",
"Ismael",
"Oliver",
"Carlos",
"Alberto",
"Francisco Manuel",
"Lluis Carles"  };

// Apellidos de ejemplo
string Alumno::list_apellido[] = {
        "Albaladejo" ,
    "Albiach" ,
    "Aldana" ,
    "Alonso" ,
    "Anda" ,
    "Andres" ,
    "Angel" ,
    "Aranda" ,
    "Bernal" ,
    "Bonell" ,
    "Calderon" ,
    "Chakkour" ,
    "Contreras" ,
    "Correa" ,
    "Dacasa" };


/**
 * Constructor Alumno.
 * Genera un alumno con datos aleatorios excepto el curso, que se pasa como parámetro.
 * @param curs curso del alumno
 */
Alumno::Alumno(unsigned curs): curso(curs)
{
    unsigned num = rand() % 100000000;
    std::stringstream s;
    s << num;
    string letra;
    letra.push_back( rand() % (90-65+1) + 65 ); // A 65, Z 90
    dni = s.str() + letra;
    nombre = list_nombre[ rand() % NUM_NOMBRE];
    apellidos = list_apellido[ rand() % NUM_NOMBRE];
    telefono = rand() % 100000000 + 600000000;
}

/**
 * Escribe el alumno en un stream de salida
 * @param out Stream de salida
 * @param alu alumno a escribir
 */
std::ostream & operator<<(std::ostream & out, const Alumno & alu)
{
    const string tab = "    ";
    out << "==================================" << std::endl;
    out << tab << "DNI: " << alu.dni << std::endl;
    out << tab << "Nombre: " << alu.nombre << tab << alu.apellidos << std::endl;;
    out << tab << "Curso: " << alu.curso;
    out << tab << "Telefono: " << alu.telefono << std::endl;
    out << "==================================" << std::endl;
    return out;
}

/**
 * Devuelve el DNI como valor numerico
 * @return DNI como int
 */
int Alumno::GetDNInum() const
{
    string DNI=dni;
    DNI.resize(8);
    return atoi( DNI.c_str() );
}
