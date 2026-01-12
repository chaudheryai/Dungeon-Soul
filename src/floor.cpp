#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include <iostream>
#include "../header/floorTile.h"
#include "../header/floor.h"
#include "../header/player.h"
using namespace std;

Floor::Floor(int row, int column, Player& player, int PortalPlace){
    srand(static_cast<unsigned int>(time(nullptr) + PortalPlace));
    this->height = row;
    this->width = column;
    grid.resize(height, std::vector<FloorTile*>(width,nullptr));
    generateLevel();
    placePlayerStart(player);
    placePortal(PortalPlace);
}



Floor::~Floor(){
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            delete grid.at(i).at(j);
        }
    }
}

void Floor::generateLevel(){
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            randomizeTileContent(i, j);
        }
    }
    
}

FloorTile* Floor::getTileAt(int row, int column){
    return grid.at(row).at(column);
}

void Floor::setTileEmpty(int column, int  row){
    delete grid.at(row).at(column);
    EmptyTile* tile = new EmptyTile;
    grid.at(row).at(column) = tile;
}


void Floor::randomizeTileContent(int row, int column){
    int random_number = rand() % 5 + 1;
    int trapDamage = rand() % 3 + 1;
    if(random_number == 1){
        EnemyTile* tile = new EnemyTile;
        grid.at(row).at(column) = tile;
    }else if(random_number == 2){
        TrapTile* tile = new TrapTile;
        tile->setTrapDamage(trapDamage);
        grid[row][column] = tile;
    }else if(random_number == 3){
        TreasureTile* tile = new TreasureTile;
        vector<Item*> treasure;
        if(rand() % 2 == 0){
            Potion* potion = new Potion(rand() % 50 + 25, rand() % 3 + 1);
            treasure.push_back(potion);
        }
        if(rand() % 8 == 0){
            Armor* chest = new Armor(
                Armor::ArmorType::CHEST, 
                {{"maxHealth", rand() % 50 + 10}}, 
                "Health Helmet", 
                "Increases max health by "  + to_string(rand() % 50 + 10 ) + ".",
                1
            );
            treasure.push_back(chest);
        }
        if(rand() % 8 == 1){
            Armor* legs = new Armor(
                Armor::ArmorType::LEGS, 
                {{"maxHealth", rand() % 30 + 5}}, 
                "Health Helmet", 
                "Increases max health by " + to_string(rand() % 30 + 5 ) + ".",
                1
            );
            treasure.push_back(legs);
        }
        if(rand() % 8 == 2){
            Armor* shoes = new Armor(
                Armor::ArmorType::SHOES, 
                {{"maxHealth", rand() % 10 + 1}}, 
                "Health Helmet", 
                "Increases max health by " + to_string(rand() % 10 + 1 ) + ".",
                1
            );
            treasure.push_back(shoes);
        }
        if(rand() % 8 == 3){
            Armor* helm = new Armor(
                Armor::ArmorType::HELM, 
                {{"maxHealth", rand() % 25 + 5}}, 
                "Health Helmet", 
                "Increases max health by " + to_string(rand() % 25 + 5 ) + ".",
                1
            );
            treasure.push_back(helm);
        }
        if(rand() % 8 == 4){
            Weapon* sword = new Weapon(
                {{"currHealth", -20}}, 
                "Basic Sword", 
                "Regular damage: 20",
                1
            );
            treasure.push_back(sword);
        }
        if(rand() % 8 == 5){
            Weapon* staff = new Weapon(
                {{"currHealth", -20}}, 
                "Basic Sword", 
                "Regular damage: 20",
                1
            );
            treasure.push_back(staff);
        }
        if(rand() % 8 == 6){
            Weapon* hammer = new Weapon(
                {{"currHealth", -20}}, 
                "Basic Sword", 
                "Regular damage: 20",
                1
            );
            treasure.push_back(hammer);
        }
        if(rand() % 8 == 7){
            Weapon* dagger = new Weapon(
                {{"currHealth", -20}}, 
                "Basic Sword", 
                "Regular damage: 20",
                1
            );
            treasure.push_back(dagger);
        }
        tile->setTreasure(treasure);
        grid.at(row).at(column) = tile;
    }else if(random_number == 4){
        EmptyTile* tile = new EmptyTile;
        grid.at(row).at(column) = tile;
    }else if(random_number == 5){
        NPCTile* tile = new NPCTile;
        grid.at(row).at(column) = tile;
    }
}

void Floor::placePlayerStart(Player& player){ // seting to 0,0 for now, will update with maps
    player.setPosition(0,0);
}

void Floor::placePortal(int PortalPlace){ // place at a undetermined place, using 0,1 for now
    delete grid.at(0).at(PortalPlace);
    PortalTile* tile = new PortalTile;
    grid.at(0).at(PortalPlace) = tile;
}

bool Floor::isValidTile(int row, int col){
    if(row < 0 || row >= height) return false;
    if(col < 0 || col >= width)  return false;
    return grid.at(row).at(col)->isWalkable();
}

int Floor::getWidth(){
    return width;
}

int Floor::getHeight(){
    return height;
}