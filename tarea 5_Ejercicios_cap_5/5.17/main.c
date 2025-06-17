#include <stdio.h>
#include <stdlib.h>

/* Apuntadores y arreglos */
int main(void)
{
    int V1[4] = {1, 3, 5, 7}, V2[4] = {2, 4, 0, 0};
    int *AX, *AY;

    AX = &V1[2];  // apunta a V1[2] (valor 5)
    AY = &V2[2];  // apunta a V2[2] (valor 0, inicializado)

    V2[2] = *(AX + 1); // V1[3] = 7 -> V2[2] = 7
    V2[3] = *AX;       // V1[2] = 5 -> V2[3] = 5

    AX = AX + 1;       // AX apunta ahora a V1[3] (7)
    V1[0] = *AX;       // V1[0] = 7

    printf("\nV1[0]=%d V1[1]=%d V1[2]=%d V1[3]=%d \tV2[0]=%d V2[1]=%d V2[2]=%d V2[3]=%d",
        V1[0], V1[1], V1[2], V1[3], V2[0], V2[1], V2[2], V2[3]);

    V1[2] = *AY;      // V2[2] = 7, entonces V1[2] = 7
    V1[1] = --*AY;    // decrementa *AY (V2[2]) de 7 a 6, y asigna V1[1] = 6

    AX = AX + 1;      // AX apunta fuera del arreglo (Cuidado: comportamiento indefinido)
    V1[3] = *AX;      // lectura fuera del arreglo (puede ser basura o error)

    printf("\nV1[0]=%d V1[1]=%d V1[2]=%d V1[3]=%d \tV2[0]=%d V2[1]=%d V2[2]=%d V2[3]=%d\n",
        V1[0], V1[1], V1[2], V1[3], V2[0], V2[1], V2[2], V2[3]);

    return 0;
}
