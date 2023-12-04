#pragma once
#include <vector>

#include "Component.h"

class GameObject
{
    friend class GameLogic;

    void Init();
    void Start();
    void Update();
    void End();

    std::vector<Component*> components;
public:
    Transform* transform;
    ObjectRenderer* objectRenderer;

    void AddComponent(Component* component);
    void RemoveComponent(Component* component);
};
