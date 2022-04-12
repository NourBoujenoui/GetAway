prog:fonctions.o main.o
	gcc fonctions.o main.o -o prog -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
main.o:main.c
	gcc -c main.c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
fonctions.o:fonctions.c
	gcc -c fonctions.c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g


