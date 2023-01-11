#include <iostream>
#include <cmath>
#include <math.h>
#include <iomanip>

using namespace std;

#define NUM 10

int main()
{
    int n = 10, i, j;
    double x[NUM], y[NUM];
    double a0, a1, a, b;
    double lx[NUM], ly[NUM], lx2[NUM], lyx[NUM], slx = 0, slx2 = 0, sly = 0, slyx = 0;
    
    x[0] = 1.0;
    x[1] = 2.0;
    x[2] = 3.0;
    x[3] = 4.0;
    x[4] = 5.0;
    x[5] = 6.0;
    x[6] = 7.0;
    x[7] = 8.0;
    x[8] = 9.0;
    x[9] = 10.0;
    
    y[0] = 0.829;
    y[1] = 3.206;
    y[2] = 10.13;
    y[3] = 23.7;
    y[4] = 42.2;
    y[5] = 69.16;
    y[6] = 106.5;
    y[7] = 153.2;
    y[8] = 209.2;
    y[9] = 281.3;
    
    for(i = 0; i<n; i++){
        lx[i] = log(x[i]);
        lx2[i] = lx[i]*lx[i];
        ly[i] = log(y[i]);
        lyx[i] = lx[i]*ly[i];
    }
    
    for(i = 0; i<n; i++){
        slx += lx[i];
        sly += ly[i];
        slx2 += lx2[i];
        slyx += lyx[i];
    }
    
    a0 = (slx2*sly - slyx*slx)/(double (n) * slx2 - slx * slx);
    a1 = (double (n) * slyx - slx*sly)/(double (n) * slx2 - slx * slx);
    a = exp(a0);
    b = a1;
    
    cout << "\t\tlog(x)\t\tlog(y)\t\tlog(x) ^2\t\tlog(y)log(x)" << endl;
    for(i = 0; i<n; i++){
        cout << "\t\t" << lx[i] << "\t\t" << ly[i] << "\t\t" << lx2[i] << "\t\t" << lyx[i] << endl;
    }
    
    cout << "-------------------------------------------------------------------------" << endl;
    cout << "Somas\t\t" << slx << "\t\t" << sly << "\t\t" << slx2 << "\t\t" << slyx << endl;
    cout << "-------------------------------------------------------------------------" << endl;
    
    cout << "a0 = " << a0 << "\t\ta1 = " << a1 << endl;
    cout << "a = " << a << "\t\tb = " << b << endl;
}

