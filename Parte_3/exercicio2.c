#include <stdio.h>
#include <stdlib.h>

int main() {

    int **matriz;
    int m, n;
    int i, j;

    printf("Digite o numero de linhas: ");
    scanf("%d", &m);

    printf("Digite o numero de colunas: ");
    scanf("%d", &n);

    matriz = (int **) malloc(m * sizeof(int *));

    if (matriz == NULL) {
        printf("Erro ao alocar memoria\n");
        return 1;
    }

    for (i = 0; i < m; i++) {
        matriz[i] = (int *) malloc(n * sizeof(int));

        if (matriz[i] == NULL) {
            printf("Erro ao alocar memoria\n");
            return 1;
        }
    }

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("Digite um valor: ");
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("\nMatriz:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < m; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}