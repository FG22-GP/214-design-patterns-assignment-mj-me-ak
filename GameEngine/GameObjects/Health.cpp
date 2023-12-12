#include "Health.h"

#include "../GameLogic.h"

void Health::Start()
{
    Component::Start();

    currentHealth = initialHealth;
}

void Health::ChangeHealth(int delta)
{
    currentHealth += delta;

    if(currentHealth <= 0)
    {
        GameLogic::Destroy(gameObject);
    }
}
