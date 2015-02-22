#ifndef _CEVENT_H_
#define _CEVENT_H_

#include <SDL/SDL.h>


/** Class CEvent: All the possible events in SDL, is an abstract class.
        If any of the events are to be used in the project, the function has to be
        redefined in the inherited class SDL_Base. */
class CEvent {
    public:
        CEvent();

        virtual ~CEvent();

        virtual void OnEvent(SDL_Event* Event);

        virtual void OnInputFocus();

        virtual void OnInputBlur();

        virtual void OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);

        virtual void OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode);

        virtual void OnMouseFocus();

        virtual void OnMouseBlur();

        virtual void OnMouseMove(int mX, int mY, int relX, int relY, bool Left,bool Right,bool Middle);

        virtual void OnMouseWheel(bool Up, bool Down);    //Not implemented

        virtual void OnLButtonDown(int mX, int mY);

        virtual void OnLButtonUp(int mX, int mY);

        virtual void OnRButtonDown(int mX, int mY);

        virtual void OnRButtonUp(int mX, int mY);

        virtual void OnMButtonDown(int mX, int mY);

        virtual void OnMButtonUp(int mX, int mY);

        virtual void OnJoyAxis(Uint8 which, Uint8 axis, Sint16 value);

        virtual void OnJoyButtonDown(Uint8 which, Uint8 button);

        virtual void OnJoyButtonUp(Uint8 which, Uint8 button);

        virtual void OnJoyHat(Uint8 which, Uint8 hat, Uint8 value);

        virtual void OnJoyBall(Uint8 which, Uint8 ball, Sint16 xrel, Sint16 yrel);

        virtual void OnMinimize();

        virtual void OnRestore();

        virtual void OnResize(int w,int h);

        virtual void OnExpose();

        virtual void OnExit();

        virtual void OnUser(Uint8 type, int code, void* data1, void* data2);
};

#endif
