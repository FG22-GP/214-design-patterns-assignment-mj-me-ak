#include "CommandManager.h"

#include <SDL_scancode.h>

#include "Player.h"
#include "../input.h"

void CommandManager::Start()
{
    Component::Start();

    inputHandler = new InputHandler(InputScheme(SDL_SCANCODE_A, SDL_SCANCODE_D, SDL_SCANCODE_W, SDL_SCANCODE_S));
}

void CommandManager::Update()
{
    Component::Update();

    std::vector<Command*> commands = inputHandler->handleInput();
    for (auto command : commands)
    {
        command->execute(player);
    }
}

void CommandManager::End()
{
    Component::End();

    delete inputHandler;
}
