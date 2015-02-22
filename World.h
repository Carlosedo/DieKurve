#ifndef WORLD_H
#define WORLD_H

#include "SDL/SDL.h"
#include "Define.h"
#include "SDL_Base.h"
#include "Player.h"
#include "Powerups.h"

#include <vector>


/** Class World: contains and manages the playground. */
class World
{
public:
    World();

    static World world;
    static vector<Powerups*> PUlist;

    SDL_Rect wallL;
    SDL_Rect wallU;
    SDL_Rect wallR;
    SDL_Rect wallD;

    int alivecount;
    bool winner;

    bool pathmap[GAME_WIDTH][GAME_HEIGHT];
    SDL_Color colors[4];

    void addToPathMap(float x, float y, float init_x, float init_y, int prev_x, int prev_y, int player);
    void cleanPathMap();
    void riseScore();
};

#endif // WORLD_H
