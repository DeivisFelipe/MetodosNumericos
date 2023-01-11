#include <iostream> 
#include <cmath>    
#include <iomanip>  
#include <math.h> 

#define NMAX 20

using namespace std;

//f(x)=ℯ^(-x) sen(2 π (1.7 x-0.91 x x+2 g(x)))
//g(x)=cos(2 π (1.4 x-1 x x))
// 0.2555033659831

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
    int i, j , k, n;
    double a, b, h, A[NMAX], ER[NMAX], epsilon = 0.000001;
    double xl, xc, xr;

    a=0.0;
    b=1.0;
    h=(b-a);

    A[0] = h/3.0*(f(a) + f(0.5*(a+b)) + f(b));
    ER[0] = 1.0;
    
    i=0;
    n=1;

    while(ER[i] > epsilon && i < NMAX) {
        i++;
        n = 2*n;
        h = (b-a)/double(n);

        A[i] = 0.0;
        for (j=0; j<n; j++) {
            xl = a + j*h;
            xr = xl + h;
            xc = 0.5*(xl + xr);
            A[i] = A[i] + f(xl) + 4 * f(xc) + f(xr);
        }
        A[i] = 0.5 * A[i] * h / 3.0;
        ER[i] = abs(A[i] - A[i-1]) / abs(A[i]);
    }

    // IMPRESSÃO NA TELA

    cout << "k\t\tA(k)\t\tER(k)" << endl;

    for (j = 0; j <= i; j++) {
        cout << j << ";" << setprecision(10) << A[j] << ";" << setprecision(10) << ER[j] << endl;
    }
}
