//
// Created by arell on 11/21/2022.
//

#ifndef MAIN_C_GRAPHICS_H
#define MAIN_C_GRAPHICS_H

#include "Board.h"
#include "Validationpieces.h"
#include "raylib.h"
#include "Globals.h"

void MainWindow();
void DrawGraphics(Texture2D BoardPNG, Texture2D PiecesPNG, Texture2D TransparentPNG);
void Movement(Piece *Piece_to_move, Piece *exchange, int x, int y, void*(swap)(Board, void*, void*));
int isAvailable(Piece Piece_to_move);


#endif //MAIN_C_GRAPHICS_H
