#include "../header/Armor.h"

Armor::Armor(ArmorType type, vector<pair<string, int>> statValuePairs, string name, string description, int count)
    : Item(name, description, count), statValuePairs(statValuePairs) {
        this->type = type;
        this->statValuePairs = statValuePairs;
}