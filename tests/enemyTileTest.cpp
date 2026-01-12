#include "gtest/gtest.h"
#include "../header/Enemy.h"
#include "../header/CharacterStats.h"
#include "../header/floorTile.h"
#include <vector>
using namespace std;

class EnemyTileTestingUsingCharacterStats : public ::testing::Test {
protected:

    vector<int> growth;
    vector<Enemy*> enemies;
    CharacterStats stats;   
    /* ^Shared for all tests in this suite^ */ 

    void SetUp() override {
        for (int i = 0; i < 29; i++) {
            growth.push_back(1);
        }   
        
        stats.maxHealth = 1;
        stats.currHealth = 2;
        stats.vigor = 3;
        stats.physicalDef = 4;
        stats.magicalPower = 5;
        stats.magicalDef = 6;
        stats.immunity = 7;
        stats.agility = 8;
        stats.strength = 9;
        stats.stamina = 9;
        stats.pierceResistance = 10;
        stats.bluntResistance = 11;
        stats.slashResistance = 12;
        stats.fireAffinity = 13;
        stats.earthAffinity = 14;
        stats.waterAffinity = 15;
        stats.windAffinity = 16;
        stats.lightningAffinity = 17;
        stats.fireResistance = 18;
        stats.earthResistance = 19;
        stats.waterResistance = 20;
        stats.windResistance = 21;
        stats.lightningResistance = 22;
        stats.poisonResistance = 23;
        stats.sleepResistance = 24;
        stats.paralysisResistance = 25;
        stats.statResistance = 26;
        stats.dexterity = 27;
        stats.speed = 28;

        Enemy* e1 = new Enemy("Humanoid", 1, "Goblin", false, false);
        Enemy* e2 = new Enemy("Humanoid", 10, "Goblin", false, false, 3, growth, stats);
        enemies.push_back(e1);
        enemies.push_back(e2);
    }
};

using EnemyTileFunctionsTests = EnemyTileTestingUsingCharacterStats;

TEST_F(EnemyTileFunctionsTests, EnemiesVectorCount) {
    EnemyTile tile;
    tile.setTileEnemies(enemies);
    
    EXPECT_EQ(tile.getTileEnemies().size(), 2);
}

TEST_F(EnemyTileFunctionsTests, PrintEnemiesOnTile) {  
    cout << "\n--- Print info of enemies on the tile below ---\n";
    cout << "------------------------------------\n";
    
    EnemyTile tile;
    tile.setTileEnemies(enemies);
    vector<Enemy*> result = tile.getTileEnemies();
    
    for(int i = 0; i < result.size(); i++) {
        cout << "Enemy Family: " << result.at(i)->getFamily() << endl;
        cout << "Enemy EXP Drop: " << result.at(i)->getEXPDrop() << endl;
        cout << "Enemy Type: " << result.at(i)->getEnemyType() << endl;
        if(result.at(i)->getIsMiniBoss()) {
            cout << "Enemy is a mini boss" << endl;
        } else {
            cout << "Enemy is not a mini boss" << endl;
        }
        if(result.at(i)->getIsBoss()) {
            cout << "Enemy is a boss" << endl;
        } else {
            cout << "Enemy is not a boss" << endl;
        }
        cout << "Enemy Level: " << result.at(i)->getLevel() << endl;
    }

    cout << "------------------------------------\n";
}