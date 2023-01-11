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
    double a, b, area = 0.0, x[NUM+1], h;
    a = 0.2;
    b = 1.8;
    h = (b-a)/(n);
    
    x[0] = a;
    for(i = 1; i <= n; i++){
        x[i] = x[i-1] + h;
    }
    
    // Calcula a area
    area = f(x[0]) + f(x[n]);
    for(i = 1; i <= int(n/2.0); i++){
        area += 4.0 * f(x[2*i-1]);
    }
    for(i = 1; i < int(n/2.0); i++){
        area += 2.0 * f(x[2*i]);
    }
    area = area * h / 3.0;
    
    cout << "Area = " << setprecision(10) << area << endl;
}

double f(double x){
    double y =0.0, pi = 3.14159265359, z;
    z = pi * x;
    y = 2.0*exp(-x*x) + 4.0 + sin(2.0*z) + sin(3.0*z) + cos(4.0*z);
    return y;
}
