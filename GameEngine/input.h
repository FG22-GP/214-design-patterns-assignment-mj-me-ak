#pragma once
#include <cstdio>

#include "Character.h"

class Character;

class input
{
    
};

class Command
{
public:
    virtual ~Command() {}
    virtual void execute(Character& character) = 0;
};

//Actions
class MoveLeft : Command 
{
public:
    void execute(Character& character) { character.Left(); }
};
class MoveRight : Command
{
    void execute(Character& character) { printf("Right"); }
};
class Punch : Command
{
    void execute(Character& character) { printf("Punch"); }
};

class InputHandler
{
    
    Command* buttonLeft_;
    Command* buttonRight_;
    Command* buttonNumPad1_;

public:
    Command* handleInput();
    InputHandler();
    ~InputHandler();

    //void configure(int key, Command* command);
    
};

