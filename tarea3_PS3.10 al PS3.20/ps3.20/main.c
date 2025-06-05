#include <stdio.h>
#include <math.h>

int main()
{
    int T, P, R;
    double resultado;

    // Probar valores razonables para limitar el tiempo de ejecución
    for (T = 1; T <= 10; T++) {
        for (P = 1; P <= 10; P++) {
            for (R = 1; R <= 10; R++) {
                resultado = 7 * pow(T, 4) - 6 * pow(P, 3) + 12 * pow(R, 5);

                if (resultado < 5850) {
                    printf("T = %d, P = %d, R = %d --> Resultado = %.0f\n", T, P, R, resultado);
                }
            }
        }
    }

    return 0;
}
