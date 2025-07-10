#include <stdio.h>
#include <stdlib.h>

void main(void)
{
    char cad[50];
    int res;
    FILE *ar;
    if ((ar = fopen("arc.txt", "w")) != NULL)
    /* Se abre el archivo para escritura. En la misma instrucción se verifica si se pudo abrir. */
    {
        printf("\nDesea ingresar una cadena de caracteres?  Si-1 No-0: ");
        scanf("%d", &res);
        while (res)
        {
            fflush(stdin);
            printf("Ingrese la cadena: ");
            gets(cad);
            fputs(cad, ar);     /* Observa la forma como se escribe la cadena en el archivo. */
            printf("\nDesea ingresar otra cadena de caracteres?  Si-1  No-0: ");
            scanf("%d", &res);
            if (res)
                fputs("\n", ar);
            /* Se indica un salto de linea, excepto en la ultima cadena. Si no
               se hiciera esta indicacion, la funcion fputs pegaría las cadenas y
               luego tendriamos dificultades en el momento de leerlas. Por otra
               parte, si realizáramos este salto de linea al final de la ultima
               cadena, en la escritura se repetiría la ultima cadena. */
        }
        fclose(ar);
    }
    else
        printf("No se puede abrir el archivo");
}
