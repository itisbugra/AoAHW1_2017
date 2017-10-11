#pragma once

#include "PrefixHeader.pch"

#include <vector>

#include "SortingStrategy.hpp"

namespace Homework {
    class InsertionSortingStrategy : public SortingStrategy {
    public:
        void sort(std::vector<Card> &cards, Key key) noexcept override;
    };
}
