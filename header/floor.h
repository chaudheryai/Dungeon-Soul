#ifndef FLOOR_H
#define FLOOR_H
#include <string>
#include <vector>
#include "floorTile.h"
#include "player.h"
using namespace std;

class Floor{
private:
    int width;
    int height;
    vector<vector<FloorTile*>> grid;
public:
    Floor(int, int, Player&,int);
    ~Floor();
    void generateLevel();
    FloorTile* getTileAt(int, int);
    void randomizeTileContent(int, int);
    void placePlayerStart(Player&);
    void placePortal(int);
    bool isValidTile(int, int);
    int getWidth();
    int getHeight();
    void setTileEmpty(int row, int column);

};

#endif