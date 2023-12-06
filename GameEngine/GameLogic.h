#pragma once
#include "GameObjects/GameObject.h"

class Vector;

class GameLogic
{
public:
    inline static std::vector<GameObject*> GameObjects;

    GameLogic();
    
    void Init();
    void Update();
    void End();

    static GameObject* Instansiate();
    static GameObject* Instansiate(Vector position);
    static GameObject* Instansiate(Vector position, Vector scale);
    static void Destroy(GameObject* gameObject);
    static void RegisterGameObject(GameObject* gameObject);
    static void UnregisterGameObject(GameObject* gameObject);
};
