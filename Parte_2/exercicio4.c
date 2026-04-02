#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Usuario {
    char *nome;
};

int main() {

    struct Usuario *u;
    char temp[100];

    u = (struct Usuario *) malloc(sizeof(struct Usuario));

    if (u == NULL) {
        printf("Erro ao alocar usuario\n");
        return 1;
    }

    printf("Digite o nome: ");
    scanf("%s", temp);

    u->nome = (char *) malloc((strlen(temp) + 1) * sizeof(char));

    if (u->nome == NULL) {
        printf("Erro ao alocar nome\n");
        return 1;
    }

    strcpy(u->nome, temp);

    printf("Nome: %s\n", u->nome);

    free(u->nome);
    free(u);

    return 0;
}