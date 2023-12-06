//Using SDL and standard IO
#pragma once

#include <SDL.h>
#include <stdio.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "GameLogic.h"
#include "input.h"
#include "Window.h"
#include "GameObjects/ObjectRenderer.h"

const Uint32 MS_PER_UPDATE = 16;

//Screen dimension constants
const int SCREEN_WIDTH = 1600;
const int SCREEN_HEIGHT = 800;

const char* pikachuImagePath{ "img/pikachu.png" };

int main(int argc, char* args[])
{
	Window window = Window(SCREEN_WIDTH, SCREEN_HEIGHT);

	// All data related to pikachu
	SDL_Texture* textTexture = window.GetTextureFromFont("font/lazy.ttf", 100);

	SDL_Event e; bool quit = false;

	GameLogic gameLogic;
	gameLogic.Init();

	Uint32 previous = SDL_GetTicks();
	Uint32 lag = 0.0;
	
	while (quit == false)
	{
		Uint32 current = SDL_GetTicks();
		Uint32 elapsed = current - previous;
		previous = current;
		lag += elapsed;

		//check for exit input
		while (SDL_PollEvent(&e))
		{
			switch (e.type)
			{
				case SDL_QUIT:				
					quit = true;
					break;
			}
		}

		gameLogic.Update(static_cast<float>(elapsed) / 1000.f);

		// update game logic
		while (lag >= MS_PER_UPDATE)
		{
			gameLogic.FixedUpdate();
			lag -= MS_PER_UPDATE;
		}

		// render
		window.clear();
		for (auto gameObject : GameLogic::GameObjects)
		{
			gameObject->objectRenderer->Render(&window);			
		}
		window.present();
	}
	gameLogic.End();

	return 0;
}
