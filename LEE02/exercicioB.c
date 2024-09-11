#include <stdio.h>

int calcularC(int A, int B, int Y) {
    int AB = A | B;

    if (AB == Y) {
        return 0; 
    }

    int C = Y & ~AB;
    if ((A | B | C) == Y) {
        return C;
    }

    return -1;
}

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        int A, B, Y;
        scanf("%d %d %d", &A, &B, &Y);

        int resultado = calcularC(A, B, Y);
        printf("%d\n", resultado);
    }

    return 0;
}
