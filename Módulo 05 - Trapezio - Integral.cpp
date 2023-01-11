#include <iostream>
#include <cmath>
#include <math.h>
#include <iomanip>

using namespace std;

#define NUM 4

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
    for(i = 1; i < n; i++){
        area += 2 * f(x[i]);
    }
    area = area * h * 0.5;
    
    cout << "Area = " << setprecision(10) << area << endl;
}

double g(double x){
    double pi = 3.14159265359;
    double c1 = 1.7;
    double c2 = 0.91;
    double c3 = 1.4;
    double c4 = 1.0;
    return cos(2.0*pi*(c3*x-c4*x*x));
}

double f(double x){
    double pi = 3.14159265359;
    double c1 = 1.7;
    double c2 = 0.91;
    double c3 = 1.4;
    double c4 = 1.0;
    return pow(exp(1.0), -1.0*x)*sin(2.0*pi*(c1*x-c2*x*x+2.0*g(x)));
}

