#ifndef ARMOR_H
#define ARMOR_H
#include "../header/Item.hpp"
#include <vector>
#include <string>
#include <utility>
using namespace std;

class Armor : public Item {
public:
enum ArmorType { HELM, CHEST, LEGS, SHOES } type;
    vector<pair<string, int>> statValuePairs;
    Armor(ArmorType type, vector<pair<string, int>> statValuePairs, string name, string description, int count);
};

#endif // ARMOR_H