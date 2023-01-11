#include <iostream>
#include <cmath>
#include <math.h>
#include <iomanip>

using namespace std;

#define NUM 16

double f(double x);

int main()
{
    int i, n=NUM; // n quantidade de intervalos
    double a, b, area = 0.0, x[NUM+1], y[2*NUM], h;
    double x1, x2;
    
    a = 0.2;
    b = 1.8;
    h = (b-a)/(n);
    x[0] = a; // São os pontos que definem as extremidades dos intervalos
    for(i = 1; i <= n; i++){
        x[i] = x[i-1] + h;
    }
    
    for(i=0; i<n; i++){
        y[2*i] = x[i]+x[i+1]-sqrt(3)*(x[i+1]-x[i])/2.0;
        y[2*i + 1] = x[i]+x[i+1]+sqrt(3)*(x[i+1]-x[i])/2.0;
        area += f(y[2*i]) + f(y[2*i + 1]);
    }
    
    area *= h * 0.5;
    
    cout << "Area = " << setprecision(10) << area << endl;
}

double f(double x){
    double y =0.0, pi = 3.14159265359, z;
    z = pi * x;
    y = 2.0*exp(-x*x) + 4.0 + sin(2.0*z) + sin(3.0*z) + cos(4.0*z);
    return y;
}
