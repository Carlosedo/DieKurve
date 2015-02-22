#ifndef SDL_BASE_H
#define SDL_BASE_H

#include "SDL/SDL.h"

#include "Player.h"
#include "CEvent.h"
#include "Define.h"

#include <fstream>
#include <iostream>
using namespace std;

/** Class SDL_Base: main class of the game, it manages the initialization, events, loops, rendering
        and cleanup of the game. Inherits from CEvent. */

class SDL_Base : public CEvent {
    public:
        bool    Running;
        bool    paused;
        bool    load;
        int     num;
        int     goalScore;

        static SDL_Surface*    Surf_Display;
        static SDL_Surface*    Scoreback;
        static SDL_Surface*    message;
        static SDL_Surface*    winner;
        SDL_Surface* Surf_Test;

        static TTF_Font* font;

        static Player playerlist[MAX_PLAYERS];

    public:
        SDL_Base(int numP, char l);

        int OnExecute();

    public:

        bool OnInit();

        void OnEvent(SDL_Event* Event);

        void OnExit();

        void OnLoop();

        void OnRender();

        void Rendertext(char string[], SDL_Color color, int x, int y);

        void OnCleanup();

        void OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);
};

#endif // SDL_BASE_H
