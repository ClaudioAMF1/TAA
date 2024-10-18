#include <iostream>
#include <cmath>
#include <iomanip>
 
using namespace std;
 
double resolver(double A, double B, double C) {
    double inicio = 0.0, fim = 1e9;
    double precisao = 1e-9;
    while (fim - inicio > precisao) {
        double x = (inicio + fim) / 2.0;
        double resultado = A * x + B * cos(x);
        if (fabs(resultado - C) < precisao) return x;
        if (resultado < C) inicio = x;
        else fim = x;
    }
    return (inicio + fim) / 2.0;
}
 
int main() {
    double A, B, C;
    cin >> A >> B >> C;
    double x = resolver(A, B, C);
    cout << fixed << setprecision(4) << x << endl;
    return 0;
}
