#include "GameLogic.h"

#include "GameObjects/GameObject.h"
#include "GameObjects/Player.h"
#include "GameObjects/Transform.h"

void GameLogic::Init()
{
    gameObject = new GameObject();
    gameObject->Init();
    gameObject->Start();
    gameObject->AddComponent<Player>();
}

void GameLogic::Update()
{
    gameObject->Update();
}

void GameLogic::End()
{
    gameObject->End();
    delete gameObject;
}
