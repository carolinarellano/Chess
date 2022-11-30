//
// Created by Arlyn Linette Medina García on 18/11/22.
//

#include "Board.h"

Board* create_board()
{
    Board *new = malloc(sizeof(Board));
    char tablero[8][8] = {{BRook, BKnight, BBishop, BQueen, BKing, BBishop, BKnight, BRook},
                          {BPawn, BPawn, BPawn, BPawn, BPawn, BPawn, BPawn, BPawn},
                          {Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty},
                          {Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty},
                          {Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty},
                          {Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty},
                          {WPawn, WPawn, WPawn, WPawn, WPawn, WPawn, WPawn, WPawn},
                          {WRook, WKnight, WBishop, WQueen, WKing, WBishop, WKnight, WRook}};

    memccpy(new->tablero, tablero, 1, sizeof(Board));
    return new;
};

int is_empty(Board *board)
{
    int count = 0;
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        if(board->tablero[i][j] == 0)
            count++;
    }
    if(count == 64)
        return 1;
    return 0;
};



