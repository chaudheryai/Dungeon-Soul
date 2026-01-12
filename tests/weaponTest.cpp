#include "gtest/gtest.h"
#include "../header/Weapon.h"
#include "../header/Enemy.h"
#include "../header/player.h"
#include "../header/Inventory.hpp"
using namespace std;


//Constructor
TEST(WeaponConstructorTests, VectorSize) {

    Weapon sword({{"currHealth", -20}}, "Basic Sword", "Regular damage: 20", 1);
    
    EXPECT_EQ(sword.attackStatValuePairs.size(), 1);
}

TEST(WeaponConstructorTests, StatName) {
    Weapon sword({{"currHealth", -20}}, "Basic Sword", "Regular damage: 20", 1);

    EXPECT_EQ(sword.attackStatValuePairs[0].first, "currHealth");
}


TEST(WeaponConstructorTests, StatValue) {
    Weapon sword({{"currHealth", -20}}, "Basic Sword", "Regular damage: 20", 1);

    EXPECT_EQ(sword.attackStatValuePairs[0].second, -20);
}

TEST(WeaponUseTests, WeaponModifiesSingleStatOfEnemy) {
    Enemy enemy;
    enemy.setEnemyType("Goblin");
    enemy.getEnemyStats().setCurrHealth(50);
    
    Weapon sword({{"currHealth", -20}}, "Basic Sword", "Regular damage: 20", 1);
    sword.applyAttack(&enemy);

    EXPECT_EQ(enemy.getEnemyStats().getCurrHealth(), 30);
}

TEST(WeaponUseTests, WeaponModifiesMultipleStatsOfEnemy) {
    Enemy enemy;
    enemy.setEnemyType("Orc");
    enemy.getEnemyStats().setCurrHealth(40);
    enemy.getEnemyStats().setPhysicalDef(8);

    Weapon betterSword({{"currHealth", -30}, {"physicalDef", -4}}, "Better Sword", "Deals 30 damage and decreases physical defense by 4.", 1);
    betterSword.applyAttack(&enemy);

    EXPECT_TRUE(enemy.getEnemyStats().getCurrHealth() == 10 && 
        enemy.getEnemyStats().getPhysicalDef() == 4);
}

TEST(WeaponUseTests, WeaponWorksForPlayer) {
    Weapon betterSword({{"currHealth", -30}, {"physicalDef", -4}}, "Better Sword", "Deals 30 damage and decreases physical defense by 4.", 1);

    
    Inventory inv(1);
    inv.setWeapon(&betterSword);

    Player player;
    player.setInventory(inv);
    
    Enemy enemy;
    enemy.setEnemyType("Orc");
    enemy.getEnemyStats().setCurrHealth(40);
    enemy.getEnemyStats().setPhysicalDef(8);

    player.attackEnemy(&enemy);

    EXPECT_TRUE(enemy.getEnemyStats().getCurrHealth() == 10 && 
        enemy.getEnemyStats().getPhysicalDef() == 4);
}


TEST(WeaponPrintTests, ManualPrintCheckForConstruction) {
    cout << "\n--- Manual Weapon Output Below ---\n";
    cout << "------------------------------------\n";
    
    Weapon sword({{"currHealth", -20}}, "Basic Sword", "Regular damage: 20", 1);
    cout << sword.attackStatValuePairs[0].first << ": " << sword.attackStatValuePairs[0].second << "\n";
    cout << "------------------------------------\n";
}

TEST(WeaponPrintTests, ManualPrintCheckForPlayerEquip) {
    cout << "\n--- Manual Weapon Player Equip Output Below ---\n";
    cout << "------------------------------------\n";
    
    Weapon sword({{"currHealth", -20}}, "Basic Sword", "Regular damage: 20", 1);
    Player player;
    player.getInventory().setItemsSize(1);
    player.getInventory().addItem(&sword);
    player.equipWeapon(&sword);

    cout << "------------------------------------\n";
}

TEST(WeaponPrintTests, ManualPrintCheckForUse) {
    cout << "\n--- Manual Weapon Use Output Below ---\n";
    cout << "------------------------------------\n";
    
    Weapon sword({{"currHealth", -20}}, "Basic Sword", "Regular damage: 20", 1);
    Enemy enemy;
    enemy.setEnemyType("Goblin");
    enemy.getEnemyStats().setCurrHealth(50);
    sword.applyAttack(&enemy);

    cout << "------------------------------------\n";
}

TEST(WeaponPrintTests, ManualPrintCheckForPlayerUse) {
    cout << "\n--- Manual Weapon Player Use Output Below ---\n";
    cout << "------------------------------------\n";
    
    Weapon sword({{"currHealth", -20}}, "Basic Sword", "Regular damage: 20", 1);
    
    Inventory inv(1);
    inv.setWeapon(&sword);

    Player player;
    player.setInventory(inv);
    
    Enemy enemy;
    enemy.setEnemyType("Goblin");
    enemy.getEnemyStats().setCurrHealth(25);

    player.attackEnemy(&enemy);

    cout << "------------------------------------\n";
}