#include "GameObject.h"

#include "ObjectRenderer.h"
#include "Transform.h"

void GameObject::Init()
{
    transform = new Transform();
    objectRenderer = new ObjectRenderer();
    components = {};

    transform->Init(transform, objectRenderer);
    objectRenderer->Init(transform, objectRenderer);
}

void GameObject::Start()
{
    transform->Start();
    objectRenderer->Start();
}

void GameObject::Update()
{
    transform->Update();
    objectRenderer->Update();
    for (Component* component : components)
    {
        component->Update();
    }
}

void GameObject::End()
{
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
