#include "ObjectRenderer.h"

#include "Transform.h"
#include "../TextureLoader.h"

void ObjectRenderer::Start()
{
    Component::Start();

    texture = TextureLoader::GetTextureFromPath("img/pikachu.png");
}

void ObjectRenderer::Render(Window* window)
{
    SDL_Rect targetRectangle{
        transform->position->x,
        transform->position->y,
        200,
        200
    };
    window->CopyTextureToRenderer(texture, NULL, &targetRectangle);
}
