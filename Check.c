//
// Created by Arlyn Linette Medina García on 04/12/22.
//
//No salio esta parte pero esta la idea :(
#include "Check.h"

//Posicion del rey que se actualizaria cada que se moviera
Move Bking_position = (Move) {0, 4};

//Compara si la pieza que se movio se pudiera comer al rey en la siguiente partida
int InCheckBlack(Move start, Board b, int nm)
{
    for (int i = 0; i < 8; i++){

    }
    Move* possible_moves = GenerateMoves(start, b, &nm);
    if (possible_moves->x == Bking_position.x && possible_moves->y == Bking_position.y)
    {
        printf("Jaque\n");
        return 1;
    }
    printf("No jaque\n");
    return 0;
}

//Obtiene la posicion de la pieza que se movio
Move GetMove(Move* moves, int nm, Move move) {
    for (int i = 0; i < nm; i++) {
        if ((moves + i)->x == move.x && (moves + i)->y == move.y){
            Move position = (Move) {(moves + i)->x,  (moves + i)->y};
            printf("%d", position.x);
            printf("%d", position.y);
            return position;
        }
    }
}