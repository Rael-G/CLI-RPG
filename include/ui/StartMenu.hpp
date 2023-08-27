#pragma once

#include <map>
#include <iostream>
#include <algorithm>
#include "ui/UserInterface.hpp"
#include "utils/ConsoleUtils.hpp"
#include "ui/CreationMenu.hpp"
#include "exceptions/EmptySaveFolderException.hpp"
#include "exceptions/CorruptedSaveGameException.hpp"
#include <exceptions/WorldObjectException.hpp>

class StartMenu : public UserInterface 
{
    public:
        StartMenu();
        std::string ToString() override;
        void New();
        void Load();
        void Options();
        void Help() override;
};