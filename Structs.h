//
// Created by renis on 12/1/2022.
//

#ifndef SUPERCOOLCHESS_STRUCTS_H
#define SUPERCOOLCHESS_STRUCTS_H

typedef char** Board;

typedef struct move{
    int x;
    int y;
}Move;

typedef struct button_struct {
    Vector2 position;
    Rectangle mask;
    Rectangle collision;
    int status; // 1 if pressed, 0 if not
} Button;





#endif //SUPERCOOLCHESS_STRUCTS_H
