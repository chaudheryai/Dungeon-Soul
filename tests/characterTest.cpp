#include "gtest/gtest.h"
#include "../header/Character.h"
#include "../header/CharacterStats.h"
using namespace std;

class CharacterTestsUsingCharacterStats : public ::testing::Test {
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

using CharacterLevelingTests = CharacterTestsUsingCharacterStats;

TEST(CharacterConstructorTests, DefaultConstructorCharacterPosition) {
    Character a;

    EXPECT_TRUE(a.getX() == 0 && a.getY() == 0);
}

TEST(CharacterConstructorTests, DefaultConstructorCharacterAlive) {
    Character a;

    EXPECT_TRUE(a.getIsAlive());
}

TEST(CharacterConstructorTests, DefaultConstructorCharacterLevel1) {
    Character a;

    EXPECT_EQ(a.getLevel(), 1);
}

TEST_F(CharacterLevelingTests, SetLevel) {
    vector<int> growth(29,1);
    Character a(1, growth, stats);

    a.setLevel(4);
    
    EXPECT_EQ(a.getLevel(), 4);
}

TEST_F(CharacterLevelingTests, LevelUpMaxHealthChangesCorrectly) {
    vector<int> growth(29,1);
    Character a(1, growth, stats);

    int oldMaxHealth = a.getStats().getMaxHealth();
    a.setLevel(3);
    a.adjustStatsForLevel();
    
    EXPECT_EQ(oldMaxHealth, a.getStats().getMaxHealth() - 2);
}