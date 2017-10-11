#pragma once

#include <string>
#include <exception>

namespace Homework {
    class InvalidArgumentException : public std::runtime_error {
    public:
        InvalidArgumentException(const std::string &reason);
    };
}
