#include <stdio.h>
#include <stdlib.h>

int main(void)
 {
    int N, i, j;
    float VIN; // Cantidad para un vino específico
    float totalTipo[4] = {0, 0, 0, 0};  // Acumuladores para cada tipo de vino
    float totalAnual;                    // Total producido en un año

    printf("Ingrese el número de años: ");
    scanf("%d", &N);

    for(i = 1; i <= N; i++) {
        totalAnual = 0;
        printf("\nAño %d:\n", i);
        for(j = 0; j < 4; j++) {
            printf("Cantidad producida del vino tipo %d: ", j + 1);
            scanf("%f", &VIN);
            totalTipo[j] += VIN;   // Acumular total por tipo
            totalAnual += VIN;     // Acumular total anual
        }
        printf("Total producido en el año %d: %.2f litros\n", i, totalAnual);
    }

    printf("\nTotal producido de cada tipo de vino en los últimos %d años:\n", N);
    for(j = 0; j < 4; j++) {
        printf("Tipo %d: %.2f litros\n", j + 1, totalTipo[j]);
    }

    return 0;
}
