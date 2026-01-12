#include "../header/Enemy.h"
#include "../header/Item.hpp"

using namespace std;

Enemy::Enemy(): family(""), EXPDrop(0), enemyType(""), isMiniBoss(false), isBoss(false) {
    materialDrop = nullptr;
}
Enemy::Enemy(string family, int EXPDrop, string enemyType, bool isMiniBoss, bool isBoss):
family(family), EXPDrop(EXPDrop), enemyType(enemyType), isMiniBoss(isMiniBoss), isBoss(isBoss) {
    materialDrop = nullptr;
}
Enemy::Enemy(string family, int EXPDrop, string enemyType, bool isMiniBoss, bool isBoss, int level, vector<int> growthRate, CharacterStats stats):
family(family), EXPDrop(EXPDrop), enemyType(enemyType), isMiniBoss(isMiniBoss), isBoss(isBoss), Character(level, growthRate, stats) {
    materialDrop = nullptr;
}
Enemy::Enemy(string family, int EXPDrop, string enemyType, bool isMiniBoss, bool isBoss, int level, vector<int> growthRate, CharacterStats stats, int x, int y):
family(family), EXPDrop(EXPDrop), enemyType(enemyType), isMiniBoss(isMiniBoss), isBoss(isBoss), Character(level, growthRate, stats, x, y) {
    materialDrop = nullptr;
}

void Enemy::setEnemyState(bool miniBoss, bool boss) {
    if (miniBoss && boss) {  // can't be a mini boss and a boss at the same time
        throw invalid_argument("Enemy cannot be both miniBoss and boss");
    }
    isMiniBoss = miniBoss;
    isBoss = boss;
}
void Enemy::setEnemyType(string enemyType) {
    this->enemyType = enemyType;
}
void Enemy::setEXPDrop(int EXPDrop) {
    this->EXPDrop = EXPDrop;
}
void Enemy::setFamily(string family) {
    this->family = family;
}

bool Enemy::getIsBoss() const {
    return isBoss;
}
bool Enemy::getIsMiniBoss() const {
    return isMiniBoss;
}
string Enemy::getEnemyType() const {
    return enemyType;
}
int Enemy::getEXPDrop() const {
    return EXPDrop;
}
string Enemy::getFamily() const {
    return family;
}

vector<Item*> Enemy::getDeathLootItemList() {
    return deathLootItemList;
}
void Enemy::addToDeathLootItemList(Item* addedItem) {
    deathLootItemList.push_back(addedItem);
}

void Enemy::setMaterialDrop(Item* item) {
    bool inItemList = false;
    for(int i = 0; i < deathLootItemList.size(); i++) {
        if(deathLootItemList.at(i) == item) {
            inItemList = true;
        }
    }
    if(!inItemList) {
        addToDeathLootItemList(item);
    }
    materialDrop = item;
}
void Enemy::randomizeMaterialDrop() {
    if(deathLootItemList.size() == 0) {
        throw runtime_error("Taking from empty loot table");
    }
    srand(time(nullptr));
    int randomIndex = rand() % deathLootItemList.size();
    materialDrop = deathLootItemList.at(randomIndex);
}

Item* Enemy::getMaterialDrop() {
    return materialDrop;
}
CharacterStats& Enemy::getEnemyStats() {
    return stats;
}