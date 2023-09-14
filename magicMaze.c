#include <stdio.h>
#include "magicHeader.h"
#include <string.h>

int main() {
    FILE *file;
    char cell[3]; // To accommodate two-character cells and a null terminator
    struct tablero inicio;
    
    // Open the file for reading
    file = fopen("Inicio.txt", "r");
    
    // Check if the file was successfully opened
    if (file == NULL) {
        perror("Error opening the file");
        return 1;
    }
    
    // Read and populate the matrix
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            fscanf(file, "%s", cell); // Read a cell from the file
            strcpy(inicio.data[i][j], cell); // Store the cell in the matrix
        }
    }
    
    // Close the file
    fclose(file);
    
    // Print the matrix (for verification)
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%s ", inicio.data[i][j]);
        }
        printf("\n");
    }

    struct jugador jugador1;

    jugador1.row = 1;
    jugador1.col = 1;
    strcpy(jugador1.number, "J1");

    moveRight(jugador1, inicio);

    printTablero(inicio);

    //cambiar a que la structura tablero almacene el struct jugador en la posicion 





    
    
    return 0;
}
