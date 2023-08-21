#include "Game.hpp"

Game::Game(Hero *hero, Location *location) : UserInterface() 
{
    this->hero = hero;
    this->location = location;

    commands.push_back({"save", std::bind(&Game::Save, this)});

    for (int i = 0; i < location->GetCommands().size(); i++)
    {
        subCommands.push_back(location->GetCommands()[i]);
    }
}

std::string Game::ToString()
{
    return location->ToString();
}

void Game::Save()
{
    ConsoleUtils::ClearScreen();
    ConsoleUtils::PrintTextSlowly("Not Yet Implemented.\n\n", 1);
}

