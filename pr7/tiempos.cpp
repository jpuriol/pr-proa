/**
* @file tiempos.cpp
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
    
    //PARTE 2
    SArray2<double> z(TAM), v(TAM);

    for(unsigned i = 0; i < TAM; i++)
    {
        z[i] = 2;
        v[i] = 3;
    }
        
    //PARTE 4
    ArrayXd alfa(TAM);
    ArrayXd beta(TAM);
    for(unsigned i = 0; i < TAM; i++)
    {
        alfa[i] = 2;
        beta[i] = 3;
    }
    
    timespec ini_time1, ini_time2, fin_time1, fin_time2;
    
    cout << "Expression template:" << endl;
    clock_gettime(CLOCK_REALTIME, &ini_time1);
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ini_time2);
    for(unsigned i=0; i<100; i++)
        x =  ((1.2+x) * y + ((2.0*y)^2.0));
    clock_gettime(CLOCK_REALTIME, &fin_time1);
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &fin_time2);
    cout << "\tCLOCK_REALTIME:" << (double)fin_time1.tv_sec - (double) ini_time1.tv_sec + fin_time1.tv_nsec * 1e-9 - ini_time1.tv_nsec * 1e-9 << endl;
    cout << "\tCLOCK_PROCESS_CPUTIME_ID:" << (double)fin_time2.tv_sec - (double) ini_time2.tv_sec + fin_time2.tv_nsec * 1e-9 - ini_time2.tv_nsec * 1e-9 << endl;
    cout << "\tOperating system time:" << ((double)fin_time1.tv_sec - (double) ini_time1.tv_sec + fin_time1.tv_nsec * 1e-9 - ini_time1.tv_nsec * 1e-9 )-( (double)fin_time2.tv_sec - (double) ini_time2.tv_sec + fin_time2.tv_nsec * 1e-9 - ini_time2.tv_nsec * 1e-9) << endl;
    
    cout << "Classical Way:" << endl;
    clock_gettime(CLOCK_REALTIME, &ini_time1);
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ini_time2);
    for(unsigned i=0; i<100; i++)
        z =  ((z+1.2) * v + ((v*2.0)^2.0));
    clock_gettime(CLOCK_REALTIME, &fin_time1);
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &fin_time2);
    cout << "\tCLOCK_REALTIME: " << (double)fin_time1.tv_sec - (double) ini_time1.tv_sec + fin_time1.tv_nsec * 1e-9 - ini_time1.tv_nsec * 1e-9 << endl;
    cout << "\tCLOCK_PROCESS_CPUTIME_ID: " << (double)fin_time2.tv_sec - (double) ini_time2.tv_sec + fin_time2.tv_nsec * 1e-9 - ini_time2.tv_nsec * 1e-9 << endl;
    cout << "\tOperating system time: " << ((double)fin_time1.tv_sec - (double) ini_time1.tv_sec + fin_time1.tv_nsec * 1e-9 - ini_time1.tv_nsec * 1e-9 )-( (double)fin_time2.tv_sec - (double) ini_time2.tv_sec + fin_time2.tv_nsec * 1e-9 - ini_time2.tv_nsec * 1e-9) << endl;
    
    cout << "Eigen:" << endl;
    clock_gettime(CLOCK_REALTIME, &ini_time1);
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ini_time2);
    for(unsigned i=0;i<100;i++)
        alfa =  (alfa+1.2)*beta + ((beta*2.0).pow(2.0));
    clock_gettime(CLOCK_REALTIME, &fin_time1);
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &fin_time2);
    cout << "\tCLOCK_REALTIME:" << (double)fin_time1.tv_sec - (double) ini_time1.tv_sec + fin_time1.tv_nsec * 1e-9 - ini_time1.tv_nsec * 1e-9 << endl;
    cout << "\tCLOCK_PROCESS_CPUTIME_ID:" << (double)fin_time2.tv_sec - (double) ini_time2.tv_sec + fin_time2.tv_nsec * 1e-9 - ini_time2.tv_nsec * 1e-9 << endl;
    cout << "\tOperating system time:" << ((double)fin_time1.tv_sec - (double) ini_time1.tv_sec + fin_time1.tv_nsec * 1e-9 - ini_time1.tv_nsec * 1e-9 )-( (double)fin_time2.tv_sec - (double) ini_time2.tv_sec + fin_time2.tv_nsec * 1e-9 - ini_time2.tv_nsec * 1e-9) << endl;
    
    return 0;
}
