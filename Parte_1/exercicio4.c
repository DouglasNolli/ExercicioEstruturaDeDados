#include <stdio.h>
#include <stdlib.h>

int main() {

    int *ptr;
    int i;

    ptr = (int *) malloc(5 * sizeof(int));

    if (ptr == NULL) {
        printf("Erro ao alocar memoria\n");
        return 1;
    }

    for (i = 0; i < 5; i++) {
        printf("Digite um valor: ");
        scanf("%d", ptr);
        ptr++;
    }

    ptr = ptr - 5;

    for (i = 0; i < 5; i++) {
        printf("%d\n", *ptr);
        ptr++;
    }

    // voltando de novo para liberar corretamente
    ptr = ptr - 5;

    free(ptr);

    return 0;
}