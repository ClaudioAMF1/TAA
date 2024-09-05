#include <stdio.h>
#include <string.h>

int main() {
    int D;
    
    while (1) {
        scanf("%d", &D);
        if (D == -1) break;

        char numero[D + 1];
        scanf("%s", numero);

        int soma = 0;
        for (int i = 0; i < D; i++) {
            soma += numero[i] - '0';
        }

        printf("%d ", soma);
        if (soma % 3 == 0) {
            printf("sim\n");
        } else {
            printf("nao\n");
        }
    }

    return 0;
}