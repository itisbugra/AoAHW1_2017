#pragma once

#include "PrefixHeader.pch"

#include <vector>
#include <memory>
#include <iostream>

#include "SortingStrategy.hpp"

namespace Homework {
    class MergeSortingStrategy : public SortingStrategy {
    public:
        void sort(std::vector<Card> &cards, Key key) noexcept override;
        
    private:
        std::shared_ptr<std::vector<Card>> cache;
        
        void mergeRange(std::vector<Card> &cards, Key key, UInt start, UInt end) noexcept;
    };
}
