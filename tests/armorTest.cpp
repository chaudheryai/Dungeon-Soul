#include "gtest/gtest.h"
#include "../header/player.h"
#include "../header/Armor.h"
using namespace std;

//Constructor
TEST(ArmorConstructorTests, VectorSize) {

    Armor helm(Armor::ArmorType::HELM, {{"maxHealth", 20}}, "Health Helmet", "Increases max health by 20.", 1);

    EXPECT_EQ(helm.statValuePairs.size(), 1);
}

TEST(ArmorConstructorTests, ArmorType) {

    Armor helm(Armor::ArmorType::SHOES, {{"maxHealth", 20}}, "Health Helmet", "Increases max health by 20.", 1);

    EXPECT_EQ(helm.type, Armor::ArmorType::SHOES);
}

TEST(ArmorConstructorTests, StatName) {
    Armor helm(Armor::ArmorType::HELM, {{"maxHealth", 20}}, "Health Helmet", "Increases max health by 20.", 1);

    EXPECT_EQ(helm.statValuePairs[0].first, "maxHealth");
}


TEST(ArmorConstructorTests, StatValue) {
    Armor helm(Armor::ArmorType::HELM, {{"maxHealth", 20}}, "Health Helmet", "Increases max health by 20.", 1);

    EXPECT_EQ(helm.statValuePairs[0].second, 20);
}

TEST(ArmorUseTests, ArmorModifiesSingleStat) {
    Player player;
    player.getPlayerStats().setMaxHealth(40);
    
    //add an accessory to the player's inventory and equip it 
    Armor helm(Armor::ArmorType::HELM, {{"maxHealth", 20}}, "Health Helmet", "Increases max health by 20.", 1);
    player.getInventory().setItemsSize(1);
    player.getInventory().setAccessoriesSize(1);
    player.getInventory().addItem(&helm);    
    player.equipArmor(&helm);
    EXPECT_EQ(player.getPlayerStats().getMaxHealth(), 60);
}

TEST(ArmorUseTests, ArmorModifiesMultipleStats) {
    Player player;
    player.getPlayerStats().setMaxHealth(40);
    player.getPlayerStats().setDexterity(8);
    
    //add an armor to the player's inventory and equip it 
    Armor helm(Armor::ArmorType::HELM, {{"maxHealth", 15}, {"dexterity", 4}}, "Heart Helmet", "Increases max health by 15 and Dexterity by 4.", 1);
    player.getInventory().setItemsSize(1);
    player.getInventory().setAccessoriesSize(1);
    player.getInventory().addItem(&helm);    
    player.equipArmor(&helm);

    EXPECT_TRUE(player.getPlayerStats().getMaxHealth() == 55 && 
        player.getPlayerStats().getDexterity() == 12);
}


TEST(ArmorPrintTests, PrintTypeAndStat) {
    cout << "\n--- Armor type and stat below ---\n";
    cout << "------------------------------------\n";
    
    Armor helm(Armor::ArmorType::HELM, {{"maxHealth", 20}}, "Health Helmet", "Increases max health by 20.", 1);
    cout << helm.type << "(0 means HELM) " << helm.statValuePairs[0].first << ": " << helm.statValuePairs[0].second << "\n";
    cout << "------------------------------------\n";
}


TEST(ArmorPrintTests, PrintFromEquipFunction) {
    cout << "\n--- Print from player 'equip' function below ---\n";
    cout << "------------------------------------\n";
    
    Armor helm(Armor::ArmorType::HELM, {{"maxHealth", 20}}, "Health Helmet", "Increases max health by 20.", 1);
    Player player;
    player.getPlayerStats().setMaxHealth(40);
    player.getInventory().setItemsSize(1);
    player.getInventory().setAccessoriesSize(1);
    player.getInventory().addItem(&helm);    
    player.equipArmor(&helm);

    cout << "------------------------------------\n";
}