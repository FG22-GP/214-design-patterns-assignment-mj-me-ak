#pragma once

class ObjectRenderer;
class Transform;

class Component
{
public:
    const Transform* transform;
    const ObjectRenderer* objectRenderer;

    Component();
    virtual ~Component() = default;

    void Init(Transform* transform, ObjectRenderer* objectRenderer);
    virtual void Start();
    virtual void Update();
    virtual void End();
};
