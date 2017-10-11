#include "InsertionSortingStrategy.hpp"

using Homework::InsertionSortingStrategy;

void
InsertionSortingStrategy::sort(std::vector<Card> &cards, Key key) noexcept
{
    for (Int i = 0; i < cards.size(); ++i) {
        Card cursor = cards[i];
        
        Int reverseIndex = i - 1;
        
        while (reverseIndex >= 0) {
            Boolean comparisonResult;
            
            switch (key) {
                case Key::Class:
                    comparisonResult = cards[reverseIndex].className > cursor.className;
                    
                    break;
                case Key::Cost:
                    comparisonResult = cards[reverseIndex].cost > cursor.cost;
                    
                    break;
                case Key::Name:
                    comparisonResult = cards[reverseIndex].name > cursor.name;
                    
                    break;
                case Key::Type:
                    comparisonResult = cards[reverseIndex].type > cursor.type;
                    
                    break;
            }
            
            if (!comparisonResult) {
                break;
            }
            
            cards[reverseIndex + 1] = cards[reverseIndex];
            
            reverseIndex -= 1;
        }
        
        cards[reverseIndex + 1] = cursor;
    }
}
