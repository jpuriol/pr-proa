/**
 * Implementation of a hash table
 * Curso 2017/2018
 * 
 */
#ifndef _TABLA_T_H
#define _TABLA_T_H

#include <string>
#include <vector>
#include <iostream>
#include "alumno.h"

using std::string;
using std::vector;
using std::ostream;

template <typename TClave, typename TDato, template <typename Elem> class TContenedor=vector>
class Tabla
{
public:
    typedef TClave TipoClave;
    typedef TDato TipoDato;
    struct Celda {
        TipoClave clave;
        TipoDato dato;
    };
        
    Tabla(unsigned tam) { t.resize(tam); }; 
    
    unsigned hash(int) const;
    unsigned hash(string) const;
    bool buscar(TipoClave, TipoDato&);

    void insertar(TipoClave clave, const TipoDato& valor) { 
        unsigned i;
        i = hash(clave);
        t[i].push_back(Celda{clave,valor} );
    };

    void mostrar(ostream & sal) const;

private:
    typedef TContenedor<Celda> ListaDatos; 
    vector<ListaDatos> t;
};

/**
 * Insert an element
 * @param clave Key of the element
 * @param valor Value to be stored
 */
/*template <typename TipoClave,typename TipoDato, template <typename Elem> class TContenedor=vector>
void Tabla<TipoClave,TipoDato>::insertar(TipoClave clave, const TipoDato & valor)
{
    unsigned i;
    i = hash(clave);
    t[i].push_back(Celda{clave,valor} );
}*/

/**
 * Search for an element
 * @param clave Key of the element
 * @param valor Value founded with key "clave"
 * @return true if element founded, false otherwise
 */
template <typename TipoClave,typename TipoDato> 
bool Tabla<TipoClave,TipoDato>::buscar(TipoClave clave, TipoDato & valor) 
{
    unsigned i;
    i = hash(clave);
    for(unsigned j=0; j < t[i].size(); j++)
    {
       if(t[i][j].clave == clave) 
       {
           valor = t[i][j].dato;
           return true;
       }
    }
    return false;
}

/**
 * Write the hash table to a stream
 * @param sal output stream
 */
template <typename TipoClave,typename TipoDato> 
void Tabla<TipoClave,TipoDato>::mostrar(std::ostream & sal) const
{
    for(unsigned i = 0; i < t.size(); i++)
    {
        sal << i << ":" ;
        for(auto it = t[i].begin(); it != t[i].end(); ++it)
            sal << *it << "->";
        sal << std::endl;
    }
}

template <typename TipoClave,typename TipoDato> 
unsigned Tabla<TipoClave,TipoDato>::hash(string clave) const
{
    unsigned long h = 5381;
    
    for(unsigned i = 0; i < clave.size(); i++)
        h = ((h << 5) + h) + clave[i];
        
    return h % t.size();
}
template <typename TipoClave,typename TipoDato> 
unsigned Tabla<TipoClave,TipoDato>::hash(int clave) const
{
    return (clave )% t.size();
}

#endif
