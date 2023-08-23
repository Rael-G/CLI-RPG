#pragma once

#include <string>

class Item {
    private:
        std::string name;
    public:
        Item(std::string name);
        virtual std::string ToString();
};