#include "Player.h"

// #include <complex>
// #include <iostream>

#include "GameObject.h"
#include "ObjectRenderer.h"
#include "Transform.h"
#include "../Animator.h"

class Animator;

void Player::Start()
{
    Component::Start();

    objectRenderer->SetSpriteSheet("img/AnimationSheet.png", 8, 2);
    transform->scale->x = 3;
    transform->scale->y = 3;
    Animator* animator = gameObject->GetComponent<Animator>();
    animator->OnNotify(*gameObject, StartWalk);
}

void Player::FixedUpdate()
{
    Component::FixedUpdate();

    transform->position->x += horizontalSpeed * moveSpeed;
}

void Player::Move(int direction)
{
    horizontalSpeed += direction;
}
