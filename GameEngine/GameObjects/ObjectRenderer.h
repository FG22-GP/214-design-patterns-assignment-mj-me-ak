#pragma once
#include "Component.h"
#include "../Window.h"

class ObjectRenderer : public Component
{
    SDL_Texture* texture;
public:
    virtual void Start() override;
    void SetTexture(const char* imagePath);
    void Render(Window* window);
};
