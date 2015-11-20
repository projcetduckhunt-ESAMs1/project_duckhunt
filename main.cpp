#include <iostream>
#include <cstdlib>
#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <sstream>
#include "level.h"
#include "duck.h"

/*test*/
using namespace std;

const int SCREEN_WIDTH=750;
const int SCREEN_HEIGHT=761;
const int SCREEN_BPP=32;

/*struct canard
{
  int x;     // abscisse
  int y;     // ordonnée
  SDL_Surface *source;
  SDL_Rect lecture;
  SDL_Rect lectureFront;
  SDL_Rect lectureBack;
};*/




int main()
{
    SDL_Surface *screen;
    SDL_Surface *fond = SDL_LoadBMP("backGame.bmp");



    SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO );
    screen=SDL_SetVideoMode(SCREEN_WIDTH,SCREEN_HEIGHT,SCREEN_BPP,SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Projet Duck Hunt",NULL);
    SDL_FillRect(screen,&screen->clip_rect,SDL_MapRGB(screen->format,0,0,255));
    applySurface(0,0,fond,screen,NULL);

    SDL_Flip(screen);
    pause();

    SDL_FreeSurface(screen);

}

