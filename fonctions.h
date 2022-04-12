#ifndef FONCTIONS_H_
#define FONCTIONS_H_
typedef struct 
{
int sec;
int min;
}Time;
typedef struct 
{
SDL_Surface *tab[8];
SDL_Rect positionperso;
int i;
SDL_Surface *sc;

float vitesse;
float acc;
int up;

Time t;
}Personne;





void initPerso(Personne *p);
void afficherPerso(Personne p, SDL_Surface * screen);
void deplacerPerso (Personne *p,Uint32 dt);
void animerPerso (Personne* p);
void saut (Personne* p,int dt, int posinit);


#endif
