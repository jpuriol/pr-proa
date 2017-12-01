/**
 * Implementacion de una lista simplemente enlazada
 * Programacion Avanzada
 * Curso 2015/2016
 *
 * Modificada para agregar un iterador
 * a fecha de 27/12/2017
 *
 * @author F. Barber
 * @author Ignacio Gomis
 * @author Juan Pablo Uriol
 */

#ifndef _LISTA_H
#define _LISTA_H

#include<iostream>
#include <iterator>
#include <list>
template <  typename T >
class Lista;

/**
 *  Clase ListaIterator<T>
 *  Iterador sobre una clase lista simplemente enlazada
 *  @param T clase de elementos almacenados en la Lista
 */
template <  typename T >
class ListaIterator : public std::iterator <std::forward_iterator_tag, T>
{
protected:
    typedef typename Lista<T>::PtrNodo Pointer;
    Pointer pointer; 

public:
    /**
     * Constructor
     * @param p puntero a un nodo de la lista
     */
    ListaIterator (Pointer p) {
        pointer = p;
    }
    
    /**
     * Operador de igualdad
     * @param value otro ListaIterator
     * @return bool True si apuntan a la misma posicion
     */
    bool operator== (const ListaIterator<T> value) {
        return (pointer == value.pointer);
    }
    
    /**
     * Operador de desigualdad
     * @param value otro ListaIterator
     * @return bool True si apuntan a distinta posicion
     */
    bool operator!= (const ListaIterator<T> value) {
        return !(pointer == value.pointer);
    }

    /**
     * Operador de referencia
     * @return T valor del nodo apuntado por este iterador
     */
    T operator* () {
        return pointer->valor;
    }
    
    /**
     * Operador de incremento
     * @return siguiente iterador
     */
    ListaIterator<T> operator++ () {
        if(pointer!=nullptr)
            pointer=pointer->sig;
        return pointer;
    }

    /**
     * Operador de incremento mediante un temporal
     * @return siguiente iterador
     */
    ListaIterator<T> operator++ (int) {
        ListaIterator<T> tmp(pointer);
        ++tmp();
        return tmp;
    }
};


/**
 * Lista simplemente enlazada
 * @param T Tipo de los elementos de la lista
 */
template<typename T>
class Lista
{
    struct Nodo
    {
        T valor;
        Nodo * sig;
    };
    
    typedef Nodo * PtrNodo;
    
    PtrNodo ptr;
    // Agregada clase amiga
    friend class ListaIterator<T>;
    
public:
    Lista():ptr(nullptr) {}
    void push_front(const T &);
    void mostrar() const;
    /**
     * Final de lista
     * @return Iterador a un nullpointer
     */
    ListaIterator<T> end(){
        return (ListaIterator<T>(nullptr));
        }
    /**
     * Final de lista
     * @return Iterador a primer nodo de la lista
     */
    ListaIterator<T> begin(){
        return (ListaIterator<T>(ptr));}
};

/**
 * Agregar elemento al inicio de la lista
 * @param x elemento a agregar
 */
template<typename T>
void Lista<T>::push_front(const T & x)
{
    PtrNodo aux = new Nodo;
    aux->valor = x;
    aux->sig = ptr;
    ptr = aux;
}

/**
 * Muestra la lista por pantalla
 */
template<typename T>
void Lista<T>::mostrar() const
{
    PtrNodo aux = ptr;
    
    while(aux != nullptr)
    {
        std::cout << aux->valor << " ";
        aux = aux->sig;
    }
}

#endif
