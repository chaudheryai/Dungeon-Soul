#include "gtest/gtest.h"
#include "../header/player.h"
#include "../header/CharacterStats.h"
#include "../header/Weapon.h"
#include <vector>
using namespace std;

class PlayerTestingUsingCharacterStats : public ::testing::Test {
protected:

    vector<int> growth;
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
    }
};

using PlayerEXPTests = PlayerTestingUsingCharacterStats;
using PlayerStatsTests = PlayerTestingUsingCharacterStats;
using PlayerPrintTests = PlayerTestingUsingCharacterStats;

TEST(PlayerConstructorTests, DefaultConstructorInventoryMaxSlotsIsZero) {
    Player player;

    EXPECT_EQ(player.getMaxInventorySlots(), 0);
}

TEST(PlayerConstructorTests, DefaultConstructorPositionIsZero) {
    Player player;

    EXPECT_TRUE(player.getX() == 0 && player.getY() == 0);
}

TEST(PlayerArmorUnequipTests, UnequipArmorMovesToInventory) {
    Player player;
    Inventory inv(10);

    Armor helm(Armor::ArmorType::HELM, {{"poisonResistance", 5}}, "Ivy Hat", "Infused with Medusa's power", 1);
    inv.addItem(&helm);
    player.setInventory(inv);
    player.equipArmor(&helm);
    player.unequipArmor(Armor::HELM);

    EXPECT_TRUE(player.getInventory().hasItem("Ivy Hat") && player.getInventory().getHelm() == nullptr);
}

TEST(PlayerArmorUnequipTests, UnequipArmorFailsMoveToInventoryWhenFull) {
    Player player;
    Inventory inv(1);

    Armor helm(Armor::ArmorType::HELM, {{"poisonResistance", 5}}, "Ivy Hat", "Infused with Medusa's power", 1);
    inv.addItem(&helm);
    player.setInventory(inv);
    player.equipArmor(&helm);

    Item item("item", "desc", 1);
    player.pickupItem(&item); //fill inventory
    
    player.unequipArmor(Armor::HELM);

    EXPECT_FALSE(player.getInventory().hasItem("Ivy Hat") && player.getInventory().getHelm() == nullptr);
}

TEST(PlayerArmorUnequipTests, EquipArmorSwapsWhenSlotFilled) {
    Player player;
    Inventory inv(1);
    player.setInventory(inv);

    Armor helm(Armor::ArmorType::HELM, {{"poisonResistance", 5}}, "Ivy Hat", "Infused with Medusa's power", 1);
    player.pickupItem(&helm);
    player.equipArmor(&helm);

    Armor newHelm(Armor::ArmorType::HELM, {{"fireResistance", 10}}, "Flame Crown", "Burns with eternal fire", 1);
    player.pickupItem(&newHelm);    
    player.equipArmor(&newHelm); //should swap

    EXPECT_TRUE(player.getInventory().hasItem("Ivy Hat") && player.getInventory().getHelm() == &newHelm);
}

TEST(PlayerWeaponUnequipTests, UnequipWeaponMovesToInventory) {
    Player player;
    Inventory inv(10);

    Weapon sword({{"currHealth", -20}}, "Basic Sword", "Regular damage: 20", 1);
    inv.addItem(&sword);
    player.setInventory(inv);
    player.equipWeapon(&sword);
    player.unequipWeapon();

    EXPECT_TRUE(player.getInventory().hasItem("Basic Sword"));
}

TEST(PlayerWeaponUnequipTests, UnequipWeaponFailsMoveToInventoryWhenFull) {
    Player player;
    Inventory inv(1);

    Weapon sword({{"currHealth", -20}}, "Basic Sword", "Regular damage: 20", 1);
    inv.addItem(&sword);
    player.setInventory(inv);
    player.equipWeapon(&sword);

    player.getInventory().setItemsSize(0);
    player.unequipWeapon();

    EXPECT_FALSE(player.getInventory().hasItem("Basic Sword") && !player.getInventory().getWeapon());
}

TEST(PlayerWeaponUnequipTests, EquipWeaponSwapsWhenSlotFilled) {
    Player player;
    Inventory inv(1);
    player.setInventory(inv);

    Weapon sword({{"currHealth", -20}}, "Basic Sword", "Regular damage: 20", 1);
    player.pickupItem(&sword);
    player.equipWeapon(&sword);

    Weapon newSword({{"currHealth", -57}}, "Better Sword", "Regular damage: 57", 1);
    player.pickupItem(&newSword);    
    player.equipWeapon(&newSword); //should swap
    
    EXPECT_TRUE(player.getInventory().hasItem("Basic Sword") && player.getInventory().getWeapon() == &newSword);
}

TEST(PlayerAccessoryUnequipTests, UnequipAccessoryMovesToInventory) {
    Player player;
    Inventory inv(3,3);

    Accessory acc({{"maxHealth", 20}}, "Health Stone", "Increases max health by 20.", 1);
    inv.addItem(&acc);
    player.setInventory(inv);
    player.equipAccessory(&acc);
    player.unequipAccessory(1);

    EXPECT_TRUE(player.getInventory().hasItem("Health Stone") && player.getInventory().getAccessories().size() == 0);
}

TEST(PlayerAccessoryUnequipTests, UnequipAccessorySecondSlot) {
    Player player;
    Inventory inv(3,3);

    Accessory acc1({{"maxHealth", 20}}, "Health Stone", "Increases max health by 20.", 1);
    Accessory acc2({{"dexterity", 15}}, "Speedy Flag", "Increases dexterity by 15.", 1);
    inv.addItem(&acc1);
    inv.addItem(&acc2);
    player.setInventory(inv);
    player.equipAccessory(&acc1);
    player.equipAccessory(&acc2);
    player.unequipAccessory(2);

    EXPECT_TRUE(player.getInventory().hasItem("Speedy Flag") && player.getInventory().getAccessories().size() == 1);
}

TEST(PlayerAccessoryUnequipTests, UnequipAccessoryFailsMoveToInventoryWhenFull) {
    Player player;
    Inventory inv(3,3);

    Accessory acc({{"maxHealth", 20}}, "Health Stone", "Increases max health by 20.", 1);
    inv.addItem(&acc);
    player.setInventory(inv);
    player.equipAccessory(&acc);
    player.setMaxInventorySlots(0);
    player.unequipAccessory(1);

    EXPECT_FALSE(player.getInventory().hasItem("Health Stone") && player.getInventory().getAccessories().size() == 0);
}

TEST_F(PlayerEXPTests, GainEXP) {
    Player player(0, 0, 1, 0, "Swordsman", "Sword School", growth, "Adam", 0, {}, 0, stats);
    player.gainEXP(150);    

    EXPECT_EQ(player.getEXP(), 150);
}

TEST_F(PlayerEXPTests, LevelUp) {
    Player player(0, 0, 1, 0, "Swordsman", "Sword School", growth, "Adam", 0, {}, 0, stats);
    player.levelUp(150);    

    EXPECT_EQ(player.getLevel(), 151);
}

TEST_F(PlayerPrintTests, PrintStats) {
    cout << "\n--- Print player 'printStats' function below ---\n";

    Player player(0, 0, 1, 0, "Swordsman", "Sword School", growth, "Adam", 0, {}, 0, stats);
    player.printStats();   

    cout << "------------------------------------\n";
}

TEST_F(PlayerPrintTests, PrintInventoryNonEmpty) {
    Player player;
    Inventory inv(10, 29);
    Item a("Hammer", "Blunt damage dealer. Destroys all in sight.", 1);
    Item b("Apple", "Crunchy fruit", 23);
    Armor helm(Armor::ArmorType::HELM, {{"poisonResistance", 99}}, "Ivy Hat", "Infused with Medusa's power", 1);
    Accessory accessory({}, "Impossible Triangle", "Don't think about it too hard.", 1);

    inv.addItem(&a);
    inv.addItem(&b);
    inv.addAccessory(&accessory);
    inv.setHelm(&helm);

    player.setInventory(inv);

    cout << "\n--- Print non-empty player 'openInventory' function below ---\n";

    player.openInventory();

    cout << "------------------------------------\n";
}

TEST_F(PlayerPrintTests, PrintInventoryEmpty) {
    Player player;

    cout << "\n--- Print empty player 'openInventory' function below ---\n";

    player.openInventory();

    cout << "------------------------------------\n";
}