#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Hospital.
   El programa genera información acerca de los pacientes de un hospital. */

typedef struct {   /* Declaración de la estructura domicilio */
    char cal[20];   /* Calle */
    int num;        /* Número */
    char col[20];   /* Colonia */
    char cp[6];     /* Código Postal (5 caracteres + '\0') */
    char ciu[20];   /* Ciudad */
} domicilio;

typedef struct {   /* Declaración de la estructura paciente */
    char nom[20];   /* Nombre y apellido */
    int edad;
    char sexo;
    int con;        /* Condición */
    domicilio dom;  /* Campo de tipo domicilio */
    char tel[15];   /* Teléfono */
} paciente;

void Lectura(paciente *, int);
void F1(paciente *, int);
void F2(paciente *, int);
void F3(paciente *, int);

int main(void) {
    paciente HOSPITAL[100];
    int TAM;

    do {
        printf("Ingrese el número de pacientes (1-50): ");
        scanf("%d", &TAM);
        fflush(stdin);
    } while (TAM > 50 || TAM < 1);

    Lectura(HOSPITAL, TAM);
    F1(HOSPITAL, TAM);
    F2(HOSPITAL, TAM);
    F3(HOSPITAL, TAM);

    return 0;
}

void Lectura(paciente A[], int T) {
    int I;
    for (I = 0; I < T; I++) {
        printf("\n\t\tPaciente %d\n", I + 1);

        fflush(stdin);
        printf("Nombre: ");
        fgets(A[I].nom, sizeof(A[I].nom), stdin);
        A[I].nom[strcspn(A[I].nom, "\n")] = '\0';  // Quitar salto de línea

        printf("Edad: ");
        scanf("%d", &A[I].edad);
        fflush(stdin);

        printf("Sexo (F-M): ");
        scanf("%c", &A[I].sexo);
        fflush(stdin);

        printf("Condición (1..5): ");
        scanf("%d", &A[I].con);
        fflush(stdin);

        printf("\tCalle: ");
        fgets(A[I].dom.cal, sizeof(A[I].dom.cal), stdin);
        A[I].dom.cal[strcspn(A[I].dom.cal, "\n")] = '\0';

        printf("\tNúmero: ");
        scanf("%d", &A[I].dom.num);
        fflush(stdin);

        printf("\tColonia: ");
        fgets(A[I].dom.col, sizeof(A[I].dom.col), stdin);
        A[I].dom.col[strcspn(A[I].dom.col, "\n")] = '\0';

        printf("\tCódigo Postal: ");
        fgets(A[I].dom.cp, sizeof(A[I].dom.cp), stdin);
        A[I].dom.cp[strcspn(A[I].dom.cp, "\n")] = '\0';

        printf("\tCiudad: ");
        fgets(A[I].dom.ciu, sizeof(A[I].dom.ciu), stdin);
        A[I].dom.ciu[strcspn(A[I].dom.ciu, "\n")] = '\0';

        printf("Teléfono: ");
        fgets(A[I].tel, sizeof(A[I].tel), stdin);
        A[I].tel[strcspn(A[I].tel, "\n")] = '\0';
    }
}

void F1(paciente A[], int T) {
    int I;
    int FEM = 0, MAS = 0;
    for (I = 0; I < T; I++) {
        switch (A[I].sexo) {
            case 'F':
            case 'f':
                FEM++;
                break;
            case 'M':
            case 'm':
                MAS++;
                break;
            default:
                break;
        }
    }
    int TOT = FEM + MAS;
    if (TOT > 0) {
        printf("\nPorcentaje de Hombres: %.2f%%", (float)MAS / TOT * 100);
        printf("\nPorcentaje de Mujeres: %.2f%%", (float)FEM / TOT * 100);
    } else {
        printf("\nNo hay datos de género válidos.");
    }
}

void F2(paciente A[], int T) {
    int I, C1 = 0, C2 = 0, C3 = 0, C4 = 0, C5 = 0;
    for (I = 0; I < T; I++) {
        switch (A[I].con) {
            case 1: C1++; break;
            case 2: C2++; break;
            case 3: C3++; break;
            case 4: C4++; break;
            case 5: C5++; break;
            default: break;
        }
    }
    printf("\nNúmero pacientes en condición 1: %d", C1);
    printf("\nNúmero pacientes en condición 2: %d", C2);
    printf("\nNúmero pacientes en condición 3: %d", C3);
    printf("\nNúmero pacientes en condición 4: %d", C4);
    printf("\nNúmero pacientes en condición 5: %d", C5);
}

void F3(paciente A[], int T) {
    int I;
    printf("\nPacientes ingresados en estado de gravedad (condición 5):\n");
    for (I = 0; I < T; I++) {
        if (A[I].con == 5)
            printf("Nombre: %s\tTeléfono: %s\n", A[I].nom, A[I].tel);
    }
}
