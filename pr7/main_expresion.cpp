

#include<iostream>
#include "expresion.h"
using namespace std;

const unsigned TAM = 1000000;

int main()
{
    Array<double> x(TAM), y(TAM);

    for(unsigned i = 0; i < TAM; i++)
    {
        x[i] = i;
        y[i] = i+5;
    }
    
    x =  ((1.2+x) + (1.2*y)) * (y^2.0);
    
    for(unsigned i = 0; i < 10; i++)
    {
        cout << x[i] << " ";
    }
    cout << endl;
}
