#include <stdio.h>
#include <stdlib.h>

/* Declaración de cadenas de caracteres y asignación de valores. */

void main(void)
{
    char *cad0;

    cad0 = "Argentina";
    /* La declaración y la asignación son correctas.
       cad0 apunta a una cadena constante en memoria. */
    puts(cad0);

    cad0 = "Brasil";
    /* Correcto. Se modifica el contenido del apuntador cad0, apuntando ahora a otra cadena constante. */
    puts(cad0);

    char *cad1;
    // gets(*cad1); // Incorrecto, provoca error en ejecución porque *cad1 no es puntero válido.
    // gets(cad1);  // Incorrecto, cad1 no está inicializado ni apunta a espacio válido.

    /* Para usar gets con un puntero a cadena, debe apuntar a un espacio válido,
       como un arreglo o memoria dinámica reservada. */
    // char *cad1 = ""; // Cadena vacía constante, no se debe usar gets para modificarla.

    char cad2[20] = "México";
    /* Correcto: arreglo de caracteres con espacio reservado para 20 caracteres. */
    puts(cad2);

    gets(cad2);
    /* Correcto: se puede modificar el contenido del arreglo cad2 porque tiene espacio reservado. */
    puts(cad2);

    // cad2[10] = "Guatemala";
    /* Incorrecto: no se puede asignar una cadena a una posición del arreglo.
       cad2[10] es un solo carácter, y "Guatemala" es una cadena de caracteres.
       Esto provoca error de compilación. */
}
