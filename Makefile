CC = clang
CFLAGS = -Wall -Wextra -Werror

.PHONY: main
main: main.exe

main.exe: main.c
	$(CC) $(CFLAGS) main.c -o main.exe
