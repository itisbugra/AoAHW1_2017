#include "InvalidArgumentException.hpp"

using Homework::InvalidArgumentException;

InvalidArgumentException::InvalidArgumentException(const std::string &reason)
: std::runtime_error(reason)
{
    //  Empty implementation
}
