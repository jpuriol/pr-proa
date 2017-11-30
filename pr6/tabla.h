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


template < typename Cell >
class TablaIterator : public std::iterator <std::forward_iterator_tag, Cell>
{
protected:
    typedef Cell * Pointer;
    Pointer pointer; 
    typename vector<vector<Cell>>::iterator ovIt;
    typename vector<vector<Cell>>::iterator ovItEnd;
    typename vector<Cell>::iterator subIt;
    typename vector<Cell>::iterator subItEnd;
    
public:
    TablaIterator<Cell> (vector<vector<Cell>> & t, bool inicio) {
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
    
    bool operator== (const TablaIterator<Cell> value) {
        return (ovIt == value.ovIt&&subIt == value.subIt);
    }
    
    bool operator!= (const TablaIterator<Cell> value) {
        return !(ovIt == value.ovIt && subIt == value.subIt);
    }

    Cell operator* () {
        return *subIt;
    }
    
    TablaIterator<Cell> operator++ () { //++i
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

    TablaIterator<Cell> operator++ (int) {//i++
        TablaIterator<Cell> tmp(pointer);
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
    };
        
    Tabla(unsigned); 
    bool buscar(TipoClave, TipoDato&) ; 
    void insertar(TipoClave, const TipoDato&); 
    unsigned hash(TipoClave) const;
    void mostrar(std::ostream & sal) const;
    
    /**
     * Punteros inicio y fin
     */
    TablaIterator<Celda> end(){
        return (TablaIterator<Celda>(t,false));
        }
    TablaIterator<Celda> begin(){
        return (TablaIterator<Celda>(t,true));
        }

private:
    typedef vector<Celda> ListaDatos; 
    vector<ListaDatos> t;
    friend class TablaIterator<Celda>;
};

#endif
