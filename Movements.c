//
// Created by renis on 12/1/2022.
//

#include "Movements.h"

Move* GenerateMoves(Move start, Board board, int* nm) {
    if (!CheckMateBlack(board) || !CheckMateWhite(board)) {
        *nm = 0;
        Move *possible_moves = NULL;
        if (IsBlack(start.x, start.y, board)) {
            switch (GetPiece(start.x, start.y, board)) {
                case BLACK_PAWN: {
                    possible_moves = MemAlloc(sizeof(Move) * 4);
                    if (start.y == 1 && IsEmpty(start.x, start.y + 2, board) && IsEmpty(start.x, start.y + 1, board)) {
                        *(possible_moves + *nm) = (Move) {start.x, start.y + 2};
                        (*nm)++;
                    }
                    if (IsEmpty(start.x, start.y + 1, board) && IsInBoard(start.x, start.y + 1)) {
                        *(possible_moves + *nm) = (Move) {start.x, start.y + 1};
                        (*nm)++;
                    }
                    if (IsWhite(start.x + 1, start.y + 1, board) && IsInBoard(start.x + 1, start.y + 1)) {
                        *(possible_moves + *nm) = (Move) {start.x + 1, start.y + 1};
                        (*nm)++;
                    }
                    if (IsWhite(start.x - 1, start.y + 1, board) && IsInBoard(start.x - 1, start.y + 1)) {
                        *(possible_moves + *nm) = (Move) {start.x - 1, start.y + 1};
                        (*nm)++;
                    }
                    //if(start.y == 7)
                        //Promote
                }
                    break;
                case BLACK_ROOK: {
                    possible_moves = MemAlloc(sizeof(Move) * 16);
                    /* go right */
                    for (int i = start.x + 1; IsInBoard(i, start.y) && !IsBlack(i, start.y, board); i++){
                        *(possible_moves + *nm) = (Move) {i, start.y};
                        (*nm)++;
                        if (IsWhite(i, start.y, board))
                            break;
                    }
                    /* go left */
                    for (int i = start.x - 1; IsInBoard(i, start.y) && !IsBlack(i, start.y, board); i--) {
                        *(possible_moves + *nm) = (Move) {i, start.y};
                        (*nm)++;
                        if (IsWhite(i, start.y, board))
                            break;
                    }
                    /* go down */
                    for (int i = start.y + 1; IsInBoard(start.x, i) && !IsBlack(start.x, i, board); i++) {
                        *(possible_moves + *nm) = (Move) {start.x, i};
                        (*nm)++;
                        if (IsWhite(start.x, i, board))
                            break;
                    }
                    /* go up */
                    for (int i = start.y - 1; IsInBoard(start.x, i) && !IsBlack(start.x, i, board); i--) {
                        *(possible_moves + *nm) = (Move) {start.x, i};
                        (*nm)++;
                        if (IsWhite(start.x, i, board))
                            break;
                    }
                }
                    break;
                case BLACK_BISHOP: {
                    possible_moves = MemAlloc(sizeof(Move) * 16);
                    /* down right */
                    for (int i = start.x + 1, j = start.y + 1; IsInBoard(i, j) && !IsBlack(i, j, board); i++, j++) {
                        *(possible_moves + *nm) = (Move) {i, j};
                        (*nm)++;
                        if (IsWhite(i, j, board))
                            break;
                    }
                    /* down left */
                    for (int i = start.x - 1, j = start.y + 1; IsInBoard(i, j) && !IsBlack(i, j, board); i--, j++) {
                        *(possible_moves + *nm) = (Move) {i, j};
                        (*nm)++;
                        if (IsWhite(i, j, board))
                            break;
                    }
                    /* up right */
                    for (int i = start.x + 1, j = start.y - 1; IsInBoard(i, j) && !IsBlack(i, j, board); i++, j--) {
                        *(possible_moves + *nm) = (Move) {i, j};
                        (*nm)++;
                        if (IsWhite(i, j, board))
                            break;
                    }
                    /* up left */
                    for (int i = start.x - 1, j = start.y - 1; IsInBoard(i, j) && !IsBlack(i, j, board); i--, j--) {
                        *(possible_moves + *nm) = (Move) {i, j};
                        (*nm)++;
                        if (IsWhite(i, j, board))
                            break;
                    }
                }
                    break;
                case BLACK_QUEEN: {
                    possible_moves = MemAlloc(sizeof(Move) * 32);
                    /* down right */
                    for (int i = start.x + 1, j = start.y + 1; IsInBoard(i, j) && !IsBlack(i, j, board); i++, j++) {
                        *(possible_moves + *nm) = (Move) {i, j};
                        (*nm)++;
                        if (IsWhite(i, j, board))
                            break;
                    }
                    /* down left */
                    for (int i = start.x - 1, j = start.y + 1; IsInBoard(i, j) && !IsBlack(i, j, board); i--, j++) {
                        *(possible_moves + *nm) = (Move) {i, j};
                        (*nm)++;
                        if (IsWhite(i, j, board))
                            break;
                    }
                    /* up right */
                    for (int i = start.x + 1, j = start.y - 1; IsInBoard(i, j) && !IsBlack(i, j, board); i++, j--) {
                        *(possible_moves + *nm) = (Move) {i, j};
                        (*nm)++;
                        if (IsWhite(i, j, board))
                            break;
                    }
                    /* up left */
                    for (int i = start.x - 1, j = start.y - 1; IsInBoard(i, j) && !IsBlack(i, j, board); i--, j--) {
                        *(possible_moves + *nm) = (Move) {i, j};
                        (*nm)++;
                        if (IsWhite(i, j, board))
                            break;
                    }
                    /* go right */
                    for (int i = start.x + 1; IsInBoard(i, start.y) && !IsBlack(i, start.y, board); i++) {
                        *(possible_moves + *nm) = (Move) {i, start.y};
                        (*nm)++;
                        if (IsWhite(i, start.y, board))
                            break;
                    }
                    /* go left */
                    for (int i = start.x - 1; IsInBoard(i, start.y) && !IsBlack(i, start.y, board); i--) {
                        *(possible_moves + *nm) = (Move) {i, start.y};
                        (*nm)++;
                        if (IsWhite(i, start.y, board))
                            break;
                    }
                    /* go down */
                    for (int i = start.y + 1; IsInBoard(start.x, i) && !IsBlack(start.x, i, board); i++) {
                        *(possible_moves + *nm) = (Move) {start.x, i};
                        (*nm)++;
                        if (IsWhite(start.x, i, board))
                            break;
                    }
                    /* go up */
                    for (int i = start.y - 1; IsInBoard(start.x, i) && !IsBlack(start.x, i, board); i--) {
                        *(possible_moves + *nm) = (Move) {start.x, i};
                        (*nm)++;
                        if (IsWhite(start.x, i, board))
                            break;
                    }
                }
                    break;
                case BLACK_KING: {
                    possible_moves = MemAlloc(sizeof(Move) * 8);
                    /* all the position anti clockwise sense */
                    for (int y = -1; y <= 1; y++) {
                        for (int x = -1; x <= 1; x++) {
                            if (!(x == 0 && y == 0)) {
                                if (IsInBoard(start.x + x, start.y + y) && !IsBlack(start.x + x, start.y + y, board)) {
                                    *(possible_moves + *nm) = (Move) {start.x + x, start.y + y};
                                    (*nm)++;
                                }
                            }
                        }
                    }

                }
                    break;
                case BLACK_KNIGHT: {
                    /* not sure if it's 8 or not */
                    possible_moves = MemAlloc(sizeof(Move) * 8);
                    /* Upper positions */
                    if (IsInBoard(start.x + 1, start.y - 2) && !IsBlack(start.x + 1, start.y - 2, board)) {
                        *(possible_moves + *nm) = (Move) {start.x + 1, start.y - 2};
                        (*nm)++;
                    }
                    if (IsInBoard(start.x - 1, start.y - 2) && !IsBlack(start.x - 1, start.y - 2, board)) {
                        *(possible_moves + *nm) = (Move) {start.x - 1, start.y - 2};
                        (*nm)++;
                    }
                    /* Lower positions */
                    if (IsInBoard(start.x + 1, start.y + 2) && !IsBlack(start.x + 1, start.y + 2, board)) {
                        *(possible_moves + *nm) = (Move) {start.x + 1, start.y + 2};
                        (*nm)++;
                    }
                    if (IsInBoard(start.x - 1, start.y + 2) && !IsBlack(start.x - 1, start.y + 2, board)) {
                        *(possible_moves + *nm) = (Move) {start.x - 1, start.y + 2};
                        (*nm)++;
                    }
                    /* Right positions */
                    if (IsInBoard(start.x + 2, start.y - 1) && !IsBlack(start.x + 2, start.y - 1, board)) {
                        *(possible_moves + *nm) = (Move) {start.x + 2, start.y - 1};
                        (*nm)++;
                    }
                    if (IsInBoard(start.x + 2, start.y + 1) && !IsBlack(start.x + 2, start.y + 1, board)) {
                        *(possible_moves + *nm) = (Move) {start.x + 2, start.y + 1};
                        (*nm)++;
                    }
                    /* Left positions */
                    if (IsInBoard(start.x - 2, start.y - 1) && !IsBlack(start.x - 2, start.y - 1, board)) {
                        *(possible_moves + *nm) = (Move) {start.x - 2, start.y - 1};
                        (*nm)++;
                    }
                    if (IsInBoard(start.x - 2, start.y + 1) && !IsBlack(start.x - 2, start.y + 1, board)) {
                        *(possible_moves + *nm) = (Move) {start.x - 2, start.y + 1};
                        (*nm)++;
                    }
                }
                    break;
                default: {
                    possible_moves = MemAlloc(sizeof(Move));
                    *possible_moves = (Move) {start.x, start.y + 1};
                    *nm = 1;
                }
            }
        } else {
            switch (GetPiece(start.x, start.y, board)) {
                case WHITE_PAWN: {
                    possible_moves = MemAlloc(sizeof(Move) * 4);
                    if (start.y == 6 && IsEmpty(start.x, start.y - 2, board) && IsEmpty(start.x, start.y - 1, board)) {
                        *(possible_moves + *nm) = (Move) {start.x, start.y - 2};
                        (*nm)++;
                    }
                    if (IsEmpty(start.x, start.y - 1, board) && IsInBoard(start.x, start.y - 1)) {
                        *(possible_moves + *nm) = (Move) {start.x, start.y - 1};
                        (*nm)++;
                    }
                    if (IsBlack(start.x + 1, start.y - 1, board) && IsInBoard(start.x + 1, start.y - 1)) {
                        *(possible_moves + *nm) = (Move) {start.x + 1, start.y - 1};
                        (*nm)++;
                    }
                    if (IsBlack(start.x - 1, start.y - 1, board) && IsInBoard(start.x - 1, start.y - 1)) {
                        *(possible_moves + *nm) = (Move) {start.x - 1, start.y - 1};
                        (*nm)++;
                    }
                }
                    break;
                case WHITE_ROOK: {
                    possible_moves = MemAlloc(sizeof(Move) * 16);
                    /* go right */
                    for (int i = start.x + 1; IsInBoard(i, start.y) && !IsWhite(i, start.y, board); i++) {
                        *(possible_moves + *nm) = (Move) {i, start.y};
                        (*nm)++;
                        if (IsBlack(i, start.y, board))
                            break;
                    }
                    /* go left */
                    for (int i = start.x - 1; IsInBoard(i, start.y) && !IsWhite(i, start.y, board); i--) {
                        *(possible_moves + *nm) = (Move) {i, start.y};
                        (*nm)++;
                        if (IsBlack(i, start.y, board))
                            break;
                    }
                    /* go down */
                    for (int i = start.y + 1; IsInBoard(start.x, i) && !IsWhite(start.x, i, board); i++) {
                        *(possible_moves + *nm) = (Move) {start.x, i};
                        (*nm)++;
                        if (IsBlack(start.x, i, board))
                            break;
                    }
                    /* go up */
                    for (int i = start.y - 1; IsInBoard(start.x, i) && !IsWhite(start.x, i, board); i--) {
                        *(possible_moves + *nm) = (Move) {start.x, i};
                        (*nm)++;
                        if (IsBlack(start.x, i, board))
                            break;
                    }
                }
                    break;
                case WHITE_BISHOP: {
                    possible_moves = MemAlloc(sizeof(Move) * 16);
                    /* down right */
                    for (int i = start.x + 1, j = start.y + 1; IsInBoard(i, j) && !IsWhite(i, j, board); i++, j++) {
                        *(possible_moves + *nm) = (Move) {i, j};
                        (*nm)++;
                        if (IsBlack(i, j, board))
                            break;
                    }
                    /* down left */
                    for (int i = start.x - 1, j = start.y + 1; IsInBoard(i, j) && !IsWhite(i, j, board); i--, j++) {
                        *(possible_moves + *nm) = (Move) {i, j};
                        (*nm)++;
                        if (IsBlack(i, j, board))
                            break;
                    }
                    /* up right */
                    for (int i = start.x + 1, j = start.y - 1; IsInBoard(i, j) && !IsWhite(i, j, board); i++, j--) {
                        *(possible_moves + *nm) = (Move) {i, j};
                        (*nm)++;
                        if (IsBlack(i, j, board))
                            break;
                    }
                    /* up left */
                    for (int i = start.x - 1, j = start.y - 1; IsInBoard(i, j) && !IsWhite(i, j, board); i--, j--) {
                        *(possible_moves + *nm) = (Move) {i, j};
                        (*nm)++;
                        if (IsBlack(i, j, board))
                            break;
                    }
                }
                    break;
                case WHITE_QUEEN: {
                    possible_moves = MemAlloc(sizeof(Move) * 32);
                    /* down right */
                    for (int i = start.x + 1, j = start.y + 1; IsInBoard(i, j) && !IsWhite(i, j, board); i++, j++) {
                        *(possible_moves + *nm) = (Move) {i, j};
                        (*nm)++;
                        if (IsBlack(i, j, board))
                            break;
                    }
                    /* down left */
                    for (int i = start.x - 1, j = start.y + 1; IsInBoard(i, j) && !IsWhite(i, j, board); i--, j++) {
                        *(possible_moves + *nm) = (Move) {i, j};
                        (*nm)++;
                        if (IsBlack(i, j, board))
                            break;
                    }
                    /* up right */
                    for (int i = start.x + 1, j = start.y - 1; IsInBoard(i, j) && !IsWhite(i, j, board); i++, j--) {
                        *(possible_moves + *nm) = (Move) {i, j};
                        (*nm)++;
                        if (IsBlack(i, j, board))
                            break;
                    }
                    /* up left */
                    for (int i = start.x - 1, j = start.y - 1; IsInBoard(i, j) && !IsWhite(i, j, board); i--, j--) {
                        *(possible_moves + *nm) = (Move) {i, j};
                        (*nm)++;
                        if (IsBlack(i, j, board))
                            break;
                    }
                    /* go right */
                    for (int i = start.x + 1; IsInBoard(i, start.y) && !IsWhite(i, start.y, board); i++) {
                        *(possible_moves + *nm) = (Move) {i, start.y};
                        (*nm)++;
                        if (IsBlack(i, start.y, board))
                            break;
                    }
                    /* go left */
                    for (int i = start.x - 1; IsInBoard(i, start.y) && !IsWhite(i, start.y, board); i--) {
                        *(possible_moves + *nm) = (Move) {i, start.y};
                        (*nm)++;
                        if (IsBlack(i, start.y, board))
                            break;
                    }
                    /* go down */
                    for (int i = start.y + 1; IsInBoard(start.x, i) && !IsWhite(start.x, i, board); i++) {
                        *(possible_moves + *nm) = (Move) {start.x, i};
                        (*nm)++;
                        if (IsBlack(start.x, i, board))
                            break;
                    }
                    /* go up */
                    for (int i = start.y - 1; IsInBoard(start.x, i) && !IsWhite(start.x, i, board); i--) {
                        *(possible_moves + *nm) = (Move) {start.x, i};
                        (*nm)++;
                        if (IsBlack(start.x, i, board))
                            break;
                    }
                }
                    break;
                case WHITE_KING: {
                    possible_moves = MemAlloc(sizeof(Move) * 8);
                    /* all the position anti clockwise sense */
                    for (int y = -1; y <= 1; y++) {
                        for (int x = -1; x <= 1; x++) {
                            if (!(x == 0 && y == 0)) {
                                if (IsInBoard(start.x + x, start.y + y) && !IsWhite(start.x + x, start.y + y, board)) {
                                    *(possible_moves + *nm) = (Move) {start.x + x, start.y + y};
                                    (*nm)++;
                                }
                            }
                        }
                    }

                }
                    break;
                case WHITE_KNIGHT: {
                    /* not sure if it's 8 or not */
                    possible_moves = MemAlloc(sizeof(Move) * 8);
                    /* Upper positions */
                    if (IsInBoard(start.x + 1, start.y - 2) && !IsWhite(start.x + 1, start.y - 2, board)) {
                        *(possible_moves + *nm) = (Move) {start.x + 1, start.y - 2};
                        (*nm)++;
                    }
                    if (IsInBoard(start.x - 1, start.y - 2) && !IsWhite(start.x - 1, start.y - 2, board)) {
                        *(possible_moves + *nm) = (Move) {start.x - 1, start.y - 2};
                        (*nm)++;
                    }
                    /* Lower positions */
                    if (IsInBoard(start.x + 1, start.y + 2) && !IsWhite(start.x + 1, start.y + 2, board)) {
                        *(possible_moves + *nm) = (Move) {start.x + 1, start.y + 2};
                        (*nm)++;
                    }
                    if (IsInBoard(start.x - 1, start.y + 2) && !IsWhite(start.x - 1, start.y + 2, board)) {
                        *(possible_moves + *nm) = (Move) {start.x - 1, start.y + 2};
                        (*nm)++;
                    }
                    /* Right positions */
                    if (IsInBoard(start.x + 2, start.y - 1) && !IsWhite(start.x + 2, start.y - 1, board)) {
                        *(possible_moves + *nm) = (Move) {start.x + 2, start.y - 1};
                        (*nm)++;
                    }
                    if (IsInBoard(start.x + 2, start.y + 1) && !IsWhite(start.x + 2, start.y + 1, board)) {
                        *(possible_moves + *nm) = (Move) {start.x + 2, start.y + 1};
                        (*nm)++;
                    }
                    /* Left positions */
                    if (IsInBoard(start.x - 2, start.y - 1) && !IsWhite(start.x - 2, start.y - 1, board)) {
                        *(possible_moves + *nm) = (Move) {start.x - 2, start.y - 1};
                        (*nm)++;
                    }
                    if (IsInBoard(start.x - 2, start.y + 1) && !IsWhite(start.x - 2, start.y + 1, board)) {
                        *(possible_moves + *nm) = (Move) {start.x - 2, start.y + 1};
                        (*nm)++;
                    }
                }
                    break;
                default: {
                    possible_moves = MemAlloc(sizeof(Move));
                    *possible_moves = (Move) {start.x, start.y - 1};
                    *nm = 1;
                }
            }
        }
        return possible_moves;
    }

}

int CheckMove(Move* moves, int nm, Move move) {
    for (int i = 0; i < nm; i++) {
        if ((moves + i)->x == move.x && (moves + i)->y == move.y)
            return 1;
    }
    return 0;
}

int IsWhite(int x, int y, Board board) {
    if (GetPiece(x, y, board) >= 'A' && GetPiece(x, y, board) <= 'Z' && GetPiece(x, y, board) != EMPTY)
        return 1;
    return 0;
}

int IsBlack(int x, int y, Board board) {
    if (GetPiece(x, y, board) >= 'a' && GetPiece(x, y, board) <= 'z' && GetPiece(x, y, board) != EMPTY)
        return 1;
    return 0;
}

int IsEmpty(int x, int y, Board board) {
    return (GetPiece(x, y, board) == EMPTY);
}

char GetPiece(int x, int y, Board board) {
    return *(*(board + y) + x);
}

int IsInBoard(int x, int y) {
    return (x < 8 && x > -1 && y > -1 && y < 8);
}

void Win(char* Winner)
{
    DrawText(Winner, 730, 330, 20, BLACK);
    DrawText("Wins!", 730, 340, 20, BLACK);

};

int Draw(int draw_active)
{
    if(draw_active == 1){
        DrawRectangle(240, 225, 350, 150, (Color) {142, 64, 58, 255});
        DrawText("DRAW", 305, 265, 80, BLACK);
    }
    return 1;
}

int CheckMateBlack(Board b){
    for (int i = 0; i < 8; i++){
        for (int j = 0; i < 8; i++){
            if (GetPiece(i, j, b) == BLACK_KING)
                return 0;
        }
    }
    Win("Whites");
    return 1;
}


int CheckMateWhite(Board b)
{
    for (int i = 0; i < 8; i++){
        for (int j = 0; i < 8; i++){
            if(GetPiece(i, j, b) == WHITE_KING){
                return 0;
            }
        }
    }
    Win("Blacks");
    return 1;
};

//int inCheck(Board b)


void Restart(Board board)
{
    int step = GetScreenHeight() / BOARD_SIDE; /* create and resize the textures and load them in vram */
    Texture2D* textures = LoadAssets(step);
    DestroyAssets(textures);
    PrintBoard(board, textures);
};

/*PromotePawn
{
    GetPosition(x, y, b)
}*/
