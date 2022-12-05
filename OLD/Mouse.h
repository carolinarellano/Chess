//
// Created by renis on 12/2/2022.
//

#ifndef CHESSFINAL_MOUSE_H
#define CHESSFINAL_MOUSE_H

#include "Board.h"
//#include "stdbool.h"

typedef struct Board board;

void Process(Board board);
int Click();
void GetPosition(int *x, int *y);

#endif //CHESSFINAL_MOUSE_H
