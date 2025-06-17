#include <stdio.h>
#include <stdlib.h>

/* Búsqueda secuencial en arreglos ordenados en forma creciente. */
const int MAX = 100;
void Lectura(int A[], int T);       /* Prototipos de funciones. */
int Busca(int A[], int T, int E);

int main(void)
{
    int RES, ELE, TAM, VEC[MAX];
    do
    {
        printf("Ingrese el tamaño del arreglo: ");
        scanf("%d", &TAM);
    }
    while (TAM > MAX || TAM < 1);   /* Se verifica que el tamaño del arreglo sea correcto. */

    Lectura(VEC, TAM);

    printf("\nIngrese el elemento a buscar: ");
    scanf("%d", &ELE);

    RES = Busca(VEC, TAM, ELE);    /* Se llama a la función que busca en el arreglo. */

    if (RES)
        printf("\nEl elemento se encuentra en la posición: %d\n", RES);
    else
        printf("\nEl elemento no se encuentra en el arreglo\n");

    return 0;
}

void Lectura(int A[], int T)
/* La función Lectura se utiliza para leer un arreglo unidimensional de T elementos de tipo entero. */
{
    int I;
    for (I = 0; I < T; I++)
    {
        printf("Ingrese el elemento %d: ", I + 1);
        scanf("%d", &A[I]);
    }
}

int Busca(int A[], int T, int E)
/* Esta función se utiliza para localizar el elemento E en el arreglo unidimensional A.
Si se encuentra, la función regresa la posición correspondiente. En caso contrario regresa 0. */
{
    int I = 0, BAN = 0, RES = 0;
    while ((I < T) && (E >= A[I]) && !BAN)
    {
        if (A[I] == E)
            BAN = 1;
        else
            I++;
    }
    if (BAN)
        RES = I + 1;     /* Se asigna I+1 dado que las posiciones en el arreglo comienzan desde cero. */
    return RES;
}
