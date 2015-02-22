#include "Player.h"
#include "World.h"
#include "SDL_Base.h"

void Player::collisions(){

    World::world.addToPathMap(x, y, init_x, init_y, prev_x, prev_y, n);

    if(CheckWalls(World::world.wallL, World::world.wallU, World::world.wallR, World::world.wallD) && alive){
        x = prev_x;
        y = prev_y;
        alive = false;
        World::world.riseScore();
    }
}
