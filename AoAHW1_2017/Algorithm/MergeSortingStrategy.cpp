#include "MergeSortingStrategy.hpp"

using Homework::MergeSortingStrategy;

void
MergeSortingStrategy::sort(std::vector<Card> &cards, Key key) noexcept
{
    cache = cache.make_shared(std::vector<Card>(cards.size()));
    
    mergeRange(cards, key, 0, cards.size());
}

void
MergeSortingStrategy::mergeRange(std::vector<Card> &cards, Key key, UInt start, UInt end) noexcept
{
    if (end == start + 1) {
        return;
    }
    
    UInt length = end - start;
    UInt middle = length / 2;
    
    UInt left = start;
    UInt right = start + middle;
    
    mergeRange(cards, key, start, start + middle);
    mergeRange(cards, key, start + middle, end);
    
    for (UInt64 i = 0; i < length; ++i) {
        Boolean comparisonResult;
        
        switch (key) {
            case Key::Class:
                comparisonResult = cards[left].className > cards[right].className;
                
                break;
            case Key::Cost:
                comparisonResult = cards[left].cost > cards[right].cost;
                
                break;
            case Key::Name:
                comparisonResult = cards[left].name > cards[right].name;
                
                break;
            case Key::Type:
                comparisonResult = cards[left].type > cards[right].type;
                
                break;
        }
        
        if (left < start + middle && (right == end || comparisonResult)) {
            (*cache)[i] = cards[left++];
        } else {
            (*cache)[i] = cards[right++];
        }
    }
    
    for (UInt64 i = start; i < end; ++i) {
        cards[i] = (*cache)[i - start];
    }
}
