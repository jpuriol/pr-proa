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

int main()
{
    srand(time(NULL));
    Graph<float> g(6, false);
    /*g.set(0,3,5);
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
    cout<< g.toString();*/
    g.randomFill(0.5,6);
    cout<< g.toString()<<endl;
    print(Floyd(g));
    
    /*
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
