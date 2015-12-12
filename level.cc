using namespace std;
#include "level.h"

// Fonctions
void initNiveau(niveau &n, int difficulte )
{
    //initialisation du premier canard de ce niveau (il y en a 10 à faire)
    initCanard(n.listeCanard[0]);

    //initialise la difficulté du niveau
    n.difficulte = difficulte;

    //Affiche les canard

}


void pause()
{
    int continuer = 1;
    SDL_Event event;

    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
        case SDL_QUIT:
            continuer = 0;
        }
    }
}


void tirer(int &nbballe,int &score,canard a,canard b){
    SDL_Event event;
    int x = event.button.x;
    int y = event.button.y;

    nbballe--;


    if((x>a.x)&&(x<a.x+a.w)&&(y>a.y)&&(y<a.y+a.h))
    {
        score+=1;//a modif
        cout << score << endl;

    }
    if((x>b.x)&&(x<b.x+b.w)&&(y>b.y)&&(y<b.y+b.h))
    {
        score+=1;//a modif

    }
}


void menu(SDL_Event event,SDL_Surface *screen){
    bool on=true;
    bool jouer= true;
    SDL_Surface *menu;

    TTF_Init();
    TTF_Font *fonts;
    SDL_Color textColor= {255,255,255};
    int fontSize=45;
    string police="font/duck_hunt.ttf";
    fonts = TTF_OpenFont(police.c_str(),fontSize);

    ostringstream mssg1;
    mssg1.flush();
    mssg1.str("");
    mssg1 <<  "Duck Hunt";

    ostringstream mssg2;
    mssg2.flush();
    mssg2.str("");
    mssg2 <<  "Iut Bdx 2015";

    ostringstream mssg3;
    mssg3.flush();
    mssg3.str("");
    mssg3 <<  "--> Mode classique";

    ostringstream mssg4;
    mssg4.flush();
    mssg4.str("");
    mssg4 <<  "Quit";

    ostringstream mssg5;
    mssg5.flush();
    mssg5.str("");
    mssg5 <<  "Mode classique";

    ostringstream mssg6;
    mssg6.flush();
    mssg6.str("");
    mssg6 <<  "--> Quit";


    menu=loadImageWithColorKey("sprites/menu.bmp",0,255,255);
    applySurface(0,0,menu,screen,NULL);
    showMessageScreen(mssg1.str(),30,30,fonts,fontSize,textColor,screen);
    showMessageScreen(mssg2.str(),30,70,fonts,fontSize,textColor,screen);

    while(on==true)
    {

           applySurface(0,0,menu,screen,NULL);
           showMessageScreen(mssg1.str(),30,30,fonts,fontSize,textColor,screen);
           showMessageScreen(mssg2.str(),30,70,fonts,fontSize,textColor,screen);


           SDL_Delay(5);
           SDL_WaitEvent(&event);

           Uint8 *keystates = SDL_GetKeyState( NULL );
           if(jouer==true){
               showMessageScreen(mssg3.str(),120,300,fonts,fontSize,textColor,screen);
               showMessageScreen(mssg4.str(),200,370,fonts,fontSize,textColor,screen);
               if( keystates[ SDLK_RETURN] || keystates[ SDLK_KP_ENTER] )
                  on=false;

           }else{
               showMessageScreen(mssg5.str(),200,300,fonts,fontSize,textColor,screen);
               showMessageScreen(mssg6.str(),120,370,fonts,fontSize,textColor,screen);
               if(  keystates[ SDLK_RETURN] || keystates[ SDLK_KP_ENTER] )
                   SDL_Quit();
           }
                 if( keystates[ SDLK_UP] )
                     jouer=true;     
                 if( keystates[ SDLK_DOWN] )
                     jouer=false;
                 if( event.type==SDL_QUIT)
                         SDL_Quit();

          SDL_Flip(screen);
    }
}

void showMessageScreen(string message,int x,int y,TTF_Font *font,int fontSize,SDL_Color textColor,SDL_Surface* &screen)
{
    string mot="";
    string space=" ";
    int i=0,j;
    SDL_Surface *mes=NULL;

    j = message.find(space);
    while( j != string::npos )
    {
        mot=message.substr(i,j-i);
        if(mot != "")
        {
            mes=TTF_RenderText_Solid(font,mot.c_str(),textColor);
            applySurface(x,y,mes,screen,NULL);
            x+=mes->w;
            SDL_FreeSurface(mes);
        }
        x+=fontSize;
        i=j+1;
        j = message.find(space,i);
    }


    mot=message.substr(i);
    mes=TTF_RenderText_Solid(font,mot.c_str(),textColor);
    applySurface(x,y,mes,screen,NULL);
    SDL_FreeSurface(mes);
}

void scoreGesture(int score[], int round, int nbKilled, bool finRound)
{
    if(finRound==true)
    {
        switch(nbKilled){
            case 0: score[round*2]=1; score[round*2 + 1]=1; break;
            case 1: score[round*2]=2; score[round*2+1]=1; break;
            case 2: score[round*2]=2; score[round*2+1]=2; break;
        }
    }
}

void showScores(SDL_Surface* screen, SDL_Surface* scoreSheet, int score[])
{
    int left_x = 205;
    int left_y = 665;
    SDL_Rect s;

    s.y=0;
    s.h=33;
    s.w=23;

    for(int i=0; i<10; i++)
    {
        switch(score[i]){
            case 0: s.x=6; break;
            case 1: s.x=30; break;
            case 2: s.x=54; break;
        }
        applySurface(left_x+((s.w+5)*i),left_y,scoreSheet,screen,&s);
    }
}

