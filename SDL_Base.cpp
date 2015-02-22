#include "SDL_Base.h"

SDL_Surface* SDL_Base::Surf_Display;
SDL_Surface* SDL_Base::message;
SDL_Surface* SDL_Base::winner;
SDL_Surface* SDL_Base::Scoreback;
TTF_Font* SDL_Base::font;

Player SDL_Base::playerlist[MAX_PLAYERS];

char *names[4] = {"Fred", "Bluebell", "Greenlee", "Pinky"};
SDL_Color colors[4] = {{ 255, 0, 0 }, { 0, 0, 255 }, { 0, 255, 0 }, { 255, 0, 204 }};

/**
* @brief Constructor for class SDL_Base: initialices its attributes.
* @param numP: the number of players for the game.
* @param l: defines if a games has to be loaded.
*/
SDL_Base::SDL_Base(int numP, char l) {
    Surf_Display = NULL;
    Surf_Test = NULL;
    message = NULL;
    winner = NULL;
    Scoreback = NULL;
    font = NULL;
    num = numP;
    goalScore = num * 10;
    Running = true;
    paused = true;
    for(int i = 0; i < MAX_PLAYERS; i++){
        Player *p = &playerlist[i];
        p->n = i + 1;
        sprintf(p->name, names[i]);
        p->textColor = colors[i];
    }
    for(int i = 0; i < numP; i++){
        Player *p = &playerlist[i];
        p->active = true;
    }
    if(l == 'y'){
        load = true;
    }else{
        load = false;
    }
}

