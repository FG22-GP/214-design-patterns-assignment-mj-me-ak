#pragma once
#include "GameObjects/GameObject.h"

class GameLogic
{
    bool moveRight;
public:
    GameObject* gameObject;
    void Init();
    void Update();
    void End();
};
