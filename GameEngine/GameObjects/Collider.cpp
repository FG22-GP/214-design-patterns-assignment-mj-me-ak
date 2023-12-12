#include "Collider.h"

#include <SDL_render.h>

#include "ObjectRenderer.h"
#include "Transform.h"
#include "../TextureLoader.h"

Collider::Collider()
{
    scale = std::make_shared<Vector>(1, 1);
}

void Collider::Awake()
{
    Component::Awake();

    objectRenderer->collider = this;
}

void Collider::DrawDebugBound(Window* window)
{
    Bounds bounds = GetBounds();
    VectorInt bottomLeftScreenSpace = transform->WorldToScreen(Vector(bounds.x, bounds.y)); 
    VectorInt topRightScreenSpace = transform->WorldToScreen(Vector(bounds.x + bounds.w, bounds.y + bounds.h)); 
    SDL_Point points[] = 
        {
        SDL_Point(bottomLeftScreenSpace.x, bottomLeftScreenSpace.y),
        SDL_Point(bottomLeftScreenSpace.x, topRightScreenSpace.y),
        SDL_Point(topRightScreenSpace.x, topRightScreenSpace.y),
        SDL_Point(topRightScreenSpace.x, bottomLeftScreenSpace.y),
        SDL_Point(bottomLeftScreenSpace.x, bottomLeftScreenSpace.y)
    };
    SDL_SetRenderDrawColor(window->renderer, 255, 0, 0, 255);
    SDL_RenderDrawLines(window->renderer, points, 5);
}

Bounds Collider::GetBounds()
{
    return Bounds(
        transform->position->x - transform->scale->x * scale->x / 2,
        transform->position->y - transform->scale->y * scale->y / 2,
        transform->scale->x * scale->x,
        transform->scale->y * scale->y);
}
