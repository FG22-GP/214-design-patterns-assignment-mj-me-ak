#pragma once
#include "Component.h"
#include "../Math/Bounds.h"

class Player;

class Attack : public Component
{
    
    Bounds GetPunchBounds();
public:
    Player* player;
    float punchHeight = 1;
    float punchWidth = 3;
    int punchDamage = 2;
    
    void Punch();
};
