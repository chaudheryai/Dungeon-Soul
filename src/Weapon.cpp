#include "../header/Weapon.h"
#include "../header/Enemy.h"
#include "../header/CharacterStats.h"
#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;

Weapon::Weapon(vector<pair<string, int>> attackStatValuePairs, string name, string description, int count)
    : Item(name, description, count), attackStatValuePairs(attackStatValuePairs) {
        this->attackStatValuePairs = attackStatValuePairs;
}

void Weapon::applyAttack(Enemy* enemy) {
    string enemyType = enemy->getEnemyType();
    cout <<'\n' << enemyType << " is attacked with " << this->getName() << "!\n";
    CharacterStats& enemyStats = enemy->getEnemyStats();
    
    for (const auto& attackStatValuePair : attackStatValuePairs) {
        const string& statName = attackStatValuePair.first;
        int statValue = attackStatValuePair.second;
        auto it = CharacterStats::statLookup.find(statName);
        if (it != CharacterStats::statLookup.end()) {
            enemyStats.*(it->second) += statValue;
            cout <<"The " << enemyType << "'s " << statName << " changed by " << statValue << ". New value: " << enemyStats.*(it->second) << "\n";
        } else {
            cout << "Unknown stat: " << statName << "\n";
        }
    }
}