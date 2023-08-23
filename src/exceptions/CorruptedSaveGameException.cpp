#include "exceptions/CorruptedSaveGameException.hpp"

CorruptedSaveGameException::CorruptedSaveGameException(int corrupts)
: msg(Message()), corrupts(corrupts) {}

const char* CorruptedSaveGameException::what() const noexcept
{
    return msg.c_str();
}

std::string CorruptedSaveGameException::Message() const
{
    return "There is " + std::to_string(corrupts) + " corrupted SaveGame. ";
}