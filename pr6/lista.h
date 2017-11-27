/**
 * Implementacion de una lista simplemente enlazada
 * Programacion Avanzada
 * Curso 2015/2016
 * 
 * @author F. Barber
 */

#ifndef _LISTA_H
#define _LISTA_H

#include<iostream>
#include <iterator>
#include <list>

//Consultar C++ the standart library 9.6
template <  typename Container >
class ListaIterator : public std::iterator <std::bidirectional_iterator_tag, type, std::ptrdiff_t, type*, type&>
{
protected:
    Container& container; //Elemento apuntado
    
public:
    explicit ListaIterator (Container& c) : Container(c) {
    }

    void operator= (const typename Container::value_type& value) {
        this.container=value;
    }
    
    bool operator== (const typename Container::value_type& value) {
        return this==value;
    }
    
    bool operator!= (const typename Container::value_type& value) {
        return this!=value;
    }

    Container& operator* () {
        return container;
    }
    
    
    void operator++ () {
        this=container.sig;
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
public:
    Lista():ptr(nullptr) {}
    void push_front(const T &);
    void mostrar() const;
    ListaIterator<T> begin();
    ListaIterator<T> end();
};

/**
 * Añadir elemento al inicio de la lista
 * @param x elemento a añadir
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

/**
 * Devuelve puntero al final
 */
template<typename T>
ListaIterator<T> Lista<T>::end() 
{
    PtrNodo aux = nullptr;
    return (ListaIterator<T>(aux));
}

/**
 * Devuelve puntero al principio
 */
template<typename T>
ListaIterator<T> Lista<T>::begin() 
{
    PtrNodo aux = ptr;
    return (ListaIterator<T>(aux));
}


#endif
