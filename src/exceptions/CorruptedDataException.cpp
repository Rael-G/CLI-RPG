#include <exceptions/CorruptedDataException.hpp>

CorruptedDataException::CorruptedDataException(std::string msg)
{
    this->msg = Message() + msg;
}

const char* CorruptedDataException::what() const noexcept
{
    return msg.c_str();
}

std::string CorruptedDataException::Message() const
{
    return Text::GetText("EX-06");
}