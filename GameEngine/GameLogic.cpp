#include "GameLogic.h"

#include "GameObjects/CommandManager.h"
#include "GameObjects/GameObject.h"
#include "GameObjects/ObjectRenderer.h"
#include "GameObjects/Player.h"
#include "GameObjects/Transform.h"

GameLogic::GameLogic()
{
    GameObjects = {};
}

void GameLogic::Init()
{
    auto playerGameObject1 = new GameObject();
    auto playerGameObject2 = new GameObject();
    playerGameObject1->AddComponent<Player>();
    playerGameObject2->AddComponent<Player>();

    auto inputGameObject = new GameObject();
    auto commandManager = inputGameObject->AddComponent<CommandManager>();
    commandManager->player1 = playerGameObject1;
    commandManager->player2 = playerGameObject2;
    playerGameObject2->objectRenderer->SetTexture("img/charmander.png");
}

void GameLogic::Update()
{
    for (auto gameObject : GameObjects)
    {
        gameObject->Update();
    }
}

void GameLogic::End()
{
    const int gameObjectCount = GameObjects.size();
    for (int i = gameObjectCount - 1; i >= 0; --i)
    {
        Destroy(GameObjects[i]);
    }
}

GameObject* GameLogic::instantiate()
{
    auto gameObject = new GameObject();
    return gameObject;
}

GameObject* GameLogic::instantiate(Vector position)
{
    auto gameObject = new GameObject();
    gameObject->transform->position->x = position.x;
    gameObject->transform->position->y = position.y;
    return gameObject;
}

GameObject* GameLogic::instantiate(Vector position, Vector scale)
{
    auto gameObject = new GameObject();
    gameObject->transform->position->x = position.x;
    gameObject->transform->position->y = position.y;
    gameObject->transform->scale->x = scale.x;
    gameObject->transform->scale->y = scale.y;
    return gameObject;
}

void GameLogic::Destroy(GameObject* gameObject)
{
    gameObject->End();
    delete gameObject;
}

void GameLogic::RegisterGameObject(GameObject* gameObject)
{
    if(std::ranges::find(GameObjects, gameObject) == GameObjects.end())
    {
        GameObjects.push_back(gameObject);
    }
}

void GameLogic::UnregisterGameObject(GameObject* gameObject)
{
    if(std::ranges::find(GameObjects, gameObject) != GameObjects.end())
    {
        std::erase(GameObjects, gameObject);
    }
}
