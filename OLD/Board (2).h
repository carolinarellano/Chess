//
// Created by Arlyn Linette Medina García on 18/11/22.
//

#ifndef MAIN_C_BOARD_H
#define MAIN_C_BOARD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "raylib.h"
#include "Globals.h"

typedef struct board
{
    int tablero[8][8];
} Board;

Board* create_board();
int is_empty(Board *board);

#endif //MAIN_C_BOARD_H
