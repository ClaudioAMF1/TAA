#include <iostream>
using namespace std;

unsigned int inverterBits(unsigned int numero) {
    unsigned int invertido = 0;
    int posicoes = 32;
    
    while (posicoes--) {
        invertido <<= 1;
        invertido |= (numero & 1);
        numero >>= 1;
    }
    
    return invertido;
}

int main() {
    unsigned int N;
    cin >> N;
    
    unsigned int resultado = inverterBits(N);
    cout << resultado << endl;
    
    return 0;
}
