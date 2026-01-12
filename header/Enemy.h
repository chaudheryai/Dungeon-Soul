#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"
#include <string>
#include <vector>
using namespace std;

class Item; //forward declaration

class Enemy : public Character {  // Enemy keeps track of specific information important to enemies like family, drops, etc.
    public:
        Enemy();
        Enemy(std::string, int, std::string, bool, bool);  // uses basic Character()
        Enemy(std::string, int, std::string, bool, bool, int, std::vector<int>, CharacterStats);  // uses parameterized Character(int, vector<int>, CharacterStats)
        Enemy(std::string, int, std::string, bool, bool, int, std::vector<int>, CharacterStats, int, int);  // uses fully parameterized Character(int, vector<int>, CharacterStats, int, int)
        vector<Item*> getDeathLootItemList();
        void addToDeathLootItemList(Item*);
        void setMaterialDrop(Item* item);
        void randomizeMaterialDrop();
        Item* getMaterialDrop();
        void setEnemyState(bool, bool);  // is the enemy a miniBoss or boss
        bool getIsMiniBoss() const;
        bool getIsBoss() const;
        void setEnemyType(std::string);
        std::string getEnemyType() const;
        void setEXPDrop(int);
        int getEXPDrop() const;
        void setFamily(std::string);
        std::string getFamily() const;
        CharacterStats& getEnemyStats();
    private:
        std::string family;  // enemies of the same family wont attack eachother, but might attack other enemies from different families
        int EXPDrop;
        Item* materialDrop;  // item that will actually be dropped on death
        vector<Item*> deathLootItemList;  // list of items that can be dropped on death
        std::string enemyType;  // the specific enemy that is fought (goblin, orc, ogre, etc)
        bool isMiniBoss;
        bool isBoss; 
};

#endif