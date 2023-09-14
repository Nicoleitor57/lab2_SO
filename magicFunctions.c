#include "magicHeader.h"
#include <stdio.h>
#include <string.h>

void moveRight(struct jugador *jugador, struct tablero *tablero){
    int row = jugador->row;
    int col = jugador->col;
    tablero->data[row][col][3] = 0;
    tablero->data[row][col + 1][3] = jugador->number;
    jugador->col++;
}

void printTablero(struct tablero *tablero){
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%s ", tablero->data[i][j]);
        }
        printf("\n");
    }
}