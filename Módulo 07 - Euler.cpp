#include <iostream>
#include <cmath>
#include <math.h>
#include <iomanip>

using namespace std;

double f(double y, double t){
    double z, pi = 3.14159265359;
    z = y*(y-1.0)*(y-2.0) + sin(pi*t);
    return z;
}

int main()
{
    int N = 20, i, j, k;
    double y[N+1], t[N+1], h, a, b;
    
    a = 0.0;
    b = 10.0;
    h = (b-a)/double(N);
    
    for(i = 0; i <= N; i++){
        t[i] = a + i*h;
    }
    
    y[0] = 0.5;
    
    for(i = 0; i<N; i++){
        y[i+1] = y[i] + h * f(y[i], t[i]);
    }
    
    cout << "k\t\tt\t\ty\t\t" << endl;
    for( i = 0; i<=N; i++){
        cout << i << "\t\t" << t[i] << "\t\t" << y[i] << endl;
    }

    return 0;
}

