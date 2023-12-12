#include "Animator.h"

#include "GameObjects/ObjectRenderer.h"

Animator::Animator()
{
    currentAnimationTime = 0.0f;

    Animation* idleAnimation = new Animation {Idle, 1, 1, false, {Keyframe{0.0f, 0}}};
    
    Animation* walkAnimation = new Animation {Walk, 8, 0.8f, true,
        {Keyframe{0.0f, 0},
            Keyframe{0.1f, 1},
        Keyframe{0.2f, 2},
        Keyframe{0.3f, 3},
        Keyframe{0.4f, 4},
        Keyframe{0.5f, 5},
        Keyframe{0.6f, 6},
        Keyframe{0.7f, 7}}};

    Animation* crouchAnimation = new Animation {Crouch, 1, 1, false, {Keyframe{0.0f, 0}}};

    Animation* punchAnimation = new Animation {Punch, 7, 0.7f, false,
        {Keyframe{0.0f, 0},
        Keyframe(0.1f, 1),
        Keyframe(0.2f, 2),
        Keyframe(0.3f, 3),
        Keyframe(0.4f, 4),
        Keyframe(0.5f, 5),
        Keyframe(0.6f, 6)}};

    animations[Idle] = idleAnimation;
    animations[Walk] = walkAnimation;
    animations[Crouch] = crouchAnimation;
    animations[Punch] = punchAnimation;
}

void Animator::OnNotify(const GameObject& gameObject, Event event)
{
    currentAnimationTime = 0.0f;
    switch (event)
    {
        case StartWalk:
            currentAnimation = animations[Walk];
            break;
        case StartIdle:
            currentAnimation = animations[Idle];
            break;
        case StartCrouch:
            currentAnimation = animations[Crouch];
            break;
        case StartPunch:
            currentAnimation = animations[Punch];
            break;
    }
}

void Animator::Update(float deltaTime)
{
    Component::Update(deltaTime);
    if(currentAnimation == NULL)
    {
        return;
    }

    for (int i = 0; i <= currentAnimation->keyframes.size() - 1; i++)
    {
        auto keyframe = currentAnimation->keyframes[i];

        if(i == currentAnimation->keyframes.size()-1)
        {
            if(currentAnimationTime >= keyframe.time)
            {
                keyframe.Execute(gameObject, currentAnimation->animationName);
            }
            
            if(currentAnimationTime >= currentAnimation->length && currentAnimation->shouldLoop)
            {
                currentAnimationTime = 0.0f;
            }
            break;
        }
        
        if(currentAnimationTime >= keyframe.time && currentAnimationTime < currentAnimation->keyframes[i+1].time)
        {
            keyframe.Execute(gameObject, currentAnimation->animationName);
        }
    }
    currentAnimationTime += deltaTime;
}
