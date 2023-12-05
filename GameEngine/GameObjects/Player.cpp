#include "Player.h"

#include "GameObject.h"
#include "ObjectRenderer.h"
#include "Transform.h"

void Player::Start()
{
    Component::Start();

    objectRenderer->SetTexture("img/pikachu.png");
    transform->position->y = 0;
    transform->scale->x = 5;
    transform->scale->y = 5;
}

void Player::Update()
{
    Component::Update();

    if (moveRight) {
        transform->position->x += 0.1f;
        if (transform->position->x > 19) moveRight = false;
    }
    else {
        transform->position->x -= 0.1f;
        if (transform->position->x < -19) moveRight = true;
    }
}
