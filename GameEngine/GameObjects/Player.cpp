#include "Player.h"

#include <complex>

#include "GameObject.h"
#include "ObjectRenderer.h"
#include "Transform.h"

void Player::Start()
{
    Component::Start();

    objectRenderer->SetTexture("img/pikachu.png");
    transform->scale->x = 3;
    transform->scale->y = 3;
}

void Player::FixedUpdate()
{
    Component::FixedUpdate();

    //transform->position->x = std::cos(SDL_GetTicks() / 500.f) * 2;
    //transform->position->y = std::sin(SDL_GetTicks() / 500.f) * 2;
}
