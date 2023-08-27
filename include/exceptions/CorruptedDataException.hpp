#pragma once

#include <exception>
#include <string>
#include <global/Text.hpp>

class CorruptedDataException : public std::exception
{
private:
    std::string msg;
public:
    CorruptedDataException(std::string msg);
    virtual const char* what() const noexcept override;
    std::string Message() const;
};