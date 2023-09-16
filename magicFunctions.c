#include "magicHeader.h"
#include <stdio.h>
#include <string.h>

void moveRight(struct jugador *jugador, struct tablero *tablero){
    int row = jugador->row;
    int col = jugador->col;
    strcpy(tablero->data[row][col], "0");
    strcpy(tablero->data[row][(col + 1)], jugador->number);
    jugador->col++;
};

void moveDown(struct jugador *jugador, struct tablero *tablero){
    int row = jugador->row;
    int col = jugador->col;
    strcpy(tablero->data[row][col], "0");
    strcpy(tablero->data[row - 1][(col)], jugador->number);
    jugador->row++;
};

void moveLeft(struct jugador *jugador, struct tablero *tablero){
    int row = jugador->row;
    int col = jugador->col;
    strcpy(tablero->data[row][col], "0");
    strcpy(tablero->data[row][(col - 1)], jugador->number);
    jugador->col--;
};

void moveUp(struct jugador *jugador, struct tablero *tablero){
    int row = jugador->row;
    int col = jugador->col;
    strcpy(tablero->data[row][col], "0");
    strcpy(tablero->data[row + 1][(col)], jugador->number);
    jugador->row++;
};


void printTablero(struct tablero *tablero){
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%s ", tablero->data[i][j]);
        }
        printf("\n");
    }
};
