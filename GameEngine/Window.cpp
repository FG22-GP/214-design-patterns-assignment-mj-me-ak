#include "Window.h"

Window::Window(int width, int height)
{
	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
	}

	// initialize SDL_ttf for font loading
	if (TTF_Init() == -1)
	{
		printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
	}

	//Start up SDL and create window
	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO))
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}

	// Create Window and Renderer
	SDL_CreateWindowAndRenderer(width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE, &window, &renderer);
	if (!window)
	{
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
	}

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");  // make the scaled rendering look smoother.
	SDL_RenderSetLogicalSize(renderer, width, height);
}

Window::~Window()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}

void Window::clear()
{
	SDL_SetRenderDrawColor(renderer, 120, 60, 255, 255);
	SDL_RenderClear(renderer);
}

void Window::present()
{
	SDL_RenderPresent(renderer);
}

void Window::CopyTextureToRenderer(SDL_Texture* texture, SDL_Rect* srcRect, SDL_Rect* dstRect)
{
	SDL_RenderCopy(renderer, texture, srcRect, dstRect);
}

SDL_Texture* Window::GetTextureFromPath(const char* path)
{
	SDL_Surface* loadedSurface = IMG_Load(path);
	SDL_Texture* texture = NULL;

	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path, IMG_GetError());
		return nullptr;
	}
	else
	{
		//Convert surface to screen format
		texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		if (texture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path, SDL_GetError());
			return nullptr;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
		return texture;
	}
	return nullptr;
}

SDL_Texture* Window::GetTextureFromFont(const char* fontPath, int fontSize)
{
	SDL_Texture* textTexture;

	auto font = TTF_OpenFont(fontPath, fontSize);
	if (font == NULL)
	{
		printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
		return nullptr;
	}

	// create text from font
	SDL_Color textColor = { 0xff, 0xff, 0xff };

	// render the text into an unoptimized CPU surface
	SDL_Surface* textSurface = TTF_RenderText_Solid(font, "The lazy fox, blah blah", textColor);
	int textWidth, textHeight;
	if (textSurface == NULL)
	{
		printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
		return nullptr;
	}
	else
	{
		// Create texture GPU-stored texture from surface pixels
		textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
		if (textTexture == NULL)
		{
			printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
			return nullptr;
		}
		// Get image dimensions
		auto width = textSurface->w;
		auto height = textSurface->h;
		textWidth = textSurface->w;
		textHeight = textSurface->h;
		//Get rid of old loaded surface
		SDL_FreeSurface(textSurface);

		return textTexture;
	}
	return nullptr;
}
