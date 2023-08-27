#include "exceptions/WorldObjectException.hpp"

WorldObjectException::WorldObjectException(std::string msg)
{
    this->msg = "Error Getting object from World. " + msg;
}

const char* WorldObjectException::what() const noexcept
{
    return msg.c_str();
}
