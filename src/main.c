#include "raylib.h"
#include <bits/stdint-uintn.h>
#include <stdbool.h>
#include <stdio.h>

#define WIDTH 64
#define HEIGHT 32

bool display[HEIGHT][WIDTH] = {false};

uint8_t V[16];

int main(void) {
    InitWindow(WIDTH * 10 + 200, HEIGHT * 10, "CHIP-8 Interpreter");
    SetTargetFPS(60);

    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            display[j][i] = true;
        }
    }

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
            }
        }

        char str[9];

        for (int i = 0; i < 16; i++) {
            sprintf(str, "V%x: 0x%x", i, V[i]);
            DrawText(str, 660, 50 + i * 16, 16, WHITE);
        }

        EndDrawing();
    }

    CloseWindow();
}
