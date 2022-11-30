//
// Created by Arlyn Linette Medina García on 17/11/22.
//

#include "Validationpieces.h"
#include "Board.h"

typedef struct{
    int x;
    int y;
}Movimientos;

int GetPiece(int x, int y, Board *board)
{
    return board->tablero[x][y];
}

int IsWhite(int x, int y, Board *board){
    if (GetPiece(x, y, board) == WPawn || GetPiece(x, y, board) == WKnight || GetPiece(x, y, board) == WQueen ||
        GetPiece(x, y, board) == WKing || GetPiece(x, y, board) == WBishop || GetPiece(x, y, board) == WRook)
        return 1;
    return 0;
}

int IsBlack(int x, int y, Board *board){
    if (GetPiece(x, y, board) == BPawn || GetPiece(x, y, board) == BKnight || GetPiece(x, y, board) == BQueen ||
        GetPiece(x, y, board) == BKing || GetPiece(x, y, board) == BBishop || GetPiece(x, y, board) == BRook)
        return 1;
    return 0;
}

int IsEmpty(int x, int y, Board *board){
    return (GetPiece(x, y, board) == Empty);
}

int InBoard(int x, int y){
    return (x <8 && x>-1 && y >-1 && y<8);
}

Movimientos* ValidarMovimientos(Movimientos comienzo, Board *board, int *temporal){
    *temporal = 0;
    Movimientos *posibles = NULL;
    if (IsBlack(comienzo.x, comienzo.y, board)) {
        switch (GetPiece(comienzo.x, comienzo.y, board)) {
            case BPawn: {
                //Dos movimientos al frente
                posibles = malloc(sizeof(Movimientos) * 4); //PORQUEEEE
                if (comienzo.y == 1 && IsEmpty(comienzo.x, comienzo.y + 2, board) &&
                    IsEmpty(comienzo.x, comienzo.y + 1, board)) {
                    *(posibles + *temporal) = (Movimientos) {comienzo.x, comienzo.y + 2};
                    (*temporal)++;
                }

                //Un movimiento al frente
                if (IsEmpty(comienzo.x, comienzo.y + 1, board) && InBoard(comienzo.x, comienzo.y + 1)) {
                    *(posibles + *temporal) = (Movimientos) {comienzo.x, comienzo.y + 1};
                    (*temporal)++;
                }

                //Comer en diagonal hacia la derecha
                if (IsWhite(comienzo.x + 1, comienzo.y + 1, board) && InBoard(comienzo.x + 1, comienzo.y + 1)) {
                    *(posibles + *temporal) = (Movimientos) {comienzo.x + 1, comienzo.y + 1};
                    (*temporal)++;
                }

                //Comer en diagonal hacia la izquierda
                if (IsWhite(comienzo.x - 1, comienzo.y + 1, board) && InBoard(comienzo.x - 1, comienzo.y + 1)) {
                    *(posibles + *temporal) = (Movimientos) {comienzo.x - 1, comienzo.y + 1}; //Como cambiar esto
                    (*temporal)++; //Que es temporal????
                }
            }
                break;
            case BRook: {
                posibles = malloc(sizeof(Movimientos) * 16);
                //Moverse a la derecha
                for (int i = comienzo.x + 1; InBoard(i, comienzo.y) && !IsBlack(i, comienzo.y, board); i++) {
                    *(posibles + *temporal) = (Movimientos) {i, comienzo.y};
                    (*temporal)++;
                    if (IsWhite(i, comienzo.y, board))
                        break;
                }
                //Moverse a la derecha
                for (int i = comienzo.x - 1; InBoard(i, comienzo.y) && !IsBlack(i, comienzo.y, board); i--) {
                    *(posibles + *temporal) = (Movimientos) {i, comienzo.y};
                    (*temporal)++;
                    if (IsWhite(i, comienzo.y, board))
                        break;
                }
                //Moverse abajo
                for (int i = comienzo.y + 1; InBoard(comienzo.x, i) && !IsBlack(comienzo.x, i, board); i++) {
                    *(posibles + *temporal) = (Movimientos) {comienzo.x, i};
                    (*temporal)++;
                    if (IsWhite(comienzo.x, i, board))
                        break;
                }
                //Moverse arriba
                for (int i = comienzo.y - 1; InBoard(comienzo.x, i) && !IsBlack(comienzo.x, i, board); i--) {
                    *(posibles + *temporal) = (Movimientos) {comienzo.x, i};
                    (*temporal)++;
                    if (IsWhite(comienzo.x, i, board))
                        break;
                }
            }
                break;
            case BBishop: {
                posibles = malloc(sizeof(Movimientos) * 16);
                //Moverse abajo/derecha
                for (int i = comienzo.x + 1, j = comienzo.y + 1; InBoard(i, j) && !IsBlack(i, i, board); i++, j++) {
                    *(posibles + *temporal) = (Movimientos) {i, j};
                    (*temporal)++;
                    if (IsWhite(i, j, board))
                        break;
                }
                //Moverse abajo/izquierda
                for (int i = comienzo.x - 1, j = comienzo.y + 1; InBoard(i, j) && !IsBlack(i, i, board); i--, j++) {
                    *(posibles + *temporal) = (Movimientos) {i, j};
                    (*temporal)++;
                    if (IsWhite(i, j, board))
                        break;
                }
                //Moverse arriba/derecha
                for (int i = comienzo.x + 1, j = comienzo.y - 1; InBoard(i, j) && !IsBlack(i, i, board); i++, j--) {
                    *(posibles + *temporal) = (Movimientos) {i, j};
                    (*temporal)++;
                    if (IsWhite(i, j, board))
                        break;
                }
                //Moverse arriba/izquierda
                for (int i = comienzo.x - 1, j = comienzo.y - 1; InBoard(i, j) && !IsBlack(i, i, board); i--, j--) {
                    *(posibles + *temporal) = (Movimientos) {i, j};
                    (*temporal)++;
                    if (IsWhite(i, j, board))
                        break;
                }
            }
                break;
            case BQueen: {
                posibles = malloc(sizeof(Movimientos) * 32);
                //Moverse abajo/derecha
                for (int i = comienzo.x + 1, j = comienzo.y + 1; InBoard(i, j) && !IsBlack(i, i, board); i++, j++) {
                    *(posibles + *temporal) = (Movimientos) {i, j};
                    (*temporal)++;
                    if (IsWhite(i, j, board))
                        break;
                }
                //Moverse abajo/izquierda
                for (int i = comienzo.x - 1, j = comienzo.y + 1; InBoard(i, j) && !IsBlack(i, i, board); i--, j++) {
                    *(posibles + *temporal) = (Movimientos) {i, j};
                    (*temporal)++;
                    if (IsWhite(i, j, board))
                        break;
                }
                //Moverse arriba/derecha
                for (int i = comienzo.x + 1, j = comienzo.y - 1; InBoard(i, j) && !IsBlack(i, i, board); i++, j--) {
                    *(posibles + *temporal) = (Movimientos) {i, j};
                    (*temporal)++;
                    if (IsWhite(i, j, board))
                        break;
                }
                //Moverse arriba/izquierda
                for (int i = comienzo.x - 1, j = comienzo.y - 1; InBoard(i, j) && !IsBlack(i, i, board); i--, j--) {
                    *(posibles + *temporal) = (Movimientos) {i, j};
                    (*temporal)++;
                    if (IsWhite(i, j, board))
                        break;
                }
                //Moverse a la derecha
                for (int i = comienzo.x + 1; InBoard(i, comienzo.y) && !IsBlack(i, comienzo.y, board); i++) {
                    *(posibles + *temporal) = (Movimientos) {i, comienzo.y};
                    (*temporal)++;
                    if (IsWhite(i, comienzo.y, board))
                        break;
                }
                //Moverse a la izquierda
                for (int i = comienzo.x - 1; InBoard(i, comienzo.y) && !IsBlack(i, comienzo.y, board); i--) {
                    *(posibles + *temporal) = (Movimientos) {i, comienzo.y};
                    (*temporal)++;
                    if (IsWhite(i, comienzo.y, board))
                        break;
                }
                //Moverse hacia abajo
                for (int i = comienzo.y + 1; InBoard(comienzo.x, i) && !IsBlack(comienzo.x, i, board); i++) {
                    *(posibles + *temporal) = (Movimientos) {comienzo.x, i};
                    (*temporal)++;
                    if (IsWhite(comienzo.x, i, board))
                        break;
                }
                //Moverse hacia arriba
                for (int i = comienzo.y - 1; InBoard(comienzo.x, i) && !IsBlack(comienzo.x, i, board); i--) {
                    *(posibles + *temporal) = (Movimientos) {comienzo.x, i};
                    (*temporal)++;
                    if (IsWhite(comienzo.x, i, board))
                        break;
                }
            }
                break;
            case BKing: {
                posibles = malloc(sizeof(Movimientos) * 8);
                //Que es lo que hace esto jeje
                for (int y = -1; y <= 1; y++) {
                    for (int x = -1; y <= 1; x++) {
                        if (!(x == 0 && y == 0)) {
                            if (InBoard(comienzo.x + x, comienzo.y + y) &&
                                !IsBlack(comienzo.x + x, comienzo.y + y, board)) {
                                *(posibles + *temporal) = (Movimientos) {comienzo.x + x, comienzo.y + y};
                                (*temporal)++;
                            }
                        }

                    }
                }
            }
                break;
            case BKnight: {
                posibles = malloc(sizeof(Movimientos) * 8);
                //Posiciones Superiores
                if (InBoard(comienzo.x + 1, comienzo.y - 2) && !IsBlack(comienzo.x + 1, comienzo.y - 2, board)) {
                    *(posibles + *temporal) = (Movimientos) {comienzo.x + 1, comienzo.y - 2};
                    (*temporal)++;
                }
                if (InBoard(comienzo.x - 1, comienzo.y - 2) && !IsBlack(comienzo.x - 1, comienzo.y - 2, board)) {
                    *(posibles + *temporal) = (Movimientos) {comienzo.x - 1, comienzo.y - 2};
                    (*temporal)++;
                }
                //Posiciones Inferiores
                if (InBoard(comienzo.x + 1, comienzo.y + 2) && !IsBlack(comienzo.x + 1, comienzo.y + 2, board)) {
                    *(posibles + *temporal) = (Movimientos) {comienzo.x + 1, comienzo.y + 2};
                    (*temporal)++;
                }
                if (InBoard(comienzo.x - 1, comienzo.y + 2) && !IsBlack(comienzo.x - 1, comienzo.y + 2, board)) {
                    *(posibles + *temporal) = (Movimientos) {comienzo.x - 1, comienzo.y + 2};
                    (*temporal)++;
                }
                //Posiciones de la Derecha
                if (InBoard(comienzo.x + 2, comienzo.y - 1) && !IsBlack(comienzo.x + 2, comienzo.y - 1, board)) {
                    *(posibles + *temporal) = (Movimientos) {comienzo.x + 2, comienzo.y - 1};
                    (*temporal)++;
                }
                if (InBoard(comienzo.x + 2, comienzo.y + 1) && !IsBlack(comienzo.x + 2, comienzo.y + 1, board)) {
                    *(posibles + *temporal) = (Movimientos) {comienzo.x + 2, comienzo.y + 1};
                    (*temporal)++;
                }
                //Posiciones de la Izquierda
                if (InBoard(comienzo.x - 2, comienzo.y - 1) && !IsBlack(comienzo.x - 2, comienzo.y - 1, board)) {
                    *(posibles + *temporal) = (Movimientos) {comienzo.x - 2, comienzo.y - 1};
                    (*temporal)++;
                }
                if (InBoard(comienzo.x - 2, comienzo.y + 1) && !IsBlack(comienzo.x - 2, comienzo.y + 1, board)) {
                    *(posibles + *temporal) = (Movimientos) {comienzo.x - 2, comienzo.y + 1};
                    (*temporal)++;
                }
            }
                break;
            default: {
                posibles = malloc(sizeof(Movimientos));
                *posibles = (Movimientos) {comienzo.x, comienzo.y + 1};
                *temporal = 1;
            }
        }
    }
    else{
        switch (GetPiece(comienzo.x, comienzo.y, board)){
            case WPawn: {
                //Dos movimientos al frente
                posibles = malloc(sizeof(Movimientos) * 4); //PORQUEEEE
                if (comienzo.y == 6 && IsEmpty(comienzo.x, comienzo.y - 2, board) &&
                    IsEmpty(comienzo.x, comienzo.y - 1, board)) {
                    *(posibles + *temporal) = (Movimientos) {comienzo.x, comienzo.y - 2};
                    (*temporal)++;
                }

                //Un movimiento al frente
                if (IsEmpty(comienzo.x, comienzo.y - 1, board) && InBoard(comienzo.x, comienzo.y - 1)) {
                    *(posibles + *temporal) = (Movimientos) {comienzo.x, comienzo.y - 1};
                    (*temporal)++;
                }

                //Comer en diagonal hacia la derecha
                if (IsBlack(comienzo.x + 1, comienzo.y - 1, board) && InBoard(comienzo.x + 1, comienzo.y - 1)) {
                    *(posibles + *temporal) = (Movimientos) {comienzo.x + 1, comienzo.y - 1};
                    (*temporal)++;
                }

                //Comer en diagonal hacia la izquierda
                if (IsBlack(comienzo.x - 1, comienzo.y - 1, board) && InBoard(comienzo.x - 1, comienzo.y - 1)) {
                    *(posibles + *temporal) = (Movimientos) {comienzo.x - 1, comienzo.y - 1}; //Como cambiar esto
                    (*temporal)++; //Que es temporal????
                }
            }
                break;
            case WRook: {
                posibles = malloc(sizeof(Movimientos) * 16);
                //Moverse a la derecha
                for (int i = comienzo.x + 1; InBoard(i, comienzo.y) && !IsWhite(i, comienzo.y, board); i++) {
                    *(posibles + *temporal) = (Movimientos) {i, comienzo.y};
                    (*temporal)++;
                    if (IsBlack(i, comienzo.y, board))
                        break;
                }
                //Moverse a la derecha
                for (int i = comienzo.x - 1; InBoard(i, comienzo.y) && !IsWhite(i, comienzo.y, board); i--) {
                    *(posibles + *temporal) = (Movimientos) {i, comienzo.y};
                    (*temporal)++;
                    if (IsBlack(i, comienzo.y, board))
                        break;
                }
                //Moverse abajo
                for (int i = comienzo.y + 1; InBoard(comienzo.x, i) && !IsWhite(comienzo.x, i, board); i++) {
                    *(posibles + *temporal) = (Movimientos) {comienzo.x, i};
                    (*temporal)++;
                    if (IsBlack(comienzo.x, i, board))
                        break;
                }
                //Moverse arriba
                for (int i = comienzo.y - 1; InBoard(comienzo.x, i) && !IsWhite(comienzo.x, i, board); i--) {
                    *(posibles + *temporal) = (Movimientos) {comienzo.x, i};
                    (*temporal)++;
                    if (IsBlack(comienzo.x, i, board))
                        break;
                }
            }
                break;
            case WBishop: {
                posibles = malloc(sizeof(Movimientos) * 16);
                //Moverse abajo/derecha
                for (int i = comienzo.x + 1, j = comienzo.y + 1; InBoard(i, j) && !IsWhite(i, i, board); i++, j++) {
                    *(posibles + *temporal) = (Movimientos) {i, j};
                    (*temporal)++;
                    if (IsBlack(i, j, board))
                        break;
                }
                //Moverse abajo/izquierda
                for (int i = comienzo.x - 1, j = comienzo.y + 1; InBoard(i, j) && !IsWhite(i, i, board); i--, j++) {
                    *(posibles + *temporal) = (Movimientos) {i, j};
                    (*temporal)++;
                    if (IsBlack(i, j, board))
                        break;
                }
                //Moverse arriba/derecha
                for (int i = comienzo.x + 1, j = comienzo.y - 1; InBoard(i, j) && !IsWhite(i, i, board); i++, j--) {
                    *(posibles + *temporal) = (Movimientos) {i, j};
                    (*temporal)++;
                    if (IsBlack(i, j, board))
                        break;
                }
                //Moverse arriba/izquierda
                for (int i = comienzo.x - 1, j = comienzo.y - 1; InBoard(i, j) && !IsWhite(i, i, board); i--, j--) {
                    *(posibles + *temporal) = (Movimientos) {i, j};
                    (*temporal)++;
                    if (IsBlack(i, j, board))
                        break;
                }
            }
                break;
            case WQueen: {
                posibles = malloc(sizeof(Movimientos) * 32);
                //Moverse abajo/derecha
                for (int i = comienzo.x + 1, j = comienzo.y + 1; InBoard(i, j) && !IsWhite(i, i, board); i++, j++) {
                    *(posibles + *temporal) = (Movimientos) {i, j};
                    (*temporal)++;
                    if (IsBlack(i, j, board))
                        break;
                }
                //Moverse abajo/izquierda
                for (int i = comienzo.x - 1, j = comienzo.y + 1; InBoard(i, j) && !IsWhite(i, i, board); i--, j++) {
                    *(posibles + *temporal) = (Movimientos) {i, j};
                    (*temporal)++;
                    if (IsBlack(i, j, board))
                        break;
                }
                //Moverse arriba/derecha
                for (int i = comienzo.x + 1, j = comienzo.y - 1; InBoard(i, j) && !IsWhite(i, i, board); i++, j--) {
                    *(posibles + *temporal) = (Movimientos) {i, j};
                    (*temporal)++;
                    if (IsBlack(i, j, board))
                        break;
                }
                //Moverse arriba/izquierda
                for (int i = comienzo.x - 1, j = comienzo.y - 1; InBoard(i, j) && !IsWhite(i, i, board); i--, j--) {
                    *(posibles + *temporal) = (Movimientos) {i, j};
                    (*temporal)++;
                    if (IsBlack(i, j, board))
                        break;
                }
                //Moverse a la derecha
                for (int i = comienzo.x + 1; InBoard(i, comienzo.y) && !IsWhite(i, comienzo.y, board); i++) {
                    *(posibles + *temporal) = (Movimientos) {i, comienzo.y};
                    (*temporal)++;
                    if (IsBlack(i, comienzo.y, board))
                        break;
                }
                //Moverse a la izquierda
                for (int i = comienzo.x - 1; InBoard(i, comienzo.y) && !IsWhite(i, comienzo.y, board); i--) {
                    *(posibles + *temporal) = (Movimientos) {i, comienzo.y};
                    (*temporal)++;
                    if (IsBlack(i, comienzo.y, board))
                        break;
                }
                //Moverse hacia abajo
                for (int i = comienzo.y + 1; InBoard(comienzo.x, i) && !IsWhite(comienzo.x, i, board); i++) {
                    *(posibles + *temporal) = (Movimientos) {comienzo.x, i};
                    (*temporal)++;
                    if (IsBlack(comienzo.x, i, board))
                        break;
                }
                //Moverse hacia arriba
                for (int i = comienzo.y - 1; InBoard(comienzo.x, i) && !IsWhite(comienzo.x, i, board); i--) {
                    *(posibles + *temporal) = (Movimientos) {comienzo.x, i};
                    (*temporal)++;
                    if (IsBlack(comienzo.x, i, board))
                        break;
                }
            }
                break;
            case WKing: {
                posibles = malloc(sizeof(Movimientos) * 8);
                //Que es lo que hace esto jeje
                for (int y = -1; y <= 1; y++) {
                    for (int x = -1; y <= 1; x++) {
                        if (!(x == 0 && y == 0)) {
                            if (InBoard(comienzo.x + x, comienzo.y + y) &&
                                !IsWhite(comienzo.x + x, comienzo.y + y, board)) {
                                *(posibles + *temporal) = (Movimientos) {comienzo.x + x, comienzo.y + y};
                                (*temporal)++;
                            }
                        }

                    }
                }
                break;
                case WKnight: {
                    posibles = malloc(sizeof(Movimientos) * 8);
                    //Posiciones Superiores
                    if (InBoard(comienzo.x + 1, comienzo.y - 2) && !IsWhite(comienzo.x + 1, comienzo.y - 2, board)) {
                        *(posibles + *temporal) = (Movimientos) {comienzo.x + 1, comienzo.y - 2};
                        (*temporal)++;
                    }
                    if (InBoard(comienzo.x - 1, comienzo.y - 2) && !IsWhite(comienzo.x - 1, comienzo.y - 2, board)) {
                        *(posibles + *temporal) = (Movimientos) {comienzo.x - 1, comienzo.y - 2};
                        (*temporal)++;
                    }
                    //Posiciones Inferiores
                    if (InBoard(comienzo.x + 1, comienzo.y + 2) && !IsWhite(comienzo.x + 1, comienzo.y + 2, board)) {
                        *(posibles + *temporal) = (Movimientos) {comienzo.x + 1, comienzo.y + 2};
                        (*temporal)++;
                    }
                    if (InBoard(comienzo.x - 1, comienzo.y + 2) && !IsWhite(comienzo.x - 1, comienzo.y + 2, board)) {
                        *(posibles + *temporal) = (Movimientos) {comienzo.x - 1, comienzo.y + 2};
                        (*temporal)++;
                    }
                    //Posiciones de la Derecha
                    if (InBoard(comienzo.x + 2, comienzo.y - 1) && !IsWhite(comienzo.x + 2, comienzo.y - 1, board)) {
                        *(posibles + *temporal) = (Movimientos) {comienzo.x + 2, comienzo.y - 1};
                        (*temporal)++;
                    }
                    if (InBoard(comienzo.x + 2, comienzo.y + 1) && !IsWhite(comienzo.x + 2, comienzo.y + 1, board)) {
                        *(posibles + *temporal) = (Movimientos) {comienzo.x + 2, comienzo.y + 1};
                        (*temporal)++;
                    }
                    //Posiciones de la Izquierda
                    if (InBoard(comienzo.x - 2, comienzo.y - 1) && !IsWhite(comienzo.x - 2, comienzo.y - 1, board)) {
                        *(posibles + *temporal) = (Movimientos) {comienzo.x - 2, comienzo.y - 1};
                        (*temporal)++;
                    }
                    if (InBoard(comienzo.x - 2, comienzo.y + 1) && !IsWhite(comienzo.x - 2, comienzo.y + 1, board)) {
                        *(posibles + *temporal) = (Movimientos) {comienzo.x - 2, comienzo.y + 1};
                        (*temporal)++;
                    }
                }
                break;
                default: {
                    posibles = malloc(sizeof(Movimientos));
                    *posibles = (Movimientos) {comienzo.x, comienzo.y -1};
                    *temporal = 1;
                }
            }
        }
    }
    return posibles;
}