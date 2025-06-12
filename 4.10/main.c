#include <stdio.h>
#include <stdlib.h>

/* Funciones y parámetros. */
int a, b, c, d; // Variables globales

void funcion1(int, int *, int *);  // Prototipos
int funcion2(int *, int);

int main(void)
{
    int a_local;

    b = 2;
    c = 3;
    d = 4;

    a_local = 1;
    printf("\n%d %d %d %d", a_local, b, c, d);

    a = funcion2(&a, c);  // Llamada a funcion2

    return 0;
}

void funcion1(int r, int *b_ptr, int *c_ptr)
{
    int d_local;
    a = *c_ptr;
    d_local = a + 3 + *b_ptr;

    if (r)
    {
        *b_ptr = *b_ptr + 2;
        *c_ptr = *c_ptr + 3;
        printf("\n%d %d %d %d", a, *b_ptr, *c_ptr, d_local);
    }
    else
    {
        *b_ptr = *b_ptr + 5;
        *c_ptr = *c_ptr + 4;
        printf("\n%d %d %d %d", a, *b_ptr, *c_ptr, d_local);
    }
}

int funcion2(int *d_ptr, int c_param)
{
    int b_local;
    a = 1;
    b_local = 7;

    funcion1(-1, d_ptr, &b_local);

    printf("\n%d %d %d %d", a, b_local, c_param, *d_ptr);

    c_param += 3;
    (*d_ptr) += 2;

    printf("\n%d %d %d %d", a, b_local, c_param, *d_ptr);

    return c_param;
}
