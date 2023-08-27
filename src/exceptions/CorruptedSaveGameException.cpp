#include "exceptions/CorruptedSaveGameException.hpp"

CorruptedSaveGameException::CorruptedSaveGameException()
: msg(Message()) 
{}

const char* CorruptedSaveGameException::what() const noexcept
{
    return msg.c_str();
}

std::string CorruptedSaveGameException::Message() const
{
    return "There are a corrupted SaveGame. ";
}