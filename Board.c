//
// Created by renis on 12/1/2022.
//
#include "Files.h"
#include "Board.h"
#include "raylib.h"
#include "stdlib.h"
#include "stdio.h"

Board InitBoard() {
    char** new_board = (char**)malloc(sizeof(char*) * 8);
    if (new_board == NULL) {
        return NULL;
    }
    for (int i = 0; i < 8; i++) {
        *(new_board + i) = (char*)malloc(sizeof(char) * 8);
        if (*(new_board + i) == NULL) {
            return NULL;
        }
    }
    return new_board;
}

int LoadFenString(Board board, char* fen_string) {
    int index = 0; //Lee el string que contiene las posiciones del tablero
    int row = 0;
    int col = 0;

    while (row < BOARD_SIDE) {
        char current = *(fen_string + index); //Obtiene el caracter actual

        if ((current >= 'A' && current <= 'Z') || (current >= 'a' && current <= 'z')) {
            *(*(board + row) + col) = current;
            col++;
        }
        else if (current == '/') {
            row++;
            col = 0;
        }
        else if (current >= '0' && current <= '9') {
            for (int i = 0; i < current - '0'; i++) {
                *(*(board + row) + col) = EMPTY;
                col++;
            }
        }
        else {
            return 1;
        }
        index++;
    }

    return 0;
}

void PrintBoardOnTerminal(Board board) {
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            printf(" %c ", *(*(board + row) + col));
        }
        printf("\n");
    }
}

void PrintBoard(Board board, Texture2D* textures) {
    int step = GetScreenHeight() / BOARD_SIDE;
    int start = (GetScreenWidth() - (step * 8)) / 2; //Se centra el tablero

    for (int row = 0; row < BOARD_SIDE; row++) {
        for (int col = 0; col < BOARD_SIDE; col++) {
            int x_pos = (col * step) + start;
            int y_pos = row * step;
            DrawRectangle(x_pos, y_pos, step, step, (row + col) % 2 == 0 ? BLACK: WHITE);
            if (*(*(board + row) + col) != ' ') {
                x_pos += 10;
                y_pos += 10;
                switch (*(*(board + row) + col)) {
                    case 'b':
                        DrawTexture(textures[0], x_pos, y_pos, WHITE);
                        break;
                    case 'k':
                        DrawTexture(textures[1], x_pos, y_pos, WHITE);
                        break;
                    case 'n':
                        DrawTexture(textures[2], x_pos, y_pos, WHITE);
                        break;
                    case 'p':
                        DrawTexture(textures[3], x_pos, y_pos, WHITE);
                        break;
                    case 'q':
                        DrawTexture(textures[4], x_pos, y_pos, WHITE);
                        break;
                    case 'r':
                        DrawTexture(textures[5], x_pos, y_pos, WHITE);
                        break;
                    case 'B':
                        DrawTexture(textures[6], x_pos, y_pos, WHITE);
                        break;
                    case 'K':
                        DrawTexture(textures[7], x_pos, y_pos, WHITE);
                        break;
                    case 'N':
                        DrawTexture(textures[8], x_pos, y_pos, WHITE);
                        break;
                    case 'P':
                        DrawTexture(textures[9], x_pos, y_pos, WHITE);
                        break;
                    case 'Q':
                        DrawTexture(textures[10], x_pos, y_pos, WHITE);
                        break;
                    case 'R':
                        DrawTexture(textures[11], x_pos, y_pos, WHITE);
                        break;
                    default:
                        printf("Error Unknown Piece");
                }
            }
        }
    }

}

void DestroyBoard(Board board) {
    for (int i = 0; i < BOARD_SIDE; i++) {
        free(*(board + i));
    }
    free(board);
}

