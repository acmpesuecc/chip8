#include "raylib.h"
#include <bits/stdint-uintn.h>
#include <stdbool.h>
#include <stdio.h>

#define WIDTH 64
#define HEIGHT 32

bool display[HEIGHT][WIDTH] = {false};

uint8_t V[16]; // 16 general purpose registers
uint16_t PC = 0x200; // program counter
uint8_t SP; // stack pointer

uint8_t memory[4096]; // 4KiB memory

uint16_t fetch(void) {
    uint8_t upper_byte = memory[PC];
    uint8_t lower_byte = memory[PC + 1];
    uint16_t instruction = (upper_byte << 8) | (lower_byte);
    return instruction;
}

int main(void) {
    InitWindow(WIDTH * 10 + 200, HEIGHT * 10, "CHIP-8 Interpreter");
    SetTargetFPS(60);

    // 00E0
    memory[0x200] = 0x00;
    memory[0x201] = 0xE0;

    // 1000
    memory[0x202] = 0x10;
    memory[0x203] = 0x02;

    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            display[j][i] = true;
        }
    }

    while (!WindowShouldClose()) {
        uint16_t instruction = fetch();
        if (instruction == 0x00E0) { // decode
            // clear screen
            printf("CLS\n");
            for (int i = 0; i < HEIGHT; i++) {
                for (int j = 0; j < WIDTH; j++) {
                    display[i][j] = false;
                }
            }
            PC += 2;
        } else if (instruction == 0x1000) {
            printf("JP 0x000\n");
            PC = 0x000 + 0x200;
        } else {
            printf("Invalid instruction\n");
            break;
        }

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
