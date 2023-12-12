#include "Attack.h"
#include "Player.h"
#include "Transform.h"
#include "../Animator.h"

void Attack::Start()
{
    Component::Start();

    AddObserver(gameObject->GetComponent<Animator>());
}

void Attack::Update(float deltaTime)
{
    Component::Update(deltaTime);

    if(punchStarted && punchHitBoxEnabled && !hasHitEnemy)
    {
        Bounds punchBound = GetPunchBounds();
        if(player->other->collider->CollidesWith(punchBound))
        {
            player->other->health->ChangeHealth(-punchDamage);
            hasHitEnemy = true;
        }
    }
}

// create weak pointer
// pass player b as weak pointer to player a
// when player a accesses it, you can check weak pointer get reference, which returns a shared pointer, it ensures player does not get destroyed while you hold it
// engine (or someone else) always holds a shared pointer until Destroy is called, then you release the shared pointer handle

void Attack::StartPunch()
{
    if(punchStarted || player->locked) return;
    
    player->locked = true;
    punchStarted = true;
    Notify(*gameObject, Event::StartPunch);
}

void Attack::EnablePunchHitBox()
{
    if(punchStarted)
        punchHitBoxEnabled = true;
}

void Attack::DisablePunchHitBox()
{
    if(punchStarted)
        punchHitBoxEnabled = false;
}

void Attack::EndPunch()
{
    punchStarted = false;
    punchHitBoxEnabled = false;
    hasHitEnemy = false;

    player->locked = false;
    Notify(*gameObject, Event::StartIdle);
}

Bounds Attack::GetPunchBounds()
{
    return Bounds(transform->position->x, transform->position->y - punchHeight * 2, punchWidth, punchHeight);
}
