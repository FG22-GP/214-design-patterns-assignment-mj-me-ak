#include "input.h"
#
#include <SDL_keyboard.h>
#include <SDL_stdinc.h>

using namespace std;

InputHandler::InputHandler(InputScheme inputScheme)
{

    this->inputScheme = &inputScheme; //&inputScheme turns into ptr , inputScheme& then its reference?
        
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


 std::vector<Command*> InputHandler::handleInput()
{
    std::vector<Command*> commands = { };
    const Uint8* keystate = SDL_GetKeyboardState(NULL);
    if (keystate[SDL_SCANCODE_A] || keystate[SDL_SCANCODE_LEFT]) commands.push_back(buttonLeft);
    if (keystate[SDL_SCANCODE_D] || keystate[SDL_SCANCODE_RIGHT]) commands.push_back(buttonRight);
    if (keystate[SDL_SCANCODE_W] || keystate[SDL_SCANCODE_UP]) commands.push_back(buttonUp);
    if (keystate[SDL_SCANCODE_S] || keystate[SDL_SCANCODE_DOWN]) commands.push_back(buttonDown);
    return commands;
    
}

class input_scheme
{
    int up;
    int down;
    int left;
    int right;
};


