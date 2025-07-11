#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Alumno {
    char nombre[50];
    int edad;
    float promedio;
    struct Alumno* siguiente; // puntero al siguiente alumno
} Alumno;

void guardarEnArchivo(Alumno* inicio, const char* nombreArchivo) {
    FILE* archivo = fopen(nombreArchivo, "wb");
    if (!archivo) {
        printf("No se pudo abrir el archivo para escritura.\n");
        return;
    }

    Alumno* actual = inicio;
    while (actual != NULL) {
        fwrite(actual, sizeof(Alumno) - sizeof(Alumno*), 1, archivo);
        actual = actual->siguiente;
    }

    fclose(archivo);
}

Alumno* leerDesdeArchivo(const char* nombreArchivo) {
    FILE* archivo = fopen(nombreArchivo, "rb");
    if (!archivo) {
        printf("No se pudo abrir el archivo para lectura.\n");
        return NULL;
    }

    Alumno* inicio = NULL;
    Alumno* anterior = NULL;

    while (!feof(archivo)) {
        Alumno* nuevo = (Alumno*)malloc(sizeof(Alumno));
        if (fread(nuevo, sizeof(Alumno) - sizeof(Alumno*), 1, archivo) == 1) {
            nuevo->siguiente = NULL;
            if (inicio == NULL)
                inicio = nuevo;
            else
                anterior->siguiente = nuevo;
            anterior = nuevo;
        } else {
            free(nuevo);
        }
    }

    fclose(archivo);
    return inicio;
}

void mostrarAlumnos(Alumno* inicio) {
    Alumno* actual = inicio;
    while (actual != NULL) {
        printf("Nombre: %s\nEdad: %d\nPromedio: %.2f\n\n",
               actual->nombre, actual->edad, actual->promedio);
        actual = actual->siguiente;
    }
}

int main() {
    Alumno* inicio = NULL;
    Alumno* nuevo = NULL;
    char continuar;

    // Entrada de datos
    do {
        nuevo = (Alumno*)malloc(sizeof(Alumno));
        printf("Nombre: ");
        scanf("%s", nuevo->nombre);
        printf("Edad: ");
        scanf("%d", &nuevo->edad);
        printf("Promedio: ");
        scanf("%f", &nuevo->promedio);
        nuevo->siguiente = inicio;
        inicio = nuevo;

        printf("¿Agregar otro alumno? (s/n): ");
        scanf(" %c", &continuar);
    } while (continuar == 's' || continuar == 'S');

    guardarEnArchivo(inicio, "alumnos.dat");

    // Liberar memoria
    while (inicio != NULL) {
        Alumno* temp = inicio;
        inicio = inicio->siguiente;
        free(temp);
    }

    printf("\nDatos leídos desde archivo:\n");
    Alumno* leidos = leerDesdeArchivo("alumnos.dat");
    mostrarAlumnos(leidos);

    // Liberar lista leída
    while (leidos != NULL) {
        Alumno* temp = leidos;
        leidos = leidos->siguiente;
        free(temp);
    }

    return 0;
}
