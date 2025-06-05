#include <stdio.h>
#include <stdlib.h>

int main()
 {
    int N1, N2, r;

    // Leer los n�meros
    printf("Introduce el primer n�mero (N1): ");
    scanf("%d", &N1);
    printf("Introduce el segundo n�mero (N2): ");
    scanf("%d", &N2);

    // Algoritmo de Euclides
    while (N2 != 0) {
        r = N1 % N2;
        N1 = N2;
        N2 = r;
    }

    // Resultado
    printf("El MCD es: %d\n", N1);

    return 0;
}
