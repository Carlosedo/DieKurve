#include "FPS.h"

FPS FPS::FPSControl;

FPS::FPS() {
    OldTime     = 0;
    LastTime    = 0;

    SpeedFactor    = 0;
    delta          = 0;

    Frames      = 0;
    NumFrames   = 0;
}

void FPS::OnLoop() {
    if(OldTime + 1000 < SDL_GetTicks()) {
        OldTime = SDL_GetTicks();

        NumFrames = Frames;

        Frames = 0;
    }

    delta = (SDL_GetTicks() - LastTime);

    SpeedFactor = (delta / 1000.0f) * 32.0f;

    LastTime = SDL_GetTicks();

    Frames++;
}

int FPS::GetFPS() {
    return NumFrames;
}

float FPS::GetSpeedFactor() {
    return SpeedFactor;
}

int FPS::GetDelta(){
    return delta;
}
