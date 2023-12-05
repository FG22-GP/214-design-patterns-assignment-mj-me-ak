#pragma once
#include "Component.h"
#include "../Math/Vector.h"
#include "../Math/VectorInt.h"

class Transform : public Component
{
    const float WidthBound = 20.f;
public:
    Transform();
    Vector* position;
    Vector* scale;

    virtual void End() override;

    VectorInt WorldToScreenPos();
    VectorInt WorldToScreenScale();
};
