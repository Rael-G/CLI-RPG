#include <ui/UserInterface.hpp>
#include <global/Text.hpp>

UserInterface::UserInterface()
{
        commands.push_back({"CMD-RETURN", std::bind(&UserInterface::Return, this)});
        commands.push_back({"CMD-EXIT", std::bind(&UserInterface::Exit, this)});
}

void UserInterface::Run()
{
    std::string input {""};
    while (input != Text::GetText("CMD-RETURN"))
    {
        ConsoleUtils::PrintTextSlowly(this->ToString() + "\n\n", -1);
        ShowCommands();
        std::string msg {"> "};
        ConsoleUtils::PrintTextSlowly(msg, 1);
        input = ConsoleUtils::ScanInput();

        std::transform(input.begin(), input.end(), input.begin(), [](unsigned char c) 
        {
            return std::tolower(c);
        });

        Input(input);
    }
}

void UserInterface::ShowCommands()
{
    std::string msg {"Available Commands:\n"};
    for ( int i = 0; i < commands.size(); i++)
    {
        msg += "<" + Text::GetText(commands[i].first) + "> ";
    }
    msg += "\n";

    for ( int i = 0; i < subCommands.size(); i++)
    {
        msg += "<" + Text::GetText(subCommands[i].first) + "> ";
    }
    msg += "\n";
    
    ConsoleUtils::PrintTextSlowly(msg);
}

void UserInterface::Input(std::string input)
{
    for (int i = 0; i < commands.size(); i++)
    {
        if (Text::GetText(commands[i].first) == input)
        {
            commands[i].second();
            return;
        }
    }
    for (int i = 0; i < subCommands.size(); i++)
    {
        if (Text::GetText(subCommands[i].first) == input)
        {
            subCommands[i].second();
            return;
        }
    }

    ConsoleUtils::ClearScreen();
    std::string msg {"Invalid Command!\n\n"};
    ConsoleUtils::PrintTextSlowly(msg);
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