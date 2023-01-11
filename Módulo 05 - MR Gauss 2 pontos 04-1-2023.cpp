#include <iostream>
#include <cmath>
#include <math.h>
#include <iomanip>

using namespace std;

#define NMAX 20

double f(double x);

int main()
{
    int i = 0, j, n; // n quantidade de intervalos
    double a, b, area[NMAX], ER[NMAX], h, epsilon = 0.000001;
    double xl, xc, xr, y1, y2;
    
    // entradas do código
    a = 0.0;
    b = 1.0;
    y1 = (a + b - sqrt(3)/3.0*(b-a))*0.5;
    y2 = (a + b + sqrt(3)/3.0*(b-a))*0.5;
    area[0] = 0.5*(b-a)*(f(y1)+f(y2));
    ER[0] = 1.0;
    n = 1;
    
    while(ER[i] > epsilon && i < NMAX){
        i++;
        n = 2*n;
        h = (b - a)/double(n);
        
        area[i] = 0.0;
        
        for(j=0 ; j < n; j++){
            xl =  a + j * h;
            xr = xl + h;
            y1 = (xl + xr - sqrt(3)/3.0*(xr-xl))*0.5;
            y2 = (xl + xr + sqrt(3)/3.0*(xr-xl))*0.5;
            area[i] = area[i] + f(y1) + f(y2);
        }
        area[i] = 0.5*area[i]*h;
        ER[i] = abs(area[i]-area[i-1])/abs(area[i]);
    }
    
    cout << "k;A(k);ER(k)" << endl;
    for(j = 0; j <= i; j++){
        cout << j << ";" << setprecision(10) << area[j] << ";" << setprecision(10) << ER[j] << endl;
    }
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



