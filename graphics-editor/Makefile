CC = gcc
CFLAGS = -Wall -Wextra -std=c99

graphics_editor: main.c graphics.c graphics.h
	$(CC) $(CFLAGS) main.c graphics.c -o graphics_editor

clean:
	del /f /q graphics_editor.exe 2>nul || rm -f graphics_editor
