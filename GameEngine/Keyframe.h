#pragma once
#include "AnimationName.h"
#include "GameObjects/GameObject.h"
#include "GameObjects/ObjectRenderer.h"

struct Keyframe
{
    float time;
    int frameIndex;

    void Execute(GameObject* gameObject, AnimationName animationName)
    {
        gameObject->objectRenderer->SetSpriteSheetIndex(frameIndex, animationName);
    }
};
