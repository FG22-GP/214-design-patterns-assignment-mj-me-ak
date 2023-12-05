#include "ObjectRenderer.h"

#include "Transform.h"
#include "../TextureLoader.h"
#include "../Math/VectorInt.h"

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

    const VectorInt transformScreenPos = transform->WorldToScreenPos();
    const VectorInt transformScreenScale = transform->WorldToScreenScale();
    SDL_Rect targetRectangle{
        transformScreenPos.x - transformScreenScale.x / 2,
        transformScreenPos.y - transformScreenScale.y / 2,
        transformScreenScale.x,
        transformScreenScale.y
    };
    window->CopyTextureToRenderer(texture, NULL, &targetRectangle);
}
