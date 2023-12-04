#include "Component.h"

#include <cstdio>

Component::Component()
{
    transform = nullptr;
    objectRenderer = nullptr;
}

void Component::Init(Transform* transform, ObjectRenderer* objectRenderer)
{
    this->transform = transform;
    this->objectRenderer = objectRenderer;
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
