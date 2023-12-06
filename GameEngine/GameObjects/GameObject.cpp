#include "GameObject.h"

#include "ObjectRenderer.h"
#include "Transform.h"
#include "../GameLogic.h"

GameObject::GameObject()
{
    Init();
    Start();
}

void GameObject::Init()
{
    transform = new Transform();
    objectRenderer = new ObjectRenderer();
    components = {};

    transform->Init(this);
    objectRenderer->Init(this);

    GameLogic::RegisterGameObject(this);

    transform->Awake();
    objectRenderer->Awake();
}

void GameObject::Start()
{
    transform->Start();
    objectRenderer->Start();
}

void GameObject::Update(float deltaTime)
{
    transform->Update(deltaTime);
    objectRenderer->Update(deltaTime);
    for (Component* component : components)
    {
        component->Update(deltaTime);
        component->Update(deltaTime);
    }
}

void GameObject::FixedUpdate()
{
    transform->FixedUpdate();
    objectRenderer->FixedUpdate();
    for (Component* component : components)
    {
        component->FixedUpdate();
        component->LateUpdate();
    }
}

void GameObject::End()
{
    GameLogic::UnregisterGameObject(this);
    
    transform->End();
    objectRenderer->End();

    const int componentCount = components.size();
    for (int i = componentCount - 1; i >= 0; --i)
    {
        RemoveComponent(components[i]);
    }

    delete transform;
    delete objectRenderer;
}
