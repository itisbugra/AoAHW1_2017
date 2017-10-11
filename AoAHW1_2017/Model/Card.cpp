#include "Card.hpp"

#include <algorithm>
#include <string>

#include "InvalidArgumentException.hpp"

using Homework::Card;

Card::Card(std::string name, std::string className, Rarity rarity, std::string set, Type type, UInt64 cost)
: name(name), className(className), rarity(rarity), set(set), type(type), cost(cost)
{
    //  Empty implementation
}

auto
Card::rarityForString(const std::string &rarityString)
-> Card::Rarity
{
    std::string copy(rarityString);
    std::transform(copy.begin(), copy.end(), copy.begin(), ::tolower);
    
    if (copy == "basic") {
        return Rarity::Basic;
    } else if (copy == "epic") {
        return Rarity::Epic;
    } else if (copy == "legendary") {
        return Rarity::Legendary;
    } else if (copy == "rare") {
        return Rarity::Rare;
    } else if (copy == "common") {
        return Rarity::Common;
    } else {
        throw InvalidArgumentException("unknown rarity");
    }
}

auto
Card::typeForString(const std::string &typeString)
-> Card::Type
{
    std::string copy(typeString);
    std::transform(copy.begin(), copy.end(), copy.begin(), ::tolower);
    
    if (copy == "spell") {
        return Type::Spell;
    } else if (copy == "minion") {
        return Type::Minion;
    } else if (copy == "hero") {
        return Type::Hero;
    } else if (copy == "weapon") {
        return Type::Weapon;
    } else {
        throw InvalidArgumentException("unknown type");
    }
}

auto
Card::stringForRarity(Homework::Card::Rarity rarity) noexcept
-> std::string
{
    switch (rarity) {
        case Card::Rarity::Basic:
            return "Basic";
        case Card::Rarity::Epic:
            return "Epic";
        case Card::Rarity::Legendary:
            return "Legendary";
        case Card::Rarity::Rare:
            return "Rare";
        case Card::Rarity::Common:
            return "Common";
    }
}

auto
Card::stringForType(Homework::Card::Type type) noexcept
-> std::string
{
    switch (type) {
        case Card::Type::Spell:
            return "Spell";
        case Card::Type::Minion:
            return "Minion";
        case Card::Type::Hero:
            return "Hero";
        case Card::Type::Weapon:
            return "Weapon";
    }
}
