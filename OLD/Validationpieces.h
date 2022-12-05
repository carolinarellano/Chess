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
Coordinate* ValidateMovement(Board *b, Coordinate *current, Piece *p);
int InCheckWHITE(Board *b, Coordinate *wkingcoordinate);
int InCheckBLACK(Board *b, Coordinate *bkingcoordinate);


#endif //MAIN_C_VALIDATIONPIECES_H
