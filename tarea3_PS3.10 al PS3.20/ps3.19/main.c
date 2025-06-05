#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, i, j, num;

    // Leer N
    printf("Introduce un número entero positivo: ");
    scanf("%d", &N);

    // Generar figura
    for (i = 1; i <= N; i++) {
        num = i;

        // Parte creciente
        for (j = 1; j <= i; j++) {
            printf("%d ", num % 10);
            num++;
        }

        // Preparar para parte decreciente
        num -= 2;

        // Parte decreciente
        for (j = 1; j < i; j++) {
            printf("%d ", num % 10);
            num--;
        }

        // Nueva línea
        printf("\n");
    }

    return 0;
}
