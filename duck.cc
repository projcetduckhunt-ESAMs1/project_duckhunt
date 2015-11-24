#include "duck.h"
using namespace std;

void initCanard(canard &c)
{

    int tab[2];
    tab[0]=-2;
    tab[1]=2;

    cout << "Initialisation du canard passe en parametre !" << endl;
    c.couleur = rand()%3;
    c.vitesse;
    c.x=350;
    c.y=150;
    c.w=80;
    c.h=70;
    c.mvt_x=tab[alea(2)-1];
    c.mvt_y=tab[alea(2)-1];
}
// (initialiser, déplacer, tuer, sauver, ...).

bool collision(SDL_Rect a, SDL_Rect b)
{
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    leftA = a.x;
    rightA = a.x + a.w;
    topA = a.y;
    bottomA = a.y + a.h;

    leftB = b.x;
    rightB = b.x + b.w;
    topB = b.y;
    bottomB = b.y + b.h;

    if(bottomA <= topB)
        return false;
    if(topA >= bottomB)
        return false;
    if(rightA <= leftB)
        return false;
    if(leftA >= rightB)
        return false;

    return true;
}

void moveDuck(canard &c)
{
    SDL_Rect tmp;

    c.x+=c.mvt_x;

    tmp.x=c.x-TAILLE/2;
    tmp.y=c.y-TAILLE/2;
    tmp.h=TAILLE;
    tmp.w=TAILLE;

    // Correction Mouvement Horizontal
    if(collision(tmp) || collision(tmp))
    {
        c.x-=c.mvt_x;
        c.mvt_x*=-1;
    }
    b.y+=b.mvt_y;

    tmp.x=b.x-TAILLE/2;
    tmp.y=b.y-TAILLE/2;

    // Correction Mouvement Vertical
    if((b.y+TAILLE>761) || (b.y-TAILLE<0))
    {
        b.y-=b.mvt_y;
        b.mvt_y*=-1;
    }
}

void showDuck(canard c, SDL_Surface *s)
{
    SDL_Rect r;
    r.x=b.x-TAILLE/2;
    r.y=b.y-TAILLE/2;
    r.w=TAILLE;
    r.h=TAILLE;

    SDL_FillRect(s,&r,SDL_MapRGB(s->format,255,164,255));
}

