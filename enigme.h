#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>

typedef struct 
{

 SDL_Surface * img;
 SDL_Rect 	p;
int pos_selected;
	SDL_Rect pos_timer;//pos timer al ecran
	SDL_Surface *timer[12];
	int num_animation;
	int time_over;
char image1[30],image2[30],image3[30],image4[30];
}enigme;

void init_enigme(enigme * e,char nomfichier[]);

void  generate_afficher (SDL_Surface * screen  , char image [],enigme *e,int *alea) ;

//int solution_e (char image []);

//int resolution (int * running,int *run);

void afficher_resultat (SDL_Surface * screen,int s,int r,enigme *en) ;

void animer(enigme *e) ; 

void afficher_chrono(enigme *en,SDL_Surface *screen,int i) ;
