#pragma once

#include <exception>
#include <string>

class WorldObjectException : public std::exception
{
    private:
        std::string msg;
    public:
        WorldObjectException(std::string msg);
        virtual const char* what() const noexcept override;
};