#include <stdio.h>

int calcular_hamming(unsigned long long x, unsigned long long y) {
    unsigned long long resultado = x ^ y;
    int contagem = 0;

    while (resultado != 0) {
        if (resultado % 2 == 1) {
            contagem++;
        }
        resultado /= 2;
    }

    return contagem;
}

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        unsigned long long X, Y;
        scanf("%llu %llu", &X, &Y);

        int hamming = calcular_hamming(X, Y);
        printf("%d\n", hamming);
    }

    return 0;
}
