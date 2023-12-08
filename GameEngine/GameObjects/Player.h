#pragma once
#include "Component.h"

class Player : public Component
{
    float horizontalSpeed = 0;
    bool isMoving;
public:
    float moveSpeed = 0.1f;
    
    virtual void Start() override;
    virtual void FixedUpdate() override;

    void Move(int direction);
};
