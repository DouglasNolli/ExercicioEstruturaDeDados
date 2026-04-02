#include <stdio.h>
#include <stdlib.h>

int main() {

    char *x;

    x = (char *) malloc(1024 * 1024 * 1024);

    if (x == NULL) {
        printf("Erro: nao foi possivel alocar memoria\n");
    } else {
        printf("Memoria alocada !\n");
        free(x);
    }

    return 0;
}