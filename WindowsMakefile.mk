cc := gcc
cflags := -std=c99 -ggdb -Wall -Iraylib_windows/include
lflags := -Lraylib_windows/lib -lraylib -lwinmm -lgdi32 -lm

target := bin/chip8

$(target): src/main.c
	$(cc) $^ -o $@ $(cflags) $(lflags)

.PHONY: run
run: $(target)
	.\$(target)
