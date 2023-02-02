#include <iostream>
#include <cmath>
#include <math.h>
#include <iomanip>

using namespace std;

double A = 1.898;
double B = 6.908;
double x0 = 2.439;

double f(double y, double t){
    double z, pi = 3.14159265359;
    z = 2.0*y*(A - y) + sin(B*pi*t);
    return z;
}

int main()
{
    int N = pow(2,6), i, j, k;
    double y[N+1], t[N+1], h, a, b, pi = 3.14159265359;
    
    a = 0.0;
    b = 2.0;
    h = (b-a)/double(N);
    
    for(i = 0; i <= N; i++){
        t[i] = a + i*h;
    }
    
    y[0] = x0;
    
    for(i = 0; i<N; i++){
        y[i+1] = y[i] + h * f(y[i], t[i]) + 0.5 * h * h * (((2.0 * (-2.0 * y[i] + A)) * f(y[i], t[i])) + (B * pi * cos(B * pi * t[i])));
    }
    
    cout << "k\t\tt\t\ty\t\t" << endl;
    for( i = 0; i<=N; i++){
        cout << setprecision(10) << t[i] << ";" << y[i] << endl;
    }

    return 0;
}

