#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int NUM, i, j, cont;

    printf("Ingrese un número entero positivo: ");
    scanf("%d", &NUM);

    if(NUM <= 1) {
        printf("No hay números primos menores a %d\n", NUM);
        return 0;
    }

    printf("Números primos menores a %d:\n", NUM);

    for(i = 2; i < NUM; i++) {
        cont = 0;
        for(j = 1; j <= i; j++) {
            if(i % j == 0) {
                cont++;
            }
        }
        if(cont == 2) {
            printf("%d\t", i);
        }
    }

    printf("\n");
    return 0;
}
