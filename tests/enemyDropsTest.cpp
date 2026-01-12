#include "../header/CombatSystem.h"
#include "../header/Potion.h"

CharacterStats makeGoblinBaseStats();
CharacterStats makePlayerBaseStats();

int main() {
    // make enemy loot
    Item* loot1 = new Item("Test", "Tester Item", 5);
    Item* loot2 = new Item("Test2", "Tester Item 2", 5);
    Item* loot3 = new Item("Test3", "Tester Item 3", 5);
    Item* loot4 = new Item("Test4", "Tester Item 4", 5);
    // make encounter enemies
    CharacterStats goblinStats = makeGoblinBaseStats();
    vector<int> goblinGrowthRate(29, 1);
    Enemy* e1 = new Enemy("Humanoid", 1, "Goblin", false, false, 3, goblinGrowthRate, goblinStats);
    Enemy* e2 = new Enemy("Humanoid", 10, "Goblin", false, false, 3, goblinGrowthRate, goblinStats);
    e1->addToDeathLootItemList(loot1);
    e1->addToDeathLootItemList(loot2);
    e1->addToDeathLootItemList(loot3);
    e1->addToDeathLootItemList(loot4);
    e1->randomizeMaterialDrop();
    // e1->setMaterialDrop(loot1);
    vector<Enemy*> encounter;
    encounter.push_back(e1);
    encounter.push_back(e2);
    // make player
    CharacterStats playerStats = makePlayerBaseStats();
    vector<int> playerGrowthRate(29, 1);
    Inventory playerInventory(5);
    Item* healthPotion = new Potion(10, 2);
    playerInventory.addItem(healthPotion);
    Player tester(0, 0, 1, 0, "Swordsman", "Swift Sword", playerGrowthRate, "Adam", 5, playerInventory, 5, playerStats);
    //fight
    CombatSystem simulation(encounter, &tester);
    cout << "goblin speed " << e1->getEnemyStats().speed << endl;
    cout << "goblin2 speed " << e2->getEnemyStats().speed << endl;
    cout << "player speed " << tester.getPlayerStats().speed << endl;
    cout << "Player Inventory before combat: " << endl;
    tester.getInventory().printInventory();
    cout << endl;
    simulation.startCombat();
    cout << "Player Inventory after combat: " << endl;
    tester.getInventory().printInventory();

    return 0;
}

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
    goblinBaseStats.setStrength(0);
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