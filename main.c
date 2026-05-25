#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include "joc.h"

typedef enum {
    STATE_MENU,
    STATE_PLAYING,
    STATE_SELECTING_MODE,
    STATE_SELECTING_DIMENSION,
    STATE_MULTIPLAYER,
    STATE_SINGLEPLAYER
} GameState;

int main()
{
    int dimension;
    Color colorBackground = {187, 173, 160, 255};
    InitWindow(640,480,"Tic-Tac-Toe");
    SetTargetFPS(60);
    GameState state = STATE_MENU;

    int selectedBtn = 0;

    while(!WindowShouldClose())
    {
        Vector2 mouse = GetMousePosition();

        Rectangle startBtn = { 245, 260, 160, 48 };
        Rectangle M3Btn = { 245, 200, 160, 48 };
        Rectangle M4Btn = { 245, 260, 160, 48 };
        Rectangle M5Btn = { 245, 320, 160, 48 };
        Rectangle M6Btn = { 245, 380, 160, 48 };
        Rectangle SingleBtn = { 245, 260, 160, 48 };
        Rectangle MultiBtn = { 245, 260, 160, 48 };


        bool hoveredstart = CheckCollisionPointRec(mouse, startBtn);
        bool hoveredm3 = CheckCollisionPointRec(mouse, M3Btn);
        bool hoveredm4 = CheckCollisionPointRec(mouse, M4Btn);
        bool hoveredm5 = CheckCollisionPointRec(mouse, M5Btn);
        bool hoveredm6 = CheckCollisionPointRec(mouse, M6Btn);
        bool hoveredsingle = CheckCollisionPointRec(mouse, SingleBtn);
        bool hoveredmulti = CheckCollisionPointRec(mouse, MultiBtn);
        if ((hoveredstart && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) || IsKeyPressed(KEY_ENTER)){
            state=STATE_SELECTING_DIMENSION;
        }
        else if (hoveredm3 && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
            state=STATE_SELECTING_MODE;
            dimension=3;
        }
        else if (hoveredm4 && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
            state=STATE_SELECTING_MODE;
            dimension=4;
        }
        else if (hoveredm5 && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
            state=STATE_SELECTING_MODE;
            dimension=5;
        }
        else if (hoveredm6 && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
            state=STATE_SELECTING_MODE;
            dimension=6;
        }
        else if (hoveredsingle && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
            state=STATE_SINGLEPLAYER;
        }
        else if (hoveredmulti && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
            state=STATE_MULTIPLAYER;
        }

        // ── MENU ─────────────────────────────────────────────────────────
        BeginDrawing();
        ClearBackground(BEIGE);
        switch(state){
            case STATE_MENU:{
                DrawText("Tic-Tac-Toe",
                    (640 - MeasureText("Tic-Tac-Toe", 80)) / 2,
                    80, 80, DARKBROWN);

                DrawRectangle(245, 260, 160, 48, YELLOW);

                const char *sl = "START";

                DrawText(sl,250 + (160 - MeasureText(sl, 24)) / 2,272,24, ORANGE);

                const char *hint = "Press ENTER to start";
                DrawText(hint,
                    (640 - MeasureText(hint, 20)) / 2,
                    332, 20, DARKBROWN);

                EndDrawing();

            break;
            }

            case STATE_SELECTING_DIMENSION:{
                //Selectarea dimensiunii matricei
                DrawText("Dimensiune Matrice",(840 - MeasureText("Dimensiune Matrice", 80)) / 2,80, 60, DARKBROWN);

                DrawRectangle(245, 200, 160, 48, YELLOW);
                DrawRectangle(245, 260, 160, 48, YELLOW);
                DrawRectangle(245, 320, 160, 48, YELLOW);
                DrawRectangle(245, 380, 160, 48, YELLOW);

                const char *s2 = "3X3";
                const char *s3 = "4X4";
                const char *s4 = "5X5";
                const char *s5 = "6X6";

                DrawText(s2,255 + (150 - MeasureText(s2, 20)) / 2,214,20, ORANGE);
                DrawText(s3,250 + (150 - MeasureText(s3, 20)) / 2,274, 20, ORANGE);
                DrawText(s4,250 + (150 - MeasureText(s3, 20)) / 2,334, 20, ORANGE);
                DrawText(s5,250 + (150 - MeasureText(s3, 20)) / 2,394, 20, ORANGE);

                EndDrawing();
            break;
            }

            case STATE_SELECTING_MODE:{
                // Afisare_Meniu
                DrawText("Meniu",(640 - MeasureText("Meniu", 80)) / 2,80, 80, DARKBROWN);

                DrawRectangle(245, 240, 160, 48, YELLOW);
                DrawRectangle(245, 300, 160, 48, YELLOW);

                const char *s2 = "Singleplayer";
                const char *s3 = "Multiplayer";

                DrawText(s2,255 + (160 - MeasureText(s2, 24)) / 2,252,20, ORANGE);

                DrawText(s3,250 + (160 - MeasureText(s3, 20)) / 2,312, 20, ORANGE);

                EndDrawing();
            break;
            }

            case STATE_SINGLEPLAYER:{
                //Jocu cu Botul
                DrawText("Singleplayer",(640 - MeasureText("Singleplayer", 80)) / 2,80, 60, DARKBROWN);

                DrawRectangle(245, 240, 160, 48, YELLOW);
                DrawRectangle(245, 300, 160, 48, YELLOW);

                const char *s2 = "Singleplayer";
                const char *s3 = "Multiplayer";

                DrawText(s2,255 + (160 - MeasureText(s2, 24)) / 2,252,20, ORANGE);

                DrawText(s3,250 + (160 - MeasureText(s3, 20)) / 2,312, 20, ORANGE);

                EndDrawing();
            break;
            }

            case STATE_MULTIPLAYER:{
                // Jocu pe un dispozitiv 2 persoane
                DrawText("Multiplayer",(640 - MeasureText("Multiplayer", 80)) / 2,80, 60, DARKBROWN);

                DrawRectangle(245, 240, 160, 48, YELLOW);
                DrawRectangle(245, 300, 160, 48, YELLOW);

                const char *s2 = "Singleplayer";
                const char *s3 = "Multiplayer";

                DrawText(s2,255 + (160 - MeasureText(s2, 24)) / 2,252,20, ORANGE);

                DrawText(s3,250 + (160 - MeasureText(s3, 20)) / 2,312, 20, ORANGE);

                EndDrawing();
            break;
            }
        }
    }
    return 0;
}
