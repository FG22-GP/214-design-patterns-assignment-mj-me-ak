#include "ObjectRenderer.h"

#include "Transform.h"
#include "../TextureLoader.h"

void ObjectRenderer::Start()
{
    Component::Start();
}

void ObjectRenderer::SetTexture(const char* imagePath)
{
    texture = TextureLoader::GetTextureFromPath(imagePath);
}

void ObjectRenderer::Render(Window* window)
{
    if(texture == nullptr)
        return;
    
    SDL_Rect targetRectangle{
        transform->position->x,
        transform->position->y,
        200,
        200
    };
    window->CopyTextureToRenderer(texture, NULL, &targetRectangle);
}
