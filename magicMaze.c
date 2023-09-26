#include <stdio.h>
#include "magicHeader.h"
//#include "magicFunctions.c"
#include <string.h>
#include <stdlib.h> 
#include <time.h>


#define NUM_ROWS 4
#define NUM_COLS 5
#define MAX_FILENAME_LENGTH 20

int main() {
    FILE *file;
    srand(time(NULL));
    struct tablero inicio;
    struct tablero mapa1;
    struct tablero mapa2;
    //struct tablero mapa3;
    //struct tablero mapa4;
    //struct tablero mapa5;
    //struct tablero mapa6;
    //struct tablero mapa7;
    //struct tablero mapa8;

    struct jugador jugador1;
    //struct jugador jugador2;
    //struct jugador jugador3;
    //struct jugador jugador4;

    jugador1.row = 0;
    jugador1.col = 2;
    strcpy(jugador1.number, "J1");

    //jugador2.row = 1;
    //jugador2.col = 3;
    //strcpy(jugador2.number, "J2");

    //jugador3.row = 3;
    //jugador3.col = 1;
    //strcpy(jugador3.number, "J3");

    //jugador4.row = 1;
    //jugador4.col = 3;
    //strcpy(jugador4.number, "J4");

    
    
    char mapData[NUM_ROWS][NUM_COLS][MAX_FILENAME_LENGTH] = {
        {"tablero1.txt","tablero2.txt","tablero4.txt","tablero7.txt","tablero8.txt"},
        {"tablero4.txt","tablero2.txt","tablero3.txt","tablero5.txt","tablero6.txt"},
        {"tablero1.txt","tablero2.txt","tablero3.txt","tablero5.txt","tablero8.txt"},
        {"tablero4.txt","tablero1.txt","tablero3.txt","tablero6.txt","tablero7.txt"},
    };

    for(int turno = 1; turno <= 1; turno++){
        file = fopen("Inicio.txt", "r");
         // Check if the file was successfully opened
        if (file == NULL) {
            perror("Error opening the file");
            return 1;
        }


        populateTablero(&inicio, file, turno);
        printTablero(&inicio);
        printf("--------------------------------------------\n");

        
        Bsearch(&jugador1, &mapa1, &mapData, turno);
        Bsearch(&jugador1, &mapa2, &mapData, turno);
        Bsearch(&jugador1, &mapa1, &mapData, turno);
        Bsearch(&jugador1, &mapa2, &mapData, turno);
        Bsearch(&jugador1, &mapa2, &mapData, turno);
        
        

        printf("--------\n");


          
        // Close the file
        fclose(file);
    
    }
    
    //cambiar a que la structura tablero almacene el struct jugador en la posicion 
    
    return 0;
}
