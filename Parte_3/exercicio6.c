#include <stdio.h>
#include <stdlib.h>

struct Produto {
    int id;
    float preco;
};

struct Produto* buscar(struct Produto *vetor, int tamanho, int id) {
    int i;

    for (i = 0; i < tamanho; i++) {
        if (vetor[i].id == id) {
            return &vetor[i]; 
        }
    }

    return NULL; 
}

int main() {

    struct Produto *vetor;
    struct Produto *resultado;
    int i, id_busca;

    vetor = (struct Produto *) malloc(10 * sizeof(struct Produto));

    for (i = 0; i < 10; i++) {
        vetor[i].id = i + 1;
        vetor[i].preco = (i + 1) * 10;
    }

    printf("Digite o ID para buscar: ");
    scanf("%d", &id_busca);

    resultado = buscar(vetor, 10, id_busca);

    if (resultado != NULL) {
        printf("Produto encontrado!\n");
        printf("ID: %d\n", resultado->id);
        printf("Preco: %.2f\n", resultado->preco);
    } else {
        printf("Produto nao encontrado\n");
    }

    free(vetor);

    return 0;
}