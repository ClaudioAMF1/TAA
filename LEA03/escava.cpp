#include <iostream>
#include <string>
using namespace std;
 
int main() {
    int n;
    cin >> n;
 
    for (int k = 0; k < n; ++k) {
        string bloco;
        cin >> bloco;
 
        int contador = 0;
        int esquerda = 0;
 
        for (char ch : bloco) {
            if (ch == '<') {
                esquerda++;
            } else if (ch == '>' && esquerda > 0) {
                contador++;
                esquerda--;
            }
        }
 
        cout << contador << endl;
    }
 
    return 0;
}
