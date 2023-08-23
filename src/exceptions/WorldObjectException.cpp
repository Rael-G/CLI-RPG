#include "exceptions/WorldObjectException.hpp"

WorldObjectException::WorldObjectException(std::string msg)
{
    this->msg = Message() + msg;
}

const char* WorldObjectException::what() const noexcept
{
    return msg.c_str();
}

std::string WorldObjectException::Message() const
{
    return "Error Getting object from World. ";
}