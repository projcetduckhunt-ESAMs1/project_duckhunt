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
    SDL_Event event;
    SDL_Surface *screen;
    SDL_Surface *fond = SDL_LoadBMP("sprites/backGame.bmp");
    SDL_Surface *viseur = SDL_LoadBMP("sprites/viseur.bmp");

    bool quit=false;
    int nbballe=3;
    int score=0;
    int level=1;
    SDL_Rect posViseur;

    SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO );

    screen=SDL_SetVideoMode(SCREEN_WIDTH,SCREEN_HEIGHT,SCREEN_BPP,SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Projet Duck Hunt",NULL);
    SDL_FillRect(screen,&screen->clip_rect,SDL_MapRGB(screen->format,0,0,255));
    applySurface(1,1,fond,screen,NULL);
    SDL_ShowCursor(SDL_DISABLE);

    menu(event,screen);
    while(!quit)
    {
        applySurface(1,1,fond,screen,NULL);

        /*INITIALISATION CURSEUR*/
        applySurface(posViseur.x,posViseur.y,viseur, screen, NULL);
        SDL_PollEvent(&event);

        posViseur.x= event.motion.x;
        posViseur.y= event.motion.y;


        if((event.button.button)==(SDL_BUTTON_LEFT))
        {
            //tirer(nbballe,score,duck,duck2);//penser a initialiser le niveau
        }





        SDL_Flip(screen);


    }

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
