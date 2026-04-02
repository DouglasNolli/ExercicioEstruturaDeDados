#include <stdio.h>
#include <stdlib.h>

struct Endereco {
    char rua[50];
    int numero;
};

struct Pessoa {
    char nome[50];
    struct Endereco *end;
};

int main() {

    struct Pessoa *p;
    struct Endereco *e;

    p = (struct Pessoa *) malloc(sizeof(struct Pessoa));
    e = (struct Endereco *) malloc(sizeof(struct Endereco));

    if (p == NULL || e == NULL) {
        printf("Erro ao alocar memoria\n");
        return 1;
    }

    printf("Digite o nome: ");
    scanf("%s", p->nome);

    printf("Digite a rua: ");
    scanf("%s", e->rua);

    printf("Digite o numero: ");
    scanf("%d", &e->numero);

    p->end = e;

    printf("\nNome: %s\n", p->nome);
    printf("Rua: %s\n", p->end->rua);
    printf("Numero: %d\n", p->end->numero);

    free(e);
    free(p);

    return 0;
}