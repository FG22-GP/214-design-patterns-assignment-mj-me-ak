#include "GameObject.h"

#include "ObjectRenderer.h"
#include "Transform.h"

void GameObject::Init()
{
    transform = new Transform();
    objectRenderer = new ObjectRenderer();

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
    
}

void GameObject::End()
{
    transform->End();
    objectRenderer->End();

    delete transform;
    delete objectRenderer;
}
