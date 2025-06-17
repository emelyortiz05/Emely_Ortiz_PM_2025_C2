#include <stdio.h>
#include <stdlib.h>

const int TAM = 50;

void Lectura(int *, int);
void Frecuencia(int *, int, int *, int);  // Prototipos corregidos
void Impresion(int *, int);
void Mayor(int *, int);

void main(void)
{
    int CAL[TAM], FRE[6] = {0};  // Arreglo de calificaciones y frecuencias

    Lectura(CAL, TAM);           // Leer calificaciones
    Frecuencia(CAL, TAM, FRE, 6);  // Calcular frecuencia

    printf("\nFrecuencia de Calificaciones\n");
    Impresion(FRE, 6);           // Imprimir frecuencias
    Mayor(FRE, 6);               // Mostrar mayor frecuencia
}

// Lee las calificaciones de los alumnos
void Lectura(int VEC[], int T)
{
    int I;
    for (I = 0; I < T; I++)
    {
        printf("Ingrese la calificación (0-5) del alumno %d: ", I + 1);
        scanf("%d", &VEC[I]);
    }
}

// Imprime el arreglo de frecuencias
void Impresion(int VEC[], int T)
{
    int I;
    for (I = 0; I < T; I++)
        printf("\nVEC[%d]: %d", I, VEC[I]);
}

// Calcula la frecuencia de cada calificación (0 a 5)
void Frecuencia(int A[], int P, int B[], int T)
{
    int I;
    for (I = 0; I < P; I++)
    {
        if (A[I] >= 0 && A[I] < 6)  // Solo calificaciones válidas
            B[A[I]]++;
    }
}

// Encuentra y muestra la calificación con mayor frecuencia
void Mayor(int *X, int T)
{
    int I, MFRE = 0, MVAL = X[0];
    for (I = 1; I < T; I++)
    {
        if (MVAL < X[I])
        {
            MFRE = I;
            MVAL = X[I];
        }
    }
    printf("\n\nMayor frecuencia de calificaciones: %d \tValor: %d", MFRE, MVAL);
}
