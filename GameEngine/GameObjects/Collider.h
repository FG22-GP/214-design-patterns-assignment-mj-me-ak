#pragma once
#include "Component.h"
#include "../Window.h"
#include "../Math/Bounds.h"

class Collider : public Component
{
public:
    bool debugLines = false;

    void DrawDebugBound(Window* window);
    Bounds GetBounds();
};
