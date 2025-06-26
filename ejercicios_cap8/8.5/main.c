#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Uniones.
El programa muestra cómo se declara una unión, y cómo se accede a sus campos. */

union datos {
    char celular[15];
    char correo[20];
};

typedef struct {
    int matricula;
    char nombre[20];
    char carrera[20];
    float promedio;
    union datos personales;
} alumno;

void Lectura(alumno *a);  // Prototipo de función

void main(void)
{
    alumno a1 = {120, "María", "Contabilidad", 8.9, .personales.celular = "5-158-40-50"};
    alumno a2, a3;

    printf("Alumno 2\n");
    printf("Ingrese la matrícula: ");
    scanf("%d", &a2.matricula);
    fflush(stdin);
    printf("Ingrese el nombre: ");
    gets(a2.nombre);
    printf("Ingrese la carrera: ");
    gets(a2.carrera);
    printf("Ingrese el promedio: ");
    scanf("%f", &a2.promedio);
    fflush(stdin);
    printf("Ingrese el correo electrónico: ");
    gets(a2.personales.correo);

    printf("Alumno 3\n");
    Lectura(&a3);

    // Impresión de resultados
    printf("\nDatos del alumno 1\n");
    printf("%d\n", a1.matricula);
    puts(a1.nombre);
    puts(a1.carrera);
    printf("%.2f\n", a1.promedio);
    puts(a1.personales.celular);  // Muestra celular
    // El siguiente imprime basura si no se reescribe el campo
    // puts(a1.personales.correo); // opcional

    // Si sobreescribimos el campo de la unión
    strcpy(a1.personales.correo, "hgimenez@hotmail.com");
    puts(a1.personales.celular); // basura
    puts(a1.personales.correo);  // válido

    printf("\nDatos del alumno 2\n");
    printf("%d\n", a2.matricula);
    puts(a2.nombre);
    puts(a2.carrera);
    printf("%.2f\n", a2.promedio);
    puts(a2.personales.celular); // basura
    puts(a2.personales.correo);  // válido

    printf("Ingrese el teléfono celular del alumno 2: ");
    fflush(stdin);
    gets(a2.personales.celular); // Sobrescribe la unión
    puts(a2.personales.celular); // válido
    puts(a2.personales.correo);  // basura

    printf("\nDatos del alumno 3\n");
    printf("%d\n", a3.matricula);
    puts(a3.nombre);
    puts(a3.carrera);
    printf("%.2f\n", a3.promedio);
    puts(a3.personales.celular);  // válido
    puts(a3.personales.correo);   // basura
}

void Lectura(alumno *a)
{
    printf("\nIngrese la matrícula: ");
    scanf("%d", &a->matricula);
    fflush(stdin);
    printf("Ingrese el nombre: ");
    gets(a->nombre);
    printf("Ingrese la carrera: ");
    gets(a->carrera);
    printf("Ingrese el promedio: ");
    scanf("%f", &a->promedio);
    fflush(stdin);
    printf("Ingrese el teléfono celular: ");
    gets(a->personales.celular);
}
