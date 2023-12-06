#pragma once
#include "Component.h"
#include "../Window.h"

class ObjectRenderer : public Component
{
    SDL_Texture* texture;
    bool isSpriteSheet;
    int columnCount;
    int rowCount;
    int cellWidth;
    int cellHeight;
    int currentColumnIndex;
    int currentRowIndex;

    SDL_Rect GetSourceRect();
    SDL_Rect GetDestinationRect();
public:
    virtual void Start() override;
    void SetTexture(const char* imagePath);
    void SetSpriteSheet(const char* imagePath, int columnCount, int rowCount = 1);
    void SetSpriteSheetIndex(int columnIndex, int rowIndex = 0);
    void Render(Window* window);
};
