#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura do nó
typedef struct No {
    char url[100];
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

// PUSH (nova URL visitada)
void push(Pilha* p, char url[]) {
    No* novo = (No*) malloc(sizeof(No));

    if (novo == NULL) {
        printf("Erro: Falha de alocacao de memoria\n");
        return;
    }

    strcpy(novo->url, url);
    novo->prox = p->topo;
    p->topo = novo;
}

// PEEK (ver página atual sem remover)
void peek(Pilha* p) {
    if (estaVazia(p)) {
        printf("Erro: Historico vazio\n");
        return;
    }

    printf("Pagina atual: %s\n", p->topo->url);
}

// Exibir histórico (debug)
void exibir(Pilha* p) {
    No* atual = p->topo;

    printf("\nHistorico de navegacao:\n");
    while (atual != NULL) {
        printf("- %s\n", atual->url);
        atual = atual->prox;
    }
}

// MAIN (teste simples)
int main() {
    Pilha p;
    inicializar(&p);

    // Simulando navegação
    push(&p, "google.com");
    push(&p, "youtube.com");
    push(&p, "github.com");

    exibir(&p);

    printf("\n--- Peek ---\n");
    peek(&p); // deve mostrar github

    printf("\n--- Verificando se nao removeu ---\n");
    exibir(&p); // pilha continua igual

    return 0;
}