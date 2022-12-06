#include <stdio.h>
#include "raylib.h"
#include "Board.h"
#include "Files.h"
#include "Events.h"
#include "Movements.h"
#include "Structs.h"

int draw_active = 0;
int can_play = 1;
int main(int argc, char** argv) {

    InitWindow(830, 600, "Super Cool Chess");
    Board board = calloc(1, sizeof(Board));
    board = InitBoard();
    int step = GetScreenHeight() / BOARD_SIDE; //Carga las textures
    Texture2D* textures = LoadAssets(step);

    if (board == NULL || textures == NULL) { //El board no se carga bien
        if (board)
            DestroyBoard(board);
        if (textures)
            DestroyAssets(textures);
        CloseWindow();
        return 1;
    }

    //char* new_game = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

    //Carga el juego guardado en el archivo de texto (nuevo o guardado anteriormente)
    char* game = LoadGame();
    LoadFenString(board, game);

    //Siempre empieza con las blancas
    char current_player = 'w';
    Move* possible_moves = NULL;
    int number_of_moves = 0;

    int is_pos_selected = 0;
    int selected_row = -1;
    int selected_col = -1;

    while (!WindowShouldClose()) {

        DrawText("Save your game", 725, 275, 13, BLACK);
        DrawText("Press S ", 750, 290, 13, DARKBLUE);

        DrawText("Draw?", 760, 315, 13, BLACK);
        DrawText("Press D", 750, 330, 13, DARKBLUE);

        //Mientras no se haya activado la bandera de draw, se puede jugar
        if(can_play){
            //Al momento de dar click en el tablero, se obtiene la posicion del click para mostrar los movimientos posibles de la pieza seleccionada
            if (PlayerClickedOnBoard()) {
                int row, col;
                GetBoardPosition(&row, &col);
                if (!is_pos_selected && !IsEmpty(col, row, board)) {
                    if (current_player == 'w' && IsWhite(col, row, board)) {
                        is_pos_selected = 1;
                        selected_col = col;
                        selected_row = row;
                        possible_moves = GenerateMoves((Move) {selected_col, selected_row}, board, &number_of_moves);
                    } else if (current_player == 'b' && IsBlack(col, row, board)) {
                        is_pos_selected = 1;
                        selected_col = col;
                        selected_row = row;
                        possible_moves = GenerateMoves((Move) {selected_col, selected_row}, board, &number_of_moves);
                    }
                } else if (is_pos_selected && row == selected_row && col == selected_col) {
                    is_pos_selected = 0;
                    selected_row = -1;
                    selected_col = -1;
                    MemFree(possible_moves);
                    number_of_moves = 0;
                } else if (is_pos_selected && CheckMove(possible_moves, number_of_moves, (Move) {col, row})) {
                    *(*(board + row) + col) = *(*(board + selected_row) + selected_col);
                    *(*(board + selected_row) + selected_col) = EMPTY;
                    is_pos_selected = 0;
                    selected_row = -1;
                    selected_col = -1;
                    MemFree(possible_moves);
                    number_of_moves = 0;
                    //cambia de jugador
                    current_player = (current_player == 'w') ? 'b' : 'w';
                }
            }
        }

        BeginDrawing();

        ClearBackground((Color) {206, 207, 198, 0});
        PrintBoard(board, textures);
        if (is_pos_selected) {
            step = GetScreenHeight() / BOARD_SIDE;
            int start = (GetScreenWidth() - (step * 8)) / 2;
            DrawRectangle((selected_col * step) + start, selected_row * step, step, step, (Color) { 200, 200, 10, 100 });
            for (int i = 0; i < number_of_moves; i++) {
                DrawRectangle(((possible_moves + i)->x * step) + start, (possible_moves + i)->y * step, step, step, (Color) { 200, 10, 10, 100 });
            }
        }

        //Para guardar el juego, se presiona S y se escribe en el archivo de texto la partida actual
        if(IsKeyPressed(KEY_S))
            SaveGame(board);
        //Al presionar D, se declara empate y ya no se pueden mover las piezas, el juego se reinicia
        if(IsKeyReleased(KEY_D)){
            draw_active = 1;
            can_play = 0;
        }

        Draw(draw_active);
        EndDrawing();
    }

    DestroyBoard(board);
    DestroyAssets(textures);
    SaveGame(board);
    CloseWindow();
    return 0;
}

/*LO QUE FALTA:
//Enroque
//Promocion peones
//Jaque - Jaque Mate
*/