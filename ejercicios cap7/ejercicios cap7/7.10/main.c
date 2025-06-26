#include <stdio.h>
#include <stdlib.h>

/* Suma y promedio.
   El programa, al recibir como datos varias cadenas de caracteres que
   contienen reales, los suma y obtiene el promedio de los mismos. */

void main(void)
{
    char c, cad[10];
    int i = 0;
    float sum = 0.0;

    printf("\nDesea ingresar una cadena de caracteres (S/N)? ");
    c = getchar();
    fflush(stdin);

    while (c == 'S' || c == 's')
    {
        printf("\nIngrese la cadena de caracteres: ");
        gets(cad);  // gets es inseguro; se recomienda fgets
        i++;
        sum += atof(cad);
        printf("\nDesea ingresar otra cadena de caracteres (S/N)? ");
        c = getchar();
        fflush(stdin);
    }

    if (i > 0) {
        printf("\nSuma: %.2f", sum);
        printf("\nPromedio: %.2f", sum / i);
    } else {
        printf("\nNo se ingresaron datos.");
    }
}
