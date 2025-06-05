#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, i, j;

    // Leer número
    printf("Introduce un número entero positivo: ");
    scanf("%d", &N);

    for (i = 0; i < N; i++) {
        // Parte izquierda
        for (j = 1; j <= N - i; j++) {
            printf("%d  ", j);
        }

        // Espacios en el medio
        for (j = 0; j < i; j++) {
            printf("    "); // 4 espacios para mantener la alineación
        }

        // Parte derecha
        for (j = N - i; j >= 1; j--) {
            printf("%d  ", j);
        }

        // Nueva línea
        printf("\n");
    }

    return 0;
}
