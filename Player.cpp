#include "Player.h"
#include "math.h"

/**
 * @brief Constructor for class Player. Initialices its parameters.
 */
Player::Player() {
    active = false;
    float rnd;
    rnd = (float)rand() / RAND_MAX;
    init_x = INIT_SPACE + (rnd * (GAME_WIDTH - SCORE_WIDTH - (2 * INIT_SPACE)));
    rnd = (float)rand() / RAND_MAX;
    init_y = INIT_SPACE + (rnd * (GAME_HEIGHT - (2 * INIT_SPACE)));
    rnd = (float)rand() / RAND_MAX;
    init_angle = rnd * (2 * PI);
    speed = 1.0f;
    tron = false;
    noWalls = false;
    x = init_x;
    y = init_y;
    angle = init_angle;
    prev_x = x;
    prev_y = y;
    alive = true;
    score = 0;
    Point = NULL;
}


/**
* @brief ResetPlayer: Resets some of the player attributes for every new round
*/
void Player::ResetPlayer()
{
    float rnd;
    rnd = (float)rand() / RAND_MAX;
    init_x = INIT_SPACE + (rnd * (GAME_WIDTH - SCORE_WIDTH - (2 * INIT_SPACE)));
    rnd = (float)rand() / RAND_MAX;
    init_y = INIT_SPACE + (rnd * (GAME_HEIGHT - (2 * INIT_SPACE)));
    rnd = (float)rand() / RAND_MAX;
    init_angle = rnd * (2 * PI);
    speed = 1.0f;
    tron = false;
    noWalls = false;
    x = init_x;
    y = init_y;
    angle = init_angle;
    prev_x = x;
    prev_y = y;
    alive = true;
}

/**
* @brief ResetScore: Resets the score for a new game.
*/
void Player::ResetScore(){
    score = 0;
}

/**
* @brief OnLoad: loads a surface for the player.
* @param File: the file to load.
* @return Point: the surface of the player.
*/
SDL_Surface* Player::OnLoad(char* File) {
    SDL_Surface* Surf_Temp = NULL;

    if((Surf_Temp = IMG_Load(File)) == NULL) {
        return NULL;
    }

    Point = SDL_DisplayFormat(Surf_Temp);
    SDL_FreeSurface(Surf_Temp);

    return Point;
}

/**
* @brief OnDraw: draws the player's surface on the game.
* @param *Surf_Dest: pointer to the destination surface where the player is drawn.
*/
bool Player::OnDraw(SDL_Surface* Surf_Dest) {
    if(Surf_Dest == NULL || Point == NULL) {
        return false;
    }

    SDL_Rect DestR;

    DestR.x = x;
    DestR.y = y;

    SDL_BlitSurface(Point, NULL, Surf_Dest, &DestR);

    return true;
}

/**
* @brief OnMove: moves the player and calls the function to check for collisions
*/
void Player::OnMove()
{
    Uint8 *key = SDL_GetKeyState(NULL);

    if(alive){
        unsigned int curx, cury;

        if(n == 1){
            if (key[SDLK_LEFT]){
                if(tron){
                    angle -= PI / 2;
                    key[SDLK_LEFT] = 0;
                } else{
                    angle -= 0.1 * FPS::FPSControl.GetSpeedFactor();
                }
            }
            if (key[SDLK_RIGHT]){
                if(tron){
                    angle += PI / 2;
                    key[SDLK_RIGHT] = 0;
                } else{
                    angle += 0.1 * FPS::FPSControl.GetSpeedFactor();
                }
            }
        }

        else if(n == 2){
            if (key[SDLK_q]){
                if(tron){
                    angle -= PI / 2;
                    key[SDLK_q] = 0;
                } else{
                    angle -= 0.1 * FPS::FPSControl.GetSpeedFactor();
                }
            }
            if (key[SDLK_w]){
                if(tron){
                    angle += PI / 2;
                    key[SDLK_w] = 0;
                } else{
                    angle += 0.1 * FPS::FPSControl.GetSpeedFactor();
                }
            }
        }

        else if(n == 3){
            if (key[SDLK_t]){
                if(tron){
                    angle -= PI / 2;
                    key[SDLK_t] = 0;
                } else{
                    angle -= 0.1 * FPS::FPSControl.GetSpeedFactor();
                }
            }
            if (key[SDLK_y]){
                if(tron){
                    angle += PI / 2;
                    key[SDLK_y] = 0;
                } else{
                    angle += 0.1 * FPS::FPSControl.GetSpeedFactor();
                }
            }
        }

        else if(n == 4){
            if (key[SDLK_o]){
                if(tron){
                    angle -= PI / 2;
                    key[SDLK_o] = 0;
                } else{
                    angle -= 0.1 * FPS::FPSControl.GetSpeedFactor();
                }
            }
            if (key[SDLK_p]){
                if(tron){
                    angle += PI / 2;
                    key[SDLK_p] = 0;
                } else{
                    angle += 0.1 * FPS::FPSControl.GetSpeedFactor();
                }
            }
        }

        x += 1.5f * cos(angle) * speed * FPS::FPSControl.GetSpeedFactor();
        y += 1.5f * sin(angle) * speed * FPS::FPSControl.GetSpeedFactor();

        if(noWalls){
            if(x >= GAME_WIDTH - SCORE_WIDTH - 18){
                x = 11;
            }else if(x <= 11){
                x = GAME_WIDTH - SCORE_WIDTH - 20;
            }
            if(y >= GAME_HEIGHT - 18){
                y = 11;
            }else if(y <= 11){
                y = GAME_HEIGHT - 20;
            }
        }

        curx = (int)x;
        cury = (int)y;

        if (prev_x != curx || prev_y != cury) {
            collisions();
            prev_x = curx;
            prev_y = cury;
        }
    }
}

/**
* @brief CheckWalls: checks for a collision with the walls.
* @param WL: the left wall.
* @param WU: the upper wall.
* @param WR: the right wall.
* @param WD: the down wall.
* @return A bool, true if there is a collision
*/
bool Player::CheckWalls(SDL_Rect WL, SDL_Rect WU, SDL_Rect WR, SDL_Rect WD)
{
    //The sides of the rectangles
    int leftA, leftR;
    int rightA, rightL;
    int topA, topD;
    int bottomA, bottomU;

    //Calculate the sides of rect A
    leftA = x;
    rightA = x + P_WIDTH;
    topA = y;
    bottomA = y + P_WIDTH;


    leftR = WR.x;
    rightL = WL.x + WL.w;
    topD = WD.y;
    bottomU = WU.y + WU.h;

    if( bottomA >= topD )
    {
        return true;
    }

    if( topA <= bottomU )
    {
        return true;
    }

    if( rightA >= leftR )
    {
        return true;
    }

    if( leftA <= rightL )
    {
        return true;
    }

    return false;
}

/**
* @brief Operator == overload: if you compare a player to a SDL_Rect it checks for collision.
* @param B: rectangle to check collision with.
* @return A bool, true if there is a collision.
*/
bool Player::operator ==(SDL_Rect B){
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    leftA = x;
    rightA = x + P_WIDTH;
    topA = y;
    bottomA = y + P_WIDTH;

    leftB = B.x;
    rightB = B.x + B.w;
    topB = B.y;
    bottomB = B.y + B.h;

    if( bottomA <= topB )
    {
        return false;
    }

    if( topA >= bottomB )
    {
        return false;
    }

    if( rightA <= leftB )
    {
        return false;
    }

    if( leftA >= rightB )
    {
        return false;
    }

    return true;
}

/**
* @brief killPlayer: sets the alive variable to false.
*/
void Player::killPlayer(){
    alive = false;
}

/**
* @brief setSpeed: sets the player speed to a certain value.
* @param sp: value to set the speed to.
*/
void Player::setSpeed(float sp){
    speed = sp;
}

/**
* @brief setTron: set the movement modificator variable "tron" to true.
*/
void Player::setTron(){
    tron = true;
}

/**
* @brief setWorm: moves the player to its original position and changes its angle.
*/
void Player::setWorm(){
    x = init_x;
    y = init_y;
    angle = init_angle + PI;
}

/**
* @brief setNoWalls: makes the walls crossable.
*/
void Player::setNoWalls(){
    noWalls = true;
}
