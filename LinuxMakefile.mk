cc := gcc
cflags := -std=c99 -ggdb -Wall -Iraylib_linux/include
lflags := -Lraylib_linux/lib -lraylib -lm

target := bin/chip8

$(target): src/main.c
	$(cc) $^ -o $@ $(cflags) $(lflags)

.PHONY: run
run: $(target)
	./$(target)
