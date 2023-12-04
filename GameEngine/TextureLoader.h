#pragma once
#include "Window.h"

class TextureLoader
{
public:
    inline static Window* window;
    
    static SDL_Texture* GetTextureFromPath(const char* path);
    static SDL_Texture* GetTextureFromFont(const char* fontPath, int fontSize);
};
