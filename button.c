#include "button.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>


void initButton(button *B)
{ 

B->button_play = IMG_Load("/home/nouur/menu/play.png");
B->button_option = IMG_Load("/home/nouur/menu/option.png");
B->button_quit = IMG_Load("/home/nouur/menu/quit.png");



if(B->button_play==NULL || B->button_option==NULL || B->button_quit==NULL)
{printf("Unable to load : %s",SDL_GetError());
}
B->pos_play.x=100;
B->pos_play.y=100;
B->pos_option.x=100;
B->pos_option.y=200;
B->pos_quit.x=100;
B->pos_quit.y=300;


}


void afficherButton(button B,SDL_Surface *screen)
{

SDL_BlitSurface(B.button_play,NULL,screen,&B.pos_play);
SDL_BlitSurface(B.button_option,NULL,screen,&B.pos_option);
SDL_BlitSurface(B.button_quit,NULL,screen,&B.pos_quit);
}



void libererB(button B)
{
SDL_FreeSurface(B.button_play);
SDL_FreeSurface(B.button_option);
SDL_FreeSurface(B.button_quit);

}
