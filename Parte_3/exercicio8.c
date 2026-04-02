#include <stdio.h>

int main() {

    int n = 3;
    int matriz[3][3];
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            matriz[i][j] = i + j;
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}