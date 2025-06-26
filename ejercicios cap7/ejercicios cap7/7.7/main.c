#include <stdio.h>
#include <string.h>

/* Otras funciones de la biblioteca string.h para el manejo de cadenas. */
void main(void)
{
    int i;
    char cad0[20] = "Hola México";
    char cad1[20] = "Hola Guatemala";
    char cad2[20] = "Hola Venezuela";
    char cad3[20] = "Hola México";
    char *c, c3;

    // Comparación entre cadenas
    i = strcmp(cad0, cad1);
    printf("\nResultado de la comparación —cad0 y cad1—: %d", i);

    i = strcmp(cad0, cad2);
    printf("\nResultado de la comparación —cad0 y cad2—: %d", i);

    i = strcmp(cad0, cad3);
    printf("\nResultado de la comparación —cad0 y cad3—: %d", i);

    // Longitud de las cadenas
    i = strlen(cad0);
    printf("\nLongitud cadena cad0: %d", i);

    i = strlen(cad1);
    printf("\nLongitud cadena cad1: %d", i);

    // Búsqueda de caracteres
    c = strchr(cad1, 'G');  // Busca la letra 'G' en cad1
    if (c != NULL)
    {
        c3 = *c;
        printf("\nEl valor de c3 es: %c", c3);
    }

    c = strchr(cad2, 'V');  // Busca la letra 'V' en cad2
    if (c != NULL)
    {
        c3 = *c;
        printf("\nEl valor de c3 es: %c", c3);
    }
}
