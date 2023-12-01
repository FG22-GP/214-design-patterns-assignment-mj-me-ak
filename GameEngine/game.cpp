//Using SDL and standard IO
#pragma once

#include <SDL.h>
#include <stdio.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "Window.h"


//Screen dimension constants
const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;

const char* pikachuImagePath{ "img/pikachu.png" };

int main(int argc, char* args[])
{
	Window window = Window(SCREEN_WIDTH, SCREEN_HEIGHT);

	// All data related to pikachu
	SDL_Texture* pikachu = window.GetTextureFromPath(pikachuImagePath); // The final optimized image
	bool pikachuMoveRight = false;
	int pik_x, pik_y;
	pik_x = pik_y = 0;
	int pik_w, pik_h;
	pik_w = pik_h = 200;

	SDL_Texture* textTexture = window.GetTextureFromFont("font/lazy.ttf", 100);

	SDL_Event e; bool quit = false;

	// while the user doesn't want to quit
	while (quit == false)
	{
		SDL_GetTicks(); // can be used, to see, how much time in ms has passed since app start


		// loop through all pending events from Windows (OS)
		while (SDL_PollEvent(&e))
		{
			// check, if it's an event we want to react to:
			switch (e.type) {
				case SDL_QUIT: {
					quit = true;
				} break;

					// This is an example on how to use input events:
				case SDL_KEYDOWN: {
					// input example: if left, then make pikachu move left
					if (e.key.keysym.sym == SDLK_LEFT) {
						pikachuMoveRight = false;
					}
					// if right, then make pikachu move right
					if (e.key.keysym.sym == SDLK_RIGHT) {
						pikachuMoveRight = true;
					}
				} break;
			} 
		}

		SDL_DisplayMode DM;
		SDL_GetCurrentDisplayMode(0, &DM);
		auto screenWidth = DM.w;
		auto screenHeight = DM.h;

		// This is an example for how to check, whether keys are currently pressed:
		const Uint8* keystate = SDL_GetKeyboardState(NULL);
		if (keystate[SDL_SCANCODE_UP])
		{
			pik_y--;
		}
		if (keystate[SDL_SCANCODE_DOWN])
		{
			pik_y++;
		}

		// our current game logic :)
		if (pikachuMoveRight) {
			pik_x++;
			if (pik_x > 599) pikachuMoveRight = false;
		}
		else {
			pik_x--;
			if (pik_x < 1) pikachuMoveRight = true;
		}

		window.clear();
		
		// render Pikachu
		SDL_Rect targetRectangle{
			pik_x,
			pik_y,
			pik_w,
			pik_h
		};
		window.CopyTextureToRenderer(pikachu, NULL, &targetRectangle);

		// render the text
		targetRectangle = SDL_Rect{
			0,
			0,
			700,
			200
		};
		window.CopyTextureToRenderer(textTexture, NULL, &targetRectangle);

		// present screen (switch buffers)
		window.present();

		SDL_Delay(0); // can be used to wait for a certain amount of ms
	}

	return 0;
}