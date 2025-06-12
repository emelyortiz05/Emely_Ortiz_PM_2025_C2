#include <stdio.h>
#include <stdlib.h>

/* Cubo-2.
 El programa calcula el cubo de los 10 primeros n�meros naturales con la ayuda de una funci�n. */

int cubo(int);  // Prototipo de funci�n que recibe un entero

int main(void)
{
    int CUB;
    int I;
    for (I = 1; I <= 10; I++)
    {
        CUB = cubo(I);  // Llamada a la funci�n cubo, pasando I como argumento
        printf("El cubo de %d es: %d\n", I, CUB);
    }
    return 0;
}

int cubo(int n)
{
    return (n * n * n);  // Calcula el cubo de n y devuelve el resultado
}
