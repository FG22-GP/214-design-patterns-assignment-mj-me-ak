#pragma once
#include "Component.h"
#include "../Math/Vector.h"

class Transform : public Component
{
public:
    Transform();
    Vector* position;

    virtual void End() override;
};
