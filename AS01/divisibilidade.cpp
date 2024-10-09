#include <iostream>
#include <string>
#include <cmath>
 
using namespace std;
 
int main () {
    while(true) {
        int D;
        cin >> D;
 
        if (D == -1) break;
 
        string N;
        cin >> N;
 
        int somaPares = 0, somaImpares = 0;
 
        for (int i = 0; i < D; i++) {
            int digito = N[i] - '0';
            if (i % 2 == 0) {
                somaPares += digito;
            } else {
                somaImpares += digito;
            }
        }
 
        int S = somaPares - somaImpares;
 
        cout << N << ": " << somaPares << " - " << somaImpares << " = " << S << " - ";
 
        if (abs(S) % 11 == 0) {
            cout << "sim" << endl;
        } else {
            cout << "nao" << endl;
        }
    }
    return 0;
}
