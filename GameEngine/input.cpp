#include "input.h"
#
#include <SDL_keyboard.h>
#include <SDL_stdinc.h>

using namespace std;

InputHandler::InputHandler(InputScheme* inputScheme)
{

    this->inputScheme = inputScheme; //&inputScheme turns into ptr , inputScheme& then its reference?
        
    buttonLeft = new MoveLeft();
    buttonRight = new MoveRight();
    buttonUp = new Jump();
    buttonDown = new Crouch();
    
}

InputHandler::~InputHandler()
{
    delete buttonLeft;
    delete buttonRight;
    delete buttonUp;
    delete buttonDown;
    
    delete inputScheme;
}


 std::vector<Command*> InputHandler::handleInput()
{
    std::vector<Command*> commands = { };
    const Uint8* keystate = SDL_GetKeyboardState(NULL);
    if (keystate[inputScheme->left]) commands.push_back(buttonLeft);
    if (keystate[inputScheme->right]) commands.push_back(buttonRight);
    if (keystate[inputScheme->up]) commands.push_back(buttonUp);
    if (keystate[inputScheme->down]) commands.push_back(buttonDown);
    return commands;
    
}

class input_scheme
{
    int up;
    int down;
    int left;
    int right;
};


