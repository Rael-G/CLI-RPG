#include "ui/AttributesDefinition.hpp"

AttributesDefinition::AttributesDefinition(Attributes *attributes, int &points)
: attributes(attributes), points(points)
{
    commands.push_back({"reset", std::bind(&AttributesDefinition::Reset, this)});


    subCommands.push_back({"health", std::bind(&AttributesDefinition::DefHealth, this)});
    subCommands.push_back({"mana", std::bind(&AttributesDefinition::DefMana, this)});
    subCommands.push_back({"strength", std::bind(&AttributesDefinition::DefStrength, this)});
    subCommands.push_back({"dexterity", std::bind(&AttributesDefinition::DefDexterity, this)});
    subCommands.push_back({"intelligence", std::bind(&AttributesDefinition::DefIntelligence, this)});
    subCommands.push_back({"faith", std::bind(&AttributesDefinition::DefFaith, this)});
    subCommands.push_back({"charisma", std::bind(&AttributesDefinition::DefCharisma, this)});

}

std::string AttributesDefinition::ToString()
{
    return "Attributes:\n"
       "Health: " + std::to_string(attributes->GetHealth())
       + ", Mana: " + std::to_string(attributes->GetMana())
       + ", Strength: " + std::to_string(attributes->GetStrength())
       + ", Dexterity: " + std::to_string(attributes->GetDexterity())
       + ", Intelligence: " + std::to_string(attributes->GetIntelligence())
       + ", Faith: " + std::to_string(attributes->GetFaith())
       + ", Charisma: " + std::to_string(attributes->GetCharisma())
       + "\nYou have " + std::to_string(points) + " points to spent.";
}

void AttributesDefinition::Reset()
{
    ConsoleUtils::ClearScreen();
    delete attributes;
    attributes = new Attributes();
    points = 20;
}

int AttributesDefinition::Define(std::string input)
{
    int pts;
    try
    {
        pts = std::stoi(input);
    }
    catch(const std::invalid_argument& e)
    {
        ConsoleUtils::ClearScreen();
        ConsoleUtils::PrintTextSlowly("\nInvalid input.\n\n", 50);
        return 0;
    }

    points -= pts;
    if (points < 0)
    {
        points += pts;
        ConsoleUtils::ClearScreen();
        ConsoleUtils::PrintTextSlowly("\nNot enough points.\n\n");
        return 0;
    }

    return pts;
}

//DRY?
//I need to refactor it!
void AttributesDefinition::DefHealth()
{

    ConsoleUtils::PrintTextSlowly("Health: ");
    std::string input = ConsoleUtils::ScanInput();

    int pts = Define(input);

    attributes->UpHealth(pts);
    ConsoleUtils::ClearScreen();
}

void AttributesDefinition::DefMana()
{
    ConsoleUtils::PrintTextSlowly("Mana: ");
    std::string input = ConsoleUtils::ScanInput();

    int pts = Define(input);

    attributes->UpMana(pts);
    ConsoleUtils::ClearScreen();
}

void AttributesDefinition::DefStrength()
{
    ConsoleUtils::PrintTextSlowly("Strength: ");
    std::string input = ConsoleUtils::ScanInput();

    int pts = Define(input);

    attributes->UpStrength(pts);
    ConsoleUtils::ClearScreen();
}

void AttributesDefinition::DefDexterity()
{
    ConsoleUtils::PrintTextSlowly("Dexterity: ");
    std::string input = ConsoleUtils::ScanInput();

    int pts = Define(input);

    attributes->UpDexterity(pts);
    ConsoleUtils::ClearScreen();
} 

void AttributesDefinition::DefIntelligence()
{
    ConsoleUtils::PrintTextSlowly("Intelligence: ");
    std::string input = ConsoleUtils::ScanInput();

    int pts = Define(input);

    attributes->UpIntelligence(pts);
    ConsoleUtils::ClearScreen();
}

void AttributesDefinition::DefFaith()
{
    ConsoleUtils::PrintTextSlowly("Faith: ");
    std::string input = ConsoleUtils::ScanInput();

    int pts = Define(input);

    attributes->UpFaith(pts);
    ConsoleUtils::ClearScreen();
}

void AttributesDefinition::DefCharisma()
{
    ConsoleUtils::PrintTextSlowly("Charisma: ");
    std::string input = ConsoleUtils::ScanInput();

    int pts = Define(input);

    attributes->UpCharisma(pts);
    ConsoleUtils::ClearScreen();
}