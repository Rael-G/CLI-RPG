#include "exceptions/EmptySaveFolderException.hpp"

EmptySaveFolderException::EmptySaveFolderException() 
{
    msg = Message();
}

const char* EmptySaveFolderException::what() const noexcept
{
    return msg.c_str();
}

std::string EmptySaveFolderException::Message() const
{
    return "Your save folder is empty. ";
}