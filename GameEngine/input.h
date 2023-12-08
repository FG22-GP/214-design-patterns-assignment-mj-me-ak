#pragma once

#include <map>
#include <SDL_stdinc.h>

#include "GameObjects/GameObject.h"
#include "GameObjects/InputScheme.h"
#include "GameObjects/Player.h"
#include "GameObjects/Transform.h"


class Command
{
public:
    virtual ~Command() {}
    virtual void execute(GameObject* character) = 0;
};

class Move : public Command 
{
    int direction;
public:
    Move(int direction) : direction(direction)
    {        
    }
    
    void execute(GameObject* gameObject)
    {
        auto player = gameObject->GetComponent<Player>();
        player->Move(direction);
    }
};

class Punch : public Command
{
    void execute(GameObject* gameObject)
    {
        
    }
};

class Jump : public Command
{
    void execute(GameObject* gameObject)
    {
        
    }
};

class Crouch : public Command
{
    bool isCrouching;
public:
    Crouch(bool isCrouching) : isCrouching(isCrouching)
    {
        
    }
    void execute(GameObject* gameObject)
    {
        gameObject->GetComponent<Player>()->Crouch(isCrouching);
    }
};

class InputHandler
{    
    Command* buttonLeftPress;
    Command* buttonRightPress;
    Command* buttonUpPress;
    Command* buttonDownPress;
    Command* buttonLeftRelease;
    Command* buttonRightRelease;
    Command* buttonUpRelease;
    Command* buttonDownRelease;
    Command* buttonNumPad1_;

    InputScheme* inputScheme;

    std::map<int, bool> previousKeyState;
    
    //std::map <int, Command*> commands;
    //std::array<Command*, MAX_ACTION_INDEX> commands; //c++11 array
    
public:
    std::vector<Command*> handleInput();
    InputHandler(InputScheme* inputScheme);
    ~InputHandler();
    
    //void bind(int key, CommandPtr command);
};

