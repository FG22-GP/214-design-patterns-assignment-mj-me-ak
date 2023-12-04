#pragma once
#include "GameObjects/GameObject.h"

class GameLogic
{
public:
    GameObject* gameObject;
    void Init();
    void Update();
    void End();
};
