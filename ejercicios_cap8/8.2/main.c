#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Estructuras-2.
El programa muestra la manera en que se declara una estructura, así como la
forma en que se tiene acceso a los campos de los apuntadores de tipo estructura
tanto para lectura como para escritura. Se utiliza además una función que
recibe como parámetro un apuntador de tipo estructura. */

struct alumno {
    int matricula;
    char nombre[20];
    char carrera[20];
    float promedio;
    char direccion[20];
}; // Observa que la declaración de una estructura termina con punto y coma.

void Lectura(struct alumno *); // Prototipo de función.

void main(void) {
    struct alumno a0 = {120, "María", "Contabilidad", 8.9, "Querétaro"};
    struct alumno *a3, *a4, *a5, a6;

    a3 = &a0;

    a4 = (struct alumno *)malloc(sizeof(struct alumno));

    printf("\nIngrese la matrícula del alumno 4: ");
    scanf("%d", &(*a4).matricula);
    fflush(stdin);
    printf("Ingrese el nombre del alumno 4: ");
    gets(a4->nombre);
    printf("Ingrese la carrera del alumno 4: ");
    gets((*a4).carrera);
    printf("Ingrese promedio del alumno 4: ");
    scanf("%f", &a4->promedio);
    fflush(stdin);
    printf("Ingrese la dirección del alumno 4: ");
    gets(a4->direccion);

    a5 = (struct alumno *)malloc(sizeof(struct alumno));
    Lectura(a5);
    Lectura(&a6);

    printf("\nDatos del alumno 3\n");
    printf("%d\t%s\t%s\t%.2f\t%s", a3->matricula, a3->nombre, a3->carrera, a3->promedio, a3->direccion);

    printf("\nDatos del alumno 4\n");
    printf("%d\t%s\t%s\t%.2f\t%s", a4->matricula, a4->nombre, a4->carrera, a4->promedio, a4->direccion);

    printf("\nDatos del alumno 5\n");
    printf("%d\t%s\t%s\t%.2f\t%s", a5->matricula, a5->nombre, a5->carrera, a5->promedio, a5->direccion);

    printf("\nDatos del alumno 6\n");
    printf("%d\t%s\t%s\t%.2f\t%s", a6.matricula, a6.nombre, a6.carrera, a6.promedio, a6.direccion);
}

void Lectura(struct alumno *a) {
    printf("\nIngrese la matrícula del alumno: ");
    scanf("%d", &(*a).matricula);
    fflush(stdin);
    printf("Ingrese el nombre del alumno: ");
    gets(a->nombre);
    fflush(stdin);
    printf("Ingrese la carrera del alumno: ");
    gets((*a).carrera);
    printf("Ingrese el promedio del alumno: ");
    scanf("%f", &a->promedio);
    fflush(stdin);
    printf("Ingrese la dirección del alumno: ");
    gets(a->direccion);
}

/* . . .
int C1, C2, C3, C4, C5;
. . . . . . */
typedef int contador;

/* Posteriormente, ya sea en el programa principal o en una función,
declaramos las variables C1, C2, C3, C4 y C5 como de tipo contador. */
contador C1, C2, C3, C4, C5;

/* typedef struct usando nombre personalizado */
typedef struct {
    int matricula;
    char nombre[20];
    char carrera[20];
    float promedio;
    char direccion[20];
} alumno; // alumno es el nuevo tipo definido por el usuario

void Lectura2(alumno *); // Prototipo de función con typedef

void main2(void) {
    alumno a0 = {120, "María", "Contabilidad", 8.9, "Querétaro"}, *a3, *a4, *a5, a6;
    // Resto del programa
}
