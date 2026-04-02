#include <stdio.h>
#include <stdlib.h>

int main() {

    float *x;

    x = (float *) malloc(sizeof(float));
    
    *x = 2;

    printf("Valor digitado: %.2f\n", *x);

    free(x);

    return 0;
}