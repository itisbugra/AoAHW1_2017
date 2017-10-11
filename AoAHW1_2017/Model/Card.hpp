#pragma once

#include "PrefixHeader.pch"

namespace Homework {
    struct Card {
        enum class Rarity : UInt8 {
            Basic = 0,
            Epic,
            Legendary,
            Rare,
            Common
        };
        
        enum class Type : UInt8 {
            Spell = 0,
            Minion,
            Hero,
            Weapon
        };
        
        std::string name;
        std::string className;
        Rarity rarity;
        std::string set;
        Type type;
        UInt64 cost;
    };
}
