#include <iostream>
#include <vector>
using namespace std;

int desativarBit(int valor, int posicao) {
    unsigned int mascara = ~(1 << posicao);
    return valor & mascara;
}

int main() {
    int N, B;
    cin >> N >> B;
    
    vector<int> resultados;
    for (int i = 0; i < N; ++i) {
        int V;
        cin >> V;
        resultados.push_back(desativarBit(V, B));
    }

    for (int resultado : resultados) {
        cout << resultado << endl;
    }

    return 0;
}
