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

// Conversão decimal → binário
void converterBinario(int numero) {
    Pilha p;
    inicializar(&p);

    if (numero == 0) {
        printf("Binario: 0\n");
        return;
    }

    // Empilha restos
    while (numero > 0) {
        push(&p, numero % 2);
        numero = numero / 2;
    }

    // Desempilha (forma o binário)
    printf("Binario: ");
    while (!estaVazia(&p)) {
        printf("%d", pop(&p));
    }
    printf("\n");
}

// MAIN (teste)
int main() {
    int numero;

    printf("Digite um numero decimal: ");
    scanf("%d", &numero);

    converterBinario(numero);

    return 0;
}