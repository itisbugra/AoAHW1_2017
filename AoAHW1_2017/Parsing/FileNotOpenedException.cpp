#include "FileNotOpenedException.hpp"

using Homework::FileNotOpenedException;

FileNotOpenedException::FileNotOpenedException(const std::string &reason)
: std::runtime_error(reason)
{
    //  Empty implementation
}
