//
// Created by Arlyn Linette Medina García on 17/11/22.
//

#include "Validationpieces.h"
#include "Board.h"

typedef struct{
    int x;
    int y;
}Movimientos;


char GetPiece(int x, int y, Board *b){
    return *(*(b->tablero+y)+x);
}

//Defines the color of the piece
int IsWhite(int x, int y, Board *b){
    if (GetPiece(x, y, b->tablero) == WPawn || GetPiece(x, y, b->tablero) == WKnight || GetPiece(x, y, b->tablero) == WQueen ||
        GetPiece(x, y, b->tablero) == WKing || GetPiece(x, y, b->tablero) == WBishop || GetPiece(x, y, b->tablero) == WRook && GetPiece(x, y, b->tablero) != Empty)
        return 1;
    return 0;
}

int IsBlack(int x, int y, Board *b){
    if (GetPiece(x, y, b->tablero) == BPawn || GetPiece(x, y, b->tablero) == BKnight || GetPiece(x, y, b->tablero) == BQueen ||
            GetPiece(x, y, b->tablero) == BKing || GetPiece(x, y, b->tablero) == BBishop || GetPiece(x, y, b->tablero) == BRook && GetPiece(x, y, b->tablero) != Empty)
        return 1;
    return 0;
}

int IsEmpty(int x, int y, Board *b){
    return (GetPiece(x, y, b->tablero) == Empty);
}

int InBoard(int x, int y){
    return (x <8 && x>-1 && y >-1 && y<8);
}

void* swap (Board *b, Movimientos *inicio, Movimientos *final){
    Movimientos *temp =  final;
    final = inicio;
    inicio = temp;
}

Movimientos* ValidarMovimientos(Movimientos comienzo, Board *b){
    Movimientos inicio = (Movimientos) {comienzo.x, comienzo.y};
    if (IsBlack(comienzo.x, comienzo.y, b)) {
        switch (GetPiece(comienzo.x, comienzo.y, b)) {
            case BPawn: {
                //Dos movimientos al frente

                if (comienzo.y == 1 && IsEmpty(comienzo.x, comienzo.y + 2, b->tablero) &&
                    IsEmpty(comienzo.x, comienzo.y + 1, b->tablero)) {
                    (Movimientos) {comienzo.x, comienzo.y + 2};
                }

                //Un movimiento al frente
                if (IsEmpty(comienzo.x, comienzo.y + 1, b->tablero) && InBoard(comienzo.x, comienzo.y + 1)) {
                    (Movimientos) {comienzo.x, comienzo.y + 1};
                }

                //Comer en diagonal hacia la derecha
                if (IsWhite(comienzo.x + 1, comienzo.y + 1, b->tablero) && InBoard(comienzo.x + 1, comienzo.y + 1)) {
                    (Movimientos) {comienzo.x + 1, comienzo.y + 1};
                }

                //Comer en diagonal hacia la izquierda
                if (IsWhite(comienzo.x - 1, comienzo.y + 1, b->tablero) && InBoard(comienzo.x - 1, comienzo.y + 1)) {
                    (Movimientos) {comienzo.x - 1, comienzo.y + 1}; //Como cambiar esto
                }
            }
            break;
            case BRook: {
                //Moverse a la derecha
                for (int i = comienzo.x + 1; InBoard(i, comienzo.y) && !IsBlack(i, comienzo.y, b->tablero); i++) {
                    (Movimientos) {i, comienzo.y};
                    if (IsWhite(i, comienzo.y, b->tablero))
                        break;
                }
                //Moverse a la derecha
                for (int i = comienzo.x - 1; InBoard(i, comienzo.y) && !IsBlack(i, comienzo.y, b->tablero); i--) {
                    (Movimientos) {i, comienzo.y};
                    if (IsWhite(i, comienzo.y, b->tablero))
                        break;
                }
                //Moverse abajo
                for (int i = comienzo.y + 1; InBoard(comienzo.x, i) && !IsBlack(comienzo.x, i, b->tablero); i++) {
                    (Movimientos) {comienzo.x, i};
                    if (IsWhite(comienzo.x, i, b->tablero))
                        break;
                }
                //Moverse arriba
                for (int i = comienzo.y - 1; InBoard(comienzo.x, i) && !IsBlack(comienzo.x, i, b->tablero); i--) {
                    (Movimientos) {comienzo.x, i};
                    if (IsWhite(comienzo.x, i, b->tablero))
                        break;
                }
            }
            break;
            case BBishop: {
                //Moverse abajo/derecha
                for (int i = comienzo.x + 1, j = comienzo.y + 1; InBoard(i, j) && !IsBlack(i, i, b->tablero); i++, j++) {
                    (Movimientos) {i, j};
                    if (IsWhite(i, j, b->tablero))
                        break;
                }
                //Moverse abajo/izquierda
                for (int i = comienzo.x - 1, j = comienzo.y + 1; InBoard(i, j) && !IsBlack(i, i, b->tablero); i--, j++) {
                    (Movimientos) {i, j};
                    if (IsWhite(i, j, b->tablero))
                        break;
                }
                //Moverse arriba/derecha
                for (int i = comienzo.x + 1, j = comienzo.y - 1; InBoard(i, j) && !IsBlack(i, i, b->tablero); i++, j--) {
                    (Movimientos) {i, j};
                    if (IsWhite(i, j, b->tablero))
                        break;
                }
                //Moverse arriba/izquierda
                for (int i = comienzo.x - 1, j = comienzo.y - 1; InBoard(i, j) && !IsBlack(i, i, b->tablero); i--, j--) {
                    (Movimientos) {i, j};
                    if (IsWhite(i, j, b->tablero))
                        break;
                }
            }
            break;
            case BQueen: {
                //Moverse abajo/derecha
                for (int i = comienzo.x + 1, j = comienzo.y + 1; InBoard(i, j) && !IsBlack(i, i, b->tablero); i++, j++) {
                    (Movimientos) {i, j};
                    if (IsWhite(i, j, b->tablero))
                        break;
                }
                //Moverse abajo/izquierda
                for (int i = comienzo.x - 1, j = comienzo.y + 1; InBoard(i, j) && !IsBlack(i, i, b->tablero); i--, j++) {
                    (Movimientos) {i, j};
                    if (IsWhite(i, j, b->tablero))
                        break;
                }
                //Moverse arriba/derecha
                for (int i = comienzo.x + 1, j = comienzo.y - 1; InBoard(i, j) && !IsBlack(i, i, b->tablero); i++, j--) {
                    (Movimientos) {i, j};
                    if (IsWhite(i, j, b->tablero))
                        break;
                }
                //Moverse arriba/izquierda
                for (int i = comienzo.x - 1, j = comienzo.y - 1; InBoard(i, j) && !IsBlack(i, i, b->tablero); i--, j--) {
                    (Movimientos) {i, j};
                    if (IsWhite(i, j, b->tablero))
                        break;
                }
                //Moverse a la derecha
                for (int i = comienzo.x + 1; InBoard(i, comienzo.y) && !IsBlack(i, comienzo.y, b->tablero); i++) {
                    (Movimientos) {i, comienzo.y};
                    if (IsWhite(i, comienzo.y, b->tablero))
                        break;
                }
                //Moverse a la izquierda
                for (int i = comienzo.x - 1; InBoard(i, comienzo.y) && !IsBlack(i, comienzo.y, b->tablero); i--) {
                    (Movimientos) {i, comienzo.y};
                    if (IsWhite(i, comienzo.y, b->tablero))
                        break;
                }
                //Moverse hacia abajo
                for (int i = comienzo.y + 1; InBoard(comienzo.x, i) && !IsBlack(comienzo.x, i, b->tablero); i++) {
                    (Movimientos) {comienzo.x, i};
                    if (IsWhite(comienzo.x, i, b->tablero))
                        break;
                }
                //Moverse hacia arriba
                for (int i = comienzo.y - 1; InBoard(comienzo.x, i) && !IsBlack(comienzo.x, i, b->tablero); i--) {
                    (Movimientos) {comienzo.x, i};
                    if (IsWhite(comienzo.x, i, b->tablero))
                        break;
                }
            }
            break;
            case BKing: {
                //Que es lo que hace esto jeje
                for (int y = -1; y <= 1; y++) {
                    for (int x = -1; y <= 1; x++) {
                        if (!(x == 0 && y == 0)) {
                            if (InBoard(comienzo.x + x, comienzo.y + y) &&
                                !IsBlack(comienzo.x + x, comienzo.y + y, b->tablero)) {
                                (Movimientos) {comienzo.x + x, comienzo.y + y};
                            }
                        }
                    }
                }
            }
            break;
            case BKnight: {
                //Posiciones Superiores
                if (InBoard(comienzo.x + 1, comienzo.y - 2) && !IsBlack(comienzo.x + 1, comienzo.y - 2, b->tablero)) {
                    (Movimientos) {comienzo.x + 1, comienzo.y - 2};
                }
                if (InBoard(comienzo.x - 1, comienzo.y - 2) && !IsBlack(comienzo.x - 1, comienzo.y - 2, b->tablero)) {
                    (Movimientos) {comienzo.x - 1, comienzo.y - 2};
                }
                //Posiciones Inferiores
                if (InBoard(comienzo.x + 1, comienzo.y + 2) && !IsBlack(comienzo.x + 1, comienzo.y + 2, b->tablero)) {
                    (Movimientos) {comienzo.x + 1, comienzo.y + 2};
                }
                if (InBoard(comienzo.x - 1, comienzo.y + 2) && !IsBlack(comienzo.x - 1, comienzo.y + 2, b->tablero)) {
                    (Movimientos) {comienzo.x - 1, comienzo.y + 2};
                }
                //Posiciones de la Derecha
                if (InBoard(comienzo.x + 2, comienzo.y - 1) && !IsBlack(comienzo.x + 2, comienzo.y - 1, b->tablero)) {
                    (Movimientos) {comienzo.x + 2, comienzo.y - 1};
                }
                if (InBoard(comienzo.x + 2, comienzo.y + 1) && !IsBlack(comienzo.x + 2, comienzo.y + 1, b->tablero)) {
                    (Movimientos) {comienzo.x + 2, comienzo.y + 1};
                }
                //Posiciones de la Izquierda
                if (InBoard(comienzo.x - 2, comienzo.y - 1) && !IsBlack(comienzo.x - 2, comienzo.y - 1, b->tablero)) {
                    (Movimientos) {comienzo.x - 2, comienzo.y - 1};
                }
                if (InBoard(comienzo.x - 2, comienzo.y + 1) && !IsBlack(comienzo.x - 2, comienzo.y + 1, b->tablero)) {
                    (Movimientos) {comienzo.x - 2, comienzo.y + 1};
                }
            }
            break;
            default: {
                (Movimientos) {comienzo.x, comienzo.y + 1};
            }
        }
    }
    else{
        switch (GetPiece(comienzo.x, comienzo.y, b->tablero)){
            case WPawn: {
                //Dos movimientos al frente
                if (comienzo.y == 6 && IsEmpty(comienzo.x, comienzo.y - 2, b->tablero) &&
                    IsEmpty(comienzo.x, comienzo.y - 1, b->tablero)) {
                    (Movimientos) {comienzo.x, comienzo.y - 2};
                }

                //Un movimiento al frente
                if (IsEmpty(comienzo.x, comienzo.y - 1, b->tablero) && InBoard(comienzo.x, comienzo.y - 1)) {
                    (Movimientos) {comienzo.x, comienzo.y - 1};
                }

                //Comer en diagonal hacia la derecha
                if (IsBlack(comienzo.x + 1, comienzo.y - 1, b->tablero) && InBoard(comienzo.x + 1, comienzo.y - 1)) {
                    (Movimientos) {comienzo.x + 1, comienzo.y - 1};
                }

                //Comer en diagonal hacia la izquierda
                if (IsBlack(comienzo.x - 1, comienzo.y - 1, b->tablero) && InBoard(comienzo.x - 1, comienzo.y - 1)) {
                    (Movimientos) {comienzo.x - 1, comienzo.y - 1}; //Como cambiar esto
                }
            }
            break;
            case WRook: {
                //Moverse a la derecha
                for (int i = comienzo.x + 1; InBoard(i, comienzo.y) && !IsWhite(i, comienzo.y, b->tablero); i++) {
                    (Movimientos) {i, comienzo.y};
                    if (IsBlack(i, comienzo.y, b->tablero))
                        break;
                }
                //Moverse a la derecha
                for (int i = comienzo.x - 1; InBoard(i, comienzo.y) && !IsWhite(i, comienzo.y, b->tablero); i--) {
                    (Movimientos) {i, comienzo.y};
                    if (IsBlack(i, comienzo.y, b->tablero))
                        break;
                }
                //Moverse abajo
                for (int i = comienzo.y + 1; InBoard(comienzo.x, i) && !IsWhite(comienzo.x, i, b->tablero); i++) {
                    (Movimientos) {comienzo.x, i};
                    if (IsBlack(comienzo.x, i, b->tablero))
                        break;
                }
                //Moverse arriba
                for (int i = comienzo.y - 1; InBoard(comienzo.x, i) && !IsWhite(comienzo.x, i, b->tablero); i--) {
                    (Movimientos) {comienzo.x, i};
                    if (IsBlack(comienzo.x, i, b->tablero))
                        break;
                }
            }
            break;
            case WBishop: {
                //Moverse abajo/derecha
                for (int i = comienzo.x + 1, j = comienzo.y + 1; InBoard(i, j) && !IsWhite(i, i, b->tablero); i++, j++) {
                    (Movimientos) {i, j};
                    if (IsBlack(i, j, b->tablero))
                        break;
                }
                //Moverse abajo/izquierda
                for (int i = comienzo.x - 1, j = comienzo.y + 1; InBoard(i, j) && !IsWhite(i, i, b->tablero); i--, j++) {
                    (Movimientos) {i, j};
                    if (IsBlack(i, j, b->tablero))
                        break;
                }
                //Moverse arriba/derecha
                for (int i = comienzo.x + 1, j = comienzo.y - 1; InBoard(i, j) && !IsWhite(i, i, b->tablero); i++, j--) {
                    (Movimientos) {i, j};
                    if (IsBlack(i, j, b->tablero))
                        break;
                }
                //Moverse arriba/izquierda
                for (int i = comienzo.x - 1, j = comienzo.y - 1; InBoard(i, j) && !IsWhite(i, i, b->tablero); i--, j--) {
                    (Movimientos) {i, j};
                    if (IsBlack(i, j, b->tablero))
                        break;
                }
            }
            break;
            case WQueen: {
                //Moverse abajo/derecha
                for (int i = comienzo.x + 1, j = comienzo.y + 1; InBoard(i, j) && !IsWhite(i, i, b->tablero); i++, j++) {
                    (Movimientos) {i, j};
                    if (IsBlack(i, j, b->tablero))
                        break;
                }
                //Moverse abajo/izquierda
                for (int i = comienzo.x - 1, j = comienzo.y + 1; InBoard(i, j) && !IsWhite(i, i, b->tablero); i--, j++) {
                    (Movimientos) {i, j};
                    if (IsBlack(i, j, b->tablero))
                        break;
                }
                //Moverse arriba/derecha
                for (int i = comienzo.x + 1, j = comienzo.y - 1; InBoard(i, j) && !IsWhite(i, i, b->tablero); i++, j--) {
                    (Movimientos) {i, j};
                    if (IsBlack(i, j, b->tablero))
                        break;
                }
                //Moverse arriba/izquierda
                for (int i = comienzo.x - 1, j = comienzo.y - 1; InBoard(i, j) && !IsWhite(i, i, b->tablero); i--, j--) {
                    (Movimientos) {i, j};
                    if (IsBlack(i, j, b->tablero))
                        break;
                }
                //Moverse a la derecha
                for (int i = comienzo.x + 1; InBoard(i, comienzo.y) && !IsWhite(i, comienzo.y, b->tablero); i++) {
                    (Movimientos) {i, comienzo.y};
                    if (IsBlack(i, comienzo.y, b->tablero))
                        break;
                }
                //Moverse a la izquierda
                for (int i = comienzo.x - 1; InBoard(i, comienzo.y) && !IsWhite(i, comienzo.y, b->tablero); i--) {
                    (Movimientos) {i, comienzo.y};
                    if (IsBlack(i, comienzo.y, b->tablero))
                        break;
                }
                //Moverse hacia abajo
                for (int i = comienzo.y + 1; InBoard(comienzo.x, i) && !IsWhite(comienzo.x, i, b->tablero); i++) {
                    (Movimientos) {comienzo.x, i};
                    if (IsBlack(comienzo.x, i, b->tablero))
                        break;
                }
                //Moverse hacia arriba
                for (int i = comienzo.y - 1; InBoard(comienzo.x, i) && !IsWhite(comienzo.x, i, b->tablero); i--) {
                    (Movimientos) {comienzo.x, i};
                    if (IsBlack(comienzo.x, i, b->tablero))
                        break;
                }
            }
                break;
            case WKing: {
                //Que es lo que hace esto jeje
                for (int y = -1; y <= 1; y++) {
                    for (int x = -1; y <= 1; x++) {
                        if (!(x == 0 && y == 0)) {
                            if (InBoard(comienzo.x + x, comienzo.y + y) &&
                                !IsWhite(comienzo.x + x, comienzo.y + y, b->tablero)) {
                                (Movimientos) {comienzo.x + x, comienzo.y + y};
                            }
                        }

                    }
                }
                break;
                case WKnight: {
                    //Posiciones Superiores
                    if (InBoard(comienzo.x + 1, comienzo.y - 2) && !IsWhite(comienzo.x + 1, comienzo.y - 2, b->tablero)) {
                        (Movimientos) {comienzo.x + 1, comienzo.y - 2};
                    }
                    if (InBoard(comienzo.x - 1, comienzo.y - 2) && !IsWhite(comienzo.x - 1, comienzo.y - 2, b->tablero)) {
                        (Movimientos) {comienzo.x - 1, comienzo.y - 2};
                    }
                    //Posiciones Inferiores
                    if (InBoard(comienzo.x + 1, comienzo.y + 2) && !IsWhite(comienzo.x + 1, comienzo.y + 2, b->tablero)) {
                        (Movimientos) {comienzo.x + 1, comienzo.y + 2};
                    }
                    if (InBoard(comienzo.x - 1, comienzo.y + 2) && !IsWhite(comienzo.x - 1, comienzo.y + 2, b->tablero)) {
                        (Movimientos) {comienzo.x - 1, comienzo.y + 2};
                    }
                    //Posiciones de la Derecha
                    if (InBoard(comienzo.x + 2, comienzo.y - 1) && !IsWhite(comienzo.x + 2, comienzo.y - 1, b->tablero)) {
                        (Movimientos) {comienzo.x + 2, comienzo.y - 1};
                    }
                    if (InBoard(comienzo.x + 2, comienzo.y + 1) && !IsWhite(comienzo.x + 2, comienzo.y + 1, b->tablero)) {
                        (Movimientos) {comienzo.x + 2, comienzo.y + 1};
                    }
                    //Posiciones de la Izquierda
                    if (InBoard(comienzo.x - 2, comienzo.y - 1) && !IsWhite(comienzo.x - 2, comienzo.y - 1, b->tablero)) {
                        (Movimientos) {comienzo.x - 2, comienzo.y - 1};
                    }
                    if (InBoard(comienzo.x - 2, comienzo.y + 1) && !IsWhite(comienzo.x - 2, comienzo.y + 1, b->tablero)) {
                        (Movimientos) {comienzo.x - 2, comienzo.y + 1};
                    }
                }
                break;
                default: {
                    (Movimientos) {comienzo.x, comienzo.y -1};
                }
            }
        }
    }
}