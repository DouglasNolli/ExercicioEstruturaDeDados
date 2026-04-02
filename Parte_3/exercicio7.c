#include <stdio.h>
#include <stdlib.h>

struct Aluno {
    char nome[50];
    float nota;
};

struct Aluno** filtrar(struct Aluno *vetor, int tamanho, int *qtd_aprovados) {
    
    struct Aluno **aprovados;
    int i, count = 0;

    for (i = 0; i < tamanho; i++) {
        if (vetor[i].nota > 7.0) {
            count++;
        }
    }

    *qtd_aprovados = count;

    aprovados = (struct Aluno **) malloc(count * sizeof(struct Aluno *));

    // preenchendo com os endereços
    int j = 0;
    for (i = 0; i < tamanho; i++) {
        if (vetor[i].nota > 7.0) {
            aprovados[j] = &vetor[i];
            j++;
        }
    }

    return aprovados;
}

int main() {

    struct Aluno alunos[5] = {
        {"Ana", 8.0},
        {"Bruno", 6.5},
        {"Carlos", 9.0},
        {"Pedro", 5.0},
        {"Isa", 7.5}
    };

    struct Aluno **aprovados;
    int qtd, i;

    aprovados = filtrar(alunos, 5, &qtd);

    printf("Aprovados:\n");
    for (i = 0; i < qtd; i++) {
        printf("%s - %.2f\n", aprovados[i]->nome, aprovados[i]->nota);
    }

    free(aprovados);

    return 0;
}