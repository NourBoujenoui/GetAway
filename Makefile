menu:background.o texte.o menu.o jouer.o option.o button.o ButtonHover.o 
	gcc background.o texte.o menu.o jouer.o option.o button.o ButtonHover.o  -o menu -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf -g
menu.o:menu.c
	gcc -c menu.c -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf  -g 
background.o:background.c 
	gcc -c background.c -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf  -g
texte.o:texte.c 
	gcc -c texte.c -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf  -g
jouer.o:jouer.c
	gcc -c jouer.c -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf  -g
option.o:option.c
	gcc -c option.c -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf  -g
button.o:button.c
	gcc -c button.c -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf  -g
ButtonHover.o:ButtonHover.c
	gcc -c ButtonHover.c -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf  -g 




