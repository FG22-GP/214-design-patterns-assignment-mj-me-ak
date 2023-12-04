#include "Player.h"

#include "ObjectRenderer.h"
#include "Transform.h"

void Player::Start()
{
    Component::Start();

    objectRenderer->SetTexture("img/pikachu.png");
}

void Player::Update()
{
    Component::Update();

    if (moveRight) {
        transform->position->x++;
        if (transform->position->x > 599) moveRight = false;
    }
    else {
        transform->position->x--;
        if (transform->position->x < 1) moveRight = true;
    }
}
