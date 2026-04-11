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

// Função de comparação
int compararPilhas(Pilha* p1, Pilha* p2) {
    Pilha aux1, aux2;
    inicializar(&aux1);
    inicializar(&aux2);

    int iguais = 1;

    while (!estaVazia(p1) && !estaVazia(p2)) {
        int v1 = pop(p1);
        int v2 = pop(p2);

        if (v1 != v2) {
            iguais = 0;
        }

        push(&aux1, v1);
        push(&aux2, v2);
    }

    // Se tamanhos diferentes
    if (!estaVazia(p1) || !estaVazia(p2)) {
        iguais = 0;
    }

    // Restaurar pilhas originais
    while (!estaVazia(&aux1)) {
        push(p1, pop(&aux1));
    }

    while (!estaVazia(&aux2)) {
        push(p2, pop(&aux2));
    }

    return iguais;
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
    Pilha p1, p2;
    inicializar(&p1);
    inicializar(&p2);

    // Teste (iguais)
    push(&p1, 10);
    push(&p1, 20);
    push(&p1, 30);

    push(&p2, 10);
    push(&p2, 20);
    push(&p2, 30);

    exibir(&p1);
    exibir(&p2);

    int resultado = compararPilhas(&p1, &p2);

    if (resultado)
        printf("Pilhas IGUAIS\n");
    else
        printf("Pilhas DIFERENTES\n");

    // Conferir se restaurou
    printf("\n--- Depois da comparacao ---\n");
    exibir(&p1);
    exibir(&p2);

    return 0;
}