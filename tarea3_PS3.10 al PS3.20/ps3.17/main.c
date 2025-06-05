#include <stdio.h>
#include <stdlib.h>

int main()
 {
    int N, i, j;

    // Leer número entero positivo
    printf("Introduce un número entero positivo: ");
    scanf("%d", &N);

    // Imprimir la figura
    for (i = 1; i <= N; i++) {
        // Parte creciente
        for (j = 1; j <= i; j++) {
            printf("%d  ", j);
        }

        // Parte decreciente
        for (j = i - 1; j >= 1; j--) {
            printf("%d  ", j);
        }

        // Salto de línea
        printf("\n");
    }

    return 0;
}
