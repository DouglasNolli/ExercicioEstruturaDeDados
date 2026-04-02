#include <stdio.h>
#include <stdlib.h>

struct Produto {
    int id;
    float preco;
};

struct Produto* clonar(struct Produto *origem) {

    struct Produto *novo;

    novo = (struct Produto *) malloc(sizeof(struct Produto));

    if (novo == NULL) {
        return NULL;
    }

    novo->id = origem->id;
    novo->preco = origem->preco;

    return novo;
}

int main() {

    struct Produto p1;
    struct Produto *p2;

    p1.id = 1;
    p1.preco = 50.0;

    p2 = clonar(&p1);

    if (p2 != NULL) {
        printf("ID: %d\n", p2->id);
        printf("Preco: %.2f\n", p2->preco);
    }

    free(p2);

    return 0;
}