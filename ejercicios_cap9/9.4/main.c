#include <stdio.h>
#include <stdlib.h>

void main(void)
{
    char cad[50];
    FILE *ap;
    if ((ap = fopen("arc.txt", "r")) != NULL)
    /* Se abre el archivo para lectura y se verifica si se abrio correctamente. */
    {
        while (!feof(ap))
        /* Mientras no se detecte el fin de archivo se siguen leyendo cadenas de
           caracteres. */
        {
            if (fgets(cad, 50, ap) != NULL)
            {
                /* Observa que la instruccion para leer cadenas requiere de tres
                   argumentos. */
                puts(cad);       /* Despliega la cadena en la pantalla. */
            }
        }
        fclose(ap);
    }
    else
        printf("No se puede abrir el archivo");
}
