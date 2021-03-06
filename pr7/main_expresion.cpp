/**
* @file main_expresion.cpp
*
* Practicas de PROA
*
* @author Ignacio Gomis Lli
* @author Juan Pablo Uriol Balbin
* @date 14/12/2017
* @version 1.0
*/
#include<iostream>
#include "expresion.h"
#include "SArray2.h"
#include "Eigen/Dense"
using namespace std;
using Eigen::ArrayXd;

const unsigned TAM = 1000000;

int main()
{
    //PARTE 1
    
    Array<double> x(TAM), y(TAM);

    for(unsigned i = 0; i < TAM; i++)
    {
        x[i] = 2;
        y[i] = 3;
    }
    
    x =  ((1.2+x) * y + ((2.0*y)^2.0));
    
    for(unsigned i = 0; i < 10; i++)
    {
        cout << x[i] << " ";
    }
    cout << endl;
    
    //PARTE 2
    SArray2<double> z(TAM), v(TAM);

    for(unsigned i = 0; i < TAM; i++)
    {
        z[i] = 2;
        v[i] = 3;
    }
    
    z =  ((z+1.2) * v + ((v*2.0)^2.0));
    
    for(unsigned i = 0; i < 10; i++)
    {
        cout << z[i] << " ";
    }
    cout << endl;
    
    
    
    //PARTE 4
    ArrayXd alfa(TAM);
    ArrayXd beta(TAM);
    for(unsigned i = 0; i < TAM; i++)
    {
        alfa[i] = 2;
        beta[i] = 3;
    }
    
    alfa =  (alfa+1.2)*beta + ((beta*2.0).pow(2.0));
    
    for(unsigned i = 0; i < 10; i++)
    {
        cout << alfa[i] << " ";
    }
    cout<<endl;
    
    //Parte 5
    cout<< (1.2+x).type()<<endl;
    cout<< (1.2*x).type()<<endl;
    cout<< (x^1.2).type()<<endl;
    cout<< (x+x).type()<<endl;
    cout<< (y*y).type()<<endl;
    cout<< (y*(y*y)).type()<<endl;
    cout<< (1.2 * x + y).type()<<endl;
    cout<< ((1.2 + x * y) + ((2.0 * y)^2.0)).type() << endl;
}
