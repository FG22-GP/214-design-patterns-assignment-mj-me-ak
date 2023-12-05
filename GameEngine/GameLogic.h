#pragma once
#include "GameObjects/GameObject.h"

class GameLogic
{
public:
    GameObject* gameObject;
    GameObject* inputGameObject;
    void Init();
    void Update();
    void End();
};
