#include <string>
#include "UserInterface.hpp"
#include "Attributes.hpp"
#include "Hero.hpp"

#pragma once

class CreationMenu : public UserInterface 
{
    public:
        std::string name;
        std::string ToString() override;
        CreationMenu();
        void Name();
        void Finish();    
};