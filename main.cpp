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

int main()
{
    srand(time(NULL));
    SDL_Event event;
    SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO );
    SDL_Surface *screen;
    screen=SDL_SetVideoMode(SCREEN_WIDTH,SCREEN_HEIGHT,SCREEN_BPP,SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Projet Duck Hunt",NULL);

    SDL_Surface *fond = SDL_LoadBMP("sprites/backGame.bmp");


    SDL_Surface *viseur = loadImageWithColorKey("sprites/viseur.bmp", 0, 0, 0);


    bool quit=false;
    int nbballe=3;
    int score=0;
    int level=1;
    int count = 0;
    SDL_Rect posViseur;

    int timer= 0;



    /*TEMP*/
    canard duck;
    canard duck2;
    SDL_Surface *spriteSheet = loadImageWithColorKey("sprites/duck.bmp", 228, 255, 0);
    initCanard(duck);
    menu(event,screen);
    initCanard(duck2);




    SDL_FillRect(screen,&screen->clip_rect,SDL_MapRGB(screen->format,0,0,255));
    applySurface(1,1,fond,screen,NULL);
    SDL_ShowCursor(SDL_DISABLE);

    while(!quit)
    {
        applySurface(1,1,fond,screen,NULL);

        /*INITIALISATION CURSEUR*/
        applySurface(posViseur.x,posViseur.y,viseur, screen, NULL);
        SDL_PollEvent(&event);

        posViseur.x= event.motion.x;
        posViseur.y= event.motion.y;
        /*FIN INIT*/

        duckSprites(duck, spriteSheet, screen, duck.state, count);
        duckSprites(duck2, spriteSheet, screen, duck2.state, count);
        timer+=1;
        count= count%3;

        if(timer>=20)
        {
            count+=1;
            timer=0;
        }
        moveDuck(duck);
        moveDuck(duck2);


        if((event.button.button)==(SDL_BUTTON_LEFT))
        {
            tirer(nbballe,score,duck,duck2);//penser a initialiser le niveau

        }



        if( event.type==SDL_QUIT)
                SDL_Quit();

        SDL_Flip(screen);


    }

    SDL_FreeSurface(screen);
    SDL_FreeSurface(fond);
    SDL_FreeSurface(viseur);
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
