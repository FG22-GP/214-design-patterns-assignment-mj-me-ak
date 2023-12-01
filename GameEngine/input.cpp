#include "input.h"
#
#include <SDL_keyboard.h>
#include <SDL_stdinc.h>

#include "Character.h"

using namespace std;

InputHandler::InputHandler()
{
    buttonLeft_ = new MoveLeft();
}

InputHandler::~InputHandler()
{
    delete buttonLeft_;
}


Command* InputHandler::handleInput()
{
    const Uint8* keystate = SDL_GetKeyboardState(NULL);
    if (keystate[SDL_SCANCODE_W]) return buttonLeft_;
    return nullptr;
    
}
