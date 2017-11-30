/**
 * Implementation of a hash table
 * Curso 2017/2018
 * 
 */
#ifndef _TABLA_H
#define _TABLA_H

#include <string>
#include <vector>
#include <iostream>
#include "alumno.h"

using std::string;
using std::vector;
class Tabla;


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
    TablaIterator<Cell,Contenedor> (vector<vector<Cell>> & t, bool inicio) {
        if(inicio)
        {
            ovIt=t.begin();
        }
        else
        {
            ovIt=t.end();
            
        }
        ovItEnd=t.end();
        subIt=(*ovIt).begin();
        subItEnd=(*ovIt).end();
    }
    
    bool operator== (const TablaIterator<Cell,Contenedor> value) {
        return (ovIt == value.ovIt&&subIt == value.subIt);
    }
    
    bool operator!= (const TablaIterator<Cell,Contenedor> value) {
        return !(ovIt == value.ovIt && subIt == value.subIt);
    }

    Cell operator* () {
        return *subIt;
    }
    
    TablaIterator<Cell,Contenedor> operator++ () { //++i
        if(ovItEnd!=ovIt)
        {
            ++subIt;
            while(subIt==subItEnd&&ovItEnd!=ovIt)
            {
                ++ovIt;
                subIt=(*ovIt).begin();
                subItEnd=(*ovIt).end();
            }
            if(ovItEnd==ovIt)
            {
                subIt=(*ovIt).begin();
                subItEnd=(*ovIt).end();
            }
        }
        else
        {
            if(subIt!=subItEnd)
            {
                ++subIt;
            }
        }
    return *this;
    }

    TablaIterator<Cell,Contenedor> operator++ (int) {//i++
        TablaIterator<Cell,Contenedor> tmp(pointer);
        ++tmp();
        return tmp;
    }
    
};

class Tabla
{
public:
    typedef string TipoClave;
    typedef Alumno TipoDato;
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
        
    Tabla(unsigned); 
    bool buscar(TipoClave, TipoDato&) ; 
    void insertar(TipoClave, const TipoDato&); 
    unsigned hash(TipoClave) const;
    void mostrar(std::ostream & sal) const;
    
    /**
     * Punteros inicio y fin
     */
    TablaIterator<Celda,vector> end(){
        return (TablaIterator<Celda,vector>(t,false));
        }
    TablaIterator<Celda,vector> begin(){
        return (TablaIterator<Celda,vector>(t,true));
        }

private:
    typedef vector<Celda> ListaDatos; 
    vector<ListaDatos> t;
    friend class TablaIterator<Celda,vector>;
};

#endif
