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
    AddObserver(animator);
    Notify(*gameObject, StartIdle);
}

void Player::FixedUpdate()
{
    Component::FixedUpdate();

    transform->position->x += horizontalSpeed * moveSpeed;
}

void Player::Move(int direction)
{
    horizontalSpeed += direction;
    if(std::abs(horizontalSpeed) < 0.1f && isMoving)
    {
        // player has stopped moving
        isMoving = false;
        Notify(*gameObject, StartIdle);
    }
    
    if(std::abs(horizontalSpeed) >= 0.1f && !isMoving)
    {
        // player has started moving
        Notify(*gameObject, StartWalk);
        isMoving = true;
    }
}
