#include <stdio.h>
#include <stdlib.h>

int main() {

    int n, i;
    int *vetor;
    float media = 0;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    vetor = (int *) malloc(n * sizeof(int));

    if (vetor == NULL) {
        printf("Erro ao alocar memoria\n");
        return 1;
    }

    
    for (i = 0; i < n; i++) {
        printf("Digite um valor: ");
        scanf("%d", &vetor[i]);
    }

    
    for (i = 0; i < n; i++) {
        media = media + vetor[i];
    }

    media = media / n;

    printf("Media: %.2f\n", media);

    free(vetor);

    return 0;
}