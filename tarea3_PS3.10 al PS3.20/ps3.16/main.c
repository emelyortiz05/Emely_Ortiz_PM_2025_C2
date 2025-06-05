#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, i, j;

    // Leer el número
    printf("Introduce un número entero positivo: ");
    scanf("%d", &N);

    // Parte creciente
    for (i = 1; i <= N; i++) {
        for (j = 1; j <= i; j++) {
            printf("%d  ", j);
        }
        printf("\n");
    }

    // Parte decreciente
    for (i = N - 1; i >= 1; i--) {
        for (j = 1; j <= i; j++) {
            printf("%d  ", j);
        }
        printf("\n");
    }

    return 0;
}
