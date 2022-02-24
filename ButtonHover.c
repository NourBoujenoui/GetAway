#include "buttonHover.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>


void initButtonH(buttonH *BH)
{ 
BH->button_playH = IMG_Load("/home/nouur/menu/play+.png");
BH->button_optionH = IMG_Load("/home/nouur/menu/option+.png");
BH->button_quitH = IMG_Load("/home/nouur/menu/quit+.png");

if(BH->button_playH==NULL || BH->button_optionH==NULL || BH->button_quitH==NULL)
{printf("Unable to load : %s",SDL_GetError());
}
BH->pos_playH.x=100;
BH->pos_playH.y=100;
BH->pos_optionH.x=100;
BH->pos_optionH.y=200;
BH->pos_quitH.x=100;
BH->pos_quitH.y=300;


}


void afficherPlay(buttonH BH,SDL_Surface *screen)
{

SDL_BlitSurface(BH.button_playH,NULL,screen,&BH.pos_playH);

}
void afficherOption(buttonH BH,SDL_Surface *screen)
{


SDL_BlitSurface(BH.button_optionH,NULL,screen,&BH.pos_optionH);

}
void afficherQuit(buttonH BH,SDL_Surface *screen)
{


SDL_BlitSurface(BH.button_quitH,NULL,screen,&BH.pos_quitH);
}
void libererBH(buttonH BH)
{
SDL_FreeSurface(BH.button_playH);
SDL_FreeSurface(BH.button_optionH);
SDL_FreeSurface(BH.button_quitH);

}
