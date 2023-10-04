#include <stdio.h>
#include "magicHeader.h"
//#include "magicFunctions.c"
#include <string.h>
#include <stdlib.h> 
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


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

    file = fopen("Inicio.txt", "r");
        // Check if the file was successfully opened
    if (file == NULL) {
        perror("Error opening the file");
        return 1;
    }
    
    int turnos = 15;
    for(int turno = 1; turno <=turnos; turno++){
        pid_t child_pid;
        
        // Father process
        printf("Cycle %d:\n", turno);
        fatherTask();
        
        // Child 1
        child_pid = fork();
        if (child_pid == 0) {
            child1Task();
            return 0; // Terminate child 1
        } else if (child_pid < 0) {
            perror("Fork failed");
            return 1;
        }
        
        // Child 2
        child_pid = fork();
        if (child_pid == 0) {
            child2Task();
            return 0; // Terminate child 2
        } else if (child_pid < 0) {
            perror("Fork failed");
            return 1;
        }
        
        // Child 3
        child_pid = fork();
        if (child_pid == 0) {
            child3Task();
            return 0; // Terminate child 3
        } else if (child_pid < 0) {
            perror("Fork failed");
            return 1;
        }
        
        // Parent waits for all children to finish
        for (int i = 0; i < 3; i++) {
            int status;
            wait(&status);
        }
    }
    


    populateTablero(&inicio, file, turno);
    printTablero(&inicio);
    fclose(file);
    printf("--------------------------------------------\n");
    Bsearch(&jugador1, &mapa1, &mapData, turno);
    printf("--------\n");

    
    
    
    //cambiar a que la structura tablero almacene el struct jugador en la posicion 
    
    return 0;
}
