#include <stdio.h>
#include <stdlib.h>

/* Calificaciones.
 El programa, al recibir un grupo de calificaciones de un alumno, obtiene el promedio de calificaciones de cada uno de ellos y, adem�s, los alumnos con el mejor y peor promedio.
 I, MAT, MAMAT y MEMAT: variables de tipo entero.
 CAL, SUM, MAPRO, MEPRO y PRO: variables de tipo real.*/
void main(void)
{
    int I, MAT, MAMAT = 0, MEMAT = 0;
    float SUM, PRO, CAL, MAPRO = 0.0, MEPRO = 11.0;

    printf("Ingrese la matr�cula del primer alumno:\t");
    scanf("%d", &MAT);

    while (MAT)
    {
        SUM = 0;
        for (I = 1; I <= 5; I++)
        {
            printf("\tIngrese la calificaci�n %d del alumno: ", I);
            scanf("%f", &CAL);
            SUM += CAL;
        }
        PRO = SUM / 5;
        printf("\nMatr�cula: %d\tPromedio: %5.2f\n", MAT, PRO);

        if (PRO > MAPRO)
        {
            MAPRO = PRO;
            MAMAT = MAT;
        }
        if (PRO < MEPRO)
        {
            MEPRO = PRO;
            MEMAT = MAT;
        }

        printf("\nIngrese la matr�cula del siguiente alumno (0 para terminar): ");
        scanf("%d", &MAT);
    }

    printf("\nAlumno con mejor Promedio:\t%d\t%5.2f", MAMAT, MAPRO);
    printf("\nAlumno con peor Promedio:\t%d\t%5.2f\n", MEMAT, MEPRO);
}
