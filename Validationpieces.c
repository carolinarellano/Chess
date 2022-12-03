//
// Created by Arlyn Linette Medina García on 17/11/22.
//

#include "Validationpieces.h"
#include "Globals.h"
#include "Board.h"
#include "Graphics.h"


int GetPiece(int x, int y, Board *b)
{
    return *(*(b->tablero+y)+x);
}

//Defines the color of the piece
int IsWhite(int x, int y, Board *b){
    if (GetPiece(x, y, b) == WPawn || GetPiece(x, y, b) == WKnight || GetPiece(x, y, b) == WQueen ||
        GetPiece(x, y, b) == WKing || GetPiece(x, y, b) == WBishop || GetPiece(x, y, b) == WRook)
        return 1;
    return 0;
}

int IsBlack(int x, int y, Board *b){
    if (GetPiece(x, y, b) == BPawn || GetPiece(x, y, b) == BKnight || GetPiece(x, y, b) == BQueen ||
        GetPiece(x, y, b) == BKing || GetPiece(x, y, b) == BBishop || GetPiece(x, y, b) == BRook)
        return 0;
    return 1;
}

int IsEmpty(int x, int y, Board *b){
    return (GetPiece(x, y, b) == Empty);
}

int InBoard(int x, int y){
    return (x < 8 && x >-1 && y >-1 && y<8);
}

int InCheckBLACK(Board *b, Coordinate *bkingcoordinate){
    for (int i = 0; i < 8; i++){
        for (int j = 0; i < 8; i++){
            if (b->tablero[i][j] == WPawn){
                Piece *p;
                p->position->x = i;
                p->position->y = j;
                return ValidateMovement(b, p->position, p) == bkingcoordinate;
            }
            if (b->tablero[i][j] == WKnight){
                Piece *p;
                p->position->x = i;
                p->position->y = j;
                return ValidateMovement(b, p->position, p) == bkingcoordinate;
            }
            if (b->tablero[i][j] == WBishop){
                Piece *p;
                p->position->x = i;
                p->position->y = j;
                return ValidateMovement(b, p->position, p) == bkingcoordinate;
            }
            if (b->tablero[i][j] == WRook){
                Piece *p;
                p->position->x = i;
                p->position->y = j;
                return ValidateMovement(b, p->position, p) == bkingcoordinate;
            }
            if (b->tablero[i][j] == WQueen){
                Piece *p;
                p->position->x = i;
                p->position->y = j;
                return ValidateMovement(b, p->position, p) == bkingcoordinate;
            }
        }
    }
}

int InCheckWHITE(Board *b, Coordinate *wkingcoordinate){
    for (int i = 0; i < 8; i++){
        for (int j = 0; i < 8; i++){
            if (b->tablero[i][j] == BPawn){
                Piece *p;
                p->position->x = i;
                p->position->y = j;
                return ValidateMovement(b, p->position, p) == wkingcoordinate;
            }
            if (b->tablero[i][j] == BKnight){
                Piece *p;
                p->position->x = i;
                p->position->y = j;
                return ValidateMovement(b, p->position, p) == wkingcoordinate;
            }
            if (b->tablero[i][j] == BBishop){
                Piece *p;
                p->position->x = i;
                p->position->y = j;
                return ValidateMovement(b, p->position, p) == wkingcoordinate;
            }
            if (b->tablero[i][j] == BRook){
                Piece *p;
                p->position->x = i;
                p->position->y = j;
                return ValidateMovement(b, p->position, p) == wkingcoordinate;
            }
            if (b->tablero[i][j] == BQueen){
                Piece *p;
                p->position->x = i;
                p->position->y = j;
                return ValidateMovement(b, p->position, p) == wkingcoordinate;
            }
        }
    }
}

Coordinate* MakeMovement(Coordinate *current, Coordinate *final, Piece *p){
    final->x = current->x;
    final->y = current->y;
    p->position = final;
}

Coordinate *getBKingPosition(Board *b){
    Coordinate *position;
    for (int i = 0; i < 8; i++){
        for (int j = 0; i < 8; i++) {
            if(b->tablero[i][j] == BKing){
                position->x = i;
                position->y = j;
                return position;
            }
        }
    }
}
Coordinate *getWKingPosition(Board *b){
    Coordinate *position;
    for (int i = 0; i < 8; i++){
        for (int j = 0; i < 8; i++) {
            if(b->tablero[i][j] == WKing){
                position->x = i;
                position->y = j;
                return position;
            }
        }
    }
}

Coordinate* ValidateMovement(Board *b, Coordinate *current, Piece *p){
    Coordinate *inicio = {current->x, current->y};
    if (IsBlack(current->x, current->y, b)) {
        switch (GetPiece(current->x, current->y, b)) {
            InCheckBLACK(b, getBKingPosition(b));
            case BPawn: {
                //Dos movimientos al frente
                if (current->y == 1 && IsEmpty(current->x, current->y + 2, b) &&
                    IsEmpty(current->x, current->y + 2, b)) {
                    Coordinate* final = {current->x, current->y+2};
                    MakeMovement(inicio, final, p);
                    return 1;
                }

                //Un movimiento al frente
                if (IsEmpty(current->x, current->y + 1, b) && InBoard(current->x, current->y + 1)){
                    Coordinate* final = {current->x, current->y+1};
                    MakeMovement(inicio, final, p);
                }

                //Comer en diagonal hacia la derecha
                if (IsWhite(current->x + 1, current->y + 1, b) && InBoard(current->x + 1, current->y + 1))
                {
                    Coordinate* final = {current->x+1, current->y+1};
                    MakeMovement(inicio, final, p);
                }

                //Comer en diagonal hacia la izquierda
                if (IsWhite(current->x - 1, current->y + 1, b) && InBoard(current->x - 1, current->y + 1))
                {
                    Coordinate* final = {current->x-1, current->y+1};
                    MakeMovement(inicio, final, p);
                }
            }
                break;
            case BRook: {
                //Moverse a la derecha
                for (int i = current->x + 1; InBoard(i, current->y) && !IsBlack(i, current->y, b); i++)
                {
                    Coordinate* final = {i, current->y};
                    MakeMovement(inicio, final, p);
                    if (IsWhite(i, current->y, b))
                        break;
                }
                //Moverse a la derecha
                for (int i = current->x - 1; InBoard(i, current->y) && !IsBlack(i, current->y, b); i--) {
                    Coordinate* final = {i, current->y};
                    MakeMovement(inicio, final, p);
                    if (IsWhite(i, current->y, b))
                        break;
                }
                //Moverse abajo
                for (int i = current->y + 1; InBoard(current->x, i) && !IsBlack(current->x, i, b); i++) {
                    Coordinate* final = {current->x, i};
                    MakeMovement(inicio, final, p);
                    if (IsWhite(current->x, i, b))
                        break;
                }
                //Moverse arriba
                for (int i = current->y - 1; InBoard(current->x, i) && !IsBlack(current->x, i, b); i--) {
                    Coordinate* final = {current->x, i};
                    MakeMovement(inicio, final, p);
                    if (IsWhite(current->x, i, b))
                        break;
                }
            }
                break;
            case BBishop: {
                //Moverse abajo/derecha
                for (int i = current->x + 1, j = current->y + 1; InBoard(i, j) && !IsBlack(i, i, b); i++, j++) {
                    Coordinate* final = {i, j};
                    MakeMovement(inicio, final, p);
                    if (IsWhite(i, j, b))
                        break;
                }
                //Moverse abajo/izquierda
                for (int i = current->x - 1, j = current->y + 1; InBoard(i, j) && !IsBlack(i, i, b); i--, j++) {
                    Coordinate* final = {i, j};
                    MakeMovement(inicio, final, p);
                    if (IsWhite(i, j, b))
                        break;
                }
                //Moverse arriba/derecha
                for (int i = current->x + 1, j = current->y - 1; InBoard(i, j) && !IsBlack(i, i, b); i++, j--) {
                    Coordinate* final = {i, j};
                    MakeMovement(inicio, final, p);
                    if (IsWhite(i, j, b))
                        break;
                }
                //Moverse arriba/izquierda
                for (int i = current->x - 1, j = current->y - 1; InBoard(i, j) && !IsBlack(i, i, b); i--, j--) {
                    Coordinate* final = {i, j};
                    MakeMovement(inicio, final, p);
                    if (IsWhite(i, j, b))
                        break;
                }
            }
                break;
            case BQueen: {
                //Moverse abajo/derecha
                for (int i = current->x + 1, j = current->y + 1; InBoard(i, j) && !IsBlack(i, i, b); i++, j++) {
                    Coordinate* final = {i, j};
                    MakeMovement(inicio, final, p);
                    if (IsWhite(i, j, b))
                        break;
                }
                //Moverse abajo/izquierda
                for (int i = current->x - 1, j = current->y + 1; InBoard(i, j) && !IsBlack(i, i, b); i--, j++) {
                    Coordinate* final = {i, j};
                    MakeMovement(inicio, final, p);
                    if (IsWhite(i, j, b))
                        break;
                }
                //Moverse arriba/derecha
                for (int i = current->x + 1, j = current->y - 1; InBoard(i, j) && !IsBlack(i, i, b); i++, j--) {
                    Coordinate* final = {i, j};
                    MakeMovement(inicio, final, p);
                    if (IsWhite(i, j, b))
                        break;
                }
                //Moverse arriba/izquierda
                for (int i = current->x - 1, j = current->y - 1; InBoard(i, j) && !IsBlack(i, i, b); i--, j--) {
                    Coordinate* final = {i, j};
                    MakeMovement(inicio, final, p);
                    if (IsWhite(i, j, b))
                        break;
                }
                //Moverse a la derecha
                for (int i = current->x + 1; InBoard(i, current->y) && !IsBlack(i, current->y, b); i++) {
                    Coordinate* final = {i, current->y};
                    MakeMovement(inicio, final, p);
                    if (IsWhite(i, current->y, b))
                        break;
                }
                //Moverse a la izquierda
                for (int i = current->x - 1; InBoard(i, current->y) && !IsBlack(i, current->y, b); i--) {
                    Coordinate* final = {i, current->y};
                    MakeMovement(inicio, final, p);
                    if (IsWhite(i, current->y, b))
                        break;
                }
                //Moverse hacia abajo
                for (int i = current->y + 1; InBoard(current->x, i) && !IsBlack(current->x, i, b); i++) {
                    Coordinate* final = {current->x, i};
                    MakeMovement(inicio, final, p);
                    if (IsWhite(current->x, i, b))
                        break;
                }
                //Moverse hacia arriba
                for (int i = current->y - 1; InBoard(current->x, i) && !IsBlack(current->x, i, b); i--) {
                    Coordinate* final = {current->x, i};
                    MakeMovement(inicio, final, p);
                    if (IsWhite(current->x, i, b))
                        break;
                }
            }
                break;
            case BKing: {
                //Que es lo que hace esto jeje
                for (int y = -1; y <= 1; y++) {
                    for (int x = -1; y <= 1; x++) {
                        if (!(x == 0 && y == 0)) {
                            if (InBoard(current->x + x, current->y + y) && !IsBlack(current->x + x, current->y + y, b)){
                                Coordinate* final = {current->x+x, current->y+y};
                                MakeMovement(inicio, final, p);
                            }
                        }
                    }
                }
            }
                break;
            case BKnight: {
                //Posiciones Superiores
                if (InBoard(current->x + 1, current->y - 2) && !IsBlack(current->x + 1, current->y - 2, b)) {
                    Coordinate* final = {current->x+1, current->y-2};
                    MakeMovement(inicio, final, p);
                }

                if (InBoard(current->x - 1, current->y - 2) && !IsBlack(current->x - 1, current->y - 2, b)) {
                    Coordinate* final = {current->x-1, current->y-2};
                    MakeMovement(inicio, final, p);
                }

                //Posiciones Inferiores
                if (InBoard(current->x + 1, current->y + 2) && !IsBlack(current->x + 1, current->y + 2, b)) {
                    Coordinate* final = {current->x+1, current->y+2};
                    MakeMovement(inicio, final, p);
                }
                if (InBoard(current->x - 1, current->y + 2) && !IsBlack(current->x - 1, current->y + 2, b)) {
                    Coordinate* final = {current->x-1, current->y+2};
                    MakeMovement(inicio, final, p);
                }
                //Posiciones de la Derecha
                if (InBoard(current->x + 2, current->y - 1) && !IsBlack(current->x + 2, current->y - 1, b)) {
                    Coordinate* final = {current->x+2, current->y-1};
                    MakeMovement(inicio, final, p);
                }
                if (InBoard(current->x + 2, current->y + 1) && !IsBlack(current->x + 2, current->y + 1, b)) {
                    Coordinate* final = {current->x+2, current->y+1};
                    MakeMovement(inicio, final, p);
                }
                //Posiciones de la Izquierda
                if (InBoard(current->x - 2, current->y - 1) && !IsBlack(current->x - 2, current->y - 1, b)) {
                    Coordinate* final = {current->x-2, current->y-1};
                    MakeMovement(inicio, final, p);
                }
                if (InBoard(current->x - 2, current->y + 1) && !IsBlack(current->x - 2, current->y + 1, b)) {
                    Coordinate* final = {current->x-2, current->y+1};
                    MakeMovement(inicio, final, p);
                }
            }
                break;
            default: {
                Coordinate* final = {current->x, current->y+1};
                MakeMovement(inicio, final, p);
            }
        }
    }
    else{
        switch (GetPiece(current->x, current->y, b)){
            InCheckWHITE(b, getWKingPosition(b));
            case WPawn: {
                //Dos movimientos al frente
                if (current->y == 6 && IsEmpty(current->x, current->y - 2, b) &&
                    IsEmpty(current->x, current->y - 1, b)){
                    Coordinate* final = {current->x, current->y-2};
                    MakeMovement(inicio, final, p);
                }

                //Un movimiento al frente
                if (IsEmpty(current->x, current->y - 1, b) && InBoard(current->x, current->y - 1)) {
                    Coordinate* final = {current->x, current->y-1};
                    MakeMovement(inicio, final, p);
                }

                //Comer en diagonal hacia la derecha
                if (IsBlack(current->x + 1, current->y - 1, b) && InBoard(current->x + 1, current->y - 1)) {
                    Coordinate* final = {current->x+1, current->y-1};
                    MakeMovement(inicio, final, p);
                }

                //Comer en diagonal hacia la izquierda
                if (IsBlack(current->x - 1, current->y - 1, b) && InBoard(current->x - 1, current->y - 1)) {
                    Coordinate* final = {current->x-1, current->y-1};
                    MakeMovement(inicio, final, p);
                }
            }
                break;
            case WRook: {
                //Moverse a la derecha
                for (int i = current->x + 1; InBoard(i, current->y) && !IsWhite(i, current->y, b); i++) {
                    Coordinate* final = {i, current->y};
                    MakeMovement(inicio, final, p);
                    if (IsBlack(i, current->y, b))
                        break;
                }
                //Moverse a la derecha
                for (int i = current->x - 1; InBoard(i, current->y) && !IsWhite(i, current->y, b); i--) {
                    Coordinate* final = {i, current->y};
                    MakeMovement(inicio, final, p);
                    if (IsBlack(i, current->y, b))
                        break;
                }
                //Moverse abajo
                for (int i = current->y + 1; InBoard(current->x, i) && !IsWhite(current->x, i, b); i++) {
                    Coordinate* final = {current->x, i};
                    MakeMovement(inicio, final, p);
                    if (IsBlack(current->x, i, b))
                        break;
                }
                //Moverse arriba
                for (int i = current->y - 1; InBoard(current->x, i) && !IsWhite(current->x, i, b); i--) {
                    Coordinate* final = {current->x, i};
                    MakeMovement(inicio, final, p);
                    if (IsBlack(current->x, i, b))
                        break;
                }
            }
                break;
            case WBishop: {
                //Moverse abajo/derecha
                for (int i = current->x + 1, j = current->y + 1; InBoard(i, j) && !IsWhite(i, i, b); i++, j++) {
                    Coordinate* final = {i, j};
                    MakeMovement(inicio, final, p);
                    if (IsBlack(i, j, b))
                        break;
                }
                //Moverse abajo/izquierda
                for (int i = current->x - 1, j = current->y + 1; InBoard(i, j) && !IsWhite(i, i, b); i--, j++) {
                    Coordinate* final = {i, j};
                    MakeMovement(inicio, final, p);
                    if (IsBlack(i, j, b))
                        break;
                }
                //Moverse arriba/derecha
                for (int i = current->x + 1, j = current->y - 1; InBoard(i, j) && !IsWhite(i, i, b); i++, j--) {
                    Coordinate* final = {i, j};
                    MakeMovement(inicio, final, p);
                    if (IsBlack(i, j, b))
                        break;
                }
                //Moverse arriba/izquierda
                for (int i = current->x - 1, j = current->y - 1; InBoard(i, j) && !IsWhite(i, i, b); i--, j--) {
                    Coordinate* final = {i, j};
                    MakeMovement(inicio, final, p);
                    if (IsBlack(i, j, b))
                        break;
                }
            }
                break;
            case WQueen: {
                //Moverse abajo/derecha
                for (int i = current->x + 1, j = current->y + 1; InBoard(i, j) && !IsWhite(i, i, b); i++, j++) {
                    Coordinate* final = {i, j};
                    MakeMovement(inicio, final, p);
                    if (IsBlack(i, j, b))
                        break;
                }
                //Moverse abajo/izquierda
                for (int i = current->x - 1, j = current->y + 1; InBoard(i, j) && !IsWhite(i, i, b); i--, j++) {
                    Coordinate* final = {i, j};
                    MakeMovement(inicio, final, p);
                    if (IsBlack(i, j, b))
                        break;
                }
                //Moverse arriba/derecha
                for (int i = current->x + 1, j = current->y - 1; InBoard(i, j) && !IsWhite(i, i, b); i++, j--) {
                    Coordinate* final = {i, j};
                    MakeMovement(inicio, final, p);
                    if (IsBlack(i, j, b))
                        break;
                }
                //Moverse arriba/izquierda
                for (int i = current->x - 1, j = current->y - 1; InBoard(i, j) && !IsWhite(i, i, b); i--, j--) {
                    Coordinate* final = {i, j};
                    MakeMovement(inicio, final, p);
                    if (IsBlack(i, j, b))
                        break;
                }
                //Moverse a la derecha
                for (int i = current->x + 1; InBoard(i, current->y) && !IsWhite(i, current->y, b); i++) {
                    Coordinate* final = {i, current->y};
                    MakeMovement(inicio, final, p);
                    if (IsBlack(i, current->y, b))
                        break;
                }
                //Moverse a la izquierda
                for (int i = current->x - 1; InBoard(i, current->y) && !IsWhite(i, current->y, b); i--) {
                    Coordinate* final = {i, current->y};
                    MakeMovement(inicio, final, p);
                    if (IsBlack(i, current->y, b))
                        break;
                }
                //Moverse hacia abajo
                for (int i = current->y + 1; InBoard(current->x, i) && !IsWhite(current->x, i, b); i++) {
                    Coordinate* final = {current->x, i};
                    MakeMovement(inicio, final, p);
                    if (IsBlack(current->x, i, b))
                        break;
                }
                //Moverse hacia arriba
                for (int i = current->y - 1; InBoard(current->x, i) && !IsWhite(current->x, i, b); i--) {
                    Coordinate* final = {current->x, i};
                    MakeMovement(inicio, final, p);
                    if (IsBlack(current->x, i, b))
                        break;
                }
            }
                break;
            case WKing: {
                //Que es lo que hace esto jeje
                for (int y = -1; y <= 1; y++) {
                    for (int x = -1; y <= 1; x++) {
                        if (!(x == 0 && y == 0)) {
                            if (InBoard(current->x + x, current->y + y) &&
                                !IsWhite(current->x + x, current->y + y, b)) {
                                Coordinate* final = {current->x+x, current->y+y};
                                MakeMovement(inicio, final, p);
                            }
                        }

                    }
                }
                break;
                case WKnight: {
                    //Posiciones Superiores
                    if (InBoard(current->x + 1, current->y - 2) && !IsWhite(current->x + 1, current->y - 2, b)) {
                        Coordinate* final = {current->x+1, current->y-2};
                        MakeMovement(inicio, final, p);

                    }
                    if (InBoard(current->x - 1, current->y - 2) && !IsWhite(current->x - 1, current->y - 2, b)) {
                        Coordinate* final = {current->x-1, current->y-2};
                        MakeMovement(inicio, final, p);
                    }
                    //Posiciones Inferiores
                    if (InBoard(current->x + 1, current->y + 2) && !IsWhite(current->x + 1, current->y + 2, b)) {
                        Coordinate* final = {current->x+1, current->y+2};
                        MakeMovement(inicio, final, p);
                    }
                    if (InBoard(current->x - 1, current->y + 2) && !IsWhite(current->x - 1, current->y + 2, b)) {
                        Coordinate* final = {current->x-1, current->y+2};
                        MakeMovement(inicio, final, p);
                    }
                    //Posiciones de la Derecha
                    if (InBoard(current->x + 2, current->y - 1) && !IsWhite(current->x + 2, current->y - 1, b)) {
                        Coordinate* final = {current->x+2, current->y-1};
                        MakeMovement(inicio, final, p);
                    }
                    if (InBoard(current->x + 2, current->y + 1) && !IsWhite(current->x + 2, current->y + 1, b)) {
                        Coordinate* final = {current->x+2, current->y+1};
                        MakeMovement(inicio, final, p);
                    }
                    //Posiciones de la Izquierda
                    if (InBoard(current->x - 2, current->y - 1) && !IsWhite(current->x - 2, current->y - 1, b)) {
                        Coordinate* final = {current->x-2, current->y-1};
                        MakeMovement(inicio, final, p);
                    }
                    if (InBoard(current->x - 2, current->y + 1) && !IsWhite(current->x - 2, current->y + 1, b)) {
                        Coordinate* final = {current->x-2, current->y+1};
                        MakeMovement(inicio, final, p);
                    }
                }
                break;
                default: {
                    Coordinate* final = {current->x, current->y-1};
                    MakeMovement(inicio, final, p);
                }
            }
        }
    }
    return p->position;
}