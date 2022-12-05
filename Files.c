//
// Created by renis on 12/1/2022.
//
#include "Files.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_LINE_SIZE 255
FILE *fptr = NULL;

void SaveGame(Board b)
{
    fptr = fopen("../Chess", "w");
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            fprintf(fptr, " %c ", *(*(b + row) + col));
        }
        fprintf(fptr, "\n");
    }
    printf("Game Saved");
    exit(12);
};

Board LoadGame()
{
    Board loaded = calloc(1, sizeof(Board));
    FILE *descriptor_de_archivo = NULL;
    descriptor_de_archivo = fopen("../Chess", "r");

    if(descriptor_de_archivo == NULL)
    {
        printf("no se pudo abrir el archivo\n");
    }

    char buffer[MAX_LINE_SIZE];

    while (fgets(buffer, MAX_LINE_SIZE, descriptor_de_archivo) != NULL)
    {
        printf("%s", buffer);
        memcpy(loaded, buffer, sizeof(Board));
    }
    return loaded;
};