#include "raylib.h"

int main(void) {
    InitWindow(200, 200, "CHIP-8 Interpreter");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(WHITE);
        DrawRectangle(75, 75, 50, 50, RED);

        EndDrawing();
    }

    CloseWindow();
}
