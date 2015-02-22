#ifndef POWERUPS_H
#define POWERUPS_H

#include <SDL/SDL.h>
#include "Define.h"
#include "SDL_Base.h"


/** Class Powerups: Abstract base class for the different powerups that appear on the game. */

class Powerups
{
public:
    Powerups(int i);

    virtual void Picked(int player) = 0;

    bool OnCreate(SDL_Surface* Surf_Dest);

protected:
    bool active;
    int affects_on;
    int type;

public:
    SDL_Surface* PU;
    SDL_Rect pu;
};


/** Class Sprint: powerup that doubles the player's speed. Inherits from Powerups class. */
class Sprint : public Powerups
{
public:
    Sprint() : Powerups(1) {}

    void Picked(int player);

};


/** Class Tron: powerup that makes the player turn 90º. Inherits from Powerups class. */
class Tron : public Powerups
{
public:
    Tron() : Powerups(2) {}

    void Picked(int player);
};


/** Class Worm: powerup that makes the player move to its starting position and
        move in the opposite direction. Inherits from Powerups class. */
class Worm : public Powerups
{
public:
    Worm() : Powerups(3) {}

    void Picked(int player);
};


/** Class Sprint: powerup that makes the walls crossable. Inherits from Powerups class. */
class VanishWalls : public Powerups
{
public:
    VanishWalls() : Powerups(4) {}

    void Picked(int player);
};


#endif // POWERUPS_H
