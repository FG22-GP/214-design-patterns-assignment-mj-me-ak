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

    transform->position->x += (horizontalSpeed * speedMultiplier) * moveSpeed;
}

void Player::Move(float direction)
{
    float towards = direction - horizontalSpeed;
    if(std::abs(towards) > 0.01f)
        towards /= std::abs(towards);
    horizontalSpeed += towards;

    if (std::abs(horizontalSpeed) < 0.1f && isMoving)
    {
        // player has stopped moving
        isMoving = false;
        if(!isCrouching)
            Notify(*gameObject, StartIdle);
    }

    if (std::abs(horizontalSpeed) >= 0.1f && !isMoving)
    {
        // player has started moving
        isMoving = true;
        if(!isCrouching)
            Notify(*gameObject, StartWalk);
    }
}

void Player::Crouch(bool isCrouching)
{
    this->isCrouching = isCrouching;
    if (isCrouching)
    {
        speedMultiplier = 0;
        Notify(*gameObject, StartCrouch);
    }
    else
    {
        speedMultiplier = 1;
        Notify(*gameObject, isMoving ? StartWalk : StartIdle);
    }
}
