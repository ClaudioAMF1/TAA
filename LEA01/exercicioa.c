#include <stdio.h>

int McCarthy(int n) {
    if (n > 100) {
        return n - 10;
    } else {
        return 91;
    }
}

int main() {
    int C;
    scanf("%d", &C);

    for (int i = 0; i < C; i++) {
        int N;
        scanf("%d", &N);
        printf("%d\n", McCarthy(N));
    }

    return 0;
}