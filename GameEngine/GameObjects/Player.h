#pragma once
#include "Component.h"

class Player : public Component
{
public:
    virtual void Start() override;
    virtual void Update() override;
};
