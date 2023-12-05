#pragma once
#include "Component.h"
#include "../input.h"

class Player;

class CommandManager : public Component
{
    InputHandler* inputHandler;
    
public:
    GameObject* player;
    
    virtual void Start() override;
    virtual void Update() override;
    virtual void End() override;
};
