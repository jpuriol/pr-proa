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

//Consultar C++ the standard library 9.6
template <  typename Pointer >
class ListaIterator : public std::iterator <std::bidirectional_iterator_tag, Pointer, std::ptrdiff_t, Pointer*, Pointer&> {
protected:
    Pointer pointer; 
    
public:
    ListaIterator (Pointer p) {
        pointer = p;
    }

    void operator= (const ListaIterator<Pointer> value) {
        this->pointer= value.pointer;
        //this.pointer=value.pointer; // ERROR!
    }
    
    bool operator== (const ListaIterator<Pointer> value) {
        return (pointer == value.pointer);
    }
    
    bool operator!= (const ListaIterator<Pointer> value) {
        return !(pointer == value.pointer);
    }

    Pointer& operator* () {
        return *pointer;
    }
    
    void operator++ () {
        if(pointer!=nullptr)
            pointer=pointer->sig;
    }

};


/**
 * Lista simplemente enlazada
 * @param T Tipo de los elementos de la lista
 */
template<typename T>
class Lista {
    struct Nodo {
        T valor;
        Nodo * sig;
        bool operator == (const Nodo value) {
            return (sig==value.sig && valor==value.valor);
        };
        void operator = (Nodo value) {
            sig=value.sig;
            valor=value.valor;
        };
    };
    
    typedef Nodo * PtrNodo;
    
    PtrNodo ptr;
public:
    Lista():ptr(nullptr) {}
    void push_front(const T &);
    void mostrar() const;
    friend std::ostream& operator<< (std::ostream&, const Lista<T>&);
    
    ListaIterator<PtrNodo> end(){
        PtrNodo null = nullptr;
        return (ListaIterator<PtrNodo>(null));
        }
    ListaIterator<PtrNodo> begin(){
        return (ListaIterator<PtrNodo>(ptr));}
};

/**
 * Añadir elemento al inicio de la lista
 * @param x elemento a añadir
 */
template<typename T>
void Lista<T>::push_front(const T & x) {
    PtrNodo aux = new Nodo;
    aux->valor = x;
    aux->sig = ptr;
    ptr = aux;
}

/**
 * Muestra la lista por pantalla
 */
template<typename T>
friend std::ostream& operator<< (std::ostream& stream, const Lista<T>& lista) {
    PtrNodo aux = lista.ptr;
    
    while(aux != nullptr) {
        stream << aux->valor << " ";
        aux = aux->sig;
    }
}

#endif
