#include <iostream>
#include <cstdlib>
#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <sstream>
#include <ctime>
#include <level.h>
#include <duck.h>
using namespace std;
/*test de commit*/
/*Deuxieme test de commit relou*/
int main(int argc, char* argv[])
{
     niveau n;
     int difficulte = 0;
     bool quit=false;
     initNiveau(n,difficulte);

     SDL_Surface *canard1;
     SDL_Surface *screen;
     SDL_Event event;
     canard c;
     SDL_Init(SDL_INIT_VIDEO);
     screen=SDL_SetVideoMode(ECRAN_WIDTH,ECRAN_HEIGHT,SCREEN_BPP,SDL_SWSURFACE);
     initCanard(c);
     showDuck(c,canard1);
     canard1=loadImageWithColorKey("ball.bmp",0,255,255);
     while(!quit)
      {
          SDL_FillRect(screen,&screen->clip_rect,SDL_MapRGB(screen->format,0,0,0));
          applySurface(c.x,c.y,canard1,screen,NULL);
          SDL_Flip(screen);
          showDuck(c,canard1);

          while(SDL_PollEvent(&event))
          {
              if(event.type==SDL_QUIT)
                  quit=true;

          }

          moveDuck(c);
                SDL_Delay(10);
      }
     SDL_FreeSurface(screen);
     SDL_Quit();
     return EXIT_SUCCESS;
}


/****************** Nom de la fonction **********************
* NOM_FONCTION                               /               *
******************** Auteur , Dates *************************
* Nom/Date : Éventuellement la version                      *
********************* Description ***************************
* Vous décrivez ici ce que fait cette fonction              *
*********************** Entrées *****************************
* Vous décrivez ici les données en entrée de la fonction    *
*********************** Sorties *****************************
* Vous détaillez ici ce que renvoie la fonction             *
************************************************************/
