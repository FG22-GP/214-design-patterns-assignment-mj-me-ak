#pragma once
#include "Events/Observer.h"

class Animator : Observer
{
public:
    void OnNotify(const GameObject&) override;
};
