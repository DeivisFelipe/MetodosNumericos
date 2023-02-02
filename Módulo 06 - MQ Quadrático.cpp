#include <iostream>
#include <cmath>
#include <math.h>
#include <iomanip>

using namespace std;

int main()
{
    int n = 10, i, j;
    double x[n], y[n];
    double x2[n], x3[n], x4[n], yx[n], yx2[n], sx = 0, sx2 = 0, sx3 = 0, sx4 = 0, sy = 0, syx = 0, syx2 = 0;
    double a0, a1;
    
    x[0] = -3.319;
    x[1] = 0.66;
    x[2] = 7.72;
    x[3] = 9.269;
    x[4] = 14.2;
    x[5] = 22.06;
    x[6] = 24.02;
    x[7] = 32.02;
    x[8] = 34.54;
    x[9] = 40.78;
    
    y[0] = 8.76;
    y[1] = 13.52;
    y[2] = 34.04;
    y[3] = 33.46;
    y[4] = 42.4;
    y[5] = 61.64;
    y[6] = 62.96;
    y[7] = 79.88;
    y[8] = 86.2;
    y[9] = 97.68;
    
    for(i = 0; i<n; i++){
        sx += x[i];
        sy += y[i];
    }
    
    for(i = 0; i<n; i++){
        x2[i] = x[i] * x[i];
        x3[i] = x2[i] * x[i];
        x4[i] = x2[i] * x2[i];
        yx[i] = x[i] * y[i];
        yx2[i] = x2[i] * y[i];
        sx2 += x2[i];
        sx3 += x3[i];
        sx4 += x4[i];
        syx += yx[i];
        syx2 += yx2[i];
    }
    
    a0 = (sx2*sy - syx*sx)/(double (n) * sx2 - sx * sx);
    a1 = (double (n) * syx - sx*sy)/(double (n) * sx2 - sx * sx);
    
    cout << ";x;y;x2;x3;x4;yx;yx2" << endl;
    for(i = 0; i<n; i++){
        cout << ";" << x[i] << ";" << y[i] << ";" << x2[i] << ";" << x3[i] << ";" << x4[i] << ";" << yx[i] << ";" << yx2[i]  << endl;
    }
    
    cout << "------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "Somas;" << sx << ";" << sy << ";" << sx2 << ";" << sx3 << ";" << sx4 << ";" << syx << ";" << syx2 << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------------" << endl;
    
    cout << "a0 = " << a0 << ";a1 = " << a1 << endl;
}
