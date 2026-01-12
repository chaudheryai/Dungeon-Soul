#include "gtest/gtest.h"
#include "../header/Enemy.h"
#include "../header/CharacterStats.h"
using namespace std;

class EnemyTestingUsingCharacterStats : public ::testing::Test {
protected:

    CharacterStats stats;   // <--- Shared for all tests in this suite

    void SetUp() override {
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
    }
};

using EnemyGetTests = EnemyTestingUsingCharacterStats;

TEST(EnemyConstructorTests, DefaultConstructorEnemyPosition) {
    Enemy a;
    
    EXPECT_TRUE(a.getX() == 0 && a.getY() == 0);
}

TEST(EnemyConstructorTests, DefaultConstructorCharacterAlive) {
    Enemy a;

    EXPECT_TRUE(a.getIsAlive());
}

TEST(EnemyConstructorTests, DefaultConstructorCharacterLevel1) {
    Enemy a;

    EXPECT_EQ(a.getLevel(), 1);
}

TEST_F(EnemyGetTests, GetFamily) {
    vector<int> growth(29,1);
    Enemy goblin("humanoid", 10, "goblin", false, false, 1, growth, stats);

    EXPECT_EQ(goblin.getFamily(), "humanoid");
}

TEST_F(EnemyGetTests, GetEnemyType) {
    vector<int> growth(29,1);
    Enemy goblin("humanoid", 10, "goblin", false, false, 1, growth, stats);

    EXPECT_EQ(goblin.getEnemyType(), "goblin");
}

TEST_F(EnemyGetTests, GetEXPDrop) {
    vector<int> growth(29,1);
    Enemy goblin("humanoid", 10, "goblin", false, false, 1, growth, stats);

    EXPECT_EQ(goblin.getEXPDrop(), 10);
}
\
TEST_F(EnemyGetTests, GetIsBossFalse) {
    vector<int> growth(29,1);
    Enemy goblin("humanoid", 10, "goblin", false, false, 1, growth, stats);

    EXPECT_FALSE(goblin.getIsBoss());
}