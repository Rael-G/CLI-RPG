#pragma once

#include <exception>
#include <string>

class CorruptedSaveGameException: public std::exception
{
    private:
        int corrupts;
        std::string msg;
    public:
        CorruptedSaveGameException(int corrupts);
        virtual const char* what() const noexcept override;
        std::string Message() const;
};