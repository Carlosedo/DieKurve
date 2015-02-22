#include "SDL_Base.h"
#include "Player.h"
#include "World.h"

/**
* @brief OnRender: draws the surfaces on every loop of the game.
*/
void SDL_Base::OnRender() {

    SDL_Rect rect;
    rect.x = GAME_WIDTH - SCORE_WIDTH;
    rect.y = 0;

    SDL_BlitSurface(Scoreback, NULL, Surf_Display, &rect);

    char string[30];
    SDL_Color color = { 255, 255, 255 };

    sprintf(string, "GOAL SCORE: %d", goalScore);
    int Rx = GAME_WIDTH - SCORE_WIDTH + 15;
    int Ry = 50;
    Rendertext(string, color, Rx, Ry);

    sprintf(string, "Press SPACEBAR");
    Rx = GAME_WIDTH - SCORE_WIDTH + 30;
    Ry = 550;
    Rendertext(string, color, Rx, Ry);

    sprintf(string, "to START / PAUSE");
    Rx = GAME_WIDTH - SCORE_WIDTH + 15;
    Ry = 580;
    Rendertext(string, color, Rx, Ry);

    sprintf(string, "Between rounds,");
    Rx = GAME_WIDTH - SCORE_WIDTH + 30;
    Ry = 630;
    Rendertext(string, color, Rx, Ry);

    sprintf(string, "save with S");
    Rx = GAME_WIDTH - SCORE_WIDTH + 60;
    Ry = 660;
    Rendertext(string, color, Rx, Ry);

    for(int i = 0; i < MAX_PLAYERS; i++){
        if(playerlist[i].active){
            playerlist[i].OnDraw(Surf_Display);

            sprintf(string, "%s -> %d", playerlist[i].name, playerlist[i].score);
            Rx = GAME_WIDTH - SCORE_WIDTH + 15;
            Ry = 150 + i * 50;
            Rendertext(string, playerlist[i].textColor, Rx, Ry);

            if(World::world.alivecount <= 1 && playerlist[i].score >= goalScore){
                World::world.winner = true;
                SDL_Rect DestR;
                DestR.x = (GAME_WIDTH - SCORE_WIDTH) / 2 - 50;
                DestR.y = GAME_HEIGHT / 2 - 100;
                SDL_BlitSurface(winner, NULL, Surf_Display, &DestR);
            }
        }
    }

    SDL_Flip(Surf_Display);
}

void SDL_Base::Rendertext(char string[], SDL_Color color, int x, int y){
    message = TTF_RenderText_Solid(font, string, color);
    SDL_Rect DestR;
    DestR.x = x;
    DestR.y = y;
    SDL_BlitSurface(message, NULL, Surf_Display, &DestR);
}
