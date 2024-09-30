#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool verificarDistribuicao(const vector<int>& capitulos, int maxPorSessao, int totalSessao) {
    int usadas = 0;
    for (int capitulo : capitulos) {
        usadas += (capitulo + maxPorSessao - 1) / maxPorSessao;
        if (usadas > totalSessao) {
            return false;
        }
    }
    return usadas <= totalSessao;
}

int calcularMaximoPorSessao(const vector<int>& capitulos, int totalCapitulos, int limiteSessoes) {
    int inicio = 1, fim = *max_element(capitulos.begin(), capitulos.end());
    int resposta = fim;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if (verificarDistribuicao(capitulos, meio, limiteSessoes)) {
            resposta = meio;
            fim = meio - 1;
        } else {
            inicio = meio + 1;
        }
    }

    return resposta;
}

int main() {
    int totalCapitulos, limiteSessoes;
    cin >> totalCapitulos >> limiteSessoes;

    vector<int> capitulos(totalCapitulos);
    for (int i = 0; i < totalCapitulos; ++i) {
        cin >> capitulos[i];
    }

    cout << calcularMaximoPorSessao(capitulos, totalCapitulos, limiteSessoes) << endl;

    return 0;
}
