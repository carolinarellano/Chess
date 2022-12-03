//
// Created by arell on 11/21/2022.
//

#include "Graphics.h"
#include "Globals.h"


#define SCREENWIDTH 830
#define SCREENHEIGHT 500

Piece Whites[16];
Piece Blacks[16];

void MainWindow()
{
    InitWindow(SCREENWIDTH, SCREENHEIGHT, "Chess Game");
    Vector2 mousePoint;
    Texture2D BoardPNG = LoadTexture("../Assets/board.png");
    Texture2D PiecesPNG = LoadTexture("../Assets/pieces.png");
    Texture2D TransparentPNG = LoadTexture("../Assets/transparent.png");
    Texture2D YellowPNG = LoadTexture("../Assets/yellow.png");
    Texture2D StatusPNG = LoadTexture("../Assets/status.png");

    while (!WindowShouldClose())
    {
        //mousePoint = GetMonitorPosition();
        BeginDrawing();
        DrawGraphics(BoardPNG, PiecesPNG, TransparentPNG);
        EndDrawing();
    }
    CloseWindow();        // Close window and OpenGL context
}

void DrawGraphics(Texture2D BoardPNG, Texture2D PiecesPNG, Texture2D TransparentPNG)
{
    ClearBackground((Color) {57, 16, 16});
    DrawText("Chess Game",300, 20, 30, LIGHTGRAY);
    DrawTextureRec(BoardPNG, (Rectangle) {0, 0, BoardPNG.width, BoardPNG.height}, (Vector2) {0, 60},RAYWHITE);
    //  Texture -> image   Source -> Rectangle (position x, position y, ancho, alto) Pos -> (coordenadas x, y), fondo
    //DrawTextureRec(Pieces.texture, Pieces.source, Pieces.position, RAYWHITE);
    //        DrawTextureRec(Pieces.texture, (Rectangle) {0, 117, 228, 112}, (Vector2) {550, 160}, RAYWHITE);

    //Definition of pieces; one by one
    //Empty, BPawn(8), BBishop(2), BKnight(2), BRook(2), BQueen(1), BKing(1),
    //       WPawn(8), WBishop(2), WKnight(2), WRook(2), WQueen(1), WKing(1);

    Picture Pieces = {PiecesPNG, (Rectangle){0, 117, 228, 112}, {550, 160}};
    Picture B_King = {PiecesPNG,  (Rectangle) {0,  133,  37,  41}, {302,104}};
    Picture B_Queen = {PiecesPNG, (Rectangle) {41, 133,  37,  41}, {264,104}};
    Picture B_Rook1 = {PiecesPNG, (Rectangle) {80, 133,  37,  41}, {136,104}};
    Picture B_Rook2 = {PiecesPNG, (Rectangle) {80, 133,  37,  41}, {435,104}};
    Picture B_Bishop1 = {PiecesPNG, (Rectangle) {117, 133,  37,  41}, {221,104}};
    Picture B_Bishop2 = {PiecesPNG, (Rectangle) {117, 133,  37,  41}, {347,104}};
    Picture B_Knight1 = {PiecesPNG, (Rectangle) {151, 133,  37,  41}, {176,104}};
    Picture B_Knight2 = {PiecesPNG, (Rectangle) {151, 133,  37,  41}, {387,104}};
    Picture B_Pawn1 = {PiecesPNG, (Rectangle) {190, 133, 37, 41}, {133, 146}};
    Picture B_Pawn2 = {PiecesPNG, (Rectangle) {190, 133, 37, 41}, {177, 146}};
    Picture B_Pawn3 = {PiecesPNG, (Rectangle) {190, 133, 37, 41}, {219, 146}};
    Picture B_Pawn4 = {PiecesPNG, (Rectangle) {190, 133, 37, 41}, {261, 146}};
    Picture B_Pawn5 = {PiecesPNG, (Rectangle) {190, 133, 37, 41}, {303, 146}};
    Picture B_Pawn6 = {PiecesPNG, (Rectangle) {190, 133, 37, 41}, {347, 146}};
    Picture B_Pawn7 = {PiecesPNG, (Rectangle) {190, 133, 37, 41}, {388, 146}};
    Picture B_Pawn8 = {PiecesPNG, (Rectangle) {190, 133, 37, 41}, {430, 146}};

    Picture W_King = {PiecesPNG,  (Rectangle) {0,  183,  37,  45}, {302,392}};
    Picture W_Queen = {PiecesPNG, (Rectangle) {41, 183,  37,  45}, {264,392}};
    Picture W_Rook1 = {PiecesPNG, (Rectangle) {80, 183,  37,  45}, {136,392}};
    Picture W_Rook2 = {PiecesPNG, (Rectangle) {80, 183,  37,  45}, {435,392}};
    Picture W_Bishop1 = {PiecesPNG, (Rectangle) {117, 183,  37,  45}, {221,392}};
    Picture W_Bishop2 = {PiecesPNG, (Rectangle) {117, 183,  37,  45}, {347,392}};
    Picture W_Knight1 = {PiecesPNG, (Rectangle) {151, 183,  37,  45}, {176,392}};
    Picture W_Knight2 = {PiecesPNG, (Rectangle) {151, 183,  37,  45}, {387,392}};
    Picture W_Pawn1 = {PiecesPNG, (Rectangle) {190, 190, 37, 41}, {133, 356}};
    Picture W_Pawn2 = {PiecesPNG, (Rectangle) {190, 190, 37, 41}, {177, 356}};
    Picture W_Pawn3 = {PiecesPNG, (Rectangle) {190, 190, 37, 41}, {219, 356}};
    Picture W_Pawn4 = {PiecesPNG, (Rectangle) {190, 190, 37, 41}, {261, 356}};
    Picture W_Pawn5 = {PiecesPNG, (Rectangle) {190, 190, 37, 41}, {303, 356}};
    Picture W_Pawn6 = {PiecesPNG, (Rectangle) {190, 190, 37, 41}, {347, 356}};
    Picture W_Pawn7 = {PiecesPNG, (Rectangle) {190, 190, 37, 41}, {388, 356}};
    Picture W_Pawn8 = {PiecesPNG, (Rectangle) {190, 190, 37, 41}, {430, 356}};

    Picture BPieces[] = { B_King,B_Queen,
                         B_Pawn1, B_Pawn2,
                         B_Pawn3, B_Pawn4,
                         B_Pawn5, B_Pawn6,
                         B_Pawn7, B_Pawn8,
                         B_Rook1, B_Rook2,
                         B_Knight1, B_Knight2,
                         B_Bishop1,B_Bishop2};

    Picture WPieces[] = {W_King, W_Queen,
                         W_Pawn1,W_Pawn2,
                         W_Pawn3, W_Pawn4,
                         W_Pawn5, W_Pawn6,
                         W_Pawn7, W_Pawn8,
                         W_Rook1, W_Rook2,
                         W_Knight1, W_Knight2,
                         W_Bishop1, W_Bishop2};

    //Assignation of pictures to the pieces

    for(int i = 0; i < 16; i++)
    {
        Whites[i].piece = WPieces[i];
        Blacks[i].piece = BPieces[i];
    }

    Whites[0].ID = WKing; Whites[1].ID = WQueen;
    Whites[2].ID = WPawn; Whites[3].ID = WPawn;
    Whites[4].ID = WPawn; Whites[5].ID = WPawn;
    Whites[6].ID = WPawn; Whites[7].ID = WPawn;
    Whites[8].ID = WPawn; Whites[9].ID = WPawn;
    Whites[10].ID = WRook; Whites[11].ID = WRook;
    Whites[12].ID = WKnight; Whites[13].ID = WKnight;
    Whites[14].ID = WBishop; Whites[15].ID = WBishop;

    Blacks[0].ID = BKing; Blacks[1].ID = BQueen;
    Blacks[2].ID = BPawn; Blacks[3].ID = BPawn;
    Blacks[4].ID = BPawn; Blacks[5].ID = BPawn;
    Blacks[6].ID = BPawn; Blacks[7].ID = BPawn;
    Blacks[8].ID = BPawn; Blacks[9].ID = BPawn;
    Blacks[10].ID = BRook; Blacks[11].ID = BRook;
    Blacks[12].ID = BKnight; Blacks[13].ID = BKnight;
    Blacks[14].ID = BBishop; Blacks[15].ID = BBishop;

    for(int i = 0; i < 16; i++)
    {
        DrawTextureRec(Blacks[i].piece.texture, Blacks[i].piece.source, Blacks[i].piece.position, RAYWHITE);
        DrawTextureRec(Whites[i].piece.texture, Whites[i].piece.source, Whites[i].piece.position, RAYWHITE);
    }

    Picture EmptyPicture = {TransparentPNG, (Rectangle) {0,  0,  42,  42}, {90, 187}};

    int sum = 42;
    for(int i = 0; i < 8; i++)
    {
        int y = 42;
        DrawTextureRec(EmptyPicture.texture, EmptyPicture.source, (Vector2) {EmptyPicture.position.x + sum, EmptyPicture.position.y}, RAYWHITE);
        DrawTextureRec(EmptyPicture.texture, EmptyPicture.source, (Vector2) {EmptyPicture.position.x + sum, EmptyPicture.position.y + y}, RAYWHITE);
        sum = sum + 42;
    }

    int add = 42;
    for(int i = 0; i < 8; i++)
    {
        int y = 84;
        DrawTextureRec(EmptyPicture.texture, EmptyPicture.source, (Vector2) {EmptyPicture.position.x + add, EmptyPicture.position.y + y}, RAYWHITE);
        DrawTextureRec(EmptyPicture.texture, EmptyPicture.source, (Vector2) {EmptyPicture.position.x + add, EmptyPicture.position.y + y + 42}, RAYWHITE);
        add = add + 42;
    }
}

//Translate from matrix to pixels
Coordinate* translation(Piece *p, int nx, int ny)
{
    Coordinate *translated = calloc(1, sizeof(Coordinate));
    translated->x = p->piece.position.x + nx*42;
    translated->y = p->piece.position.y + ny*42;
    p->piece.position.x = translated->x;
    p->piece.position.y = translated->y;
    return translated;
};

void Movement(Piece *Piece_to_move, Coordinate *Coordinate_to_arrive, void*(swap)(Board, void*, void*)){

}
