#ifndef PLAYER_H
#define PLAYER_H


#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "SDL/SDL_ttf.h"
#include "FPS.h"
#include "Define.h"

#include <iostream>
using namespace std;


/** Class Player: Manages the player state, attributes and its behaviour. */

class Player {
    public:
        Player();

        char name[10];
        bool active;
        int n;
        int score;
        bool alive;
        SDL_Surface* Point;
        SDL_Color textColor;

    private:
        float x;
        float y;
        float init_x;
        float init_y;
        float speed;
        bool tron;
        bool noWalls;
        int prev_x;
        int prev_y;
        float angle;
        float init_angle;


    public:
        void ResetPlayer();

        void ResetScore();

        SDL_Surface* OnLoad(char* File);

        bool OnDraw(SDL_Surface* Surf_Dest);

        void OnMove();

        bool CheckWalls(SDL_Rect WL, SDL_Rect WU, SDL_Rect WR, SDL_Rect WD);

        bool operator ==(SDL_Rect B);

        void collisions();

        void killPlayer();

        void setSpeed(float sp);
        void setTron();
        void setWorm();
        void setNoWalls();
};




#endif // PLAYER_H
