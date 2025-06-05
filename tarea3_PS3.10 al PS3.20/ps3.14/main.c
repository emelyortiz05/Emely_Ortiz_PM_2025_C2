#include <stdio.h>
#include <math.h>

int main()
{
    int x, n = 1;
    float x_rad, termino, senx = 0.0, senx_anterior, diferencia;
    int signo = 1;

    // Leer el valor de x
    printf("Introduce el valor de x (en grados): ");
    scanf("%d", &x);

    // Convertir a radianes
    x_rad = x * M_PI / 180;

    // Inicializar el primer término
    termino = x_rad;

    do {
        senx_anterior = senx;
        senx += signo * termino;
        n++;

        // Calcular el siguiente término usando recurrencia
        termino = termino * x_rad * x_rad / ((2 * n - 2) * (2 * n - 1));

        // Alternar el signo
        signo *= -1;

        // Calcular diferencia para la condición de parada
        diferencia = fabs(senx - senx_anterior);

    } while (diferencia > 0.001);

    // Mostrar resultados
    printf("sen(%d) ≈ %.5f\n", x, senx);
    printf("Número de términos utilizados: %d\n", n - 1);

    return 0;
}
