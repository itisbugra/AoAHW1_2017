#pragma once

#include <vector>
#include <string>

#include "Card.hpp"

namespace Homework {
    class CardMarshaller {
    public:
        auto unmarshall(std::vector<std::string> parameters) const -> Card;
    };
}
