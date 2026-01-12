#include "gtest/gtest.h"
#include "../header/CombatSystem.h"
#include "../header/Potion.h"

using namespace std;

class CombatSystemTest : public ::testing::Test {
    protected:
        CharacterStats makeGoblinBaseStats() {
            CharacterStats goblinBaseStats;
            // main stats
            goblinBaseStats.setMaxHealth(3);
            goblinBaseStats.setCurrHealth(3);
            goblinBaseStats.setVigor(4);
            goblinBaseStats.setPhysicalDef(4);
            goblinBaseStats.setMagicalPower(2);
            goblinBaseStats.setMagicalDef(3);
            goblinBaseStats.setImmunity(2);
            goblinBaseStats.setAgility(7);
            // makes up vigor
            goblinBaseStats.setStrength(2);
            goblinBaseStats.setStamina(6);
            // makes up physDef
            goblinBaseStats.setPierceResistance(4);
            goblinBaseStats.setBluntResistance(5);
            goblinBaseStats.setSlashResistance(3);
            // makes up magPow
            goblinBaseStats.setFireAffinity(0);
            goblinBaseStats.setEarthAffinity(4);
            goblinBaseStats.setWaterAffinity(2);
            goblinBaseStats.setWindAffinity(4);
            goblinBaseStats.setLightningAffinity(0);
            // makes up magDef
            goblinBaseStats.setFireResistance(2);
            goblinBaseStats.setEarthResistance(5);
            goblinBaseStats.setWaterResistance(3);
            goblinBaseStats.setWindResistance(3);
            goblinBaseStats.setLightningResistance(2);
            // makes up immunity
            goblinBaseStats.setPoisonResistance(4);
            goblinBaseStats.setParalysisResistance(4);
            goblinBaseStats.setSleepResistance(0);
            goblinBaseStats.setStatResistance(0);
            // makes up agility
            goblinBaseStats.setDexterity(6);
            goblinBaseStats.setSpeed(8);

            return goblinBaseStats;
        }
        CharacterStats makeZombieBaseStats() {
            CharacterStats zombiBaseStats;
            // main stats
            zombiBaseStats.setMaxHealth(10);
            zombiBaseStats.setCurrHealth(10);
            zombiBaseStats.setVigor(4);
            zombiBaseStats.setPhysicalDef(4);
            zombiBaseStats.setMagicalPower(2);
            zombiBaseStats.setMagicalDef(3);
            zombiBaseStats.setImmunity(2);
            zombiBaseStats.setAgility(7);
            // makes up vigor
            zombiBaseStats.setStrength(2);
            zombiBaseStats.setStamina(6);
            // makes up physDef
            zombiBaseStats.setPierceResistance(4);
            zombiBaseStats.setBluntResistance(5);
            zombiBaseStats.setSlashResistance(3);
            // makes up magPow
            zombiBaseStats.setFireAffinity(0);
            zombiBaseStats.setEarthAffinity(4);
            zombiBaseStats.setWaterAffinity(2);
            zombiBaseStats.setWindAffinity(4);
            zombiBaseStats.setLightningAffinity(0);
            // makes up magDef
            zombiBaseStats.setFireResistance(2);
            zombiBaseStats.setEarthResistance(5);
            zombiBaseStats.setWaterResistance(3);
            zombiBaseStats.setWindResistance(3);
            zombiBaseStats.setLightningResistance(2);
            // makes up immunity
            zombiBaseStats.setPoisonResistance(4);
            zombiBaseStats.setParalysisResistance(4);
            zombiBaseStats.setSleepResistance(0);
            zombiBaseStats.setStatResistance(0);
            // makes up agility
            zombiBaseStats.setDexterity(6);
            zombiBaseStats.setSpeed(1);

            return zombiBaseStats;
        }
        CharacterStats makePlayerBaseStats() {
            CharacterStats playerBaseStats;
            // main stats
            playerBaseStats.setMaxHealth(3);
            playerBaseStats.setCurrHealth(3);
            playerBaseStats.setVigor(4);
            playerBaseStats.setPhysicalDef(4);
            playerBaseStats.setMagicalPower(2);
            playerBaseStats.setMagicalDef(3);
            playerBaseStats.setImmunity(2);
            playerBaseStats.setAgility(7);
            // makes up vigor
            playerBaseStats.setStrength(2);
            playerBaseStats.setStamina(6);
            // makes up physDef
            playerBaseStats.setPierceResistance(4);
            playerBaseStats.setBluntResistance(5);
            playerBaseStats.setSlashResistance(3);
            // makes up magPow
            playerBaseStats.setFireAffinity(0);
            playerBaseStats.setEarthAffinity(4);
            playerBaseStats.setWaterAffinity(2);
            playerBaseStats.setWindAffinity(4);
            playerBaseStats.setLightningAffinity(0);
            // makes up magDef
            playerBaseStats.setFireResistance(2);
            playerBaseStats.setEarthResistance(5);
            playerBaseStats.setWaterResistance(3);
            playerBaseStats.setWindResistance(3);
            playerBaseStats.setLightningResistance(2);
            // makes up immunity
            playerBaseStats.setPoisonResistance(4);
            playerBaseStats.setParalysisResistance(4);
            playerBaseStats.setSleepResistance(0);
            playerBaseStats.setStatResistance(0);
            // makes up agility
            playerBaseStats.setDexterity(6);
            playerBaseStats.setSpeed(7);

            return playerBaseStats;
        }
        
        void SetUp() override {
            // make encounter enemies
            CharacterStats goblinStats = makeGoblinBaseStats();
            CharacterStats zombieStats = makeZombieBaseStats();
            vector<int> goblinGrowthRate(29, 1);
            vector<int> zombieGrowthRate(29, 1);
            e1 = new Enemy("Humanoid", 1, "Goblin", false, false, 3, goblinGrowthRate, goblinStats);
            e2 = new Enemy("Humanoid", 10, "Goblin", false, false, 3, goblinGrowthRate, goblinStats);
            e3 = new Enemy("Undead", 10, "Zombie", false, false, 2, zombieGrowthRate, zombieStats);
            vector<Enemy*> encounter;
            encounter.push_back(e1);
            encounter.push_back(e2);
            encounter.push_back(e3);
            // make player
            CharacterStats playerStats = makePlayerBaseStats();
            vector<int> playerGrowthRate(29, 1);
            Inventory playerInventory(1);
            healthPotion = new Potion(10, 2);
            playerInventory.addItem(healthPotion);
            tester = new Player(0, 0, 1, 0, "Swordsman", "Swift Sword", playerGrowthRate, "Adam", 0, playerInventory, 0, playerStats);
            simulation = new CombatSystem(encounter, tester);
        }
        void TearDown() override {
            // Clean up memory
            delete simulation;
            delete e1;
            delete e2;
            delete e3;
            delete healthPotion;
            delete tester;
        }
        CombatSystem* simulation = nullptr;
        Enemy* e1 = nullptr;
        Enemy* e2 = nullptr;
        Enemy* e3 = nullptr;
        Item* healthPotion = nullptr;
        Player* tester = nullptr;
};

TEST_F(CombatSystemTest, TurnOrderIsCorrectlySortedBySpeed) {
    std::vector<int> result = simulation->determineTurnOrder();
    // The speeds are: e1 (8), e2 (8), Player (7), e3 (1)
    // The IDs are: e1 (0), e2 (1), Player (-1), e3 (2)
    ASSERT_EQ(4, result.size()) << "Turn order vector size mismatch (Expected 4).";
    EXPECT_TRUE((result[0] == 0 && result[1] == 1) || (result[0] == 1 && result[1] == 0)) 
    << "The two fastest entities (IDs 0 and 1) were not in the first two slots.";

    EXPECT_EQ(-1, result[2]) << "The third slot should be the Player (ID -1).";
    EXPECT_EQ(2, result[3]) << "The fourth slot should be the slowest Enemy (ID 2).";
}
TEST_F(CombatSystemTest, AllEnemiesDefeatedIsCorrect) {
    EXPECT_FALSE(simulation->allEnemiesDefeated()) << "Combat should be active initially.";
    e1->getEnemyStats().currHealth = 0;
    e2->getEnemyStats().currHealth = 0;
    e3->getEnemyStats().currHealth = 0;
    EXPECT_TRUE(simulation->allEnemiesDefeated()) << "Combat should be resolved when all enemies are dead.";
}
TEST_F(CombatSystemTest, CombatValidIsCorrectWithPlayers) {
    // Combat should start off valid
    EXPECT_TRUE(simulation->combatValid()) << "Combat should start off valid";
    tester->getPlayerStats().currHealth = 0;
    EXPECT_FALSE(simulation->combatValid()) << "If the player dies combat is no longer valid";
}
TEST_F(CombatSystemTest, CombatValidIsCorrectWithEnemies) {
    // Combat should start off valid
    EXPECT_TRUE(simulation->combatValid()) << "Combat should start off valid";
    e1->getEnemyStats().currHealth = 0;
    e2->getEnemyStats().currHealth = 0;
    EXPECT_TRUE(simulation->combatValid()) << "Combat should still be valid if there is still a living enemy";
    e3->getEnemyStats().currHealth = 0;
    EXPECT_FALSE(simulation->combatValid()) << "If all enemies die combat is no longer valid";
}