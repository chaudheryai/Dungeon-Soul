#include <string>
#include <vector>
#include <iostream>
#include "../header/floorTile.h"
#include "../header/Item.hpp"
using namespace std;

void FloorTile::changeWalkable(){
    Walkable = !Walkable;
}

bool EmptyTile::isWalkable(){
    return Walkable;
}

char EmptyTile::getSymbol(){
    if(isWalkable() == false) return '#';
    return 'O';
}

bool EnemyTile::isWalkable(){
    return Walkable;
}

char EnemyTile::getSymbol(){
    if(isWalkable() == false) return '#';
    return 'X';
}

void EnemyTile::setTileEnemies(const vector<Enemy*>& enemies){
    this->enemies = enemies;
}

vector<Enemy*> EnemyTile::getTileEnemies(){
    return enemies;
}

bool TrapTile::isWalkable(){
    return Walkable;
}

char TrapTile::getSymbol(){
    if(isWalkable() == false) return '#';
    return 'T';
}

void TrapTile::setTrapDamage(int damage){
    trapDamage = damage;
}

int TrapTile::getTrapDamage(){
    return trapDamage;
}

bool TreasureTile::isWalkable(){
    return Walkable;
}

char TreasureTile::getSymbol(){
    if(isWalkable() == false) return '#';
    return 'M';
}

void TreasureTile::setTreasure(const vector<Item*>& treasure){
    this->treasure = treasure;
}

vector<Item*> TreasureTile::getTreasure(){
    return treasure;
}

bool NPCTile::isWalkable(){
    return Walkable;
}

char NPCTile::getSymbol(){
    if(isWalkable() == false) return '#';
    return 'N';
}

bool PortalTile::isWalkable(){
    return true;
}

char PortalTile::getSymbol(){
    return 'B';
}
