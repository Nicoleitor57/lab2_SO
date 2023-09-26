#include "magicHeader.h"
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define NUM_ROWS 4
#define NUM_COLS 5
#define MAX_FILENAME_LENGTH 20

int randomIndex(int maxIndex){
    return rand() % (maxIndex);
};


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
    strcpy(tablero->data[row + 1][(col)], jugador->number);
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
    strcpy(tablero->data[row - 1][(col)], jugador->number);
    jugador->row++;
};

void removeFromAllArrays(char arr[][NUM_COLS][MAX_FILENAME_LENGTH], int numRows, int numCols, const char *itemToRemove, int removed[][NUM_COLS]) {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            if (!removed[i][j] && strcmp(arr[i][j], itemToRemove) == 0) {
                removed[i][j] = 1; // Mark the item as removed
            }
        }
    }
}

const char *selectRandomItem(char arr[][NUM_COLS][MAX_FILENAME_LENGTH], int numRows, int numCols, int removed[][NUM_COLS], int rowIndex) {
    if (rowIndex < 0 || rowIndex >= numRows) {
        return NULL; // Invalid row index
    }

    // Create an array to store indices of items in the row
    int indices[numCols];
    int numValidItems = 0;

    for (int j = 0; j < numCols; j++) {
        if (!removed[rowIndex][j]) {
            indices[numValidItems] = j;
            numValidItems++;
        }
    }

    if (numValidItems == 0) {
        return NULL; // No valid items left in the row
    }

    // Randomly select an index from the valid indices
    srand(time(NULL));
    int randomIndex = indices[rand() % numValidItems];

    const char *selectedItem = arr[rowIndex][randomIndex];
    removeFromAllArrays(arr, numRows, numCols, selectedItem, removed); // Remove it from all arrays

    return selectedItem;
}

const char *selectRandomItemFromRow(char fileNames[][NUM_COLS][MAX_FILENAME_LENGTH], int rowIndex) {
    static int numRows = NUM_ROWS;
    static int numCols = NUM_COLS;
    static int removed[NUM_ROWS][NUM_COLS] = {0}; // Initialize the removed flag array to all zeros

    return selectRandomItem(fileNames, numRows, numCols, removed, rowIndex);
}


//se define 0 como up,
//se define 1 como down
//se define 2 como left
//se define 3 como right
void Bsearch(struct jugador *jugador, struct tablero *tablero, char *mapData[NUM_ROWS][NUM_COLS][MAX_FILENAME_LENGTH], int turno){
    int row = jugador->row;
    int col = jugador->col;
    const char *newMap;
    FILE *file;
    
    if(row == 0){

        newMap = selectRandomItemFromRow(mapData,0);
        printf("%s\n",newMap);
        file = fopen(newMap, "r");
        if (file == NULL) {
            perror("Error opening the file");
            
        }

        populateTablero(tablero, file, turno);
        printTablero(tablero);
        fclose(file);
        
    }
    else if(row == 4){
        newMap = selectRandomItemFromRow(mapData,1);
        printf("%s\n",newMap);
        file = fopen(newMap, "r");
        if (file == NULL) {
            perror("Error opening the file");
            
        }

        populateTablero(tablero, file, turno);
        printTablero(tablero);
        fclose(file);

    }
    else if(col == 0){
        newMap = selectRandomItemFromRow(mapData,2);
        printf("%s\n",newMap);
        file = fopen(newMap, "r");
        if (file == NULL) {
            perror("Error opening the file");
            
        }

        populateTablero(tablero, file, turno);
        printTablero(tablero);
        fclose(file);

    }
    else if(col == 4){
        newMap = selectRandomItemFromRow(mapData,3);
        printf("%s\n",newMap);
        file = fopen(newMap, "r");
        if (file == NULL) {
            perror("Error opening the file");
            
        }

        populateTablero(tablero, file, turno);
        printTablero(tablero);
        fclose(file);

    }    

};

void populateTablero(struct tablero *tablero, FILE *filename, int turno){
    char cell[3];
    tablero->id = turno;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            fscanf(filename, "%s", cell); // Read a cell from the file
            strcpy(tablero->data[i][j], cell); // Store the cell in the matrix
        }
    }
};


void printTablero(struct tablero *tablero){
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%s ", tablero->data[i][j]);
        }
        printf("\n");
    }
};
