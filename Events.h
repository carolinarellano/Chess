//
// Created by renis on 12/1/2022.
//

#ifndef SUPERCOOLCHESS_EVENTS_H
#define SUPERCOOLCHESS_EVENTS_H
#include "Board.h"

void ProcessEvents(Board board);
bool PlayerClickedOnBoard();
void GetBoardPosition(int* row, int* col);

#endif //SUPERCOOLCHESS_EVENTS_H
