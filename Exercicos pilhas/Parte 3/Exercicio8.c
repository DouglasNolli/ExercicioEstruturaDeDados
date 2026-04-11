#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura do nó
typedef struct No {
    char simbolo;
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
void push(Pilha* p, char c) {
    No* novo = (No*) malloc(sizeof(No));

    if (novo == NULL) {
        printf("Erro de memoria\n");
        return;
    }

    novo->simbolo = c;
    novo->prox = p->topo;
    p->topo = novo;
}

// POP
char pop(Pilha* p) {
    if (estaVazia(p)) {
        return '\0';
    }

    No* temp = p->topo;
    char c = temp->simbolo;

    p->topo = temp->prox;
    free(temp);

    return c;
}

// Verifica se é par correspondente
int ehPar(char abre, char fecha) {
    if (abre == '(' && fecha == ')') return 1;
    if (abre == '[' && fecha == ']') return 1;
    if (abre == '{' && fecha == '}') return 1;
    return 0;
}

// Validador
int validarExpressao(char expr[]) {
    Pilha p;
    inicializar(&p);

    for (int i = 0; expr[i] != '\0'; i++) {
        char c = expr[i];

        // Se for abertura
        if (c == '(' || c == '[' || c == '{') {
            push(&p, c);
        }
        // Se for fechamento
        else if (c == ')' || c == ']' || c == '}') {
            if (estaVazia(&p)) {
                return 0; // erro
            }

            char topo = pop(&p);

            if (!ehPar(topo, c)) {
                return 0; // não corresponde
            }
        }
    }

    // No final deve estar vazia
    return estaVazia(&p);
}

// MAIN (teste)
int main() {
    char expressao[100];

    printf("Digite a expressao: ");
    fgets(expressao, 100, stdin);

    // remove \n
    expressao[strcspn(expressao, "\n")] = '\0';

    if (validarExpressao(expressao)) {
        printf("Expressao VALIDA\n");
    } else {
        printf("Expressao INVALIDA\n");
    }

    return 0;
}