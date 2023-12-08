#pragma once

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

//Actions
class MoveLeft : public Command 
{
public:
    void execute(GameObject* gameObject)
    {
        auto player = gameObject->GetComponent<Player>();
        player->MoveLeft();
    }
};
class MoveRight : public Command
{
    void execute(GameObject* gameObject)
    {
        auto player = gameObject->GetComponent<Player>();
        player->MoveRight();
    }
};
class MoveUp : public Command
{
    void execute(GameObject* gameObject)
    {
        gameObject->transform->position->y += 0.1f;
    }
};
class MoveDown : public Command
{
    void execute(GameObject* gameObject)
    {
        gameObject->transform->position->y -= 0.1f;
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
    void execute(GameObject* gameObject)
    {
        
    }
};

class InputHandler
{    
    Command* buttonLeftPress;
    Command* buttonRightPress;
    Command* buttonUpPress;
    Command* buttonDownPress;
    Command* buttonNumPad1_;

    InputScheme* inputScheme;

    const Uint8* previousKeyState;
    
    //std::map <int, Command*> commands;
    //std::array<Command*, MAX_ACTION_INDEX> commands; //c++11 array
    
public:
    std::vector<Command*> handleInput();
    InputHandler(InputScheme* inputScheme);
    ~InputHandler();
    
    //void bind(int key, CommandPtr command);
};

