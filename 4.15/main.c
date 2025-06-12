#include <stdio.h>
#include <stdlib.h>

 /* Conflicto de variables con el mismo nombre. */

 void f1(void);            /* Prototipo de función. */
int K = 5;                /* Variable global. */

int main(void)
{
    int I;
    for (I = 1; I <= 3; I++)
        f1();
    return 0;
}

void f1(void) /* La función utiliza tanto la variable local kLocal como la variable global K. */
{
    int kLocal = 2;       /* Variable local. */
    kLocal += kLocal;
    printf("\n\nEl valor de la variable local es: %d", kLocal);
    K = K + kLocal;       /* Uso de la variable global K */
    printf("\nEl valor de la variable global es: %d", K);
}
