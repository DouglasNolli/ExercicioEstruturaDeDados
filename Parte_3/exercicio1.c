#include <stdio.h>
#include <stdlib.h>

int main() {

    int *vetor;
    int i;

    vetor = (int *) malloc(2 * sizeof(int));

    if (vetor == NULL) {
        printf("Erro ao alocar memoria\n");
        return 1;
    }

    for (i = 0; i < 2; i++) {
        printf("Digite um valor: ");
        scanf("%d", &vetor[i]);
    }

    vetor = (int *) realloc(vetor, 4 * sizeof(int));

    if (vetor == NULL) {
        printf("Erro ao realocar memoria\n");
        return 1;
    }

    for (i = 2; i < 4; i++) {
        printf("Digite mais um valor: ");
        scanf("%d", &vetor[i]);
    }

    printf("\nValores:\n");
    for (i = 0; i < 4; i++) {
        printf("%d\n", vetor[i]);
    }

    free(vetor);

    return 0;
}