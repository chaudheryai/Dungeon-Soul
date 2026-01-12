#ifndef DUNGEON_H
#define DUNGEON_H
#include <string>
#include <vector>
#include "floorTile.h"
#include "floor.h"
#include "player.h"
using namespace std;

class Dungeon{
private:
    vector<Floor> floors;
    int currFloorIndex;
    int totalFloors;
public:
    Dungeon(int);
    void generateDungeon(int, int, Player&);
    Floor& getCurrentFloor();
    int getCurrentFloorIndex();
    void goToNextFloor();
    bool isLastFloor();
};

#endif