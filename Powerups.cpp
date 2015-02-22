#include "Powerups.h"
#include "math.h"

/**
 * @brief Constructor for class Plowerups. Initialices its parameters.
 */
Powerups::Powerups(int i)
{
    type = i;
    float rnd;
    rnd = (float)rand() / RAND_MAX;
    pu.x = INIT_SPACE + (rnd * (GAME_WIDTH - SCORE_WIDTH - (2 * INIT_SPACE)));
    rnd = (float)rand() / RAND_MAX;
    pu.y = INIT_SPACE + (rnd * (GAME_HEIGHT - (2 * INIT_SPACE)));
    pu.w = PU_WIDTH;
    pu.h = PU_WIDTH;
    SDL_FillRect( SDL_Base::Surf_Display, &pu, SDL_MapRGB( SDL_Base::Surf_Display->format, 0xff, 0xff, 0xff ) );
    rnd = (float)rand() / RAND_MAX;
    affects_on = (int)(rand()) % 2;
    active = true;
}

/**
* @brief OnCreate: loads and draws a powerup in the destination surface.
* @param *Surf_Dest: pointer to the destination surface.
*/
bool Powerups::OnCreate(SDL_Surface *Surf_Dest){
    SDL_Surface* Surf_Temp = NULL;

    switch(type){
        case 1:
            if(affects_on == 0){
                if((Surf_Temp = IMG_Load("sprint-self.png")) == NULL) {
                    return false;
                }
            }else if(affects_on == 1){
                if((Surf_Temp = IMG_Load("sprint-others.png")) == NULL) {
                    return false;
                }
            }
            break;

        case 2:
            if(affects_on == 0){
                if((Surf_Temp = IMG_Load("tron-self.png")) == NULL) {
                    return false;
                }
            }else if(affects_on == 1){
                if((Surf_Temp = IMG_Load("tron-others.png")) == NULL) {
                    return false;
                }
            }
            break;

        case 3:
            if(affects_on == 0){
                if((Surf_Temp = IMG_Load("worm-self.png")) == NULL) {
                    return false;
                }
            }else if(affects_on == 1){
                if((Surf_Temp = IMG_Load("worm-others.png")) == NULL) {
                    return false;
                }
            }
            break;

        case 4:
            if((Surf_Temp = IMG_Load("nowalls.png")) == NULL){
                return false;
            }
            break;
    }

    PU = SDL_DisplayFormat(Surf_Temp);
    SDL_FreeSurface(Surf_Temp);

    if(Surf_Dest == NULL || PU == NULL) {
        return false;
    }

    SDL_Rect DestR;
    DestR.x = pu.x;
    DestR.y = pu.y;

    SDL_BlitSurface(PU, NULL, Surf_Dest, &DestR);

    return true;
}

/**
* @brief Picked: called when the powerup is picked, manages its effect on the player.
*/
void Sprint::Picked(int player){
    if(active){
        if(affects_on == 0){
            SDL_Base::playerlist[player].setSpeed(2.0f);
        }
        else{
            for(int i = 0; i < MAX_PLAYERS; i++){
                if(i != player && SDL_Base::playerlist[i].active){
                    SDL_Base::playerlist[i].setSpeed(2.0f);
                }
            }
        }
        active = false;
    }
}

/**
* @brief Picked: called when the powerup is picked, manages its effect on the player.
*/
void Tron::Picked(int player){
    if(active){
        if(affects_on == 0){
            SDL_Base::playerlist[player].setTron();
        }
        else{
            for(int i = 0; i < MAX_PLAYERS; i++){
                if(i != player && SDL_Base::playerlist[i].active){
                    SDL_Base::playerlist[i].setTron();
                }
            }
        }
        active = false;
    }
}

/**
* @brief Picked: called when the powerup is picked, manages its effect on the player.
*/
void Worm::Picked(int player){
    if(active){
        if(affects_on == 0){
            SDL_Base::playerlist[player].setWorm();
        }
        else{
            for(int i = 0; i < MAX_PLAYERS; i++){
                if(i != player && SDL_Base::playerlist[i].active){
                    SDL_Base::playerlist[i].setWorm();
                }
            }
        }
        active = false;
    }
}

/**
* @brief Picked: called when the powerup is picked, manages its effect on the player.
*/
void VanishWalls::Picked(int player){
    if(active){
        for(int i = 0; i < MAX_PLAYERS; i++){
            if(SDL_Base::playerlist[i].active)
                SDL_Base::playerlist[i].setNoWalls();
        }
    }
    active = false;
}

