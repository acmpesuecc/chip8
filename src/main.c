#include "raylib.h"
#include <stdbool.h>

#define WIDTH 64
#define HEIGHT 32

bool display[HEIGHT][WIDTH] = {false};

int main(void) {
    InitWindow(WIDTH * 10, HEIGHT * 10, "CHIP-8 Interpreter");
    SetTargetFPS(60);

    // randomly set a few pixels in the display
    display[10][14] = true;
    display[14][14] = true;
    display[17][56] = true;

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                Color pixel_color = BLACK;
                if (display[i][j] == true) {
                    pixel_color = WHITE;
                }
                DrawRectangle(j * 10, i * 10, 10, 10, pixel_color);
            }
        }

        EndDrawing();
    }

    CloseWindow();
}
