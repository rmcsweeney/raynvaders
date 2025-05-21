H-FILES = src/main.h
C-FILES = src/main.c
MAKEFILE = Makefile

DEPENDENCIES = $(H-FILES) $(C-FILES) $(MAKEFILE)

main: $(DEPENDENCIES)
	gcc -Wall -D_DEFAULT_SOURCE -Wmissing-braces -Wunused-result -g -o build/project $(C-FILES) -I ../raylib/include -L ../raylib/lib/ -lraylib -lm
