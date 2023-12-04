#include "Component.h"

#include <cstdio>

#include "GameObject.h"

Component::Component()
{
    transform = nullptr;
    objectRenderer = nullptr;
}

void Component::Init(GameObject* gameObject)
{
    this->gameObject = gameObject;
    this->transform = gameObject->transform;
    this->objectRenderer = gameObject->objectRenderer;
}

void Component::Start()
{
    printf("ComponentStart \n");
}

void Component::Update()
{
    
}

void Component::End()
{
    
}
