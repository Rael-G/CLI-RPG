#include "UserInterface.hpp"
#include <string>

#pragma once

class CreationMenu : public UserInterface 
{
    private:
        std::string name;
        std::string atributes;
    public:
        CreationMenu();
        void Name();
        void Atributes();
        void Finish();    
};