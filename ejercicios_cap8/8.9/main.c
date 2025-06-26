#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Bienes raíces.
   El programa maneja información sobre las propiedades que tiene una empresa
   de bienes raíces de la ciudad de Lima, Perú, tanto para venta como para renta. */

typedef struct {   /* Declaración de la estructura ubicación */
    char zona[20];
    char calle[20];
    char colo[20];   /* Colonia */
} ubicacion;

typedef struct {   /* Declaración de la estructura propiedades */
    char clave[6];   /* +1 para el carácter nulo */
    float scu;       /* Superficie cubierta */
    float ste;       /* Superficie terreno */
    char car[50];    /* Características */
    ubicacion ubi;   /* Campo de tipo estructura ubicación */
    float precio;
    char dispo;      /* Disponibilidad: 'V' para venta, 'R' para renta */
} propiedades;

void Lectura(propiedades[], int);
void F1(propiedades[], int);
void F2(propiedades[], int);

int main(void) {
    propiedades PROPIE[100];
    int TAM;

    do {
        printf("Ingrese el número de propiedades (1-100): ");
        scanf("%d", &TAM);
        fflush(stdin);
    } while (TAM > 100 || TAM < 1);

    Lectura(PROPIE, TAM);
    F1(PROPIE, TAM);
    F2(PROPIE, TAM);

    return 0;
}

void Lectura(propiedades A[], int T) {
    int I;
    for (I = 0; I < T; I++) {
        printf("\n\tIngrese datos de la propiedad %d\n", I + 1);

        printf("Clave: ");
        fflush(stdin);
        fgets(A[I].clave, sizeof(A[I].clave), stdin);
        A[I].clave[strcspn(A[I].clave, "\n")] = '\0';  // Quitar salto de línea

        printf("Superficie cubierta: ");
        scanf("%f", &A[I].scu);

        printf("Superficie terreno: ");
        scanf("%f", &A[I].ste);
        fflush(stdin);

        printf("Características: ");
        fgets(A[I].car, sizeof(A[I].car), stdin);
        A[I].car[strcspn(A[I].car, "\n")] = '\0';

        printf("\tZona: ");
        fgets(A[I].ubi.zona, sizeof(A[I].ubi.zona), stdin);
        A[I].ubi.zona[strcspn(A[I].ubi.zona, "\n")] = '\0';

        printf("\tCalle: ");
        fgets(A[I].ubi.calle, sizeof(A[I].ubi.calle), stdin);
        A[I].ubi.calle[strcspn(A[I].ubi.calle, "\n")] = '\0';

        printf("\tColonia: ");
        fgets(A[I].ubi.colo, sizeof(A[I].ubi.colo), stdin);
        A[I].ubi.colo[strcspn(A[I].ubi.colo, "\n")] = '\0';

        printf("Precio: ");
        scanf("%f", &A[I].precio);
        fflush(stdin);

        printf("Disponibilidad (Venta-V / Renta-R): ");
        scanf("%c", &A[I].dispo);
        fflush(stdin);
    }
}

void F1(propiedades A[], int T) {
    int I;
    printf("\n\t\tListado de Propiedades para Venta en Miraflores\n");
    for (I = 0; I < T; I++) {
        if ((A[I].dispo == 'V' || A[I].dispo == 'v') &&
            strcmp(A[I].ubi.zona, "Miraflores") == 0 &&
            A[I].precio >= 450000 && A[I].precio <= 650000) {

            printf("\nClave de la propiedad: %s\n", A[I].clave);
            printf("Superficie cubierta: %.2f\n", A[I].scu);
            printf("Superficie terreno: %.2f\n", A[I].ste);
            printf("Características: %s\n", A[I].car);
            printf("Calle: %s\n", A[I].ubi.calle);
            printf("Colonia: %s\n", A[I].ubi.colo);
            printf("Precio: %.2f\n", A[I].precio);
        }
    }
}

void F2(propiedades A[], int T) {
    int I;
    float li, ls;
    char zon[20];

    printf("\n\t\tListado de Propiedades para Renta\n");
    printf("Ingrese zona geográfica: ");
    fflush(stdin);
    fgets(zon, sizeof(zon), stdin);
    zon[strcspn(zon, "\n")] = '\0';

    printf("Ingrese el límite inferior del precio: ");
    scanf("%f", &li);
    printf("Ingrese el límite superior del precio: ");
    scanf("%f", &ls);

    printf("\nPropiedades disponibles para renta en %s entre %.2f y %.2f:\n", zon, li, ls);

    for (I = 0; I < T; I++) {
        if ((A[I].dispo == 'R' || A[I].dispo == 'r') &&
            strcmp(A[I].ubi.zona, zon) == 0 &&
            A[I].precio >= li && A[I].precio <= ls) {

            printf("\nClave de la propiedad: %s\n", A[I].clave);
            printf("Superficie cubierta: %.2f\n", A[I].scu);
            printf("Superficie terreno: %.2f\n", A[I].ste);
            printf("Características: %s\n", A[I].car);
            printf("Calle: %s\n", A[I].ubi.calle);
            printf("Colonia: %s\n", A[I].ubi.colo);
            printf("Precio: %.2f\n", A[I].precio);
        }
    }
}
