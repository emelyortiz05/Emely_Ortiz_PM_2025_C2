#include <stdio.h>
#include <math.h>

//Funci�n matem�tica.
//El programa obtiene el resultado de una funci�n.
//OP y T: variable de tipo entero.
//RES: variable de tipo real.


void main(void)
{
    int OP, T;
    float RES;
    printf("Ingrese la opcion del calculo y el valor entero:");
    scanf("%d %d", &OP, &T );
    if (OP == 1)
        RES = T/5;
    else if (OP == 2)
        RES = pow (T, T);
    else if (OP == 3)
        RES = (6*T/2);
    else
        RES = 1;
    printf("\nResultado: %7.2f", RES);
}
