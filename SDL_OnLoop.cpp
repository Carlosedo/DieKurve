#include "SDL_Base.h"
#include "Player.h"
#include "World.h"

/**
* @brief OnLoop: calls the functions and takes the actions of every loop of the game: fps, movement...
*/
void SDL_Base::OnLoop() {
    FPS::FPSControl.OnLoop();

    if(World::world.alivecount > 1 && !paused){
        for(int i = 0; i < MAX_PLAYERS; i++){
            if(playerlist[i].active){
                playerlist[i].OnMove();

                for(int j = 0; j < World::world.PUlist.size(); j++){
                    if(playerlist[i] == World::world.PUlist[j]->pu)
                        World::world.PUlist[j]->Picked(i);
                }
            }
        }
    }
}



