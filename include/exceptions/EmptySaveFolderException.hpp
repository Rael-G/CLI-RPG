#pragma once

#include <exception>
#include <string>

class EmptySaveFolderException : public std::exception
{
    private:
        std::string msg;
    public:
        EmptySaveFolderException();
        virtual const char* what() const noexcept override;
        std::string Message() const;
};