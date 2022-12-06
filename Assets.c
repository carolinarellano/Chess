//
// Created by arell on 12/4/2022.
//

#include "Assets.h"
#include "stdio.h"


Texture2D* LoadAssets(int desired_side_len) {
    desired_side_len -= 20; //Resize de las piezas

    //Array de textures
    Texture2D* loaded_textures = (Texture2D*)MemAlloc(sizeof(Texture2D) * 12);
    if (loaded_textures == NULL) { return NULL; }

    //Se cargan las imagenes a partir de las direcciones de estas (definidas en el .h)
    Image black_bishop_image = LoadImage(BLACK_BISHOP_IMAGE_PATH);
    ImageResize(&black_bishop_image, desired_side_len, desired_side_len);
    *(loaded_textures + 0) = LoadTextureFromImage(black_bishop_image);
    UnloadImage(black_bishop_image);

    Image black_king_image = LoadImage(BLACK_KING_IMAGE_PATH);
    ImageResize(&black_king_image, desired_side_len, desired_side_len);
    *(loaded_textures + 1) = LoadTextureFromImage(black_king_image);
    UnloadImage(black_king_image);


    Image black_knight_image = LoadImage(BLACK_KNIGHT_IMAGE_PATH);
    ImageResize(&black_knight_image, desired_side_len, desired_side_len);
    *(loaded_textures + 2) = LoadTextureFromImage(black_knight_image);
    UnloadImage(black_knight_image);

    Image black_pawn_image = LoadImage(BLACK_PAWN_IMAGE_PATH);
    ImageResize(&black_pawn_image, desired_side_len, desired_side_len);
    *(loaded_textures + 3) = LoadTextureFromImage(black_pawn_image);
    UnloadImage(black_pawn_image);

    Image black_queen_image = LoadImage(BLACK_QUEEN_IMAGE_PATH);
    ImageResize(&black_queen_image, desired_side_len, desired_side_len);
    *(loaded_textures + 4) = LoadTextureFromImage(black_queen_image);
    UnloadImage(black_queen_image);

    Image black_rook_image = LoadImage(BLACK_ROOK_IMAGE_PATH);
    ImageResize(&black_rook_image, desired_side_len, desired_side_len);
    *(loaded_textures + 5) = LoadTextureFromImage(black_rook_image);
    UnloadImage(black_rook_image);

    Image white_bishop_image = LoadImage(WHITE_BISHOP_IMAGE_PATH);
    ImageResize(&white_bishop_image, desired_side_len, desired_side_len);
    *(loaded_textures + 6) = LoadTextureFromImage(white_bishop_image);
    UnloadImage(white_bishop_image);

    Image white_king_image = LoadImage(WHITE_KING_IMAGE_PATH);
    ImageResize(&white_king_image, desired_side_len, desired_side_len);
    *(loaded_textures + 7) = LoadTextureFromImage(white_king_image);
    UnloadImage(white_king_image);

    Image white_knight_image = LoadImage(WHITE_KNIGHT_IMAGE_PATH);
    ImageResize(&white_knight_image, desired_side_len, desired_side_len);
    *(loaded_textures + 8) = LoadTextureFromImage(white_knight_image);
    UnloadImage(white_knight_image);

    Image white_pawn_image = LoadImage(WHITE_PAWN_IMAGE_PATH);
    ImageResize(&white_pawn_image, desired_side_len, desired_side_len);
    *(loaded_textures + 9) = LoadTextureFromImage(white_pawn_image);
    UnloadImage(white_pawn_image);

    Image white_queen_image = LoadImage(WHITE_QUEEN_IMAGE_PATH);
    ImageResize(&white_queen_image, desired_side_len, desired_side_len);
    *(loaded_textures + 10) = LoadTextureFromImage(white_queen_image);
    UnloadImage(white_queen_image);

    Image white_rook_image = LoadImage(WHITE_ROOK_IMAGE_PATH);
    ImageResize(&white_rook_image, desired_side_len, desired_side_len);
    *(loaded_textures + 11) = LoadTextureFromImage(white_rook_image);
    UnloadImage(white_rook_image);

    return loaded_textures;
}

//Se destruyen los assets
void DestroyAssets(Texture2D* textures) {
    MemFree(textures);
}
