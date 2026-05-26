#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include "joc.h"

typedef enum {
    STATE_MENU,
    STATE_PLAYING,
    STATE_SELECTING_MODE,
    STATE_SELECTING_DIMENSION,
    STATE_GAME_MODE,
    STATE_MULTIPLAYER,
    STATE_SINGLEPLAYER
} GameState;

int main()
{
    int dimension;
    int tabla[6][6];
    int jucatorCurent = 1;
    Color colorBackground = {187, 173, 160, 255};
    InitWindow(640,480,"Tic-Tac-Toe");
    SetTargetFPS(60);
    GameState state = STATE_MENU;

    int selectedBtn = 0;

    while(!WindowShouldClose())
    {
        Vector2 mouse = GetMousePosition();

        Rectangle M3Btn = { 245, 200, 160, 48 };
        Rectangle M4Btn = { 245, 260, 160, 48 };
        Rectangle M5Btn = { 245, 320, 160, 48 };
        Rectangle M6Btn = { 245, 380, 160, 48 };
        Rectangle SingleBtn = { 245, 240, 160, 48 };
        Rectangle MultiBtn = { 245, 300, 160, 48 };


        bool hoveredm3 = CheckCollisionPointRec(mouse, M3Btn);
        bool hoveredm4 = CheckCollisionPointRec(mouse, M4Btn);
        bool hoveredm5 = CheckCollisionPointRec(mouse, M5Btn);
        bool hoveredm6 = CheckCollisionPointRec(mouse, M6Btn);
        bool hoveredsingle = CheckCollisionPointRec(mouse, SingleBtn);
        bool hoveredmulti = CheckCollisionPointRec(mouse, MultiBtn);
        switch(state){
            case STATE_MENU:{
                if (IsKeyPressed(KEY_ENTER)){
                    state=STATE_SELECTING_DIMENSION;
                }
                break;
            }
            case STATE_SELECTING_DIMENSION:{
                if (hoveredm3 && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                    state=STATE_SELECTING_MODE;
                    dimension=3;
                }
                if (hoveredm4 && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                    state=STATE_SELECTING_MODE;
                    dimension=4;
                }
                if (hoveredm5 && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                    state=STATE_SELECTING_MODE;
                    dimension=5;
                }
                if (hoveredm6 && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                    state=STATE_SELECTING_MODE;
                    dimension=6;
                }
                break;
            }
            case STATE_SELECTING_MODE:{
                if (hoveredsingle && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                    state = STATE_SINGLEPLAYER;
                    for(int i=0; i<6; i++) for(int j=0; j<6; j++) tabla[i][j] = 0;
                    jucatorCurent = 1;
                }
                if (hoveredmulti && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                    state = STATE_MULTIPLAYER;
                    for(int i=0; i<6; i++) for(int j=0; j<6; j++) tabla[i][j] = 0;
                    jucatorCurent = 1;
                }
                break;
            }

            case STATE_SINGLEPLAYER:
            case STATE_MULTIPLAYER: {
                int cellSize = 50;
                int gridWidth = dimension * cellSize;
                int gridHeight = dimension * cellSize;
                int startX = (640 - gridWidth) / 2;
                int startY = (480 - gridHeight) / 2 + 30;

                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    for (int i = 0; i < dimension; i++) {
                        for (int j = 0; j < dimension; j++) {
                            int cellX = startX + j * cellSize;
                            int cellY = startY + i * cellSize;
                            Rectangle celulaRec = { cellX, cellY, cellSize, cellSize };

                            if (CheckCollisionPointRec(mouse, celulaRec)) {
                                if (tabla[i][j] == 0) {
                                    tabla[i][j] = jucatorCurent;

                                    jucatorCurent = (jucatorCurent == 1) ? 2 : 1;
                                }
                            }
                        }
                    }
                }
                break;
            }
        }

        // ── MENU ─────────────────────────────────────────────────────────
        BeginDrawing();
        ClearBackground(BEIGE);
        switch(state){
            case STATE_MENU:{
                DrawText("Tic-Tac-Toe",
                    (640 - MeasureText("Tic-Tac-Toe", 80)) / 2,
                    80, 80, DARKBROWN);

                DrawRectangle(245, 260, 160, 48, WHITE);

                const char *sl = "START";

                DrawText(sl,250 + (160 - MeasureText(sl, 24)) / 2,272,24, BLACK);

                const char *hint = "Press ENTER to start";
                DrawText(hint,
                    (640 - MeasureText(hint, 20)) / 2,
                    332, 20, DARKBROWN);

                EndDrawing();

            break;
            }

            case STATE_SELECTING_DIMENSION:{
                //Selectarea Marimii grilei de joc
                DrawText("Dimensiune Grilei",(840 - MeasureText("Dimensiune Grilei", 80)) / 2,80, 60, DARKBROWN);

                DrawRectangle(245, 200, 160, 48, WHITE);
                DrawRectangle(245, 260, 160, 48, WHITE);
                DrawRectangle(245, 320, 160, 48, WHITE);
                DrawRectangle(245, 380, 160, 48, WHITE);

                const char *s2 = "3X3";
                const char *s3 = "4X4";
                const char *s4 = "5X5";
                const char *s5 = "6X6";

                DrawText(s2,250 + (150 - MeasureText(s2, 20)) / 2,214,20, BLACK);
                DrawText(s3,250 + (150 - MeasureText(s3, 20)) / 2,274, 20, BLACK);
                DrawText(s4,250 + (150 - MeasureText(s3, 20)) / 2,334, 20, BLACK);
                DrawText(s5,250 + (150 - MeasureText(s3, 20)) / 2,394, 20, BLACK);

                EndDrawing();
            break;
            }

            case STATE_SELECTING_MODE:{
                // Afisare_Meniu
                DrawText("Meniu",(640 - MeasureText("Meniu", 80)) / 2,80, 80, DARKBROWN);

                DrawRectangle(245, 240, 160, 48, WHITE);
                DrawRectangle(245, 300, 160, 48, WHITE);

                const char *s6 = "Singleplayer";
                const char *s7 = "Multiplayer";

                DrawText(s6,255 + (160 - MeasureText(s6, 24)) / 2,252,20, BLACK);

                DrawText(s7,250 + (160 - MeasureText(s7, 20)) / 2,312, 20, BLACK);

                EndDrawing();
            break;
            }

            case STATE_SINGLEPLAYER:
            case STATE_MULTIPLAYER: {
                if (state == STATE_SINGLEPLAYER) {
                    DrawText("Singleplayer", (640 - MeasureText("Singleplayer", 40)) / 2, 20, 40, DARKBROWN);
                } else {
                    DrawText("Multiplayer", (640 - MeasureText("Multiplayer", 40)) / 2, 20, 40, DARKBROWN);
                }

                int cellSize = 50;
                int gridWidth = dimension * cellSize;
                int gridHeight = dimension * cellSize;
                int startX = (640 - gridWidth) / 2;
                int startY = (480 - gridHeight) / 2 + 30;

                const char* textRand = (jucatorCurent == 1) ? "Randul lui: X" : "Randul lui: O";
                DrawText(textRand, 20, 440, 20, DARKBROWN);

                for (int i = 0; i < dimension; i++) {
                    for (int j = 0; j < dimension; j++) {
                        int cellX = startX + j * cellSize;
                        int cellY = startY + i * cellSize;

                        DrawRectangleLines(cellX, cellY, cellSize, cellSize, DARKBROWN);
                        DrawRectangle(cellX + 2, cellY + 2, cellSize - 4, cellSize - 4, RAYWHITE);

                        if (tabla[i][j] == 1) {
                            DrawText("X", cellX + 15, cellY + 10, 30, RED);
                        }
                        else if (tabla[i][j] == 2) {
                            DrawText("O", cellX + 15, cellY + 10, 30, BLUE);
                        }
                    }
                }

                EndDrawing();
                break;
            }
        }
    }
    return 0;
}
