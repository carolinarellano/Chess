//
// Created by renis on 12/1/2022.
//

#ifndef SUPERCOOLCHESS_BOARD_H
#define SUPERCOOLCHESS_BOARD_H

#include "raylib.h"
#include "Structs.h"

#define BOARD_SIDE 8
#define EMPTY ' '
#define WHITE_PAWN 'P'
#define WHITE_KNIGHT 'N'
#define WHITE_BISHOP 'B'
#define WHITE_ROOK 'R'
#define WHITE_QUEEN 'Q'
#define WHITE_KING 'K'
#define BLACK_PAWN 'p'
#define BLACK_KNIGHT 'n'
#define BLACK_BISHOP 'b'
#define BLACK_ROOK 'r'
#define BLACK_QUEEN 'q'
#define BLACK_KING 'k'

Board InitBoard();
int LoadFenString(Board board, char* fen_string);
void PrintBoardOnTerminal(Board board);
void PrintBoard(Board board, Texture2D* textures);
void DestroyBoard(Board board);

#endif //SUPERCOOLCHESS_BOARD_H
