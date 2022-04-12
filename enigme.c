#include "enigme.h"

#include <time.h>










void init_enigmes(enigme *e ){

int nbligne=0;

char question[100];
char reponse1[100];
char reponse2[100];
char reponse3[100];
int reponse;



FILE *f=NULL;
f=fopen("questionsans","r"); 
if(f!=NULL){

while(fscanf(f,"%s %s %s %s %d\n",question,reponse1,reponse2,reponse3,&reponse)!=EOF)
{
nbligne++;
}
fclose(f);
} 
//printf("%d",nbligne);





srand(time(0));
int alea=rand()%(2*nbligne);




int check=0;




///gener nombre aleatoire


f=fopen("questionsans","r");
if(f!=NULL){

while(fscanf(f,"%s %s %s %s %d\n",e->question,e->reponse1,e->reponse2,e->reponse3,&e->reponse)!=EOF)//lena t3abbi l e
{
check++;
if(check==alea){break;}

}
fclose(f);
}


e->positionquestion.x=50;
e->positionquestion.y=20;

e->positionreponse1.x=400;
e->positionreponse1.y=50;

e->positionreponse2.x=400;
e->positionreponse2.y=100;

e->positionreponse3.x=400;
e->positionreponse3.y=150;




TTF_Font*police=NULL;
police=TTF_OpenFont("Trajan Pro.ttf",20);

SDL_Color white={0,0,0};//black
SDL_Color red={155,0,0};



e->surfacequestion=TTF_RenderText_Blended(police,e->question,red);
e->surfacereponse1=TTF_RenderText_Blended(police,e->reponse1,white);
e->surfacereponse2=TTF_RenderText_Blended(police,e->reponse2,white);
e->surfacereponse3=TTF_RenderText_Blended(police,e->reponse3,white);}






void animer(enigme *e,SDL_Rect *pos_sprite,int j){
pos_sprite->x=j*pos_sprite->w;
}



void afficherenigme(enigme e,SDL_Surface *screen){
SDL_BlitSurface(e.surfacequestion,NULL,screen,&e.positionquestion);
SDL_BlitSurface(e.surfacereponse1,NULL,screen,&e.positionreponse1);
SDL_BlitSurface(e.surfacereponse2,NULL,screen,&e.positionreponse2);
SDL_BlitSurface(e.surfacereponse3,NULL,screen,&e.positionreponse3);
SDL_Flip(screen);
}






/*

void sauvegarder(personne p,background b,char *nomfichier){

background b;
personne p ;

FILE *f=NULL;
f=fopen("chargement","w");
if(f!=NULL){
fprintf(f,"%s %s %s %d\n",b.img,b.scroll,b.position,p.position)
fclose(f);
}





}





int charger(personne *p,background *b,char *nomfichier){
FILE *f=NULL;
f=fopen("chargement","r");
if(f!=NULL){
fscanf(f,"%s %s %s %d\n",b.img,b.scroll,b.position,p.position)
fclose(f);
}
return 1; 






}

*/






