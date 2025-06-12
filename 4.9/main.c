#include <stdio.h>
#include <math.h>

/* Expresi�n.
El programa escribe los valores de T, P y Q que satisfacen una determinada
expresi�n mientras el resultado sea menor a 5500.
*/

int Expresion(int, int, int);  // Prototipo de funci�n

int main(void)
{
    int EXP, T = 0, P = 0, Q = 0;

    EXP = Expresion(T, P, Q);

    while (EXP < 5500)
    {
        while (EXP < 5500)
        {
            while (EXP < 5500)
            {
                printf("\nT: %d,  P: %d,  Q: %d, Resultado: %d", T, P, Q, EXP);
                Q++;
                EXP = Expresion(T, P, Q);
            }
            P++;
            Q = 0;
            EXP = Expresion(T, P, Q);
        }
        T++;
        P = 0;
        Q = 0;
        EXP = Expresion(T, P, Q);
    }

    return 0;
}

int Expresion(int T, int P, int Q)
/* Esta funci�n obtiene el resultado de la expresi�n para los valores
de T, P y Q. */
{
    int RES;
    RES = 15 * pow(T, 4) + 12 * pow(P, 5) + 9 * pow(Q, 6);
    return RES;
}

