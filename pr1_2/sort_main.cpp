/**
 * @file sort_main.cpp
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
#include "sort.h"
using namespace std;


/**
 *
 * Funcion Main
 * Ejecuta las pruebas variando el tamaño de lista/vector y numero de elementos para obtener los tiempos.
 *
 */
int main(/*int argc, char **argv*/)
{
	int LOW = 0;
	int UPP1 = 65535;
	vector<int> vect(10000);
	list<int> lista(10000);

	struct timespec ini_time,fin_time;
	srand(time(NULL));
	const int SEED = rand();
	mt19937 aleatorio(SEED);
	double total = 0;

    for (int i = 0; i < 1000; i++) 
    {
		RandomVector(vect, LOW, UPP1, aleatorio);
	    clock_gettime(CLOCK_REALTIME, &ini_time);
		CountSort(vect, UPP1);
	    clock_gettime(CLOCK_REALTIME, &fin_time);
	    total += (double)fin_time.tv_sec - (double) ini_time.tv_sec
			  + fin_time.tv_nsec * 1e-9 - ini_time.tv_nsec * 1e-9;
	}
	cout << "Tiempo medio Countsort: " << total / 1000<<endl;

    total = 0;
	for (int i = 0; i < 1000; i++) {
		RandomVector(vect, LOW, UPP1, aleatorio);
	    clock_gettime(CLOCK_REALTIME, &ini_time);
        RadixSortVector(vect, UPP1);
        clock_gettime(CLOCK_REALTIME, &fin_time);
	    total += (double)fin_time.tv_sec - (double) ini_time.tv_sec
			  + fin_time.tv_nsec * 1e-9 - ini_time.tv_nsec * 1e-9;
	}
	cout << "Tiempo medio RadixSort Vector: " << total / 1000<<endl;

    total = 0;
	for (int i = 0; i < 1000; i++) {
		RandomList(lista, LOW, UPP1, aleatorio);
	    clock_gettime(CLOCK_REALTIME, &ini_time);
		RadixSortList(lista, UPP1);
	    clock_gettime(CLOCK_REALTIME, &fin_time);
	    total += (double)fin_time.tv_sec - (double) ini_time.tv_sec
			  + fin_time.tv_nsec * 1e-9 - ini_time.tv_nsec * 1e-9;
	}
    cout << "Tiempo medio RadixSort Lista: " << total / 1000<<endl;

  return 0;
}
