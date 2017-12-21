/**
* @file testGraph.h
*
* Practicas de PROA
*
* @author Ignacio Gomis Lli
* @author Juan Pablo Uriol Balbin
* @date 15/12/2017
* @version 1.0
*/
#include <iostream>
#include "graph.h"
#include <vector>
#include <time.h>
using namespace std;

const unsigned NODES = 6;

//Funciones
template <typename T>
vector<vector<T>> Floyd (Graph<T, NODES>);
template <typename T>
void FloydWay (Graph<T, NODES>, vector<vector<T>> &, vector<vector<vector<unsigned>>> &);
void intercalar(unsigned i,unsigned j, unsigned k, vector<vector<vector<unsigned>>> &);
//Prints
template <typename T>
void print(vector<vector<T>>);
void print(vector<vector<vector<unsigned>>>);
template <typename T>
void print(unsigned,unsigned, const vector<vector<T>> &, const vector<vector<vector<unsigned>>> &);

int main()
{
    srand(time(NULL));
    Graph<float, NODES> g(false);
    vector<vector<string>> camino(NODES);
    vector<vector<vector<unsigned>>> caminos(NODES);
    vector<vector<float>> resultado;
    //PARTE 1
    //TEST GRAFO
    g.set(0,3,5);
    float valor = g.at(0,3);
    cout<<"Agregado 5 en la posicion? "<<valor<<endl;
    for(int i=0;i<5;i++)
        for(int j=i+1;j<6;j++)
        {
            if(2*i-j>0)
            g.set(i,j,2*i-j);
            else
            g.set(i,j,-2*i+j);
        }
    cout<< g.toString()<<endl;
    g.limpiar();
    
    
    //PARTE 2
    randomFill(0.5,6.0,g);
    cout<< g.toString()<<endl;
    print(Floyd(g));
    //PARTE 3
    FloydWay(g,resultado, caminos );
    for(int i=0;i<6;i++)
    print(0,i,resultado,caminos);
}

/**
 * Algoritmo de Floyd
 * En esta version no soporta grafos no completos
 * @param grafo argumento como matriz de adyacencia
 * @return matriz con costes para ir de cada nodo a otro
 */
template <typename T>
vector<vector<T>> Floyd (Graph<T, NODES> grafo)
{
    unsigned size=grafo.size();
    vector<vector<T>> matrix(size);
    for(unsigned i=0;i<size;i++)
    {
        matrix[i].resize(size);
        for(unsigned j=0;j<size;j++)
        matrix[i][j]=grafo.at(i,j);
    }
       
    for(unsigned k=0;k<size;k++)
        for(unsigned i=0;i<size;i++)
            for(unsigned j=0;j<size;j++)
                matrix[i][j] = min(matrix[i][j],matrix[i][k]+matrix[k][j]);
                
    return matrix;
}

/**
 * Imprime una matriz
 */
template <typename T>
void print(vector<vector<T>> m)
    {
        string res="";
        for(unsigned i=0;i<m.size();i++)
        for(unsigned j=0;j<m.size();j++)
        {
        res=res+"["+ std::to_string(m[i][j]) +"]";
        if(j==(m.size()-1))
            res=res+"\n";
        }
        cout<<res;
    }

/**
 * Algoritmo de Floyd, con retorno de camino
 * En esta version no soporta grafos no completos
 * @param grafo argumento como matriz de adyacencia
 * @param matrix salida, mejores valores
 * @param caminos salida, mejores caminos
 */
template <typename T>
void FloydWay (Graph<T, NODES> grafo,vector<vector<T>> & matrix,vector<vector<vector<unsigned>>> & caminos)
{
    unsigned size=grafo.size();
    matrix.clear();
    caminos.clear();
    matrix.resize(size);
    caminos.resize(size);
    for(unsigned i=0;i<size;i++)
    {
        matrix[i].resize(size);
        caminos[i].resize(size);
        for(unsigned j=0;j<size;j++)
        {
            matrix[i][j]=grafo.at(i,j);
            if(i!=j)
            {
                caminos[i][j].push_back(i);
                caminos[i][j].push_back(j);
            }
            else
                caminos[i][i].push_back(i);
        }
    }
    for(unsigned k=0;k<size;k++)
    {
        for(unsigned i=0;i<size;i++)
        {
            for(unsigned j=0;j<size;j++)
            {
                if(matrix[i][j]<=matrix[i][k]+matrix[k][j])
                {
                    matrix[i][j] = matrix[i][j];
                }
                else
                {
                    matrix[i][j] = matrix[i][k]+matrix[k][j];
                    intercalar(i,j,k,caminos);
                }
            }
        }
    }
}

/**
 * Funcion para asignar el camino a una celda
 * @param i celda origen
 * @param j celda destino
 * @param k celda intercalada
 * @param caminos matriz con todos los caminos, por referencia
 */
void intercalar(unsigned i,unsigned j, unsigned k, vector<vector<vector<unsigned>>> & caminos)
{
    vector<unsigned> aux;
    for(unsigned h=0;h<caminos[i][k].size();h++)
    {
        aux.push_back(caminos[i][k][h]);
    }
    for(unsigned h=1;h<caminos[k][j].size();h++)
    {
        aux.push_back(caminos[k][j][h]);
    }
    caminos[i][j]=aux;
}
          
                    
void print(vector<vector<vector<unsigned>>> m)
    {
        string res="";
        for(unsigned i=0;i<m.size();i++)
        for(unsigned j=0;j<m.size();j++)
        {
        res=res+"[ ";
            for(unsigned h=0;h<m[i][j].size();h++)
            {
                if(h!=0)
                res=res+"->";
                res=res+"["+std::to_string(m[i][j][h])+"]";
            }
        res=res+" ]";
        if(j==(m.size()-1))
            res=res+"\n";
        }
        cout<<res;
    }
         
    
/**
 * Imprime un elemento de las matrices 
 * @param i indice origen
 * @param j indice destino
 * @param res matriz de pesos
 * @param cam matriz de caminos
 */               
template <typename T>
void print(unsigned i , unsigned j ,const vector<vector<T>> & res, const vector<vector<vector<unsigned>>> & cam)
{
    cout<<"Precio: "<<res[i][j]<<endl;
    string cad="[ ";
        for(unsigned h=0;h<cam[i][j].size();h++)
        {
            if(h!=0)
            cad=cad+"->";
            cad=cad+"["+std::to_string(cam[i][j][h])+"]";
        }
        cad=cad+" ]";
    cout<<"  Camino: "<<cad<<endl<<endl;
}

