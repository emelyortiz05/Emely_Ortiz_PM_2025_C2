#include <stdio.h>
#include <stdlib.h>

const int MAX = 10;  // Se define una constante para el tamaño de los arreglos

void Lectura(int VEC[], int T);
void Imprime(int VEC[], int T);  // Prototipos de funciones
void Producto(int *X, int *Y, int *Z, int T);  // Reciben arreglos como punteros

void main(void)
{
    int VE1[MAX], VE2[MAX], VE3[MAX];
    // Se declaran tres arreglos de tipo entero de 10 elementos.

    Lectura(VE1, MAX);
    // Se llama a la función Lectura. El paso del arreglo es por referencia.

    Lectura(VE2, MAX);

    Producto(VE1, VE2, VE3, MAX);
    // Se llama a la función Producto. Se pasan los nombres de los tres arreglos.

    printf("\nProducto de los Vectores");
    Imprime(VE3, MAX);
}

// Función para leer los valores del arreglo
void Lectura(int VEC[], int T)
{
    int I;
    printf("\n");
    for (I = 0; I < T; I++)
    {
        printf("Ingrese el elemento %d: ", I + 1);
        scanf("%d", &VEC[I]);
    }
}

// Función para imprimir los valores del arreglo
void Imprime(int VEC[], int T)
{
    int I;
    for (I = 0; I < T; I++)
        printf("\nVEC[%d]: %d", I + 1, VEC[I]);
}

// Función para calcular el producto de dos vectores
void Producto(int *X, int *Y, int *Z, int T)
{
    int I;
    for (I = 0; I < T; I++)
        Z[I] = X[I] * Y[I];
}
