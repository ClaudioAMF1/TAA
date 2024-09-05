#include <stdio.h>

int main() {
    int N;

    while (1) {
        scanf("%d", &N);
        if (N == -1) break;

        int resultado = 0;

        for (int i = 0; i < N; i++) {
            int V;
            scanf("%d", &V);
            resultado ^= V;
        }

        printf("%d\n", resultado);
    }

    return 0;
}
