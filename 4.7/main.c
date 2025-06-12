#include <stdio.h>
#include <math.h>

/* Temperaturas.
El programa recibe como datos 24 n�meros reales que representan las
temperaturas en el exterior en un per�odo de 24 horas. Calcula el
promedio del d�a y las temperaturas m�xima y m�nima con la hora en la
que se registraron. */

void Acutem(float);
void Maxima(float, int);     // Prototipos de funciones
void Minima(float, int);

// Variables globales
float ACT = 0.0;
float MAX = -50.0;
float MIN = 60.0;
int HMAX;
int HMIN;

/*
ACT se utiliza para acumular las temperaturas y calcular el promedio.
MAX se inicializa con un valor bajo para registrar la m�xima.
MIN se inicializa con un valor alto para registrar la m�nima.
HMAX y HMIN guardan la hora en que ocurrieron la temperatura m�xima y m�nima.
*/

int main(void)
{
    float TEM;
    int I;

    for (I = 1; I <= 24; I++)
    {
        printf("Ingresa la temperatura de la hora %d: ", I);
        scanf("%f", &TEM);
        Acutem(TEM);
        Maxima(TEM, I);
        Minima(TEM, I);
    }

    printf("\nPromedio del d�a: %5.2f", (ACT / 24));
    printf("\nM�xima del d�a: %5.2f\tHora: %d", MAX, HMAX);
    printf("\nM�nima del d�a: %5.2f\tHora: %d\n", MIN, HMIN);

    return 0;
}

void Acutem(float T)
{
    ACT += T;
}

void Maxima(float T, int H)
{
    if (MAX < T)
    {
        MAX = T;
        HMAX = H;
    }
}

void Minima(float T, int H)
{
    if (MIN > T)
    {
        MIN = T;
        HMIN = H;
    }
}
