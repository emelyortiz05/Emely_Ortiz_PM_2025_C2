#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int NUM, i, j, cont;

    printf("Ingrese un n�mero entero positivo: ");
    scanf("%d", &NUM);

    if(NUM <= 1) {
        printf("No hay n�meros primos menores a %d\n", NUM);
        return 0;
    }

    printf("N�meros primos menores a %d:\n", NUM);

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
