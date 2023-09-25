#ifndef magicHeader_H
#define magicHeader_H

#define ROWS 5
#define COLS 5
#define SIZE 3

#define NUM_ROWS 4
#define NUM_COLS 5
#define MAX_FILENAME_LENGTH 20


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
    char data[ROWS][COLS][SIZE];
};

int randomIndex(int maxIndex);

void moveRight(struct jugador *jugador, struct tablero *tablero);
void moveLeft(struct jugador *jugador, struct tablero *tablero);
void moveUp(struct jugador *jugador, struct tablero *tablero);
void moveDown(struct jugador *jugador, struct tablero *tablero);

void removeFromAllArrays(char arr[][NUM_COLS][MAX_FILENAME_LENGTH], int numRows, int numCols, const char *itemToRemove, int removed[][NUM_COLS]);
const char *selectRandomItem(char arr[][NUM_COLS][MAX_FILENAME_LENGTH], int numRows, int numCols, int removed[][NUM_COLS], int rowIndex);
const char *selectRandomItemFromRow(char fileNames[][NUM_COLS][MAX_FILENAME_LENGTH], int rowIndex);
void Bsearch(struct jugador *jugador, struct tablero *tablero,char *(*mapData)[5], int turno);


void populateTablero(struct tablero *tablero, const char *filename, int turno);
void printTablero(struct tablero *tablero);


#endif
