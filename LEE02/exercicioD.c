#include <stdio.h>

unsigned long long trocarBits(unsigned long long N, int P, int Q) {
    int bitP = (N >> P) & 1;
    int bitQ = (N >> Q) & 1;

    if (bitP != bitQ) {
        N ^= (1ULL << P);
        N ^= (1ULL << Q);
    }
    
    return N;
}

int main() {
    int casosTeste;
    scanf("%d", &casosTeste);

    for (int i = 0; i < casosTeste; i++) {
        unsigned long long numero;
        int P, Q;
        scanf("%llu %d %d", &numero, &P, &Q);

        unsigned long long resultado = trocarBits(numero, P, Q);
        printf("%llu\n", resultado);
    }

    return 0;
}
