#include "gtest/gtest.h"
#include "../header/Accessory.h"
#include "../header/CharacterStats.h"
#include "../header/player.h"
using namespace std;

//Constructor
TEST(AccessoryConstructorTests, VectorSize) {

    Accessory acc({{"maxHealth", 20}}, "Health Stone", "Increases max health by 20.", 1);

    EXPECT_EQ(acc.statValuePairs.size(), 1);
}

TEST(AccessoryConstructorTests, StatName) {
    Accessory acc({{"maxHealth", 20}}, "Health Stone", "Increases max health by 20.", 1);

    EXPECT_EQ(acc.statValuePairs[0].first, "maxHealth");
}

TEST(AccessoryConstructorTests, StatValue) {
    Accessory acc({{"maxHealth", 20}}, "Health Stone", "Increases max health by 20.", 1);

    EXPECT_EQ(acc.statValuePairs[0].second, 20);
}

TEST(AccessoryUseTests, AccessoryModifiesSingleStat) {
    Player player;
    player.getPlayerStats().setMaxHealth(40);
    
    //add an accessory to the player's inventory and equip it 
    Accessory acc({{"maxHealth", 20}}, "Health Stone", "Increases max health by 20.", 1);
    player.getInventory().setItemsSize(1);
    player.getInventory().setAccessoriesSize(1);
    player.getInventory().addItem(&acc);    
    player.equipAccessory(&acc);

    EXPECT_EQ(player.getPlayerStats().getMaxHealth(), 60);
}

TEST(AccessoryUseTests, AccessoryModifiesMultipleStats) {
    Player player;
    player.getPlayerStats().setMaxHealth(40);
    player.getPlayerStats().setDexterity(8);
    
    //add an accessory to the player's inventory and equip it 
    Accessory acc({{"maxHealth", 15}, {"dexterity", 4}}, "Heart Necklace", "Increases max health by 15 and Dexterity by 4.", 1);
    player.getInventory().setItemsSize(1);
    player.getInventory().setAccessoriesSize(1);
    player.getInventory().addItem(&acc);    
    player.equipAccessory(&acc);

    EXPECT_TRUE(player.getPlayerStats().getMaxHealth() == 55 && 
        player.getPlayerStats().getDexterity() == 12);
}

TEST(AccessoryPrintTests, PrintStat) {
    cout << "\n--- Print stat below ---\n";
    cout << "------------------------------------\n";
    
    Accessory acc({{"maxHealth", 20}}, "Health Stone", "Increases max health by 20.", 1);
    cout << acc.statValuePairs[0].first << ": " << acc.statValuePairs[0].second << "\n";

    cout << "------------------------------------\n";
}

TEST(AccessoryPrintTests, PrintFromUseFunction) {
    cout << "\n--- Print from accessory 'use' function below ---\n";
    cout << "------------------------------------\n";
    
    Accessory acc({{"maxHealth", 20}}, "Health Stone", "Increases max health by 20.", 1);
    Player player;
    player.getPlayerStats().setMaxHealth(40);
    player.getInventory().setItemsSize(1);
    player.getInventory().setAccessoriesSize(1);
    player.getInventory().addItem(&acc);    
    player.equipAccessory(&acc);

    cout << "------------------------------------\n";
}