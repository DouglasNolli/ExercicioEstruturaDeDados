#include <stdio.h>

struct Produto {
    int id;
    float preco;
};

void reset_estoque(struct Produto *p) {
    p->id = 0;
    p->preco = 0.0;
}

int main() {

    struct Produto prod;

    prod.id = 10;
    prod.preco = 50.5;

    reset_estoque(&prod);

    printf("ID: %d\n", prod.id);
    printf("Preco: %.2f\n", prod.preco);

    return 0;
}