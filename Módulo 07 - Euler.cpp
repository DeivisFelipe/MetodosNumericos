#include <iostream>
#include <cmath>
#include <math.h>
#include <iomanip>

using namespace std;

double f(double y, double t){
    double z, pi = 3.14159265359;
    z = 2.0*y*(1.898 - y) + sin(6.908*pi*t);
    return z;
}

int main()
{
    int N = pow(2, 1), i, j, k;
    double y[N+1], t[N+1], h, a, b;
    
    a = 0.0;
    b = 2;
    h = (b-a)/double(N);
    
    for(i = 0; i <= N; i++){
        t[i] = a + i*h;
    }
    
    y[0] = 2.439;
    
    for(i = 0; i<N; i++){
        y[i+1] = y[i] + h * f(y[i], t[i]);
    }
    
    cout << "k;t;y;" << endl;
    for( i = 0; i<=N; i++){
        cout << setprecision(10) << y[i] << endl;
    }

    return 0;
}

