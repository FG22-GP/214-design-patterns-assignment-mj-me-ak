#pragma once
#include "Collider.h"
#include "Component.h"
#include "../Events/Subject.h"

class Player : public Component, Subject
{
    float horizontalSpeed = 0;
    float speedMultiplier = 1;
    bool isMoving;
    bool isCrouching;

    Collider* collider;
public:
    float moveSpeed = 0.1f;

    Player* other;
    
    virtual void Start() override;
    virtual void FixedUpdate() override;

    void Move(float direction);
    void Crouch(bool isCrouching);
};
