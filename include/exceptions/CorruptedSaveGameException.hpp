#pragma once

#include <exception>
#include <string>

class CorruptedSaveGameException: public std::exception
{
    private:
        std::string msg;
    public:
        CorruptedSaveGameException();
        virtual const char* what() const noexcept override;
        std::string Message() const;
};