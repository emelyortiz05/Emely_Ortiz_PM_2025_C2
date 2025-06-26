#include <stdio.h>
#include <stdlib.h>

/* Funciones para el manejo de caracteres de la biblioteca stdlib.h. */
void main(void)
{
    int i;
    double d;
    long l;
    char cad0[20], *cad1;

    printf("\nIngrese una cadena de caracteres: ");
    gets(cad0);
    i = atoi(cad0);
    /* La función atoi convierte una cadena de caracteres que contiene números
       a un valor de tipo entero. Si la cadena comienza con otro caracter o no
       contiene números, regresa 0 o el valor queda indefinido. */
    printf("\n%s \t %d", cad0, i + 3);
    /* Se imprime el valor de i+3 para demostrar que i ya fue convertido a un entero. */

    printf("\nIngrese una cadena de caracteres: ");
    gets(cad0);
    d = atof(cad0);
    /* La función atof convierte una cadena que contiene números reales a un
       valor de tipo double. Si la cadena comienza con otro caracter o no
       contiene números, regresa 0 o el valor queda indefinido. */
    printf("\n%s \t %.2lf ", cad0, d + 1.50);

    d = strtod(cad0, &cad1);
    /* La función strtod convierte una cadena que contiene números reales a un
       valor double. El resto de la cadena se almacena en &cad1. Si no contiene
       números o empieza con otro caracter, regresa 0 o valor indefinido. */
    printf("\n%s \t %.2lf", cad0, d + 1.50);
    puts(cad1);

    l = atol(cad0);
    /* La función atol convierte una cadena que contiene números a un valor long.
       Si la cadena no contiene números o empieza con otro caracter, regresa 0. */
    printf("\n%s \t %ld ", cad0, l + 10);

    l = strtol(cad0, &cad1, 0);
    /* La función strtol convierte una cadena que contiene números a long.
       El resto de la cadena se guarda en &cad1.
       El tercer argumento indica la base: 0 detecta decimal, octal o hexadecimal. */
    printf("\n%s \t %ld", cad0, l + 10);
    puts(cad1);
}
