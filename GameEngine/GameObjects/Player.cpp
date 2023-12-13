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

    objectRenderer->SetSpriteSheet("img/AnimationSheet.png", 8, 10);
    transform->scale->x = 3;
    transform->scale->y = 3;
    Animator* animator = gameObject->GetComponent<Animator>();
    AddObserver(animator);
    Notify(*gameObject, StartIdle);

    collider = gameObject->AddComponent<Collider>();
    health = gameObject->AddComponent<Health>();
    attack = gameObject->AddComponent<Attack>();
    attack->player = this;

    collider->debugLines = true;

    collider->scale->x = 0.3f;
    collider->scale->y = 0.7f;    
    collider->offset->y = -0.35f;    
}

void Player::FixedUpdate()
{
    Component::FixedUpdate();

    if(other->transform->position->x >= transform->position->x)
    {
        isLeftOfOther = true;
    }
    else
    {
        isLeftOfOther = false;
    }

    objectRenderer->flipped = isLeftOfOther ? false : true;

    if(isMoving && !locked)
        transform->position->x += (horizontalSpeed * speedMultiplier) * moveSpeed;
}

void Player::Move(float direction)
{
    if(locked || isCrouching)
    {
        horizontalSpeed = 0;
        isMoving = false;
        return;
    }
    
    if(direction == -1 && horizontalSpeed == 1)
        horizontalSpeed = 0;
    
    float towards = direction - horizontalSpeed;
    towards = std::clamp(towards, -1.f, 1.f);
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
        isMoving = true;
        
            Notify(*gameObject, StartWalk);
    }
}

void Player::Crouch(bool isCrouching)
{
    if(locked)
        return;
    
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

