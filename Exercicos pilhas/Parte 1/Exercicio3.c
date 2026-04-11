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

// PUSH (empilhar)
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

// CLEAR (limpar pilha e contar memória)
void limpar_pilha(Pilha* p) {
    No* atual = p->topo;
    No* temp;
    int contador = 0;

    while (atual != NULL) {
        temp = atual;
        atual = atual->prox;
        free(temp);
        contador++;
    }

    p->topo = NULL;

    int memoria = contador * sizeof(No);

    printf("Memoria liberada: %d bytes\n", memoria);
}

// MAIN (teste)
int main() {
    Pilha p;
    inicializar(&p);

    // Inserindo valores
    push(&p, 10);
    push(&p, 20);
    push(&p, 30);

    exibir(&p);

    printf("\n--- Limpando pilha ---\n");
    limpar_pilha(&p);

    printf("\n--- Verificando se esta vazia ---\n");
    exibir(&p);

    return 0;
}