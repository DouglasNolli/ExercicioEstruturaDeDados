#include <stdio.h>

void dobrar(int *num) {
    *num = *num * 2;
}

int main() {

    int valor = 5;

    dobrar(&valor);

    printf("Valor dobrado: %d\n", valor);

    return 0;
}