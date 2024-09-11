#include <stdio.h>

int main() {
    int N, B;
    scanf("%d %d", &N, &B);

    for (int i = 0; i < N; i++) {
        unsigned int V;
        scanf("%u", &V);

        V |= (1 << B);

        printf("%u\n", V);
    }

    return 0;
}
