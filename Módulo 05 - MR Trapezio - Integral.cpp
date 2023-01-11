#include <iostream>
#include <cmath>
#include <math.h>
#include <iomanip>

using namespace std;

#define NMAX 20

double f(double x);

int main()
{
    int i = 0, j, n=4; // n quantidade de intervalos
    double a, b, area[NMAX], ER[NMAX], h, epsilon = 0.000001;
    
    // entradas do código
    a = 0;
    b = 1;
    h = (b-a)/(2);
    
    area[0] = 0.5*h*(f(a) * f(b));
    ER[0] = 1.0;
    n = 1;
    i = 100;
    
    while(i < NMAX && ER[i] > epsilon){
        n *= 2;
        h = 0.5*(b - a)/double(n);
        double x[n+1];
        x[0] = a;
        for(j=1; j<n; j++){
            x[j] = x[j-1] + h;
        }
        
        area[i+1] = f(x[0]) + f(x[n-1]);
        for(j = 1; j < n - 1; j++){
            area[i+1] += 2 * f(x[j]);
        }
        area[i+1] *= h;
        
        ER[i+1] = abs(area[i+1] - area[i])/abs(area[i+1]);
        
        i++;
    }
    
    cout << "k\t\tA[k]\t\tER[k]" << endl;
    for(j = 0; j<i; j++){
        cout << j << "\t\t" << area[j] << "\t\t" << ER[j] << endl;
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





