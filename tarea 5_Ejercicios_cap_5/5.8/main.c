#include <stdio.h>
#include <stdlib.h>

/* Primos.
 El programa almacena en un arreglo unidimensional los primeros 100 números primos. */
const int TAM = 100;
void Imprime(int Primos[], int T);
void Primo(int A, int *B);

int main(void)
{
    int P[TAM];
    P[0] = 2;
    P[1] = 3;
    int FLA, J = 2, PRI = 5;

    while (J < TAM)
    {
        FLA = 1;
        Primo(PRI, &FLA);       /* Se llama a la función que determina si PRI es primo. */
        if (FLA)                 /* Si FLA es 1, entonces PRI es primo. */
        {
            P[J] = PRI;
            J++;
        }
        PRI += 2;
    }
    Imprime(P, TAM);

    return 0;
}

void Primo(int A, int *B)
{
    int DI = 3;

    if (A < 2)
    {
        *B = 0;
        return;
    }
    if (A == 2) return;
    if (A % 2 == 0)
    {
        *B = 0;
        return;
    }
    while (*B && (DI * DI <= A))
    {
        if ((A % DI) == 0)
            *B = 0;
        DI += 2;
    }
}

void Imprime(int Primos[], int T)
{
    int I;
    for (I = 0; I < T; I++)
        printf("\nPrimos[%d]: %d", I, Primos[I]);
}
