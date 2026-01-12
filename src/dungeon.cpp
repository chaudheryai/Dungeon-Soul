#include <string>
#include <vector>
#include <iostream>
#include "../header/floorTile.h"
#include "../header/floor.h"
#include "../header/dungeon.h"
#include "../header/player.h"
using namespace std;

Dungeon::Dungeon(int totalFloors){
    this->totalFloors = totalFloors;
    this->currFloorIndex = 0;
    floors.reserve(totalFloors + 1);
}

void Dungeon::generateDungeon(int width, int height, Player& player){
    for(int i = 0; i < totalFloors; i++){
        floors.emplace_back(height, width, player, i+1);
    }
}

Floor& Dungeon::getCurrentFloor(){
    return floors.at(currFloorIndex);
}

int Dungeon::getCurrentFloorIndex(){
    return currFloorIndex;
}

void Dungeon::goToNextFloor(){
    if(isLastFloor()) return;
    currFloorIndex++;
}

bool Dungeon::isLastFloor(){
    if(currFloorIndex == totalFloors - 1) return true;
    return false;
}