#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura do nó (char)
typedef struct No {
    char letra;
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

// PUSH (empilhar caractere)
void push(Pilha* p, char c) {
    No* novo = (No*) malloc(sizeof(No));

    if (novo == NULL) {
        printf("Erro de memoria\n");
        return;
    }

    novo->letra = c;
    novo->prox = p->topo;
    p->topo = novo;
}

// POP (desempilhar caractere)
char pop(Pilha* p) {
    if (estaVazia(p)) {
        return '\0';
    }

    No* temp = p->topo;
    char c = temp->letra;

    p->topo = temp->prox;
    free(temp);

    return c;
}

// Função para inverter string
void inverterString(char str[]) {
    Pilha p;
    inicializar(&p);

    int i = 0;

    // Empilha todos os caracteres
    while (str[i] != '\0') {
        push(&p, str[i]);
        i++;
    }

    i = 0;

    // Desempilha (invertendo)
    while (!estaVazia(&p)) {
        str[i] = pop(&p);
        i++;
    }
}

// MAIN (teste)
int main() {
    char texto[100];

    printf("Digite uma palavra: ");
    fgets(texto, 100, stdin);

    // Remove \n do fgets
    texto[strcspn(texto, "\n")] = '\0';

    inverterString(texto);

    printf("Texto invertido: %s\n", texto);

    return 0;
}