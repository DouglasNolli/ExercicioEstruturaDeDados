#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura do nó
typedef struct No {
    char texto[100];
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

// Verificar se está vazia
int estaVazia(Pilha* p) {
    return p->topo == NULL;
}

// PUSH (registrar ação)
void push(Pilha* p, char texto[]) {
    No* novo = (No*) malloc(sizeof(No));

    if (novo == NULL) {
        printf("Erro: Falha de alocacao de memoria\n");
        return;
    }

    strcpy(novo->texto, texto);
    novo->prox = p->topo;
    p->topo = novo;
}

// POP (desfazer ação)
void pop(Pilha* p) {
    if (estaVazia(p)) {
        printf("Erro: Nao ha acoes para desfazer\n");
        return;
    }

    No* temp = p->topo;
    printf("Desfazendo: %s\n", temp->texto);

    p->topo = temp->prox;
    free(temp);
}

// Exibir histórico (ajuda no debug)
void exibir(Pilha* p) {
    No* atual = p->topo;

    printf("\nHistorico de acoes:\n");
    while (atual != NULL) {
        printf("- %s\n", atual->texto);
        atual = atual->prox;
    }
}

// MAIN (teste simples e depurável)
int main() {
    Pilha p;
    inicializar(&p);

    // Simulando ações
    push(&p, "Digitou Ola");
    push(&p, "Digitou Mundo");
    push(&p, "Apagou Mundo");

    exibir(&p);

    printf("\n--- Desfazendo ---\n");
    pop(&p);
    pop(&p);
    pop(&p);
    pop(&p); // erro esperado

    return 0;
}