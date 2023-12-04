#include "GameLogic.h"

#include "GameObjects/GameObject.h"
#include "GameObjects/Transform.h"

void GameLogic::Init()
{
    gameObject = new GameObject();
    gameObject->Init();
    gameObject->Start();
}

void GameLogic::Update()
{
    if (moveRight) {
        gameObject->transform->position->x++;
        if (gameObject->transform->position->x > 599) moveRight = false;
    }
    else {
        gameObject->transform->position->x--;
        if (gameObject->transform->position->x < 1) moveRight = true;
    }
}

void GameLogic::End()
{
    gameObject->End();
    delete gameObject;
}
