#include "Attack.h"
#include "Player.h"
#include "Transform.h"

void Attack::Punch()
{
    Bounds punchBound = GetPunchBounds();
    if(player->other->collider->CollidesWith(punchBound))
    {
        player->other->health->ChangeHealth(-punchDamage);
    }
}

Bounds Attack::GetPunchBounds()
{
    return Bounds(transform->position->x, transform->position->y - punchHeight / 2, punchWidth, punchHeight);
}
