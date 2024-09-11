#include <stdio.h>

int contaBitsUm(unsigned long long valor) {
    int total = 0;
    while (valor) {
        total += valor & 1;
        valor >>= 1;
    }
    return total;
}

int verificaSePrimo(int numero) {
    if (numero < 2) return 0;
    for (int divisor = 2; divisor * divisor <= numero; divisor++) {
        if (numero % divisor == 0) return 0;
    }
    return 1;
}

int main() {
    int quantidade;
    scanf("%d", &quantidade);

    for (int i = 0; i < quantidade; i++) {
        unsigned long long numAtual;
        scanf("%llu", &numAtual);

        int quantidadeBitsUm = contaBitsUm(numAtual);
        if (verificaSePrimo(quantidadeBitsUm)) {
            printf("%llu eh um pribit\n", numAtual);
        } else {
            printf("%llu nao eh um pribit\n", numAtual);
        }
    }

    return 0;
}