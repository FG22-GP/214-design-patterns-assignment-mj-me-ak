#pragma once
#include "../GameObjects/GameObject.h"


class Observer : Component
{
public:
    virtual ~Observer() = default; 
    virtual void OnNotify(const GameObject&) = 0;
};
