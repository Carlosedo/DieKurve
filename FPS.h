#ifndef FPS_H
#define FPS_H

#include <SDL/SDL.h>


/** Class FPS: Class to control the FPS of the game so that it runs at the same pace
        in different computers. */

class FPS {
    public:
        static FPS FPSControl;

    private:
        int     OldTime;
        int     LastTime;

        float     SpeedFactor;
        int       delta;

        int    NumFrames;
        int     Frames;

    public:
        FPS();

        void    OnLoop();

    public:
        int     GetFPS();

        float   GetSpeedFactor();

        int     GetDelta();
};

#endif // FPS_H
