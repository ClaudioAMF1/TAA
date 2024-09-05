#include <stdio.h>

int main() {
    long long N;
    scanf("%lld", &N);

    while (N != 1) {
        printf("%lld ", N);
        if (N % 2 == 0) {
            N = N / 2;
        } else {
            N = 3 * N + 1;
        }
    }

    printf("1\n");

    return 0;
}