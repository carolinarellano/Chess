//
// Created by renis on 12/1/2022.
//

#ifndef SUPERCOOLCHESS_MOVEMENTS_H
#define SUPERCOOLCHESS_MOVEMENTS_H

#define WHITE_PAWN_IMAGE_PATH "assets/white_pawn.png"
#include <stdlib.h>
#include "Board.h"
#include "Assets.h"
#include "Files.h"
#include "Events.h"
#include "Movements.h"

Board GamePlay(Board board, Texture2D* textures, int step);
int CheckMateBlack(Board b);
int CheckMateWhite(Board b);
void Win(char* Winner);
int Draw(int draw_active);
Move* GenerateMoves(Move start, Board board, int* nm);
int CheckMove(Move* moves, int nm, Move move);
int IsWhite(int x, int y, Board board);
int IsBlack(int x, int y, Board board);
int IsEmpty(int x, int y, Board board);
char GetPiece(int x, int y, Board board);
int IsInBoard(int x, int y);
void Restart(Board board);


#endif //SUPERCOOLCHESS_MOVEMENTS_H
