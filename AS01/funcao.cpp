#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    double A, B, C;
    cin >> A >> B >> C;

    double esquerda = 0.0, direita = 1e9, meio;
    double EPS = 1e-9;

    while (direita - esquerda > EPS) {
        meio = (esquerda + direita) / 2.0;
        double valor = A * meio + B * cos(meio);

        if (valor < C) {
            esquerda = meio;
        } else {
            direita = meio;
        }
    }

    cout << fixed << setprecision(4) << meio << endl;

    return 0;
}
