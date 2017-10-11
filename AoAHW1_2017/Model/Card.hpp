#pragma once

#include "PrefixHeader.pch"

#include <iostream>

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
        
        Card(std::string name = "", std::string className = "", Rarity rarity = Rarity::Basic, std::string set = "", Type type = Type::Spell, UInt64 cost = 0);
        
        static auto rarityForString(const std::string &rarityString) -> Rarity;
        static auto typeForString(const std::string &typeString) -> Type;
        static auto stringForRarity(Rarity rarity) noexcept -> std::string;
        static auto stringForType(Type type) noexcept -> std::string;
        
        friend std::ostream &operator << (std::ostream &stream, const Card &card) {
            stream << card.name << "\t";
            stream << card.className << "\t";
            stream << stringForRarity(card.rarity) << "\t";
            stream << card.set << "\t";
            stream << stringForType(card.type) << "\t";
            stream << card.cost;
            
            return stream;
        }
    };
}
