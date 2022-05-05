#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "backlevel.h"
#include "collision.h"

void Animer(int * v, int * h){
  *h = *h + 1;
  if((*h) >= 5){
    *h = 0;
    *v = *v + 1;
  }
  if((*v) >= 5){
    *v = 0;
    *h = 0;
  }
  if(((*v) == 3)&&((*h) >= 1)){
    *h = 0;
    *v = 0;
  }
}

int main(int argc, char const *argv[])
{
//-----------partie declaration-------//
    int continuer=1;
    background b;
    int direction=0,vitesse=0;
    SDL_Surface *screen;
    SDL_Event event;


//----------partie initialisation------//
    SDL_Init(SDL_INIT_VIDEO);
    screen=SDL_SetVideoMode (800,400,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
    if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1) printf("%s",Mix_GetError());
    SDL_WM_SetCaption("background\t1",NULL);
    initBack(&b);
    SDL_EnableKeyRepeat(30,30);

    //Personnage
    SDL_Surface * penguin, * penguin_r;
    penguin = IMG_Load("penguin_mini.png");
    penguin_r = IMG_Load("penguin_r.png");

    SDL_Rect cadrage, pos; //230 182
    cadrage.x = 0;
    cadrage.y = 0;
    cadrage.w = 43;
    cadrage.h = 70;
    int frameh = 0;
    int framev = 0;

    pos.x = 300;
    pos.y = 66;

    int resx = 1100;
    int resy = 500;


while (continuer) // ------boucle de jeu --------//
{
  Animer(&framev, &frameh);
  cadrage.x = (cadrage.w + 91) * frameh;
  cadrage.y = (cadrage.h + 31) * framev;
//------partie input--------//
    while(SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            continuer=0;
            break;
        case SDL_KEYDOWN:
            vitesse++;
            switch (event.key.keysym.sym)
            {
                case SDLK_RIGHT:
                    direction='R';
                   // vitesse++;
                    break;
                case SDLK_LEFT:
                    direction='L';
                   // vitesse++;
                    break;
                case SDLK_UP:
                    direction='U';
                   // vitesse++;
                    break;
                case SDLK_DOWN:
                    direction='D';
                   // vitesse++;
                    break;
            }
        break;
        case SDL_KEYUP:
            vitesse=0;
        break;
        default:
        break;
        }
    }

//------partie update------//
//scrolling(&b,direction,vitesse);
if (collision_parfaite_right(b.mask, pos, b.camera) == 0)  // switch entre scrolling et deplacement perso
{
    if ((pos.x >= resx / 2) && (direction == 'R') && (b.camera.x <= 2200 - resx))
    {

        scrolling(&b, direction, vitesse);
    }
    else if ((direction == 'R') && (pos.x < resx - 100))
    {
        pos.x += vitesse;
    }
}

//////////////////////////////////////////////////////////////////////////////////////// left
if (collision_parfaite_left(b.mask, pos, b.camera) == 0)
{
    if ((pos.x <= resx / 2) && (direction == 'L') && (b.camera.x >= 0))
    {
        scrolling(&b, direction, vitesse);
    }
    else if ((direction == 'L') && (pos.x >= 0))
    {
        pos.x -= vitesse;
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////// up
if ((collision_parfaite_up(b.mask, pos, b.camera) == 0) && (direction == 'U') && (pos.y > 0))
{
    pos.y -= vitesse;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////// down
if ((collision_parfaite_down(b.mask, pos, b.camera) == 0) && (direction == 'D') && (pos.y <= resy - 134))
{
    pos.y += vitesse;
}


//------partie affichage------//
aficherBack(b,screen);
SDL_BlitSurface(penguin, &cadrage, screen, &pos);
SDL_Flip(screen);
SDL_Delay(40);
}}

