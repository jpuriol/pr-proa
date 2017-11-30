/**
 * @file sort_stl.h
 *
 * Practicas de PROA
 * Practica 2.
 *
 * @author Ignacio Gomis Lli
 * @author Juan Pablo Uriol Balbin
 * @date 19/10/2017
 * @version 1.0
 */

#ifndef SORT_H
#define SORT_H

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <random>
#include <math.h>
using namespace std;


bool RandomVector( vector<int> &, int, int, mt19937 &);
void CountSort(vector<int> &, int);
void RadixSortVector(vector<int> &, int);
bool RandomList( list<int> &, int, int, mt19937 &);
void RadixSortList(list<int> &, int);
void PrintVector(const vector<int> &);
void PintList(const list<int> &);

#endif
