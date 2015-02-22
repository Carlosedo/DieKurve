#include "World.h"

#include <iostream>
using namespace std;

World World::world;
vector<Powerups*> World::PUlist;

/**
* @brief Constructor of class World: initialices the walls and the pathmap.
*/
World::World(){
    wallL.x = 0;
    wallL.y = 0;
    wallL.h = GAME_HEIGHT;
    wallL.w = 10;

    wallU.x = 0;
    wallU.y = 0;
    wallU.h = 10;
    wallU.w = GAME_WIDTH - SCORE_WIDTH;

    wallR.x = GAME_WIDTH - SCORE_WIDTH - 10;
    wallR.y = 0;
    wallR.h = GAME_HEIGHT;
    wallR.w = 10;

    wallD.x = 0;
    wallD.y = GAME_HEIGHT - 10;
    wallD.h = 10;
    wallD.w = GAME_WIDTH - SCORE_WIDTH;

    winner = false;

    for(int i = 0; i < GAME_WIDTH; i++){
        for (int j = 0; j < GAME_HEIGHT; j++){
            pathmap[i][j] = false;
        }
    }
}

/**
* @brief addToPathMap: adds the player's coordinates to the pathmap and checks if a player passed over them.
* @param x, y: actual coordinates of the player.
* @param init_x, init_y: initial coordinates of the player, to check if the player started moving.
* @param prev_x, prev_y: previous coordinates of the player, the ones actually added to the pathmap.
* @param player: the player's id number.
*/
void World::addToPathMap(float x, float y, float init_x, float init_y, int prev_x, int prev_y, int player){

    if(pathmap[(int)x][(int)y] == true){
        Player* p = &SDL_Base::playerlist[player - 1];
        p->killPlayer();
        riseScore();
        //delete[] p;
    }

    if(x =! init_x || y != init_y){
        pathmap[prev_x][prev_y] = true;
    }
}

/**
* @brief riseScore: increases the alive players' score when a player dies and decreases the alive count.
*/
void World::riseScore(){
    for(int i = 0; i < MAX_PLAYERS; i++){
        if(SDL_Base::playerlist[i].active && SDL_Base::playerlist[i].alive){
            SDL_Base::playerlist[i].score++;
        }
    }

    alivecount--;
}

/**
* @brief cleanPathMap: resets the pathmap.
*/
void World::cleanPathMap(){
    for(int i = 0; i < GAME_WIDTH; i++){
        for(int j = 0; j < GAME_HEIGHT; j++){
            pathmap[i][j] = false;
        }
    }
}
