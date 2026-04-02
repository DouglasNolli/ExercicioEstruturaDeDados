#include <stdio.h>
#include <stdlib.h>

struct Aluno {
    char nome[50];
    float nota;
};

int main() {

    struct Aluno *alunos;

    alunos = (struct Aluno *) malloc(3 * sizeof(struct Aluno));

    if (alunos == NULL) {
        printf("Erro ao alocar memoria\n");
        return 1;
    }

    for (int i = 0; i < 3; i++) {
        printf("Digite o nome: ");
        scanf("%s", alunos[i].nome);

        printf("Digite a nota: ");
        scanf("%f", &alunos[i].nota);
    }

    for (int i = 0; i < 3; i++) {
        printf("Aluno: %s\n", alunos[i].nome);
        printf("Nota: %.2f\n", alunos[i].nota);
    }

    free(alunos);

    return 0;
}