#include "GameLogic.h"

#include "GameObjects/CommandManager.h"
#include "GameObjects/GameObject.h"
#include "GameObjects/Player.h"
#include "GameObjects/Transform.h"

void GameLogic::Init()
{
    gameObject = new GameObject();
    gameObject->AddComponent<Player>();

    inputGameObject = new GameObject();
    auto commandManager = inputGameObject->AddComponent<CommandManager>();
    commandManager->player = gameObject;
}

void GameLogic::Update()
{
    gameObject->Update();
    inputGameObject->Update();
}

void GameLogic::End()
{
    gameObject->End();
    inputGameObject->End();
    delete gameObject;
}
