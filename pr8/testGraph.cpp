#include <iostream>
#include "graph.h"
#include <vector>
#include <time.h>
using namespace std;

const unsigned NODES = 6;

template <typename T>
vector<vector<T>> Floyd (Graph<T, NODES>);
template <typename T>
void print(vector<vector<T>>);
void print(vector<vector<string>>);
template <typename T>
void FloydWay (Graph<T, NODES>, vector<vector<T>> &, vector<vector<string>> &);
template <typename T>
void print(unsigned,unsigned, const vector<vector<T>> &, const vector<vector<string>> &);

int main()
{
    srand(time(NULL));
    Graph<float, NODES> g(false);
    vector<vector<string>> camino(NODES);
    vector<vector<float>> resultado;
    
    //PARTE 1
    //TEST GRAFO 
    g.set(0,3,5);
    float valor = g.at(0,3);
    cout<<valor<<endl;
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
    FloydWay(g,resultado, camino );
    
    for(int i=0;i<6;i++)
        print(0,i,resultado,camino);
}


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
    
void print(vector<vector<string>> m)
    {
        string res="";
        for(unsigned i=0;i<m.size();i++)
        for(unsigned j=0;j<m.size();j++)
        {
        res=res+"["+ m[i][j] +"]";
        if(j==(m.size()-1))
            res=res+"\n";
        }
        cout<<res;
    }
    
template <typename T>
void FloydWay (Graph<T, NODES> grafo,vector<vector<T>> & matrix,vector<vector<string>> & caminos)
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
                caminos[i][j]="["+std::to_string(i)+"]->["+std::to_string(j)+"]";
            else
                caminos[i][j]="["+std::to_string(i)+"]";
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
                    caminos[i][j] = caminos[i][k]+","+caminos[k][j];
                }
            }
        }
    }
}

template <typename T>
void print(unsigned i , unsigned j ,const vector<vector<T>> & res, const vector<vector<string>> & cam)
{
    cout<<"Precio: "<<res[i][j]<<endl;
    cout<<"  Camino: "<<cam[i][j]<<endl<<endl;
}
