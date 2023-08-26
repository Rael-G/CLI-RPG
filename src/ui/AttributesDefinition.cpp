#include <ui/AttributesDefinition.hpp>
#include <global/Text.hpp>

AttributesDefinition::AttributesDefinition(Attributes *attributes, int &points)
: attributes(attributes), points(points)
{
    commands.push_back({"CMD-RESET", std::bind(&AttributesDefinition::Reset, this)});


    subCommands.push_back({"ATB-HEALTH", std::bind(&AttributesDefinition::DefHealth, this)});
    subCommands.push_back({"ATB-MANA", std::bind(&AttributesDefinition::DefMana, this)});
    subCommands.push_back({"ATB-STRENGTH", std::bind(&AttributesDefinition::DefStrength, this)});
    subCommands.push_back({"ATB-DEXTERITY", std::bind(&AttributesDefinition::DefDexterity, this)});
    subCommands.push_back({"ATB-INTELLIGENCE", std::bind(&AttributesDefinition::DefIntelligence, this)});
    subCommands.push_back({"ATB-FAITH", std::bind(&AttributesDefinition::DefFaith, this)});
    subCommands.push_back({"ATB-CHARISMA", std::bind(&AttributesDefinition::DefCharisma, this)});

}

std::string AttributesDefinition::ToString()
{
    return "Attributes:\n"
        "You have " + std::to_string(points)+" points to spent.\n"
        + attributes->ToString();
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
        ConsoleUtils::PrintTextSlowly("\nInvalid input." + std::string(20, ' '), 100);
        return 0;
    }

    points -= pts;
    if (points < 0)
    {
        points += pts;
        ConsoleUtils::ClearScreen();
        ConsoleUtils::PrintTextSlowly("\nNot enough points." + std::string(20, ' '), 100);
        return 0;
    }

    return pts;
}

//DRY?
//I need to refactor it!
void AttributesDefinition::DefHealth()
{

    ConsoleUtils::PrintTextSlowly(Text::GetText("ATB-HEALTH") + ":");
    std::string input = ConsoleUtils::ScanInput();
    ConsoleUtils::ClearScreen();

    int pts = Define(input);
    attributes->UpHealth(pts);
}

void AttributesDefinition::DefMana()
{
    ConsoleUtils::PrintTextSlowly(Text::GetText("ATB-MANA") + ":");
    std::string input = ConsoleUtils::ScanInput();

    int pts = Define(input);

    attributes->UpMana(pts);
    ConsoleUtils::ClearScreen();
}

void AttributesDefinition::DefStrength()
{
    ConsoleUtils::PrintTextSlowly(Text::GetText("ATB-STRENGTH") + ":");
    std::string input = ConsoleUtils::ScanInput();

    int pts = Define(input);

    attributes->UpStrength(pts);
    ConsoleUtils::ClearScreen();
}

void AttributesDefinition::DefDexterity()
{
    ConsoleUtils::PrintTextSlowly(Text::GetText("ATB-DEXTERITY") + ":");
    std::string input = ConsoleUtils::ScanInput();

    int pts = Define(input);

    attributes->UpDexterity(pts);
    ConsoleUtils::ClearScreen();
} 

void AttributesDefinition::DefIntelligence()
{
    ConsoleUtils::PrintTextSlowly(Text::GetText("ATB-INTELLIGENCE") + ":");
    std::string input = ConsoleUtils::ScanInput();

    int pts = Define(input);

    attributes->UpIntelligence(pts);
    ConsoleUtils::ClearScreen();
}

void AttributesDefinition::DefFaith()
{
    ConsoleUtils::PrintTextSlowly(Text::GetText("ATB-FAITH") + ":");
    std::string input = ConsoleUtils::ScanInput();

    int pts = Define(input);

    attributes->UpFaith(pts);
    ConsoleUtils::ClearScreen();
}

void AttributesDefinition::DefCharisma()
{
    ConsoleUtils::PrintTextSlowly(Text::GetText("ATB-CHARISMA") + ":");
    std::string input = ConsoleUtils::ScanInput();

    int pts = Define(input);

    attributes->UpCharisma(pts);
    ConsoleUtils::ClearScreen();
}