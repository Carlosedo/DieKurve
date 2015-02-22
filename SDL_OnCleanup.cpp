#include "SDL_Base.h"
#include "World.h"

/**
* @brief OnCleanup: cleans and frees the used memory.
*/
void SDL_Base::OnCleanup() {
    SDL_FreeSurface(Surf_Display);
    SDL_FreeSurface(Surf_Test);
    SDL_FreeSurface( message );
    SDL_FreeSurface(Scoreback);
    SDL_FreeSurface(winner);

    for(int i; i < num; i++){
        SDL_FreeSurface(playerlist[i].Point);
    }

    for(int i; i < World::world.PUlist.size(); i++){
        SDL_FreeSurface(World::world.PUlist[i]->PU);
        //delete[] World::world.PUlist[i];

    }

    TTF_CloseFont( font );
    TTF_Quit();

    SDL_Quit();
}

