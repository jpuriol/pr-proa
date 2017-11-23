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
#include <fstream>
#include "alumno.h"

using std::string;
using std::vector;
using std::ostream;

/**
 *  Clase DefaultHash
 *  Operaciones: hash(clave, size)
 *  Solo soporta Enteros y Stings, para cualquier otro tipo, no usa la clave hash!
 */
class defaultHash {
    public:
        unsigned hash(int clave,unsigned size) const 
        {
            std::cout<<"I";
            return (clave * 5381 )% size;
        }
        unsigned hash(string clave,unsigned size) const
        {
            std::cout<<"S";
            unsigned long h = 5381;
            for(unsigned i = 0; i < clave.size(); i++)
                h = ((h << 5) + h) + clave[i];
        return h % size;
        };
        template<typename T>
        unsigned hash(T clave,unsigned size) const 
        {
            std::cout<<"U";
            (void)clave;
            (void) size;
            return 1;
        }
};


template <  typename TClave, 
            typename TDato, 
            template <  typename Elem,
                        typename Alloc=std::allocator<Elem>> 
            class TContenedor = vector,
            typename Hash = defaultHash>
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
    
    unsigned hash(TClave) const;
    /*unsigned hash(int) const;
    unsigned hash(string) const;*/
   
    bool buscar(TipoClave, TipoDato&);

    void insertar(TipoClave clave, const TipoDato& valor);

    void mostrar(ostream & sal) const;

private:
    typedef TContenedor<Celda> ListaDatos; 
    vector<ListaDatos> t;
    Hash h;
};

/**
 * Insert an element
 * @param clave Key of the element
 * @param valor Value to be stored
 */
template <typename TipoClave, typename TipoDato, template <typename Elem,typename Alloc=std::allocator<Elem>> class TContenedor, typename Hash>
void Tabla<TipoClave,TipoDato,TContenedor, Hash>::insertar(TipoClave clave, const TipoDato & valor)
{
    unsigned i;
    i = hash(clave);
    t[i].push_back(Celda{clave,valor} );
}

/**
 * Search for an element
 * @param clave Key of the element
 * @param valor Value founded with key "clave"
 * @return true if element founded, false otherwise
 */
template <typename TipoClave, typename TipoDato, template <typename Elem,typename Alloc=std::allocator<Elem>> class TContenedor, typename Hash>
bool Tabla<TipoClave,TipoDato, TContenedor,Hash>::buscar(TipoClave clave, TipoDato & valor) 
{
    unsigned i;
    i = hash(clave);
    for(auto it:t[i])
    {
       if(it.clave == clave) 
       {
           valor = it.dato;
           return true;
       }
    }
    return false;
}

/**
 * Write the hash table to a stream
 * @param sal output stream
 */
template <typename TipoClave, typename TipoDato, template <typename Elem,typename Alloc=std::allocator<Elem>> class TContenedor, typename Hash>
void Tabla<TipoClave,TipoDato,TContenedor,Hash>::mostrar(std::ostream & sal) const
{
    for(unsigned i = 0; i < t.size(); i++)
    {
        sal << i << ":" ;
        for(auto it = t[i].begin(); it != t[i].end(); ++it)
            sal << *it << "->";
        sal << std::endl;
    }
}

template <typename TipoClave, typename TipoDato, template <typename Elem,typename Alloc=std::allocator<Elem>> class TContenedor, typename Hash>
unsigned Tabla<TipoClave,TipoDato,TContenedor,Hash>::hash(TipoClave clave) const
{
    return h.hash(clave,t.size());
}
/**
 * Funcion hash para strings
 * @param clave para el hash
 * @return indice de la tabla
 *//*
template <typename TipoClave, typename TipoDato, template <typename Elem,typename Alloc=std::allocator<Elem>> class TContenedor>
unsigned Tabla<TipoClave,TipoDato,TContenedor>::hash(string clave) const
{
    unsigned long h = 5381;
    
    for(unsigned i = 0; i < clave.size(); i++)
        h = ((h << 5) + h) + clave[i];
        
    return h % t.size();
}*/

/**
 * Funcion hash para enteros
 * @param clave para el hash
 * @return indice de la tabla
 *//*
template <typename TipoClave, typename TipoDato, template <typename Elem,typename Alloc=std::allocator<Elem>> class TContenedor>
unsigned Tabla<TipoClave,TipoDato,TContenedor>::hash(int clave) const
{
    return (clave )% t.size();
}*/ 


#endif
