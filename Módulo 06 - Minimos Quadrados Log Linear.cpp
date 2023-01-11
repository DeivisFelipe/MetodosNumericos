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
    double x2[NUM], yx[NUM], sx = 0, sx2 = 0;
    double a0, a1;
    double ly[NUM], lyx[NUM], sly = 0, slyx = 0;
    double a, b;
    
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
    
    y[0] = 4.143;
    y[1] = 5.737;
    y[2] = 8.755;
    y[3] = 18.02;
    y[4] = 28.67;
    y[5] = 47.59;
    y[6] = 83.22;
    y[7] = 139.2;
    y[8] = 235.9;
    y[9] = 404.6;
    
    for(i = 0; i<n; i++){
        sx += x[i];
    }
    
    for(i = 0; i<n; i++){
        x2[i] = x[i] * x[i];
        ly[i] = log(y[i]);
        lyx[i] = x[i] * ly[i];
        sx2 += x2[i];
        sly += ly[i];
        slyx += lyx[i];
    }
    
    a0 = (sx2*sly - slyx*sx)/(double (n) * sx2 - sx * sx);
    a1 = (double (n) * slyx - sx*sly)/(double (n) * sx2 - sx * sx);
    a = exp(a0);
    b = exp(a1);
    
    cout << "\t\tx\t\tlog(y)\t\tx2\t\tlog(y)x" << endl;
    for(i = 0; i<n; i++){
        cout << "\t\t" << x[i] << "\t\t" << ly[i] << "\t\t" << x2[i] << "\t\t" << lyx[i] << endl;
    }
    
    cout << "-------------------------------------------------------------------------" << endl;
    cout << "Somas\t\t" << sx << "\t\t" << sly << "\t\t" << sx2 << "\t\t" << slyx << endl;
    cout << "-------------------------------------------------------------------------" << endl;
    
    cout << "a0 = " << a0 << "\t\ta1 = " << a1 << endl;
    cout << "a = " << a << "\t\tb = " << b << endl;
}

