#include <iostream>
#include <cmath>
#include <math.h>
#include <iomanip>

using namespace std;

#define NUM 10

int main()
{
    int n = 10, i, j;
    double x[NUM], y[NUM];
    double x2[NUM], yx[NUM], sx = 0, sx2 = 0, sy = 0, syx = 0;
    double a0, a1;
    
    x[0] = 1.0;
    x[1] = 2.0;
    x[2] = 3.0;
    x[3] = 4.0;
    x[4] = 5.0;
    x[5] = 6.0;
    x[6] = 7.0;
    x[7] = 8.0;
    x[8] = 9.0;
    x[9] = 10.0;
    
    y[0] = 3.54;
    y[1] = 5.72;
    y[2] = 6.35;
    y[3] = 8.6;
    y[4] = 10.82;
    y[5] = 12.34;
    y[6] = 15.37;
    y[7] = 17.28;
    y[8] = 18.37;
    y[9] = 21.42;
    
    for(i = 0; i<n; i++){
        sx += x[i];
        sy += y[i];
    }
    
    for(i = 0; i<n; i++){
        x2[i] = x[i] * x[i];
        yx[i] = x[i] * y[i];
        sx2 += x2[i];
        syx += yx[i];
    }
    
    a0 = (sx2*sy - syx*sx)/(double (n) * sx2 - sx * sx);
    a1 = (double (n) * syx - sx*sy)/(double (n) * sx2 - sx * sx);
    
    cout << "\t\tx\t\ty\t\tx2\t\tyx" << endl;
    for(i = 0; i<n; i++){
        cout << "\t\t" << x[i] << "\t\t" << y[i] << "\t\t" << x2[i] << "\t\t" << yx[i] << endl;
    }
    
    cout << "-------------------------------------------------------------------------" << endl;
    cout << "Somas\t\t" << sx << "\t\t" << sy << "\t\t" << sx2 << "\t\t" << syx << endl;
    cout << "-------------------------------------------------------------------------" << endl;
    
    cout << "a0 = " << a0 << "\t\ta1 = " << a1 << endl;
}
