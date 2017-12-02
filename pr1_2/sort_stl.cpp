/**
 * @file sort_stl.cpp
 *
 * Practicas de PROA
 * Practica 2.
 *
 * @author Ignacio Gomis Lli
 * @author Juan Pablo Uriol Balbin
 * @date 19/10/2017
 * @version 1.0
 */

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <random>
#include <math.h>
#include <time.h>
#include <algorithm>
using namespace std;

bool RandomVector(vector<int> &, int, int, mt19937 &);
bool RandomList(list<int> &, int, int, mt19937 &);
void modulo(list<int> &, vector<int> &, int, int, mt19937 &);

/**
 *
 * Funcion Main
 * Ejecuta las pruebas variando el tamaño de lista/vector y numero de elementos.
 *
 */

int main() {

    int UPP1 = 255;
    int UPP2 = 65535;
    vector<int> vect1(1000);
    list<int> lista1(1000);
    vector<int> vect2(10000);
    list<int> lista2(10000);
    vector<int> vect3(100000);
    list<int> lista3(100000);
    
    srand(time(NULL));
    const int SEED = rand();
    std::mt19937 aleatorio(SEED);

    modulo(lista1, vect1, 0, UPP1, aleatorio);
    modulo(lista1, vect1, 0, UPP2, aleatorio);
    modulo(lista2, vect2, 0, UPP1, aleatorio);
    modulo(lista2, vect2, 0, UPP2, aleatorio);
    modulo(lista3, vect3, 0, UPP1, aleatorio);
    modulo(lista3, vect3, 0, UPP2, aleatorio);

    return 0;
}

/**
 *
 * Generara un vector de enteros aleatorios
 *
 * @param[out] vect Vector de enteros con tamaño asignado
 * @param[in] lowlim Limite inferior aleatorio
 * @param[in] uplim Limite superior aleatorio
 * @return True if lowlim <= uplim False if lowlim>uplim
 */

bool RandomVector(vector<int> & vect, int lowlim, int uplim,
        mt19937 & aleatorio) {
    if (lowlim <= uplim) {
        for (unsigned i = 0; i < vect.size(); i++) {
            vect[i] = ((aleatorio() % (uplim - lowlim + 1)) + lowlim);
        }
        return true;
    } else
        return false;
}

/**
 *
 * Generara una lista de enteros aleatorios
 *
 * @param lista Lista de enteros con tamaño asignado
 * @param lowlim Limite inferior aleatorio
 * @param uplim Limite superior aleatorio
 * @return True if lowlim <= uplim False if lowlim>uplim
 */

bool RandomList(list<int> & lista, int lowlim, int uplim, mt19937 & aleatorio) {
    int num;
    if (lowlim <= uplim) {
        auto iter = lista.begin();
        while (iter != lista.end()) {
            num = aleatorio() % (uplim - lowlim + 1) + lowlim;
            *iter = num;
            std::advance(iter, 1);
        }
        return true;
    } else
    return false;
}

/**
 *
 * Calcula el tiempo medio en generar un vector y ordenarlo 
 *
 * @param lista Lista de enteros a ordenar
 * @param vect  Vector a ordenar
 * @param LOW Valor minimo para la generacion aleatoria
 * @param UPP Valor maxima para la generacion aleatoria
 * @param aleatorio Generador de numeros aleatorios
 */
void modulo(list<int> & lista, vector<int> & vect, int LOW, int UPP, mt19937 & aleatorio)
{
    struct timespec ini_time,fin_time;
    int veces=100;
    double BILLION = 1000000000;
    double total;
    
    clock_gettime(CLOCK_REALTIME, &ini_time);
    for (int i = 0; i < veces; i++) 
    {
        RandomVector(vect, LOW, UPP, aleatorio);
        sort(vect.begin(),vect.end());
    }
    clock_gettime(CLOCK_REALTIME, &fin_time);
    total = (fin_time.tv_sec - ini_time.tv_sec)
            + (fin_time.tv_nsec - ini_time.tv_nsec) / BILLION;
            
    cout << "Tiempo medio STL Vector con "<<vect.size()
        <<" elementos y "<<UPP<<" valores: " << total / veces<<endl;
    
    
    clock_gettime(CLOCK_REALTIME, &ini_time);
    for (int i = 0; i < veces; i++) 
    {
        RandomList(lista, LOW, UPP, aleatorio);
        lista.sort();
    }
    clock_gettime(CLOCK_REALTIME, &fin_time);
    total = (fin_time.tv_sec - ini_time.tv_sec)
        + (fin_time.tv_nsec - ini_time.tv_nsec) / BILLION;
    cout << "Tiempo medio STL Lista con "<<lista.size()
        <<" elementos y "<<UPP<<" valores: " << total / veces<<endl;
    
return;
}
