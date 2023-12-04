#pragma once
#include "Component.h"

class Player : public Component
{
    bool moveRight;
public:
    virtual void Start() override;
    virtual void Update() override;
};
