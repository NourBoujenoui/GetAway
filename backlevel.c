#include "backlevel.h"

void initBack(background * b){
    b->image = IMG_Load("bg.png");
    b->mask = IMG_Load("mask.png");

    b->camera.x=0;
    b->camera.y=0;
    b->camera.h=400;
    b->camera.w=800;

    b->music=Mix_LoadMUS("sonC.mp3");
    Mix_PlayMusic(b->music, -1);

}


void aficherBack(background b, SDL_Surface * screen){
    SDL_BlitSurface(b.image , &b.camera, screen  , NULL);
}

void scrolling (background * b, int direction, int pasAvancement){
   // if ((b->camera.x >= 0) && (b->camera.x <= 7200) && (b->camera.y >= 0) && (b->camera.y <= 200))
  //  {
       switch (direction)
    {
    case 'R':
        if (b->camera.x <= 7200) b->camera.x += pasAvancement ;
        break;

    case 'L':
        if (b->camera.x >= 0) b->camera.x -= pasAvancement;
        break;
    case 'U':
        if (b->camera.y >= 0) b->camera.y  -= pasAvancement;
        break;
    case 'D':
        if (b->camera.y <= 200) b->camera.y += pasAvancement;
        break;
    }

 

}
