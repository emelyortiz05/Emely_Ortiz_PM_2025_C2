#include <stdio.h>
#include <stdbool.h>

// Función que verifica si un número es primo

bool esPrimo(int num)
{
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return false;
    }
    return true;
}

int main(void) {
    int N1, N2, temp;

    printf("Ingrese dos números enteros positivos (N1 y N2): ");
    scanf("%d %d", &N1, &N2);

    // Asegurar que N1 sea menor o igual que N2
    if (N1 > N2) {
        temp = N1;
        N1 = N2;
        N2 = temp;
    }

    printf("Primos gemelos entre %d y %d:\n", N1, N2);

    for (int i = N1; i <= N2 - 2; i++) {
        if (esPrimo(i) && esPrimo(i + 2)) {
            printf("(%d, %d)\n", i, i + 2);
        }
    }

    return 0;
}
