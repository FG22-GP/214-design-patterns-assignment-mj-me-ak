#pragma once
#include "Component.h"
#include "../Events/Subject.h"
#include "../Math/Bounds.h"

class Player;

class Attack : public Component, public Subject
{
    bool punchStarted = false;
    bool punchHitBoxEnabled = false;
    bool hasHitEnemy = false;
    
    Bounds GetPunchBounds();
public:
    Player* player;
    float punchHeight = 1;
    float punchWidth = 3;
    int punchDamage = 2;

    virtual void Start() override;
    virtual void Update(float deltaTime) override;
    
    void StartPunch();
    void EnablePunchHitBox();
    void DisablePunchHitBox();
    void EndPunch();
};
