//
// Created by renis on 12/2/2022.
//

#include "Mouse.h"
//#include "Board.h"
#include "raylib.h"
#include "stdbool.h" //libreria para poder usar el tipo de dato bool.

typedef struct Board board;

void Process(Board board) {
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        int side = 336 / 8; //Side es el tamaño de l de cada cuadrado.
        int start = (336 - (side * 8)) / 2; //Este es para centrar el tablero en la ventana.

        int x_mouse_position = GetMouseX(); //Funciones de raylib lol
        int y_mouse_position = GetMouseY(); //Funciones de raylib lol

    }
}

int Click(){
    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        int x_mouse_position = GetMouseX();
        int side = 336 / 8; //8 porque son 8 cuadrados tanto de rows como de columns
        int start = (336 - (side * 8)) / 2;
        return (x_mouse_position > start && x_mouse_position < GetScreenWidth() - start); //Checa que el click este dentro de la ventana (que sea valido).
    }
    else{
        return 0;
    }
    return 1;
}

void GetPosition(int *x, int *y){
    int side = 336 / 8;
    int start = (336 - (side * 8)) / 2;

    int x_mouse_position = GetMouseX();
    int y_mouse_position = GetMouseY();

    x_mouse_position -= start;

    *x = (x_mouse_position / side);
    *y = (y_mouse_position / side);
}
