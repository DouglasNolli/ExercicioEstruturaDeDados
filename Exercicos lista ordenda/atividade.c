#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int codigo;
    char nome [50];
    char telefone [15];
} Cliente;


void insertion_Sort(Cliente vetor[], int tamanho) {
    for (int i = 1; i < tamanho; i++) {
        Cliente aux = vetor[i];
        int j = i - 1;

        while (j >= 0 && vetor[j].codigo > aux.codigo) {
            vetor[j + 1] = vetor[j];
            j--;
        }

        vetor[j + 1] = aux;
    }
}


int main() {

    Cliente vetor_cliente[] = {
        {5, "Ana", "555-8596"},
        {2, "Carlos", "555-7541"},
        {9, "Bruna", "555-8952"},
        {1, "Eduardo", "555-2354"},
        {7, "Marina", "555-4517"},
        {3, "João", "555-9631"},
        {10, "Fernanda", "555-8742"},
        {6, "Paulo", "555-4102"},
        {8, "Juliana", "555-8874"},
        {4, "Rafael", "555-0200"}
    };

    int tamanho = sizeof(vetor_cliente) / sizeof(vetor_cliente[0]);

    insertion_Sort(vetor_cliente, tamanho);

    for (int i = 0; i < tamanho; i++) {
        printf("Codigo: %d, Nome: %s, Telefone: %s\n",
            vetor_cliente[i].codigo,
            vetor_cliente[i].nome,
            vetor_cliente[i].telefone);
    }

    return 0;
}