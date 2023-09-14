#ifndef magicHeader_H
#define magicHeader_H

#define ROWS 5
#define COLS 5
#define SIZE 3


struct jugador
{
    int row;
    int col;
    char number[2];
    char carta1[10];
    char carta2[10];
};

struct tablero
{
    int id;
    int data[ROWS][COLS][SIZE];
};


void moveRight(struct jugador, struct tablero);
void moveLeft(struct jugador, struct tablero);
void moveUp(struct jugador, struct tablero);
void moveDown(struct jugador, struct tablero);

void printTablero(struct tablero);


#endif