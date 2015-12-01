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

int main(int argc, char* argv[])
{
    SDL_Surface *screen;
    SDL_Surface *fond = SDL_LoadBMP("sprites/backGame.bmp");
    SDL_Surface *canard1;
    SDL_Event *event;
    bool quit=false;

    SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO );
    screen=SDL_SetVideoMode(SCREEN_WIDTH,SCREEN_HEIGHT,SCREEN_BPP,SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Projet Duck Hunt",NULL);
    SDL_FillRect(screen,&screen->clip_rect,SDL_MapRGB(screen->format,0,0,255));
    applySurface(1,1,fond,screen,NULL);

    SDL_Flip(screen);
    pause();

    SDL_FreeSurface(screen);
    return EXIT_SUCCESS;
}







/****************** Nom de la fonction **********************
* NOM_FONCTION                               /              *
******************** Auteur , Dates *************************
* Nom/Date : Éventuellement la version                      *
********************* Description ***************************
* Vous décrivez ici ce que fait cette fonction              *
*********************** Entrées *****************************
* Vous décrivez ici les données en entrée de la fonction    *
*********************** Sorties *****************************
* Vous détaillez ici ce que renvoie la fonction             *
************************************************************/
