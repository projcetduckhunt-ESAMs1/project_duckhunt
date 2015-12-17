#ifndef _NIVEAU_H_
#define _NIVEAU_H_

#include <iostream>
#include "duck.h"

const int NB_CANARD_TO_WIN = 6;
const int NB_CANARD_PAR_NIVEAU = 10;
const int SCREEN_WIDTH=750;
const int SCREEN_HEIGHT=761;
const int SCREEN_BPP=32;

struct niveau
{
    canard listeCanard[NB_CANARD_PAR_NIVEAU];
    int difficulte;
    //... et tout plein de choses
};

//Définition des prototypes de fonctions
void initNiveau(niveau &n, int difficulte);
void pause();
void tirer(int &nbballe, int &score, canard &a, canard &b,  SDL_Rect posViseur, int &nbKilled);
void showMessageScreen(string message,int x,int y,TTF_Font *font,int fontSize,SDL_Color textColor,SDL_Surface* &screen);
void strToOstr(string text);
void menu(SDL_Event event,SDL_Surface *screen);
void showScores(SDL_Surface* screen, SDL_Surface* scoreSheet, int score[]);
void scoreGesture(int score[], int round, int &nbKilled, bool &finRound);
void showBall(int nbball,SDL_Surface* screen, SDL_Surface* spriteBall);
void NextRound(int &nbballe, int &nbKilled, int &round, bool &finround, canard &duck1, canard &duck2);
void NextLevel(int level, TTF_Font *fonts, int fontSize, SDL_Color textColor, SDL_Surface *screen);
#endif

