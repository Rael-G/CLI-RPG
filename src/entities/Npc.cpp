#include "entities/Npc.hpp"

int Npc::GetId()
{
    return id;
}
std::string Npc::GetName()
{
    return name;
}

void Npc::Talk()
{
    ConsoleUtils::ClearScreen();
    ConsoleUtils::PrintTextSlowly("Not Yet Implemented.\n\n", 1);
}
