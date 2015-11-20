#ifndef _CANARD_H_
#define _CANARD_H_

#include <iostream>
#include <stdlib.h>
//... tous les includes nécessaires

//Constantes

// Définitions des structures
struct canard
{
  int couleur;    //0 noir 1 rouge et 2 bleu
  int vitesse;    //vitesse du canard (pour gérer son déplacement)
  int posX;       //position x sur le champ de tir
  int posY;       //position y sur le champ de tir
  int W;          //Largeur
  int H;          //Hauteur

};



//Définitions des prototypes de fonctions
void initCanard(canard &c);


#endif
