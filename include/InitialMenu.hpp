#include <map>
#include <iostream>
#include <algorithm>
#include "UserInterface.hpp"
#include "ConsoleUtils.hpp"
#include "CreationMenu.hpp"

#pragma once

class InitialMenu : public UserInterface 
{
    public:
        InitialMenu();
        void Start();
};