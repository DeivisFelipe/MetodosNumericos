#include <iostream>
#include <cmath>
#include <math.h>
#include <iomanip>

using namespace std;

double fat(int x);
double binomial(int x, int y);
double f(double x);

int main()
{
    int i, j, k, m, N=10;
    double c[N][N+1], a[N], alpha[N], EA[N], ER[N];
    double z1, z2;
    
    
    for(i = 0; i < N; i++){
        
        // Determinação dos polinômions de Legendre
        // Fator 2^i
        z1 = 1.0;
        for(j = 0; j<i; j++){
            z1 = z1*2.0;
        }
        // Coeficientes
        z2 = -1.0;
        k = int(0.5*i);
        for(j = 0; j <= k; j++){
            z2 = -1.0 * z2;
            c[i][i-2*j] = z2*binomial(i, j)*binomial(2*(i-j), i)/z1;
        }
        
        // Integração numérica Gauss 2 pontos | Determinação de a[i]
        
        // Variaveis para a Integração
        int NMax = 30, n;
        double A[NMax], ER[NMax], epsilon=0.000001;
        double x1, x2, y1, y2, py1, py2, h;
        double b[N+1];
        
        y1 = -sqrt(3.0)/3.0;
        y2 = -1.0 * y1;
        
        b[i] = c[i][i];
        for(j = i-1; j >= 0 ; j--){
            b[j] = c[i][j] + b[j+1] * y1;
        }
        py1 = b[0];
        
        b[i] = c[i][i];
        for(j = i-1; j >= 0 ; j--){
            b[j] = c[i][j] + b[j+1] * y2;
        }
        py2 = b[0];
        
        A[0] = f(y1)*py1 + f(y2)*py2;
        ER[0] = 1.0;
        n = 1;
        j = 0;
        while(j < NMax && ER[j] > epsilon){
            j++;
            n=2*n;
            h = 2.0/double(n);
            A[j] = 0.0;
            for(k = 0; k < n; k++){
                x1 = -1.0 + double(k)*h;
                x2 = x1 + h;
                y1 = 0.5*(x1 + x2 - sqrt(3)/3.0*(x2-x1));
                y2 = 0.5*(x1 + x2 + sqrt(3)/3.0*(x2-x1));
                
                b[i] = c[i][i];
                for(m = i-1; m >= 0 ; m--){
                    b[m] = c[i][m] + b[m+1] * y1;
                }
                py1 = b[0];
                
                b[i] = c[i][i];
                for(m = i-1; m >= 0 ; m--){
                    b[m] = c[i][m] + b[m+1] * y2;
                }
                py2 = b[0];
                
                A[j] = A[j] + f(y1)*py1 + f(y2)*py2;
            }
            A[j] = 0.5*h*A[j];
            ER[j] = abs(A[j]-A[j-1])/abs(A[j]);
        }
        
        // Determinação do coeficiente ai
        alpha[i] = 2.0/(1.0 + 2.0*double(i));
        a[i] = A[j]/alpha[i];   
        EA[i] = 2.0*a[i]*a[i]/(2.0*double(i) + 1.0);
        ER[i] = 0;
        for(int k = 0; k <= i; k++){
            ER[i] = ER[i] + EA[k];
        }
        ER[i] = EA[i]/ER[i];
        
        cout << "a[" << i << "] = " << a[i] << endl;
        
    }
    
    for (i=0; i<N; i++) {
        cout << "p" << i << "(x) = ";
        for(int o= i; o>=0 ; o--){
            if(a[o] < 0){
                cout << setprecision(10) << a[o];
            }else{
                cout << setprecision(10) << "+" << a[o];
            }
            if(o != 0){
                cout << "*P" << o << "(x)";
            }
        }
        cout << endl;
    }
}

// f (x) = cos {𝜋 [c1x + c2 cos (𝜋x)]}.
/*
double f(double x){
    double y = 0.0, pi = 3.14159265359, z1, z2;
    double c1 = -0.2586;
    double c2 = 1.054;
    z1 = c1 * x + c2 * cos(pi * x);
    y = cos(pi * z1);
    return y;
}
*/
double f(double x){
    double y = 0.0, pi = 3.14159265359, z1, z2;
    z1 = pi*x;
    z2 = z1*(z1 + cos(z1));
    y = sin(z2);
    return y;
}

double fat(int x){
    int y = 1, z = x;
    while(z > 1){
        y = y * z;
        z--;
    }
    return double(y);
}

double binomial(int x, int y){
    double z;
    z = fat(x)/(fat(y) * fat(x-y));
    return z;
}

