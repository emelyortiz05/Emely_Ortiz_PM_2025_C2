#include <stdio.h>
#include <stdlib.h>

int main(void)
 {
    int N, i, j;
    float VIN; // Cantidad para un vino espec�fico
    float totalTipo[4] = {0, 0, 0, 0};  // Acumuladores para cada tipo de vino
    float totalAnual;                    // Total producido en un a�o

    printf("Ingrese el n�mero de a�os: ");
    scanf("%d", &N);

    for(i = 1; i <= N; i++) {
        totalAnual = 0;
        printf("\nA�o %d:\n", i);
        for(j = 0; j < 4; j++) {
            printf("Cantidad producida del vino tipo %d: ", j + 1);
            scanf("%f", &VIN);
            totalTipo[j] += VIN;   // Acumular total por tipo
            totalAnual += VIN;     // Acumular total anual
        }
        printf("Total producido en el a�o %d: %.2f litros\n", i, totalAnual);
    }

    printf("\nTotal producido de cada tipo de vino en los �ltimos %d a�os:\n", N);
    for(j = 0; j < 4; j++) {
        printf("Tipo %d: %.2f litros\n", j + 1, totalTipo[j]);
    }

    return 0;
}
