//
// Created by arell on 11/21/2022.
//

#ifndef MAIN_C_GRAPHICS_H
#define MAIN_C_GRAPHICS_H

#include "Board.h"
#include "Validationpieces.h"
#include "raylib.h"
#include "Globals.h"


typedef struct mouse_position{
    int x;
    int y;
}MousePosition;
//Struct que obtenga los valores de x y y de

void MainWindow();
void DrawGraphics(Texture2D BoardPNG, Texture2D PiecesPNG, Texture2D TransparentPNG);
//void Movement(Piece *Piece_to_move, Coordinate *Coordinate_to_arrive, void*(swap)(Board, void*, void*));
Coordinate* translation(Piece *p, int nx, int ny); //translates from matrix to pixels
int isAvailable(Piece Piece_to_move);


#endif //MAIN_C_GRAPHICS_H
