#pragma once
#include "Component.h"

class Health : public Component
{
    int currentHealth;
public:
    int initialHealth = 10;

    virtual void Start() override;
    void ChangeHealth(int delta);
};
