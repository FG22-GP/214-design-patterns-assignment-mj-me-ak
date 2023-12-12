#pragma once
#include "Attack.h"
#include "Collider.h"
#include "Health.h"
#include "Component.h"
#include "../Events/Subject.h"

class Player : public Component, Subject
{
    float horizontalSpeed = 0;
    float speedMultiplier = 1;
    bool isMoving;
    bool isCrouching;
    
public:
    Player* other;
    Collider* collider;
    Attack* attack;
    Health* health;

    bool locked;
    
    float moveSpeed = 0.1f;

    
    virtual void Start() override;
    virtual void FixedUpdate() override;
    
    void Move(float direction);
    void Crouch(bool isCrouching);
};
