#include <stdio.h>
#include <stdlib.h>
char tablero[8][8] = {
    {'T','C','A','Q','K','A','C','T'},
    {'P','P','P','P','P','P','P','P'},
    {' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' '},
    {'p','p','p','p','p','p','p','p'},
    {'t','c','a','q','k','a','c','t'}
};

void imprimirTablero() {
    printf("   A B C D E F G H\n");
    for (int i = 0; i < 8; i++) {
        printf("%d  ", 8 - i);
        for (int j = 0; j < 8; j++) {
            printf("%c ", tablero[i][j]);
        }
        printf("\n");
    }
}

void moverPieza(int turno) {
    char origen[3], destino[3];
    int oFila, oCol, dFila, dCol;

    printf("Inserte la coordenada de origen (ej: E2): ");
    scanf("%2s", origen);
    printf("Inserte la coordenada de destino (ej: E4): ");
    scanf("%2s", destino);

    oCol = origen[0] - 'A';
    oFila = 8 - (origen[1] - '0');
    dCol = destino[0] - 'A';
    dFila = 8 - (destino[1] - '0');

    char pieza = tablero[oFila][oCol];

    if ((turno == 0 && pieza >= 'a' && pieza <= 'z') ||
        (turno == 1 && pieza >= 'A' && pieza <= 'Z')) {
        tablero[dFila][dCol] = pieza;
        tablero[oFila][oCol] = ' ';
    } else {
        printf("Movimiento invalido. No puedes mover esa pieza.\n");
    }
}

int main() {
    int opcion, turno = 0;
    while (1) {
        imprimirTablero();
        printf("Turno de las piezas %s.\n", turno == 0 ? "blancas" : "negras");
        printf("Opciones:\n1: Mover una pieza\n0: Rendirse\nIngrese un numero: ");
        scanf("%d", &opcion);

        if (opcion == 0) {
            printf("%s se rindio. Fin del juego.\n", turno == 0 ? "Blancas" : "Negras");
            break;
        } else if (opcion == 1) {
            moverPieza(turno);
            turno = 1 - turno;
        } else {
            printf("Opcion invalida.\n");
        }
    }
    return 0;
}
