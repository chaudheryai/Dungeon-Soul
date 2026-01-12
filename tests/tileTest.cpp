#include "gtest/gtest.h"
#include "../header/dungeon.h"
using namespace std;

TEST(TileTests,createEmptyTile){
    EmptyTile emptyTest;
    EXPECT_TRUE(emptyTest.isWalkable());
    EXPECT_EQ(emptyTest.getSymbol(),'O');
}
TEST(TileTests,createEnemyTile){
    EnemyTile enemyTest;
    EXPECT_TRUE(enemyTest.isWalkable());
    EXPECT_EQ(enemyTest.getSymbol(),'X');
}
TEST(TileTests,createTrapTile){
    TrapTile trapTest;
    trapTest.setTrapDamage(10);
    EXPECT_TRUE(trapTest.isWalkable());
    EXPECT_EQ(trapTest.getSymbol(),'T');
    EXPECT_EQ(trapTest.getTrapDamage(), 10);
}
TEST(TileTests,createTreasureTile){ 
    TreasureTile treasureTest;
    EXPECT_TRUE(treasureTest.isWalkable());
    EXPECT_EQ(treasureTest.getSymbol(),'M');
}

TEST(TileTests,giveTreasure){
    TreasureTile treasureTest;
    vector<Item*> treasure;
    Armor* helm = new Armor(
        Armor::ArmorType::HELM, 
        {{"maxHealth", 20}}, 
        "Health Helmet", 
        "Increases max health by 20.", 1
    );
    treasure.push_back(helm);
    treasureTest.setTreasure(treasure);
    EXPECT_EQ(treasureTest.getTreasure(), treasure);
}

TEST(TileTests,createNPCTile){ // add more later
    NPCTile NPCTest;
    EXPECT_TRUE(NPCTest.isWalkable());
    EXPECT_EQ(NPCTest.getSymbol(),'N');
}
TEST(TileTests,createPortalTile){
    PortalTile portalTest;
    EXPECT_TRUE(portalTest.isWalkable());
    EXPECT_EQ(portalTest.getSymbol(),'B');
}
TEST(TileTests,unWalkableTile){
    EmptyTile emptyWalkTest;
    EnemyTile enemyWalkTest;
    TrapTile trapWalkTest;
    TreasureTile treasureWalkTest;
    NPCTile NPCWalkTest;
    PortalTile portalWalkTest;
    emptyWalkTest.changeWalkable();
    enemyWalkTest.changeWalkable();
    trapWalkTest.changeWalkable();
    treasureWalkTest.changeWalkable();
    NPCWalkTest.changeWalkable();
    portalWalkTest.changeWalkable();
    EXPECT_FALSE(emptyWalkTest.isWalkable());
    EXPECT_FALSE(enemyWalkTest.isWalkable());
    EXPECT_FALSE(trapWalkTest.isWalkable());
    EXPECT_FALSE(treasureWalkTest.isWalkable());
    EXPECT_FALSE(NPCWalkTest.isWalkable());
    EXPECT_TRUE(portalWalkTest.isWalkable());
    EXPECT_EQ(emptyWalkTest.getSymbol(),'#');
    EXPECT_EQ(enemyWalkTest.getSymbol(),'#');
    EXPECT_EQ(trapWalkTest.getSymbol(),'#');
    EXPECT_EQ(treasureWalkTest.getSymbol(),'#');
    EXPECT_EQ(NPCWalkTest.getSymbol(),'#');
    EXPECT_EQ(portalWalkTest.getSymbol(),'B');

}