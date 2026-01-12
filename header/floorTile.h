#ifndef FLOORTILE_H
#define FLOORTILE_H

#include <string>
#include <vector>
#include "Enemy.h"
#include "Item.hpp"
#include "Armor.h"
#include "Weapon.h"
#include "Potion.h"
#include "Accessory.h"
using namespace std;

class FloorTile{
private:

public:
    bool Walkable = true;
    virtual ~FloorTile() {}
    virtual bool isWalkable() = 0;
    virtual char getSymbol() = 0;
    void changeWalkable();
};

class EmptyTile: public FloorTile{
public:
    bool isWalkable() override;
    char getSymbol() override;
};

class EnemyTile: public FloorTile{
private:
    vector<Enemy*> enemies;
public:
    ~EnemyTile() {
        for (auto e : enemies) {
                delete e;
            }
    }
    bool isWalkable() override;
    char getSymbol() override;
    void setTileEnemies(const vector<Enemy*>&);
    vector<Enemy*> getTileEnemies();
};

class TrapTile: public FloorTile{
private:
    int trapDamage = 0;
public:
    bool isWalkable() override;
    char getSymbol() override;
    void setTrapDamage(int);
    int getTrapDamage();
};

class TreasureTile: public FloorTile{
private:
    vector<Item*> treasure;
public:
    ~TreasureTile() {
        for (auto item : treasure) {
            delete item;
        }
    }
    bool isWalkable() override;
    char getSymbol() override;
    void setTreasure(const vector<Item*>&);
    vector<Item*>getTreasure();
};

class NPCTile: public FloorTile{
private:
    //NPC* tileNPC;
public:
    bool isWalkable() override;
    char getSymbol() override;
    //setTileNPC(NPC) 
    //getTileNPC(): NPC
};

class PortalTile: public FloorTile{
public:
    bool isWalkable() override;
    char getSymbol() override;
};

#endif