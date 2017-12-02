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
template <  typename T >
class ListaIterator : public std::iterator <std::forward_iterator_tag, T>
{
protected:
    typedef Lista<T>::PtrNodo Pointer;
    Pointer pointer;
    //typename Lista<T>::PtrNodo pointer;

    
public:
    ListaIterator (Pointer p) {
        pointer = p;
    }
    
    bool operator== (const ListaIterator<Pointer> value) {
        return (pointer == value.pointer);
    }
    
    bool operator!= (const ListaIterator<Pointer> value) {
        return !(pointer == value.pointer);
    }

    Pointer& operator* () {
        return pointer->valor;
    }
    
    void operator++ () { //++i
        if(pointer!=nullptr)
            pointer=pointer->sig;
    }

    void operator++ (int) {//i++
        if(pointer!=nullptr)
            pointer=pointer->sig;
    }
    
    static ListIterator<Pointer>* begin(const Lista<T> & lista) {
        ListaIterator<Pointer>(lista.ptr) inicio;
        return *inicio;
    }
    
    static ListIterator<Pointer>* end() {
        return nullptr;
    }
};


/**
 * Lista simplemente enlazada
 * @param T Tipo de los elementos de la lista
 */
template<typename T>
class Lista
{
private:
    struct Nodo
    {
        T valor;
        Nodo * sig;
        bool operator == (const Nodo value)
        {
            return(sig==value.sig && valor==value.valor);
        };
        void operator = (Nodo value)
        {
            sig=value.sig;
            valor=value.valor;
        };
    };
    
    typedef Nodo * PtrNodo;
    
    PtrNodo ptr;
    
    friend ListIterator<Pointer> ListaIterator::begin(const Lista<T> & lista);
    friend ListIterator<Pointer> ListaIterator::end();
public:
    Lista():ptr(nullptr) {}
    void push_front(const T &);
    void mostrar() const;
    
    ListaIterator<PtrNodo>* end(){
        return ListaIterator::end(this);
    }
    ListaIterator<PtrNodo>* begin(){
        return ListaIterator;
    }
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

#endif
