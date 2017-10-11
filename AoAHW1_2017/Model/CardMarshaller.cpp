#include "CardMarshaller.hpp"

#include "InvalidArgumentException.hpp"

using Homework::CardMarshaller;

auto
CardMarshaller::unmarshall(std::vector<std::string> parameters) const
-> Card
{
    if (parameters.size() == 6) {
        
    } else {
        throw InvalidArgumentException("parameter count does not match");
    }
}
