#include "CardMarshaller.hpp"

#include "FileParser.hpp"
#include "InvalidArgumentException.hpp"

using Homework::CardMarshaller;

auto
CardMarshaller::unmarshall(std::vector<std::string> parameters) const
-> Card
{
    if (parameters.size() == 6) {
        return Card(parameters[0],
                    parameters[1],
                    Card::rarityForString(parameters[2]),
                    parameters[3],
                    Card::typeForString(parameters[4]),
                    std::stoll(parameters[5]));
    } else {
        throw InvalidArgumentException("parameter count does not match");
    }
}
