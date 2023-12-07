#include "GameLogic.h"

#include "Animator.h"
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
    Vector player1Pos = Vector(-10, -6);
    Vector player2Pos = Vector(10, -6);
    auto playerGameObject1 = Instantiate(player1Pos);
    auto playerGameObject2 = Instantiate(player2Pos);
    playerGameObject1->AddComponent<Animator>();
    playerGameObject2->AddComponent<Animator>();
    playerGameObject1->AddComponent<Player>();
    playerGameObject2->AddComponent<Player>();

    auto inputGameObject = new GameObject();
    auto commandManager = inputGameObject->AddComponent<CommandManager>();
    commandManager->player1 = playerGameObject1;
    commandManager->player2 = playerGameObject2;
    // playerGameObject2->objectRenderer->SetTexture("img/charmander.png");
}

void GameLogic::Update(float deltaTime)
{
    for (auto gameObject : GameObjects)
    {
        gameObject->Update(deltaTime);
    }
}

void GameLogic::FixedUpdate()
{
    for (auto gameObject : GameObjects)
    {
        gameObject->FixedUpdate();
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

GameObject* GameLogic::Instantiate()
{
    auto gameObject = new GameObject();
    return gameObject;
}

GameObject* GameLogic::Instantiate(Vector& position)
{
    auto gameObject = new GameObject();
    gameObject->transform->position = std::make_shared<Vector>(position);
    return gameObject;
}

GameObject* GameLogic::Instantiate(Vector& position, Vector& scale)
{
    auto gameObject = new GameObject();
    gameObject->transform->position = std::make_shared<Vector>(position);
    gameObject->transform->scale = std::make_shared<Vector>(scale);
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
