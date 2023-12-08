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

    objectRenderer->SetSpriteSheet("img/AnimationSheetGreyscale.png", 8, 3);
    transform->scale->x = 3;
    transform->scale->y = 3;
    Animator* animator = gameObject->GetComponent<Animator>();
    AddObserver(animator);
    Notify(*gameObject, StartIdle);
}

void Player::FixedUpdate()
{
    Component::FixedUpdate();

    transform->position->x += horizontalSpeed * moveSpeed;
}

void Player::Move(float direction)
{
    if (isCrouching) return;

    float towards = direction - horizontalSpeed;
    if(std::abs(towards) > 0.01f)
        towards /= std::abs(towards);
    horizontalSpeed += towards;

    if (std::abs(horizontalSpeed) < 0.1f && isMoving)
    {
        // player has stopped moving
        isMoving = false;
        Notify(*gameObject, StartIdle);
    }

    if (std::abs(horizontalSpeed) >= 0.1f && !isMoving)
    {
        // player has started moving
        Notify(*gameObject, StartWalk);
        isMoving = true;
    }
}

void Player::Crouch(bool isCrouching)
{
    this->isCrouching = isCrouching;
    if (isCrouching)
    {
        Notify(*gameObject, StartCrouch);
    }
    else
    {
        Notify(*gameObject, StartIdle);
    }
    horizontalSpeed = 0;
    isMoving = false;
}
