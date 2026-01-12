#ifndef WEAPON_H
#define WEAPON_H

#include "Item.hpp"
#include "Enemy.h"
#include <string>
#include <vector>
#include <utility>
using namespace std;

class Weapon : public Item {
public:
    vector<pair<string, int>> attackStatValuePairs;
    Weapon(vector<pair<string, int>> attackStatValuePairs, string name, string description, int count);
    void applyAttack(Enemy* enemy);
};

#endif // WEAPON_H