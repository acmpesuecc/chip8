#include "raylib.h"
#include <stdbool.h>

#define WIDTH 64
#define HEIGHT 32

bool display[HEIGHT][WIDTH] = {false};

int main(void) {
    InitWindow(WIDTH * 10, HEIGHT * 10, "CHIP-8 Interpreter");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                Color pixel_color = BLACK;
                if (display[i][j] == true) {
                    pixel_color = WHITE;
                }
                DrawRectangle(j * 10 + 1, i * 10 + 1, 8, 8, pixel_color);

                DrawText("something", 100, 200, 32, WHITE);
            }
        }

        EndDrawing();
    }

    CloseWindow();
}
