#pragma once
#include "Component.h"

class Player : public Component
{
public:
    virtual void Start() override;
    virtual void FixedUpdate() override;
};
