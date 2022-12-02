//
// Created by Arlyn Linette Medina García on 17/11/22.
//

#ifndef MAIN_C_VALIDATIONPIECES_H
#define MAIN_C_VALIDATIONPIECES_H

#include <stdlib.h>
#include <stdio.h>
#include "Board.h"
#include "Globals.h"

int GetPiece(int x, int y, Board *b);
int IsWhite(int x, int y, Board *b);
int IsBlack(int x, int y, Board *b);
int IsEmpty(int x, int y, Board *b);
int InBoard(int x, int y);
Coordinate* Movimiento(Board *b, Coordinate *current, Piece *p);


#endif //MAIN_C_VALIDATIONPIECES_H
