//
// Created by Arlyn Linette Medina García on 04/12/22.
//

#ifndef MAIN_C_CHECK_H
#define MAIN_C_CHECK_H
#include "Movements.h"

Move GetMove(Move* moves, int nm, Move move);
int InCheckBlack(Move start, Board b, int nm);
#endif //MAIN_C_CHECK_H
