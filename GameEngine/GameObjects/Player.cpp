#include "Player.h"

// #include <complex>
// #include <iostream>

#include <algorithm>

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

    if(isMoving)
        transform->position->x += (horizontalSpeed * speedMultiplier) * moveSpeed;
}

void Player::Move(float direction)
{
    if(direction == -1 && horizontalSpeed == 1)
        horizontalSpeed = 0;
    
    float towards = direction - horizontalSpeed;
    towards = std::clamp(towards, -1.f, 1.f);
    horizontalSpeed += towards;

    if (std::abs(horizontalSpeed) < 0.1f && isMoving)
    {
        // player has stopped moving
        isMoving = false;
        if(!isCrouching)
        {
            printf("idle \n");
            Notify(*gameObject, StartIdle);
        }
    }

    if (std::abs(horizontalSpeed) >= 0.1f && !isMoving)
    {
        // player has started moving
        isMoving = true;
        if(!isCrouching)
        {
            printf("walk \n");
            Notify(*gameObject, StartWalk);
        }
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
