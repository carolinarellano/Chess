//
// Created by arell on 11/21/2022.
//

#ifndef SU_NOMBRE_DE_PROYECTO_GLOBALS_H
#define SU_NOMBRE_DE_PROYECTO_GLOBALS_H

#include "raylib.h"

enum Pieces {
    Empty,
    BPawn, BBishop,
    BKnight, BRook,
    BQueen, BKing,
    WPawn, WBishop,
    WKnight, WRook,
    WQueen, WKing};

typedef struct button_struct {
    Texture2D texture;
    Vector2 position;
    Rectangle mask;
    Rectangle collision;
    int status; // 1 if pressed, 0 if not
} Button;

typedef struct picture_struct {
    Texture2D texture; //image
    Rectangle source; //mask ?
    Vector2 position; //where to place the picture
} Picture;

typedef struct coordinate_struct {
    int x;
    int y;
} Coordinate;

typedef struct piece_struct {
    Picture piece;
    Coordinate *position; //last movement made
    int ID;
    int inGame; //is in the board 1, if is not 0
    int isSelected; //is selected 1, if is not 0 -> Collision
} Piece;

#endif //SU_NOMBRE_DE_PROYECTO_GLOBALS_H
