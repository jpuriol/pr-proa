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
#include<stdexcept>
#include<string>
#include<stdlib.h>
using namespace std;

template<typename T, unsigned N>
class Graph {
private:
    T matrix[N][N];
    bool bidirection;
public:
    /**
     * Constructor.
     * @param bidirectional Si el grafo es bidireccional, a�adir un arco incluir� el arco de retorno con mismo peso.
     * @param s Cantidad de nodos en el interior del grafo.
     */
    Graph (bool bidirectional)
    { 
        bidirection = bidirectional;
        limpiar(); //Inicializado de pesos
    } 

    /**
     * Obtencion de elemento en posicion.
     * @param de Nodo del cual se inicia el arco.
     * @param a Nodo al cual se dirige el arco.
     * @return peso para recorrer esa distancia. Un 0 significa que no hay camino.
     */
    T at(unsigned de,unsigned a) const { 
        if(de<0 && de >= N && a<0 && a >=N)
            throw std::out_of_range("Elemento solicitado [" + to_string(de) + "][" + to_string(a) + "]\n Esperados valores entre 0 y " + to_string(N-1));
        return matrix[de][a];
    }
    
    /**
     * Asignacion de elemento en posicion.
     * @param de Nodo del cual se inicia el arco.
     * @param a Nodo al cual se dirige el arco.
     * @param weight Valor asignado a ese camino.
     */
    void set(unsigned de, unsigned a, T weight)
    {
        if(de<0 && de >= N && a<0 && a >=N)
            throw std::out_of_range("Elemento solicitado [" + to_string(de) + "][" + to_string(a) + "]\n Esperados valores entre 0 y " + to_string(N-1));
        matrix[de][a]=weight;
        if(bidirection)
            matrix[a][de]=weight;
    }
    
    /**
     * Metodo toString para recuperar la informacion
     */
    string toString()
    {
        string res="";
        for(unsigned i=0;i<N;i++)
        for(unsigned j=0;j<N;j++)
        {
        res=res+"["+ std::to_string(matrix[i][j]) +"]";
        if(j==(N-1))
            res=res+"\n";
        }
        return res;
    }

    /**
     * Metodo para poner a 0 todos los pesos del grafo
     */
    void limpiar()
    {
        unsigned s=N;
        for(unsigned i=0;i<s;i++)
            for(unsigned j=0;j<s;j++)
            matrix[i][j]=0;
    }
    
    /**
     * Devuelve el numero de nodos del grafo
     * @return numero de nodos
     */
    unsigned size()
    {
        return N;
    }
};




    /**
     * Funcion para rellenar el grafo aleatoriamente con [min,max) para floats
     * @param min Valor minimo
     * @param max Valor maximo (no alcanzable)
     */
    template <typename T, typename G>
    typename std::enable_if<std::is_floating_point<T>::value>::type randomFill(T min,T max, G & grafo)
    {
        cout<<rand()/RAND_MAX<<endl;
        cout<<(max-min)+min<<endl;
        for(unsigned i=0;i<grafo.size();i++)
            for(unsigned j=0;j<grafo.size();j++)
                if(i!=j)
                    grafo.set(i,j,((((float)rand()/(float)RAND_MAX)*(max-min)+min)));
                else
                    grafo.set(i,i,0);
    }
    
    /**
     * Funcion para rellenar el grafo aleatoriamente con [min,max) para ints
     * @param min Valor minimo
     * @param max Valor maximo (no alcanzable)
     */
     template <typename T, typename G>
    typename std::enable_if<std::is_integral <T>::value>::type randomFill(T min,T max, G & grafo)
    {
        for(unsigned i=0;i<grafo.size();i++)
            for(unsigned j=0;j<grafo.size();j++)
                if(i!=j)
                    grafo.set(i,j,(rand()%(max-min)+min));
                else
                    grafo.set(i,i,0);
    }



#endif
