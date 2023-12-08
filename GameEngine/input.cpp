#include "input.h"
#
#include <SDL_keyboard.h>
#include <SDL_stdinc.h>

using namespace std;

InputHandler::InputHandler(InputScheme* inputScheme)
{

    this->inputScheme = inputScheme; //&inputScheme turns into ptr , inputScheme& then its reference?
        
    buttonLeftPress = new MoveLeft();
    buttonRightPress = new MoveRight();
    buttonUpPress = new Jump();
    buttonDownPress = new Crouch();
    previousKeyState = new Uint8;
}

InputHandler::~InputHandler()
{
    delete buttonLeftPress;
    delete buttonRightPress;
    delete buttonUpPress;
    delete buttonDownPress;

    delete previousKeyState;
    delete inputScheme;
}

 std::vector<Command*> InputHandler::handleInput()
{
    std::vector<Command*> commands = { };
    
    const Uint8* keystate = SDL_GetKeyboardState(NULL);
    if (keystate[inputScheme->left])
    {
        
        commands.push_back(buttonLeftPress);
    }
    if (keystate[inputScheme->right]) commands.push_back(buttonRightPress);
    if (keystate[inputScheme->up]) commands.push_back(buttonUpPress);
    if (keystate[inputScheme->down]) commands.push_back(buttonDownPress);

    //delete previousKeyState;
    //auto state = *keystate;
    //previousKeyState = &state;
    
    return commands;
}

class input_scheme
{
    int up;
    int down;
    int left;
    int right;
};


