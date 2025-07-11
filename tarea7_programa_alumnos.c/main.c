#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    int matricula;
    char nombre[50];
    char carrera[30];
    float promedio;
} Alumno;

// Funcion para guardar alumnos en un archivo binario
void guardarAlumnos(Alumno alumnos[], int n, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        printf("No se pudo abrir el archivo para escritura.\n");
        return;
    }
    fwrite(alumnos, sizeof(Alumno), n, file);
    fclose(file);
}

// Funcion para leer alumnos desde un archivo binario
int leerAlumnos(Alumno alumnos[], const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("No se pudo abrir el archivo para lectura.\n");
        return 0;
    }
    int n = 0;
    while (fread(&alumnos[n], sizeof(Alumno), 1, file)) {
        n++;
    }
    fclose(file);
    return n;
}

// Ordenar por nombre (Bubble Sort)
void ordenarPorNombre(Alumno alumnos[], int n) {
    Alumno temp;
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (strcmp(alumnos[j].nombre, alumnos[j + 1].nombre) > 0) {
                temp = alumnos[j];
                alumnos[j] = alumnos[j + 1];
                alumnos[j + 1] = temp;
            }
}

// Ordenar por promedio (Bubble Sort)
void ordenarPorPromedio(Alumno alumnos[], int n) {
    Alumno temp;
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (alumnos[j].promedio > alumnos[j + 1].promedio) {
                temp = alumnos[j];
                alumnos[j] = alumnos[j + 1];
                alumnos[j + 1] = temp;
            }
}

// Mostrar alumnos
void imprimirAlumnos(Alumno alumnos[], int n) {
    printf("\n%-10s %-20s %-15s %-10s\n", "Matricula", "Nombre", "Carrera", "Promedio");
    for (int i = 0; i < n; i++) {
        printf("%-10d %-20s %-15s %-10.2f\n",
               alumnos[i].matricula,
               alumnos[i].nombre,
               alumnos[i].carrera,
               alumnos[i].promedio);
    }
}

int main() {
    Alumno alumnos[MAX];
    int opcion, n = 0;

    printf("Cantidad de alumnos a ingresar: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nAlumno #%d:\n", i + 1);
        printf("Matricula: ");
        scanf("%d", &alumnos[i].matricula);
        getchar(); // limpiar buffer
        printf("Nombre: ");
        fgets(alumnos[i].nombre, sizeof(alumnos[i].nombre), stdin);
        alumnos[i].nombre[strcspn(alumnos[i].nombre, "\n")] = '\0';
        printf("Carrera: ");
        fgets(alumnos[i].carrera, sizeof(alumnos[i].carrera), stdin);
        alumnos[i].carrera[strcspn(alumnos[i].carrera, "\n")] = '\0';
        printf("Promedio: ");
        scanf("%f", &alumnos[i].promedio);
    }

    guardarAlumnos(alumnos, n, "alumnos.dat");

    printf("\nDeseas imprimir ordenado por:\n1. Nombre\n2. Promedio\nOpcion: ");
    scanf("%d", &opcion);

    n = leerAlumnos(alumnos, "alumnos.dat");

    if (opcion == 1)
        ordenarPorNombre(alumnos, n);
    else if (opcion == 2)
        ordenarPorPromedio(alumnos, n);
    else
        printf("Opcion no valida.\n");

    imprimirAlumnos(alumnos, n);

    return 0;
}
