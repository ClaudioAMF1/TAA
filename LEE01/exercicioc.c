#include <stdio.h>

int main () {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        int V;
        scanf("%d", &V);

        int eh_primo = 1;
        if (V < 2) eh_primo = 0;
        for (int j = 2; j * j <= V; j++) {
            if (V % j == 0) {
                eh_primo = 0;
                break;
            }
        }

        if (eh_primo) {
            printf("o numero %d eh primo\n", V);
        } else {
            printf("o numero %d nao eh primo\n", V);
        }
    }

    return 0;
}