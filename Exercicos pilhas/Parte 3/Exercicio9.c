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

// Inicializar
void inicializar(Pilha* p) {
    p->topo = NULL;
}

// Verificar vazia
int estaVazia(Pilha* p) {
    return p->topo == NULL;
}

// PUSH
void push(Pilha* p, int valor) {
    No* novo = (No*) malloc(sizeof(No));

    if (novo == NULL) {
        printf("Erro de memoria\n");
        return;
    }

    novo->valor = valor;
    novo->prox = p->topo;
    p->topo = novo;
}

// POP
int pop(Pilha* p) {
    if (estaVazia(p)) {
        return -1;
    }

    No* temp = p->topo;
    int valor = temp->valor;

    p->topo = temp->prox;
    free(temp);

    return valor;
}

// PEEK
int peek(Pilha* p) {
    if (estaVazia(p)) {
        return -1;
    }
    return p->topo->valor;
}

// Função de ordenação
void ordenarPilha(Pilha* p) {
    Pilha aux;
    inicializar(&aux);

    while (!estaVazia(p)) {
        int temp = pop(p);

        // Move elementos maiores de volta pra pilha original
        while (!estaVazia(&aux) && peek(&aux) > temp) {
            push(p, pop(&aux));
        }

        push(&aux, temp);
    }

    // Volta tudo pra pilha original (já ordenada)
    while (!estaVazia(&aux)) {
        push(p, pop(&aux));
    }
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

    // Inserindo valores (desordenados)
    push(&p, 30);
    push(&p, 10);
    push(&p, 50);
    push(&p, 20);

    printf("Antes:\n");
    exibir(&p);

    ordenarPilha(&p);

    printf("\nDepois (ordenada):\n");
    exibir(&p);

    return 0;
}