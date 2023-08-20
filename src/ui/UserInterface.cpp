#include "UserInterface.hpp"

UserInterface::UserInterface()
{
        commands.push_back({"options", std::bind(&UserInterface::Options, this)});
        commands.push_back({"help", std::bind(&UserInterface::Help, this)});
        commands.push_back({"return", std::bind(&UserInterface::Return, this)});
        commands.push_back({"exit", std::bind(&UserInterface::Exit, this)});
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
    std::cout << "Available Commands:" << std::endl;
    for ( int i = 0; i < commands.size(); i++)
    {
        std::cout << "<" << commands[i].first << "> ";
    }
    std::cout << std::endl;

    for ( int i = 0; i < subCommands.size(); i++)
    {
        std::cout << "<" << subCommands[i].first << "> ";
    }
    std::cout << std::endl; 
}

void UserInterface::Input(std::string input)
{

    for (int i = 0; i < commands.size(); i++)
    {
        if (commands[i].first == input)
        {
            commands[i].second();
            return;
        }
    }
    for (int i = 0; i < subCommands.size(); i++)
    {
        if (subCommands[i].first == input)
        {
            subCommands[i].second();
            return;
        }
    }

    ConsoleUtils::ClearScreen();
    std::cout << "Invalid Command!" << std::endl;
}

void UserInterface::Options()
{
    ConsoleUtils::ClearScreen();
}

void UserInterface::Help()
{
    ConsoleUtils::ClearScreen();

    std::cout << "This is a  Command-Text based RPG. Type your command at" 
        << " the command line and magic happens!" << std::endl;
}

void UserInterface::Return()
{
    //do nothing, automately return to previous UI when Run() receive "return"
    ConsoleUtils::ClearScreen();
}

void UserInterface::Exit()
{
    ConsoleUtils::ClearScreen();

    std::exit(0);
}