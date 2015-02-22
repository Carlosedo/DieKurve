#include "SDL_Base.h"
#include "World.h"
#include "Player.h"

/**
* @brief OnInit: initialices the game, surfaces and powerups. Also handles the game loading.
* @return A bool, true if everything worked.
*/
bool SDL_Base::OnInit() {
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }

    if(load){
        ifstream loadgame("savegame.txt");
        if(loadgame.is_open()){
            int aux;
            loadgame >> aux;
            num = aux;
            goalScore = num * 10;

            for(int i = 0; i < num; i++){
                Player *p = &playerlist[i];
                p->active = true;
                loadgame >> aux;
                p->score = aux;
            }
        }
        loadgame.close();
    }

    if((Surf_Display = SDL_SetVideoMode(GAME_WIDTH, GAME_HEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
        return false;
    }

    if((message = SDL_SetVideoMode(GAME_WIDTH, GAME_HEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
        return false;
    }

    if((Scoreback = IMG_Load("scoreback.png")) == NULL) {
        return false;
    }

    if((winner = IMG_Load("winner.png")) == NULL) {
        return false;
    }

    if( TTF_Init() == -1 )
        {
            return false;
        }

    World::world.alivecount = num;

    SDL_FillRect( Surf_Display, &World::world.wallL, SDL_MapRGB( Surf_Display->format, 0x77, 0x77, 0x77 ) );
    SDL_FillRect( Surf_Display, &World::world.wallU, SDL_MapRGB( Surf_Display->format, 0x77, 0x77, 0x77 ) );
    SDL_FillRect( Surf_Display, &World::world.wallR, SDL_MapRGB( Surf_Display->format, 0x77, 0x77, 0x77 ) );
    SDL_FillRect( Surf_Display, &World::world.wallD, SDL_MapRGB( Surf_Display->format, 0x77, 0x77, 0x77 ) );



    if((Surf_Test = playerlist[0].OnLoad("red.png")) == NULL) {
            return false;
    }

    if((Surf_Test = playerlist[1].OnLoad("azul.png")) == NULL) {
            return false;
    }

    if((Surf_Test = playerlist[2].OnLoad("green.png")) == NULL) {
            return false;
    }

    if((Surf_Test = playerlist[3].OnLoad("pink.png")) == NULL){
            return false;
    }

    font = TTF_OpenFont( "ducky.ttf", 20 );

    World::PUlist.clear();
    Powerups* Pu1 = new Sprint();
    Powerups* Pu2 = new VanishWalls();
    Powerups* Pu3 = new Worm();
    Powerups* Pu4 = new Tron();
    Pu1->OnCreate(Surf_Display);
    Pu2->OnCreate(Surf_Display);
    Pu3->OnCreate(Surf_Display);
    Pu4->OnCreate(Surf_Display);
    World::PUlist.push_back(Pu1);
    World::PUlist.push_back(Pu2);
    World::PUlist.push_back(Pu3);
    World::PUlist.push_back(Pu4);

    return true;
}

