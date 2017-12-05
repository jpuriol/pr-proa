/**
 * Implementation of a hash table
 * Curso 2017/2018
 * 
 *
 * Modificada para agregar un iterador
 * a fecha de 30/12/2017
 *
 * @author Ignacio Gomis
 * @author Juan Pablo Uriol
 */
#ifndef _TABLA_H
#define _TABLA_H

#include <string>
#include <vector>
#include <iostream>
#include "alumno.h"

using std::string;
using std::vector;
template<typename TClave,typename TDato,template <  typename Elem,typename Alloc=std::allocator<Elem>> class TContenedor,typename Hash>
class Tabla;

/**
 * Clase tablaIterator<Cell,Contenedor>, iterador sobre la clase tabla
 * @param Cell Celda de la tabla, incluyendo clave y valor
 * @param Contenedor Clase que gestiona la cola de colisiones
 *
 * Explicación general, este iterador es una agrupación de dos iteradores, 
 * el primero sobre el vector externo y el segundo sobre las listas de colisión internas.
 * Tambien incluye dos iteradores a finales de los mismos para reconocer cuando acaba una linea o la tabla completa.
 */
template < typename Cell, template <  typename Elem,typename Alloc=std::allocator<Elem>> class Contenedor >
class TablaIterator : public std::iterator <std::forward_iterator_tag, Cell>
{
protected:
    typedef Contenedor<Cell> contenedor;
    typedef Cell * Pointer;
    Pointer pointer; 
    typename vector<contenedor>::iterator ovIt;
    typename vector<contenedor>::iterator ovItEnd;
    typename contenedor::iterator subIt;
    typename contenedor::iterator subItEnd;
    
public:
    /**
     * Constructor para begin y end
     * @param t tabla sobre la que definir los iteradores
     * @param inicio true para incializar al inicio, false para inicializar al final
     */
    TablaIterator<Cell,Contenedor> (vector<contenedor> & t, bool inicio) {
        //Asignación de final de vector
        ovItEnd=t.end();
        if(inicio)
        {
            //Puntero de vector actual es el inicio
            ovIt=t.begin();
            //Punteros de lista de colisión
            subIt=(*ovIt).begin();
            subItEnd=(*ovIt).end();
            //Caso de que no hayan elementos en primeras listas de colision se avanza
            while(subIt==subItEnd&&ovItEnd!=ovIt)
            {
                ++ovIt;
                subIt=(*ovIt).begin();
                subItEnd=(*ovIt).end();
            }
            //Caso de tabla vacia
            if(ovItEnd==ovIt)
            {
                subIt=(*ovIt).begin();
                subItEnd=(*ovIt).end();
            }
        }
        else
        {
            //Puntero de vector actual es el final
            ovIt=t.end();
            //Punteros de lista de colisión
            subIt=(*ovIt).begin();
            subItEnd=(*ovIt).end();
        }
    }
    
    /**
     * Constructor para un elemento cualquiera (para funciones como find)
     * @param t tabla sobre la que definir los iteradores
     * @param i indice del vector (empieza en 0)
     * @param j indice de lista de colisión (empieza en 0)
     */
    TablaIterator<Cell,Contenedor> (vector<vector<Cell>> & t, int i, int j) {
        ovIt=t.begin();
        for(int k=0;k<i;k++)
            ++ovIt;
        ovItEnd=t.end();
        subIt=(*ovIt).begin();
        for(int k=0;k<j;k++)
            ++subIt;
        subItEnd=(*ovIt).end();
    }
    
    /**
     * Operador de igualdad
     * @param value otro TablaIterator
     * @return bool True si apuntan a la misma posicion
     */
    bool operator== (const TablaIterator<Cell,Contenedor> value) {
        return (ovIt == value.ovIt&&subIt == value.subIt);
    }
    
    /**
     * Operador de desigualdad
     * @param value otro TablaIterator
     * @return bool True si apuntan a distinta posicion
     */
    bool operator!= (const TablaIterator<Cell,Contenedor> value) {
        return !(ovIt == value.ovIt && subIt == value.subIt);
    }
    
    /**
     * Operador de referencia
     * @return T celda apuntada por este iterador
     */
    Cell operator* () {
        return *subIt;
    }
    
    /**
     * Funcion de avance del iterador
     * @return siguiente iterador
     * Funcionamiento:
     * Si no esta en el ultimo elemento
     */
    TablaIterator<Cell,Contenedor> operator++ () { 
        if(ovItEnd!=ovIt)
        {
            ++subIt;
            //Mientras no el iterador sea un final de lista se avanza en el vector
            while(subIt==subItEnd&&ovItEnd!=ovIt)
            {
                ++ovIt;
                subIt=(*ovIt).begin();
                subItEnd=(*ovIt).end();
            }
            //Si se alcanza final del vector se asignan los valores finales
            if(ovItEnd==ovIt)
            {
                subIt=(*ovIt).begin();
                subItEnd=(*ovIt).end();
            }
        }
    return *this;
    }

    /**
     * Operador de incremento mediante un temporal
     * @return siguiente iterador
     */
    TablaIterator<Cell,Contenedor> operator++ (int) {
        TablaIterator<Cell,Contenedor> tmp(pointer);
        ++tmp();
        return tmp;
    }
};

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

/**
 * Clase tabla
 * Modificada para agregar iterador
 */
 template < typename TClave, 
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
        friend std::ostream & operator<<(std::ostream & out, const Celda & cel)
        {
            const string tab = "    ";
            out << "==================================" << std::endl;
            out << "Clave: "<<std::endl<<tab<<cel.clave << std::endl;
            out << "Dato: " <<std::endl<<cel.dato  << std::endl;
            return out;
        };
        friend bool operator < (Celda cel1, Celda cel2)
        {
            return cel1.dato<cel2.dato;
        }
    };
        
    Tabla(unsigned tam) { t.resize(tam); }; 
    
    unsigned hash(TClave) const;
   
    bool buscar(TipoClave, TipoDato&);

    void insertar(TipoClave clave, const TipoDato& valor);

    /**
     * Final de Tabla
     * @return Iterador a elemento de la tabla
     */
    TablaIterator<Celda,TContenedor> end(){
        return (TablaIterator<Celda,TContenedor>(t,false));
        }
        
    /**
     * Final de Tabla
     * @return Iterador a final de la tabla
     */
    TablaIterator<Celda,TContenedor> begin(){
        return (TablaIterator<Celda,TContenedor>(t,true));
        }
private:
    typedef TContenedor<Celda> ListaDatos; 
    vector<ListaDatos> t;
    Hash h;
    
    friend class TablaIterator<Celda,TContenedor>;
    
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
 * Funcion hash
 * @param clave para el hash
 * @return indice de la tabla
 */
template <typename TipoClave, typename TipoDato, template <typename Elem,typename Alloc=std::allocator<Elem>> class TContenedor, typename Hash>
unsigned Tabla<TipoClave,TipoDato,TContenedor,Hash>::hash(TipoClave clave) const
{
    return h.hash(clave,t.size());
}


#endif
