#pragma once
#include "Component.h"

class Player : public Component
{
    float horizontalSpeed = 0;
public:
    float moveSpeed = 0.1f;
    
    virtual void Start() override;
    virtual void FixedUpdate() override;

    void MoveRight();        
    void MoveLeft();        
};
