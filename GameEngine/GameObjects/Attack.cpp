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

void Attack::StartPunch()
{
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
}

Bounds Attack::GetPunchBounds()
{
    return Bounds(transform->position->x, transform->position->y - punchHeight / 2, punchWidth, punchHeight);
}
