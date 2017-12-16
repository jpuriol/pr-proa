#include <iostream>
#include "graph.h"
#include <vector>
#include <time.h>
using namespace std;

template <typename T>
vector<vector<T>> Floyd (Graph<T>);
template <typename T>
vector<vector<T>> FloydInc (Graph<T>);
template <typename T>
void print(vector<vector<T>>);
void print(vector<vector<string>>);
template <typename T>
vector<vector<string>> FloydWay (Graph<T>);

int main()
{
    srand(time(NULL));
    Graph<float> g(6, false);
    vector<vector<string>> camino;
    /*
    PARTE 1
    TEST GRAFO 
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
    cout<< g.toString();
    */
    
    //PARTE 2
    g.randomFill(1,6);
    cout<< g.toString()<<endl;
    print(Floyd(g));
    //PARTE 3
    camino = (FloydWay(g));
    cout<< camino[0][0]<<endl;
    cout<< camino[0][1]<<endl;
    cout<< camino[0][2]<<endl;
    cout<< camino[0][3]<<endl;
    cout<< camino[0][4]<<endl;
    cout<< camino[0][5]<<endl;
    
    /*
    //PARTE 2 Con el algoritmo de Floyd para grafos no completos
    Graph<int> h(6, false);
    h.randomFill(1,5,0.5);
    cout<< h.toString()<<endl;
    print(FloydInc(h));
    */
}


template <typename T>
vector<vector<T>> Floyd (Graph<T> grafo)
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

/*
template <typename T>
vector<vector<T>> FloydInc (Graph<T> grafo)
{
    T w;
    unsigned size=grafo.size();
    vector<vector<T>> matrix(size);
    for(unsigned i=0;i<size;i++)
    {
        matrix[i].resize(size);
        for(unsigned j=0;j<size;j++)
        {
            w=grafo.at(i,j);
            if(w==0&& i!=j)
                matrix[i][j]=999999999;
            else  
                matrix[i][j]=grafo.at(i,j);
        }
    }
       
    for(unsigned k=0;k<size;k++)
        for(unsigned i=0;i<size;i++)
            for(unsigned j=0;j<size;j++)
                matrix[i][j] = min(matrix[i][j],matrix[i][k]+matrix[k][j]);
                
    return matrix;
}
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
vector<vector<string>> FloydWay (Graph<T> grafo)
{
    unsigned size=grafo.size();
    vector<vector<T>> matrix(size);
    vector<vector<string>> caminos(size);
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
    return caminos;
}
