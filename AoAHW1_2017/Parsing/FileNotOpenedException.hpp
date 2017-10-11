#include "PrefixHeader.pch"

#include <exception>

namespace Homework {
    class FileNotOpenedException : public std::runtime_error {
    public:
        FileNotOpenedException(const std::string &reason);
    };
}
