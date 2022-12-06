//
// Created by renis on 12/1/2022.
//
#include "Files.h"
#include <stdlib.h>
#include <stdio.h>
#include "raylib.h"

#define MAX_LINE_SIZE 255
FILE *fptr = NULL;

//Guarda el juego en una FEN String en la posicion actual (al dar save) y al salir (usando escape) se escribe la posicion inicial del tablero
int SaveGame(Board b)
{
    fptr = fopen("../Chess", "w");

    if(IsKeyPressed(KEY_ESCAPE))
    {
        char* new = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
        fprintf(fptr, "%s", new);
    }

    int empty = 1;
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            if((*(*(b + row) + col)) == ' '){
                fprintf(fptr, "%d", empty);
            }else{
                fprintf(fptr, "%c", *(*(b + row) + col));
            }
        }
        fprintf(fptr, "/");
    }
    exit(0);
};

//Lee el archivo de texto y obtiene la FEN String del juego
char* LoadGame()
{
    char loaded[MAX_LINE_SIZE];
    FILE *descriptor_de_archivo = NULL;
    descriptor_de_archivo = fopen("../Chess", "r");

    if(descriptor_de_archivo == NULL)
    {
        printf("no se pudo abrir el archivo\n");
        exit(12);
    }

    char* text = fgets(loaded, MAX_LINE_SIZE, descriptor_de_archivo);

    return text;
};