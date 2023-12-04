#pragma once
#include <vector>

#include "Component.h"

class GameObject
{
    friend class GameLogic;

    GameObject();

    void Init();
    void Start();
    void Update();
    void End();

    std::vector<Component*> components;
public:
    Transform* transform;
    ObjectRenderer* objectRenderer;

    template<typename T, std::enable_if_t<std::is_base_of_v<Component, T>>* = nullptr>
    T* AddComponent();
    template<typename T, std::enable_if_t<std::is_base_of_v<Component, T>>* = nullptr>
    T* GetComponent();
    template<typename T, std::enable_if_t<std::is_base_of_v<Component, T>>* = nullptr>
    void RemoveComponent(T* component);
};

template <typename T, std::enable_if_t<std::is_base_of_v<Component, T>>*>
T* GameObject::AddComponent()
{
    T* component = new T();
    components.push_back(component);

    component->Init(this);
    component->Start();
    
    return component;
}

template <typename T, std::enable_if_t<std::is_base_of_v<Component, T>>*>
T* GameObject::GetComponent()
{
    for (std::vector<Component*>::iterator it = components.begin(); it != components.end(); ++it)
    {
        if (typeid(*(*it)) == typeid(T))
        {
            return *it;
        }
    }

    return nullptr;
}

template <typename T, std::enable_if_t<std::is_base_of_v<Component, T>>*>
void GameObject::RemoveComponent(T* component)
{
    // remove if it contains
    for (std::vector<Component*>::iterator it = components.begin(); it != components.end(); ++it)
    {
        if (*it == component)
        {
            it = components.erase(it);
            (*it)->End();
            delete (*it);
            break;
        }
    }
}
