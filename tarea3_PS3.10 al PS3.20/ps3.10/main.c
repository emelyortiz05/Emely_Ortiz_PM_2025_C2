#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    float L[6];           // Precios de las 6 localidades
    int CLA, CAN;         // Tipo de localidad y cantidad de boletos en una venta
    int boletosVendidos[6] = {0, 0, 0, 0, 0, 0};  // Contador de boletos vendidos por localidad
    float montoVenta, recaudacionTotal = 0.0;

    // Leer precios de las localidades
    printf("Ingrese los precios de las 6 localidades:\n");
    for (int i = 0; i < 6; i++) {
        printf("Precio L%d: ", i+1);
        scanf("%f", &L[i]);
    }

    printf("\nIngrese las ventas. Para terminar, ingrese 0 para el tipo de localidad.\n");

    while(1) {
        printf("Tipo de localidad (1-6, 0 para terminar): ");
        scanf("%d", &CLA);

        if (CLA == 0)
            break;

        if (CLA < 1 || CLA > 6) {
            printf("Tipo de localidad inválido. Intente de nuevo.\n");
            continue;
        }

        printf("Cantidad de boletos vendidos para L%d: ", CLA);
        scanf("%d", &CAN);

        // Calcular monto de esta venta
        montoVenta = L[CLA - 1] * CAN;
        printf("Monto de la venta: %.2f\n", montoVenta);

        // Acumular boletos vendidos y recaudación total
        boletosVendidos[CLA - 1] += CAN;
        recaudacionTotal += montoVenta;
    }

    // Mostrar resultados
    printf("\nNúmero total de boletos vendidos por localidad:\n");
    for (int i = 0; i < 6; i++) {
        printf("Localidad L%d: %d boletos\n", i + 1, boletosVendidos[i]);
    }

    printf("\nRecaudación total: %.2f\n", recaudacionTotal);

    return 0;
}
