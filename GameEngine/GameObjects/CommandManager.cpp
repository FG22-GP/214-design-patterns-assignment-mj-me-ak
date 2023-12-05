#include "CommandManager.h"

#include "Player.h"
#include "../input.h"

void CommandManager::Start()
{
    Component::Start();

    inputHandler = new InputHandler();
}

void CommandManager::Update()
{
    Component::Update();

    Command* command = inputHandler->handleInput();
    if(command != nullptr)
        command->execute(player);
}

void CommandManager::End()
{
    Component::End();

    delete inputHandler;
}
