CC = gcc
CFLAGS = -Iinclude

grapefruit : src/main.c src/grapefruit.c src/image.c
	@gcc $^ -Os -o bin/$@ $(CFLAGS)