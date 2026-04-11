#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura do chamado
typedef struct No {
    int id;
    int urgencia;
    char tecnico[50];
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
void push(Pilha* p, int id, int urgencia, char tecnico[]) {
    No* novo = (No*) malloc(sizeof(No));

    if (novo == NULL) {
        printf("Erro de memoria\n");
        return;
    }

    novo->id = id;
    novo->urgencia = urgencia;
    strcpy(novo->tecnico, tecnico);

    novo->prox = p->topo;
    p->topo = novo;
}

// POP
No pop(Pilha* p) {
    No vazio = {-1, -1, "", NULL};

    if (estaVazia(p)) {
        return vazio;
    }

    No* temp = p->topo;
    No valor = *temp;

    p->topo = temp->prox;
    free(temp);

    return valor;
}

// Função de filtro
void filtrarUrgenciaMaxima(Pilha* original, Pilha* prioridade) {
    Pilha aux;
    inicializar(&aux);

    // Passo 1: separa
    while (!estaVazia(original)) {
        No chamado = pop(original);

        if (chamado.urgencia == 5) {
            push(prioridade, chamado.id, chamado.urgencia, chamado.tecnico);
        } else {
            push(&aux, chamado.id, chamado.urgencia, chamado.tecnico);
        }
    }

    // Passo 2: restaura ordem da original
    while (!estaVazia(&aux)) {
        No chamado = pop(&aux);
        push(original, chamado.id, chamado.urgencia, chamado.tecnico);
    }
}

// Exibir (debug)
void exibir(Pilha* p) {
    No* atual = p->topo;

    printf("\nPilha:\n");
    while (atual != NULL) {
        printf("ID: %d | Urgencia: %d | Tecnico: %s\n",
               atual->id, atual->urgencia, atual->tecnico);
        atual = atual->prox;
    }
}

// MAIN (teste)
int main() {
    Pilha chamados, prioridade;
    inicializar(&chamados);
    inicializar(&prioridade);

    // Inserindo chamados
    push(&chamados, 1, 3, "Joao");
    push(&chamados, 2, 5, "Maria");
    push(&chamados, 3, 2, "Carlos");
    push(&chamados, 4, 5, "Ana");

    printf("Original:\n");
    exibir(&chamados);

    filtrarUrgenciaMaxima(&chamados, &prioridade);

    printf("\n--- Apos filtro ---\n");

    printf("\nChamados restantes:\n");
    exibir(&chamados);

    printf("\nPrioridade maxima:\n");
    exibir(&prioridade);

    return 0;
}