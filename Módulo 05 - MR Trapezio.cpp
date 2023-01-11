#include <iostream> 
#include <cmath>    
#include <iomanip>  
#include <math.h>  

using namespace std;

#define NMAX 20

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

int main() {

    int i, j, k, n;
    double a, b, h, A[NMAX], ER[NMAX], epsilon = 0.000001;
    
    a=0.0;
    b=1.0;
    h=b-a;
    
    A[0] = 0.5*h*(f(a) + f(b));
    ER[0] = 1.0;
    
    i=0;
    n=1;
    
    while (i < NMAX && ER[i] > epsilon) {
        i++;
        n = 2*n;
        h = (b-a)/double(n);
        
        double x[n+1];
        
        x[0] = a;
        for (j = 1; j <= n; j++) {
            x[j] = x[j-1] + h;    
        }

        A[i] = f(x[0]) + f(x[n]);
        for(j = 1; j < n; j++) {
            A[i] = A[i] + 2.0 * f(x[j]);
        }
        A[i] = A[i] * 0.5 * h;
        ER[i] = abs(A[i] - A[i-1]) / abs(A[i]);
    }

    //falha

    cout << "k" << ";" << "A[k]"<< ";" << "ER[k]" << endl;

    for (j = 0; j < i; j++) {
        cout << setprecision(10) << j << ";" << A[j] << ";" << ER[j] << endl;
    }
}