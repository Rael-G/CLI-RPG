#include "UserInterface.hpp"

UserInterface::UserInterface()
{
    commands.insert(
    {
        {"help", std::bind(&UserInterface::Help, this)},
        {"exit", std::bind(&UserInterface::Exit, this)},
        {"return", std::bind(&UserInterface::Return, this)}

    });
}

void UserInterface::Run()
{
        std::string input {""};
        while (input != "return")
        {
            ShowCommands();
            std::cout << "> ";
            std::cin >> input;

            std::transform(input.begin(), input.end(), input.begin(), [](unsigned char c) 
            {
                return std::tolower(c);
            });

            Input(input);
        }
}

void UserInterface::ShowCommands()
{
    auto it = commands.begin();
    std::cout << "Available Commands:" << std::endl;
    for ( ; it!=commands.end(); it++)
    {
        std::cout << "<" << it->first << "> ";
    }
    std::cout << std::endl;

    it = subCommands.begin();
    for ( ; it!=subCommands.end(); it++)
    {
        std::cout << "<" << it->first << "> ";
    }
    std::cout << std::endl;
    
}

void UserInterface::Input(std::string input)
{
    auto it = commands.find(input);
    if (it != commands.end())
    {
        it->second();
    }
    else 
    {
        it = subCommands.find(input);
        if (it != subCommands.end())
        {
            it->second();
        }
        else
        {
            ConsoleUtils::ClearScreen();
            std::cout << "Invalid Command!" << std::endl;
        }
    }
}

void UserInterface::Exit()
{
    ConsoleUtils::ClearScreen();

    std::exit(0);
}

void UserInterface::Help()
{
    ConsoleUtils::ClearScreen();

    std::cout << "This is a  Command-Text based RPG. Type your command at" 
        << " the command line and magic happens!" << std::endl;
}

void UserInterface::Return()
{
    ConsoleUtils::ClearScreen();
}