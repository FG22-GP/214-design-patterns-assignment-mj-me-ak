#include "input.h"
#
#include <SDL_keyboard.h>
#include <SDL_stdinc.h>

using namespace std;

InputHandler::InputHandler()
{
    buttonLeft = new MoveLeft();
    buttonRight = new MoveRight();
    buttonUp = new MoveUp();
    buttonDown = new MoveDown();
}

InputHandler::~InputHandler()
{
    delete buttonLeft;
    delete buttonRight;
    delete buttonUp;
    delete buttonDown;
}


Command* InputHandler::handleInput()
{
    const Uint8* keystate = SDL_GetKeyboardState(NULL);
    if (keystate[SDL_SCANCODE_A] || keystate[SDL_SCANCODE_LEFT]) return buttonLeft;
    if (keystate[SDL_SCANCODE_D] || keystate[SDL_SCANCODE_RIGHT]) return buttonRight;
    if (keystate[SDL_SCANCODE_W] || keystate[SDL_SCANCODE_UP]) return buttonUp;
    if (keystate[SDL_SCANCODE_S] || keystate[SDL_SCANCODE_DOWN]) return buttonDown;
    return nullptr;
    
}
