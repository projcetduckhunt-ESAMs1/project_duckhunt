/*fdp*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <sstream>

using namespace std;

const int SCREEN_WIDTH=750;
const int SCREEN_HEIGHT=761;
const int SCREEN_BPP=32;

struct canard
{
  int x;     // abscisse
  int y;     // ordonnée
  SDL_Surface *source;
  SDL_Rect lecture;
  SDL_Rect lectureFront;
  SDL_Rect lectureBack;
};


void pause()
{
    bool esc= false;
    SDL_Event event_pause;

    while(!esc){
        Uint8 *temp = SDL_GetKeyState(NULL);
        SDL_WaitEvent(&event_pause);
        if(temp[SDLK_RETURN] == 1)
            esc=true;
    }

}


void applySurface(int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip)
{
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;
    SDL_BlitSurface( source, clip, destination, &offset );
}



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

