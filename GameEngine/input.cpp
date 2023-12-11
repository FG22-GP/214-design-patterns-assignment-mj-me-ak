#include "input.h"
#
#include <SDL_keyboard.h>
#include <SDL_stdinc.h>

using namespace std;

InputHandler::InputHandler(InputScheme* inputScheme)
{

    this->inputScheme = inputScheme; //&inputScheme turns into ptr , inputScheme& then its reference?
        
    buttonLeftPress = new Move(-1.f);
    buttonLeftRelease = new Move(0);
    buttonRightPress = new Move(1.f);
    buttonRightRelease = new Move(0);
    buttonUpPress = new Jump();
    buttonDownPress = new Crouch(true);
    buttonDownRelease = new Crouch(false);
    previousKeyState = {};
}

InputHandler::~InputHandler()
{
    delete buttonLeftPress;
    delete buttonLeftRelease;
    delete buttonRightPress;
    delete buttonRightRelease;
    delete buttonUpPress;
    delete buttonUpRelease;
    delete buttonDownPress;
    delete buttonDownRelease;

    delete inputScheme;
}

 std::vector<Command*> InputHandler::handleInput()
{
    std::vector<Command*> commands = { };
    
    const Uint8* keystate = SDL_GetKeyboardState(NULL);
    if (keystate[inputScheme->left] && previousKeyState[inputScheme->left]) commands.push_back(buttonLeftPress);
    if (!keystate[inputScheme->left] && previousKeyState[inputScheme->left]) commands.push_back(buttonLeftRelease);
    
    if (keystate[inputScheme->right] && previousKeyState[inputScheme->right]) commands.push_back(buttonRightPress);
    if (!keystate[inputScheme->right] && previousKeyState[inputScheme->right]) commands.push_back(buttonRightRelease);
    
    if (keystate[inputScheme->up] && !previousKeyState[inputScheme->up]) commands.push_back(buttonUpPress);
    if (!keystate[inputScheme->up] && previousKeyState[inputScheme->up]) commands.push_back(buttonUpRelease);
    
    if (keystate[inputScheme->down] && !previousKeyState[inputScheme->down]) commands.push_back(buttonDownPress);
    if (!keystate[inputScheme->down] && previousKeyState[inputScheme->down]) commands.push_back(buttonDownRelease);

    previousKeyState[inputScheme->left] = keystate[inputScheme->left] == 1;
    previousKeyState[inputScheme->right] = keystate[inputScheme->right] == 1;
    previousKeyState[inputScheme->up] = keystate[inputScheme->up] == 1;
    previousKeyState[inputScheme->down] = keystate[inputScheme->down] == 1;    
    
    return commands;
}

class input_scheme
{
    int up;
    int down;
    int left;
    int right;
};


