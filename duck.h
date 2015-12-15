#ifndef _CANARD_H_
#define _CANARD_H_

#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <sstream>

using namespace std;
//... tous les includes nécessaires

//Constantes

// Définitions des structures
struct canard
{
  int couleur;    //0 noir 1 rouge et 2 bleu
  int vitesse;    //vitesse du canard (pour gérer son déplacement)
  int x;       //position x sur le champ de tir
  int y;       //position y sur le champ de tir
  int w;          //Largeur
  int h;          //Hauteur
  float mvt_x;      // mouvement sur l'axe des abscisses
  float mvt_y;      // mouvement sur l'axe des ordonnées
  float vitesses;
  int state;
  bool estvivant;

};



//Définitions des prototypes de fonctions
void initCanard(canard &c);
void moveDuck(canard &c);
void showDuck(canard c, SDL_Surface *s); //Bosser
int alea(int max);
void applySurface(int x, int y, SDL_Surface* source,SDL_Surface* destination, SDL_Rect* clip);
SDL_Surface * loadImageWithColorKey(string filename, int r, int g, int b);
SDL_Surface * load_image( string filename );
void menu(SDL_Event event, SDL_Surface *screen);
void duckSprites(canard duck, SDL_Surface* sprite, SDL_Surface* screen, int move, int count);

#endif
