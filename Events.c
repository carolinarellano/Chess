//
// Created by renis on 12/1/2022.
//

#include "Events.h"
#include "raylib.h"
#include "Board.h"


//Obtiene la posicion del click dentro del board, si esta fuera del board, no lo detecta
bool PlayerClickedOnBoard() {
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        int mouse_x_pos = GetMouseX();
        int step = GetScreenHeight() / BOARD_SIDE;
        int start = (GetScreenWidth() - (step * 8)) / 2;
        return (mouse_x_pos > start && mouse_x_pos < GetScreenWidth() - start);
    }
    else {
        return false;
    }
}

//Obtiene las posiciones del board para comprobar que se este haciendo el click dentro
void GetBoardPosition(int* row, int* col) {
    int step = GetScreenHeight() / BOARD_SIDE;
    int start = (GetScreenWidth() - (step * 8)) / 2;
    int mouse_x_pos = GetMouseX();
    int mouse_y_pos = GetMouseY();
    mouse_x_pos -= start;
    *col = (mouse_x_pos / step);
    *row = (mouse_y_pos / step);
}
