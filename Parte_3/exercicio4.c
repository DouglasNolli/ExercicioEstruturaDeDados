#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char **cidades;
    int n, i;
    char temp[100];

    printf("Quantas cidades: ");
    scanf("%d", &n);

    cidades = (char **) malloc(n * sizeof(char *));

    if (cidades == NULL) {
        printf("Erro ao alocar memoria\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("Digite a cidade: ");
        scanf("%s", temp);

        cidades[i] = (char *) malloc((strlen(temp) + 1) * sizeof(char));

        if (cidades[i] == NULL) {
            printf("Erro ao alocar memoria\n");
            return 1;
        }

        strcpy(cidades[i], temp);
    }

    printf("\nCidades:\n");
    for (i = 0; i < n; i++) {
        printf("%s\n", cidades[i]);
    }

    for (i = 0; i < n; i++) {
        free(cidades[i]);
    }
    free(cidades);

    return 0;
}