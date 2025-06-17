#include <stdio.h>
#include <stdlib.h>

/* Apuntadores y arreglos */
int main(void) {
    int V1[4] = {2, 3, 4, 7}, V2[4] = {6, 0, 0, 0};
    int *AX, *AY;

    AX = &V1[3];
    AY = &V2[2];

    V1[V2[0] - V1[2]] = *AY;  // V2[0] = 6, V1[2] = 4 => índice 2
    *AY = *AX - V1[0];         // *AY = V1[3] - V1[0] = 7 - 2 = 5

    printf("\nV1[0]=%d V1[1]=%d V1[2]=%d V1[3]=%d \tV2[0]=%d V2[1]=%d V2[2]=%d V2[3]=%d",
           V1[0], V1[1], V1[2], V1[3], V2[0], V2[1], V2[2], V2[3]);

    V2[1] = ++*AX;  // Incrementa V1[3] y asigna a V2[1]. V1[3] pasa de 7 a 8
    V2[3] = (*AY)++; // Asigna a V2[3] el valor actual de *AY (5), luego incrementa *AY a 6
    *AX += 2;        // Suma 2 a V1[3], ahora V1[3] = 8 + 2 = 10

    printf("\nV1[0]=%d V1[1]=%d V1[2]=%d V1[3]=%d \tV2[0]=%d V2[1]=%d V2[2]=%d V2[3]=%d\n",
           V1[0], V1[1], V1[2], V1[3], V2[0], V2[1], V2[2], V2[3]);

    return 0;
}
