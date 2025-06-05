#include <stdio.h>
#include <stdlib.h>

int main()
 {
    int N, i, j;

    // Leer n�mero entero positivo
    printf("Introduce un n�mero entero positivo: ");
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

        // Salto de l�nea
        printf("\n");
    }

    return 0;
}
