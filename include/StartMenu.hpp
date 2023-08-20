#include <map>
#include <iostream>
#include <algorithm>
#include "UserInterface.hpp"
#include "ConsoleUtils.hpp"
#include "CreationMenu.hpp"

#pragma once

class StartMenu : public UserInterface 
{
    public:
        StartMenu();
        void New();
        void Load();
};