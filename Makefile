CC = gcc
CFLAGS = -Iinclude

grapefruit : src/main.c src/grapefruit.c
	@gcc $^ -Os -o bin/$@ $(CFLAGS)