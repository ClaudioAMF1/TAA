#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int numLinhas, numColunas, consultas;
    scanf("%d %d %d", &numLinhas, &numColunas, &consultas);

    vector<int> matriz(numLinhas * numColunas);
    for (int i = 0; i < numLinhas * numColunas; ++i) {
        scanf("%d", &matriz[i]);
    }

    while (consultas--) {
        int valorBuscado;
        scanf("%d", &valorBuscado);

        auto posicao = lower_bound(matriz.begin(), matriz.end(), valorBuscado);

        if (posicao != matriz.end() && *posicao == valorBuscado) {
            int indice = posicao - matriz.begin();
            int linha = indice / numColunas;
            int coluna = indice % numColunas;
            printf("%d %d\n", linha, coluna);
        } else {
            printf("-1 -1\n");
        }
    }

    return 0;
}
