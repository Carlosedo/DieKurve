#include "SDL_Base.h"
#include "World.h"

/**
* @brief OnEvent: checks for events and passes them to the appropriate handler.
* @param *Event: pointer to the event to handle.
*/
void SDL_Base::OnEvent(SDL_Event* Event) {
    CEvent::OnEvent(Event);
}

/**
* @brief OnKeyDown: handles the event of a key being pressed.
*/
void SDL_Base::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode){

    if(World::world.alivecount <= 1 && sym == SDLK_s){
        ofstream save("savegame.txt");
        if(save.is_open()){
            save << num << endl;
            for(int i = 0; i < num; i++){
                save << playerlist[i].score << endl;
            }
        }
        save.close();
    }

    else if(World::world.alivecount <= 1 && sym == SDLK_SPACE){
        OnInit();

        World::world.cleanPathMap();

        for(int i = 0; i < MAX_PLAYERS; i ++){
            if(playerlist[i].active){
                playerlist[i].ResetPlayer();
                if(World::world.winner){
                    playerlist[i].ResetScore();
                }
            }
        }
        paused = true;
    }

    else if(sym == SDLK_SPACE){
        paused = !paused;
    }

}

void SDL_Base::OnExit() {
    Running = false;
}
