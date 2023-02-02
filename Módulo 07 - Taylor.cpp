#include <iostream>
#include <cmath>
#include <math.h>
#include <iomanip>

using namespace std;

double a = 1.198;
double b = 5.399;
double x0 = 1.788;

double f(double y, double t){
    double z, pi = 3.14159265359;
    z = 2.0*y*(a - y) + sin(b*pi*t);
    return z;
}

int main()
{
    int N = 2, i, j, k;
    double y[N+1], t[N+1], h, a, b, pi = 3.14159265359;
    
    a = 0.0;
    b = 2.0;
    h = (b-a)/double(N);
    
    for(i = 0; i <= N; i++){
        t[i] = a + i*h;
    }
    
    y[0] = x0;
    
    for(i = 0; i<N; i++){
        //y[i+1] = y[i] + h * f(y[i], t[i]) + 0.5*h*h* (f(y[i], t[i])*(2.0*(a - 2.0*y[i]))+(b*pi*cos(b*pi*t[i])));
        y[i+1] = y[i+1] = y[i] + h * f(y[i], t[i]) + 0.5 * h * h * (((2.0 * (-2.0 * y[i] + a)) * f(y[i], t[i])) + (b * pi * cos(b * pi * t[i])));;
    }
    
    cout << "k\t\tt\t\ty\t\t" << endl;
    for( i = 0; i<=N; i++){
        cout << i << "\t\t" << t[i] << "\t\t" << y[i] << endl;
    }

    return 0;
}

