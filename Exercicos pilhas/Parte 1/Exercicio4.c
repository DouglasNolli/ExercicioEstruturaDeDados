#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó
typedef struct No {
    int valor;
    struct No* prox;
} No;

// Estrutura da pilha
typedef struct {
    No* topo;
} Pilha;

// Inicializar pilha
void inicializar(Pilha* p) {
    p->topo = NULL;
}

// PUSH
void push(Pilha* p, int valor) {
    No* novo = (No*) malloc(sizeof(No));

    if (novo == NULL) {
        printf("Erro: Falha de alocacao de memoria\n");
        return;
    }

    novo->valor = valor;
    novo->prox = p->topo;
    p->topo = novo;
}

// COUNT (não altera a pilha)
int count(Pilha* p) {
    No* atual = p->topo;
    int contador = 0;

    while (atual != NULL) {
        contador++;
        atual = atual->prox;
    }

    return contador;
}

// Exibir (debug)
void exibir(Pilha* p) {
    No* atual = p->topo;

    printf("Pilha: ");
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->prox;
    }
    printf("\n");
}

// MAIN (teste)
int main() {
    Pilha p;
    inicializar(&p);

    // Inserindo valores
    push(&p, 5);
    push(&p, 10);
    push(&p, 15);

    exibir(&p);

    int total = count(&p);
    printf("Total de elementos: %d\n", total);

    // Verifica se a pilha continua intacta
    printf("\n--- Conferindo integridade ---\n");
    exibir(&p);

    return 0;
}