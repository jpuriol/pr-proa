/**
 * @file sort.cpp
 *
 * Practicas de PROA
 * Practica 2.
 *
 * @author Ignacio Gomis Lli
 * @author Juan Pablo Uriol Balbin
 * @date 19/10/2017
 * @version 1.0
 */

#include "sort.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <random>
#include <math.h>
using namespace std;

const int BASE_NUM = 16;
int Digito(int, int);
void ConcatenarVector(vector<int> &, const vector <int> &);

/**
 *
 * Generara un vector de enteros aleatorios
 *
 * @param[out] vect Vector de enteros con tama�o asignado
 * @param[in] lowlim Limite inferior aleatorio
 * @param[in] uplim Limite superior aleatorio
 * @return True if lowlim <= uplim False if lowlim>uplim
 */
bool RandomVector( vector<int> & vect, int lowlim, int uplim, mt19937 & aleatorio)
{
    uniform_int_distribution<> dis(lowlim, uplim);
    if(lowlim <= uplim)
    {
        for(unsigned i = 0; i < vect.size(); ++i)
            vect[i] = dis(aleatorio); 
        return true;
    }
    else
        return false;
}

/**
 *
 * Aplicara el algoritmo CountSort sobre un vector con valores empezando en 0
 *
 *
 * @param vect Vector a ordenar
 * @param max Numero maximo que puede alcanzar el vector
 *
 */
void CountSort(vector<int> & vectorToSort, int max)
{
        ++max; ///< Añade el 0
        vector<int> sorted( vectorToSort.size() );
        vector<int> aux(max);
        
        for(unsigned i = 0; i < vectorToSort.size(); i=i+10)
        {
            ++aux[ vectorToSort[i] ];  ///< aux[i] contiene cuantas veces aparece i+1 en v  
            ++aux[ vectorToSort[i+1] ]; 
            ++aux[ vectorToSort[i+2] ]; 
            ++aux[ vectorToSort[i+3] ]; 
            ++aux[ vectorToSort[i+4] ]; 
            ++aux[ vectorToSort[i+5] ]; 
            ++aux[ vectorToSort[i+6] ]; 
            ++aux[ vectorToSort[i+7] ]; 
            ++aux[ vectorToSort[i+8] ]; 
            ++aux[ vectorToSort[i+9] ]; 
        }
            
        for(int i = 1; i < max; ++i)
        {
            aux[i] += aux[i-1];  ///< aux[i] contiene en que pos tiene que ir i+1
        }
            
        for(int i = 0; i < max; ++i) ///< Ajuste para añadir el 0
        {
            --aux[i]; 
        }
            

        for(int i = vectorToSort.size() - 1; i >= 0; i=i-10)
        {
            sorted[ aux[ vectorToSort[i] ] ]= vectorToSort[i];
            --aux[ vectorToSort[i] ];
            sorted[ aux[ vectorToSort[i-1] ] ]= vectorToSort[i-1];
            --aux[ vectorToSort[i-1] ];
            sorted[ aux[ vectorToSort[i-2] ] ]= vectorToSort[i-2];
            --aux[ vectorToSort[i-2] ];
            sorted[ aux[ vectorToSort[i-3] ] ]= vectorToSort[i-3];
            --aux[ vectorToSort[i-3] ];
            sorted[ aux[ vectorToSort[i-4] ] ]= vectorToSort[i-4];
            --aux[ vectorToSort[i-4] ];
            sorted[ aux[ vectorToSort[i-5] ] ]= vectorToSort[i-5];
            --aux[ vectorToSort[i-5] ];
            sorted[ aux[ vectorToSort[i-6] ] ]= vectorToSort[i-6];
            --aux[ vectorToSort[i-6] ];
            sorted[ aux[ vectorToSort[i-7] ] ]= vectorToSort[i-7];
            --aux[ vectorToSort[i-7] ];
            sorted[ aux[ vectorToSort[i-8] ] ]= vectorToSort[i-8];
            --aux[ vectorToSort[i-8] ];
            sorted[ aux[ vectorToSort[i-9] ] ]= vectorToSort[i-9];
            --aux[ vectorToSort[i-9] ];
        }

        vectorToSort = sorted;
    }


/**
 *
 * Aplicara el algoritmo LSDRadixSort sobre un vector
 *
 *
 * @param vect Vector a ordenar
 * @param max Numero maximo que puede alcanzar el vector
 *
 */
void RadixSortVector(vector<int> & vectorToSort, int max)
{
    unsigned n = vectorToSort.size();
    int d;
    vector< vector<int> > aux(BASE_NUM);   

    unsigned iterations = log2(max) / 4;
    for(unsigned i = 0; i <= iterations; ++i)
    {
        for(unsigned j = 0; j < BASE_NUM; ++j)
            aux[j].clear();

        for(unsigned j = 0; j < n; ++j)
        {
            d = Digito( i, vectorToSort[j] );
            aux[d].push_back( vectorToSort[j] );
        }
        vectorToSort = move( aux[0] );
        for(unsigned j = 1; j < BASE_NUM; ++j)
            ConcatenarVector(vectorToSort, aux[j]);
    }
}

/**
 *
 * Concatenacion de 2 vectores
 *
 *
 * @param v1 Vector inicial
 * @param v2 Vector a insertar tras v1
 *
 */

void ConcatenarVector(vector<int> & v1, const vector <int> & v2)
{
    for(unsigned i = 0;i < v2.size(); i++)
        v1.push_back( v2[i] );
}

/**
 *
 * Obtiene un digito de un entero
 *
 *
 * @param posicion Indice de posicion que obtener el digito del numero.
 * @param num Numero del cual obtener el digito.
 *
 */
int Digito(int pos, int num)
{
    for(int i = 0; i < pos; ++i)
        num = num >> 4;
    num = num % BASE_NUM;
    return num;
}

/**
 *
 * Generara una listToSort de enteros aleatorios
 *
 * @param listToSort ListToSort de enteros con tamano asignado
 * @param lowlim Limite inferior aleatorio
 * @param uplim Limite superior aleatorio
 * @return True if lowlim <= uplim False if lowlim>uplim
 */
bool RandomList (list<int> & listToSort, int lowlim, int uplim, mt19937 & aleatorio)
{
    uniform_int_distribution<> dis(lowlim, uplim);
    if(lowlim <= uplim)
    {
        auto iter=listToSort.begin();
        while(iter!=listToSort.end())
        {
            *iter = dis(aleatorio); 
            std::advance(iter,1);
        }
        return true;
    }
    else
        return false;
}

/**
 *
 * Aplicara el algoritmo LSDRadixSort sobre una listToSort
 *
 *
 * @param listToSort ListToSort a ordenar
 * @param max Numero maximo que puede alcanzar la listToSort
 *
 */
void RadixSortList(list<int> & listToSort, int max)
{
    int d;
    vector<list<int> > aux(BASE_NUM);

    unsigned iterations = log2(max) / 4;
    for(unsigned i = 0; i <= iterations; ++i)
    {
    for(unsigned j = 1; j < BASE_NUM; ++j)
            aux[j].clear();

            auto iter=listToSort.begin();
            while(iter!=listToSort.end())
            {
                    d = Digito( i, *iter );
                    aux[d].push_back( *iter );
                    ++iter;
            }

    for(unsigned j = 1; j < BASE_NUM; ++j)
        aux[0].splice(aux[0].end(), aux[j]);
        listToSort = move( aux[0] );
        }
}

/**
 *
 * Imprime un vector por pantalla
 *
 *
 * @param vect Vector a imprimir
 *
 */
void PrintVector(const vector<int> & vect) 
{
    for(auto v : vect)
        cout << "[" << v << "]";
    cout << endl; 
}

/**
 *
 * Imprime una lista por pantalla
 *
 *
 * @param listToSort lista a imprimir
 *
 */
void PintList(const list<int> & lis) 
{
    for(auto l : lis)
        cout << "[" << l <<"]";
    cout << endl;
}
