

#include<iostream>
#include "expresion.h"
//#include "sarray2.h"
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
    
    x =  (1.2+x) * y + ((2.0*y)^2.0);
    
    for(unsigned i = 0; i < 10; i++)
    {
        cout << x[i] << " ";
    }
    cout << endl;
    //PARTE 2
    
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
}
