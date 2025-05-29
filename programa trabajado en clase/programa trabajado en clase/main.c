#include <stdio.h>
#include <stdlib.h>

/*Hacer un programa que determine el rango de edad de una persona
1- recien nacido: persona de edad menor al año
2- infante con edad entre 1 y 3 años
3- Niño con edad entre 3 y 12 años
4- Adolecente con edad mayor de 12 años y menos a 18
5- Mayor de edad es una persona mayor a 18 y menor de 32
6- Adulto mayor es mayor de 38 y menor de 68
7- envejeciente mayor de 68 y menor 86
Anciano es mayor de 86 años*/

int main()
{
    printf("Clase de Seleccion!\n");

    int edad =0;

    printf("Ingrese su edad\n");

    scanf("%i",&edad);

    if( edad >= 0 && edad <= 120)
    {
        if(edad <=1)
        {

            printf("\nUsted es un recien nacido");

        }
        else if(edad >=1 && edad <3)
        {
            printf("\nUsted es un infante");
        }
        else if(edad >=3 && edad <12 )
        {
            printf("\nUsted es un niño");
        }
        else if(edad >=12 && edad <18 )
        {
            printf("\nUsted es un adolecente");
        }
        else if(edad >=18 && edad <32 )
        {
            printf("\nUsted es mayor");
        }
        else if(edad >=32 && edad <68 )
        {
            printf("\nUsted es un adulto");
        }
        else if(edad >=68 && edad <86 )
        {
            printf("\nUsted es un envejeciente");
        }
        else if(edad >=68)
        {
            printf("\nUsted es un anciano");
        }

    }
    else
    {
        if ( edad < 0)
        {
            printf("\nErro edad negativa");
        }
        else if ( edad >120)
        {
            printf("\n Edad muy alta no real");
        }
    }
    getchar();
    return 0;
}
