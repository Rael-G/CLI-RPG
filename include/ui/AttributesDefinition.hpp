#pragma once

#include "ui/UserInterface.hpp"
#include "entities/Attributes.hpp"

class AttributesDefinition : public UserInterface
{
    private:
        Attributes *attributes;
        int &points;
        int Define(std::string input);
    public:
        AttributesDefinition(Attributes *attributes, int &points);
        std::string ToString() override;
        void Help() override;

        
        void Reset();
        void DefHealth();
        void DefMana();
        void DefStrength();
        void DefDexterity();
        void DefIntelligence();
        void DefFaith();
        void DefCharisma();
};