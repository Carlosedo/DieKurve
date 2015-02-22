#include "SDL_Base.h"
#include "Define.h"
#include "FPS.h"
#include "Player.h"
#include "World.h"



int main() {
    srand(SDL_GetTicks());

    cout << "Welcome to Die Kurve" << endl;
    cout << "Controls for player 1: left, right" << endl;
    cout << "Controls for player 2: q, w" << endl;
    cout << "Controls for player 3: t, y" << endl;
    cout << "Controls for player 4: o. p" << endl << endl;
    cout << "Do you want to load a previous game? [y/n]" << endl;
    char load;
    cin >> load;

    int numP = 0;
    if(load == 'n'){
        cout << "Set the number of players to start:" << endl;
        cin >> numP;
    }else if(load == 'y'){
        cout << "Loading game..." << endl;
    }

    SDL_Base theApp(numP, load);

    return theApp.OnExecute();
    //}
}

int SDL_Base::OnExecute() {
    if(OnInit() == false) {
        return -1;
    }

    SDL_Event Event;

    while(Running) {
        while(SDL_PollEvent(&Event)) {
            OnEvent(&Event);
        }

            OnLoop();
            OnRender();

    }

    OnCleanup();

    return 0;
}
