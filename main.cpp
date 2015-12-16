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
    SDL_Surface *fond2 = loadImageWithColorKey("sprites/backGameBlit.png",0,0,0);


    SDL_Surface *viseur = loadImageWithColorKey("sprites/viseur.bmp", 0, 0, 0);

    bool quit=false;
    bool finround=false;

    int round=-1;
    int nbKilled=0;
    int nbballe=3;
    int score=0;// rouge 1500 bleu 1000 noir 500
    int level=1;
    int count = 0;
    SDL_Rect posViseur;

    int timer= 0;

    TTF_Init();
    TTF_Font *fonts;
    SDL_Color textColor= {255,255,255};
    int fontSize=35;
    string police="font/duck_hunt.ttf";
    fonts = TTF_OpenFont(police.c_str(),fontSize);

    ostringstream msgscore;
    msgscore.flush();
    msgscore.str("");
    msgscore <<  score;

    /*TEMP*/
    canard duck1;
    canard duck2;
    SDL_Surface *spriteScore = loadImageWithColorKey("sprites/hit.png", 0, 0, 0);
    SDL_Surface *spriteSheet = loadImageWithColorKey("sprites/duck.png", 228, 255, 0);
    SDL_Surface *spritBall = loadImageWithColorKey("sprites/shot.bmp", 255, 255, 255);
    initCanard(duck1);
    menu(event,screen);
    initCanard(duck2);
    int scoreTemp[10];
    for(int i=0; i<10; i++)
        scoreTemp[i] = 0;


    SDL_FillRect(screen,&screen->clip_rect,SDL_MapRGB(screen->format,0,0,255));
    applySurface(1,1,fond,screen,NULL);
    SDL_ShowCursor(SDL_DISABLE);

    while(!quit)
    {
        applySurface(0,0,fond,screen,NULL);
        duckSprites(duck1, spriteSheet, screen, duck1.state, count);
        duckSprites(duck2, spriteSheet, screen, duck2.state, count);
        applySurface(0,0,fond2,screen,NULL);
        scoreGesture(scoreTemp,round,nbKilled,finround);
        showScores(screen, spriteScore,scoreTemp);
        msgscore.str("");
        msgscore <<  score;
        showBall(nbballe,screen, spritBall);
        showMessageScreen(msgscore.str(),575,670,fonts,fontSize,textColor,screen);
        applySurface(posViseur.x,posViseur.y,viseur, screen, NULL);

        SDL_Delay(10);
        /*FIN INIT*/


        timer+=1;


        if(timer>=5)
        {
            count+=1;
            timer=0;
        }
        count=count%3;

        moveDuck(duck1);
        moveDuck(duck2);

        while(SDL_PollEvent(&event)){
            if(event.type==SDL_MOUSEBUTTONUP){
                if(event.button.button==SDL_BUTTON_LEFT && nbballe>0){
                    tirer(nbballe,score,duck1,duck2,posViseur,nbKilled);
                }
            }

            if(event.type==SDL_MOUSEMOTION){
                posViseur.x= event.motion.x;
                posViseur.y= event.motion.y;
            }

            if( event.type==SDL_QUIT)
                SDL_Quit();
        }



        NextRound(nbballe,nbKilled,round,finround,duck1,duck2);


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
