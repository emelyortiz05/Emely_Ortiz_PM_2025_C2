#include <stdio.h>
#include <stdlib.h>

/* Funciones y parámetros */
int F1(int, int *); // Prototipo

// Variables globales
int A = 3;
int B = 7;
int C = 4;
int D = 2;

int main(void)
{
    A = F1(C, &D);
    printf("\n%d %d %d %d", A, B, C, D);

    C = 3;
    C = F1(A, &C);
    printf("\n%d %d %d %d", A, B, C, D);

    return 0;
}

int F1(int X, int *Y)
{
    int A;
    A = X * (*Y);  // Multiplicación

    C++;           // Aumenta global C
    B += *Y;       // Suma valor apuntado a global B

    printf("\n%d %d %d %d", A, B, C, D);

    (*Y)--;        // Decrementa el valor apuntado por Y

    return C;      // Retorna la nueva C
}
