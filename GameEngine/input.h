#pragma once
#include <cstdio>
#include <memory>
#include "Character.h"
#include <map>



class Command
{
public:
    virtual ~Command() {}
    virtual void execute(Character& character) = 0;
    //virtual InputType get_input_type() = 0;
    //typedef std::shared_ptr<Character> CharacterPtr;
};

//Actions
class MoveLeft : public Command 
{
public:
    void execute(Character& character) { character.Left(); }
};
class MoveRight : public Command
{
    void execute(Character& character) { printf("Right"); }
};
class Punch : public Command
{
    void execute(Character& character) { printf("Punch"); }
};

class InputHandler
{

    
    //int MAX_ACTION_INDEX;
    Command* buttonLeft_;
    Command* buttonRight_;
    Command* buttonNumPad1_;

    //std::map <int, Command*> commands;
    //std::array<Command*, MAX_ACTION_INDEX> commands; //c++11 array
    
public:
    Command* handleInput();
    InputHandler();
    ~InputHandler();

    //void bind(int key, CommandPtr command);
    
};

