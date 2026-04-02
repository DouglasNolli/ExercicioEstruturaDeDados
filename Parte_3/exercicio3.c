#include <stdio.h>
#include <stdlib.h>

void liberar_matriz(int **matriz, int m) {
    int i;

    for (i = 0; i < m; i++) {
        free(matriz[i]);
    }

    free(matriz);
}

int main() {

    int **matriz;
    int m = 2, n = 2;
    int i;

    matriz = (int **) malloc(m * sizeof(int *));

    for (i = 0; i < m; i++) {
        matriz[i] = (int *) malloc(n * sizeof(int));
    }

    liberar_matriz(matriz, m);

    return 0;
}