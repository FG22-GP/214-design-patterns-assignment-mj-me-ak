#pragma once

#include <SDL.h>
#include <stdio.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

//extern class IImageLoader;

class Window
{
	//The window we'll be rendering to
	SDL_Window* window{};
	//The surface contained by the window
	SDL_Surface* screenSurface{};
	//Whether Window Startup was successful
	bool success;
	// dependency to the ImageLoader
	//IImageLoader* imageLoader;
	SDL_Renderer* renderer;
public:
	Window(int width, int height);
	~Window();
	bool wasSuccessful() { return success; }
	//void render(Image* image);
	void clear();
	void present();

	void CopyTextureToRenderer(SDL_Texture* texture, SDL_Rect* srcRect, SDL_Rect* dstRect);

	//std::unique_ptr<Image> loadImage(const char* path);

	SDL_Texture* GetTextureFromPath(const char* path);
	SDL_Texture* GetTextureFromFont(const char* fontPath, int fontSize);
};

