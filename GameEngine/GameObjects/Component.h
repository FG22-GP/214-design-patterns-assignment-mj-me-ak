#pragma once

class GameObject;
class ObjectRenderer;
class Transform;

class Component
{
public:
    GameObject* gameObject;
    Transform* transform;
    ObjectRenderer* objectRenderer;

    Component();
    virtual ~Component() = default;

    void Init(GameObject* gameObject);
    virtual void Awake();
    virtual void Start();
    virtual void Update();
    virtual void LateUpdate();
    virtual void End();
};
