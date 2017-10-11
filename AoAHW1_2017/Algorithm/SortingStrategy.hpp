#pragma once

#include "Card.hpp"

namespace Homework {
    class SortingStrategy {
    public:
        enum class Key {
            Class,
            Cost,
            Name,
            Type
        };
        
        virtual ~SortingStrategy() noexcept = default;
        
        virtual void sort(std::vector<Card> &cards, Key key) noexcept = 0;
    };
}
