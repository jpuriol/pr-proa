/**
* @file graph.h
*
* Practicas de PROA
*
* @author Ignacio Gomis Lli
* @author Juan Pablo Uriol Balbin
* @date 15/12/2017
* @version 1.0
*/
#ifndef _GRAPH_H
#define _GRAPH_H
#include<cassert>
#include<string>
#include<stdlib.h>
using namespace std;

template<typename T>
class Graph {   
    T* matrix;
    bool bidirection;
    unsigned nodes;


public:
    /**
     * Constructor.
     * @param bidirectional Si el grafo es bidireccional, añadir un arco incluirá el arco de retorno con mismo peso.
     * @param s Cantidad de nodos en el interior del grafo.
     */
    explicit Graph (const unsigned s, bool bidirectional)
    : matrix(new T[s*s]) { 
    nodes = s;
    bidirection = bidirectional;
    limpiar(); //Inicializado de pesos
    } 

    /**
     * Constructor de copia.
     * @param orig Otro grafo.
     */
    Graph<T>& operator= (Graph<T> const& orig) { 
        if (&orig != this) { 
            copy(orig); 
        } 
        return *this; 
    } 

    /**
     * Obtencion de elemento en posicion.
     * @param de Nodo del cual se inicia el arco.
     * @param a Nodo al cual se dirige el arco.
     * @return peso para recorrer esa distancia. Un 0 significa que no hay camino.
     */
    T at(unsigned de,unsigned a) const { 
        assert(de>=0 && de <nodes && a>=0 && a <nodes);
        return matrix[nodes*de+a];
    } 
    
    /**
     * Obtencion de elemento en posicion.
     * @param de Nodo del cual se inicia el arco.
     * @param a Nodo al cual se dirige el arco.
     * @return peso para recorrer esa distancia. Un 0 significa que no hay camino.
     */
    T& at(unsigned de,unsigned a) { 
        assert(de>=0 && de <nodes && a>=0 && a <nodes);
        return matrix[nodes*de+a]; 
    }
    
    /**
     * Asignacion de elemento en posicion.
     * @param de Nodo del cual se inicia el arco.
     * @param a Nodo al cual se dirige el arco.
     * @param weight Valor asignado a ese camino.
     */
    void set(unsigned de, unsigned a, T weight)
    {
        assert(weight>=0 && de>=0 && de <nodes && a>=0 && a <nodes);
        matrix[nodes*de+a]=weight;
        if(bidirection)
            matrix[nodes*a+de]=weight;
    }
    
    /**
     * Metodo toString para recuperar la informacion
     */
    string toString()
    {
        string res="";
        for(unsigned i=0;i<nodes;i++)
        for(unsigned j=0;j<nodes;j++)
        {
        res=res+"["+ std::to_string(matrix[nodes*i+j]) +"]";
        if(j==(nodes-1))
            res=res+"\n";
        }
        return res;
    }

    /**
     * Metodo para poner a 0 todos los pesos del grafo
     */
    void limpiar()
    {
        unsigned s=nodes*nodes;
        for(unsigned i=0;i<s;i++)
            matrix[i]=0;
    }
    
    /**
     * Funcion para rellenar el grafo aleatoriamente con [min,max)
     * @param min Valor minimo
     * @param max Valor maximo (no alcanzable)
     */
    void randomFill(T min,T max)
    {
        if(!bidirection)
        {
            for(unsigned i=0;i<nodes;i++)
                for(unsigned j=0;j<nodes;j++)
                    if(i!=j)
                        set(i,j,((float)(rand()%100)/100*(max-min)+min));
                    else
                        set(i,i,0);
        }
        else
        {
            for(unsigned i=0;i<nodes;i++)
                for(unsigned j=i;j<nodes;j++)
                    if(i!=j)
                        set(i,j,((float)(rand()%100)/100*(max-min)+min));
                    else
                        set(i,i,0);
        }
    }
    
    /**
     * Funcion para rellenar el grafo aleatoriamente con [min,max)
     * @param min Valor minimo
     * @param max Valor maximo (no alcanzable)
     * @param prob Probabilidad de no haber arco
     */
    void randomFill(T min,T max,float prob)
    {
        if(!bidirection)
        {
            for(unsigned i=0;i<nodes;i++)
                for(unsigned j=0;j<nodes;j++)
                    if(i!=j && (float)(rand()%100)/100>prob)
                        set(i,j,((float)(rand()%100)/100*(max-min)+min));
                    else
                        set(i,j,0);
        }
        else
        {
            for(unsigned i=0;i<nodes;i++)
                for(unsigned j=i;j<nodes;j++)
                    if(i!=j && (float)(rand()%100)/100>prob)
                        set(i,j,((float)(rand()%100)/100*(max-min)+min));
                    else
                        set(i,j,0);
        }
    }
    
    /**
     * Devuelve el numero de nodos del grafo
     * @return numero de nodos
     */
    unsigned size()
    {
        return nodes;
    }
};

#endif
    
