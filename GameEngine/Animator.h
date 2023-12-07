#pragma once
#include <map>

#include "Animation.h"
#include "Events/Observer.h"

class Animator : public Component, Observer 
{
private:
    std::map<AnimationName ,Animation*> animations; 

    Animation* currentAnimation;
    float currentAnimationTime;
    
public:
    Animator();
    void OnNotify(const GameObject& gameObject, Event event) override;
    void Update(float deltaTime) override;
};
