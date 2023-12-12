#pragma once
#include <memory>

#include "Component.h"
#include "../Window.h"
#include "../Math/Bounds.h"

class Vector;

class Collider : public Component
{
public:
    Collider();
    
    bool debugLines = false;
    std::shared_ptr<Vector> scale;

    virtual void Awake() override;
    
    void DrawDebugBound(Window* window);
    virtual Bounds GetBounds();
};
