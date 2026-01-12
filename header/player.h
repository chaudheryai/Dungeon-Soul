#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include "Inventory.hpp"
#include "CharacterStats.h"
#include "Accessory.h"
#include "Armor.h"
#include "Weapon.h"
using namespace std;

class Player{
private:
    int X;
    int Y;
    int level;
    int previousLevel;
    int EXP;
    int EXPToNextLevel;
    string playerClass;
    string classSchool;
    vector<int> growthRate;
    string name;
    int maxAccesorySlots;
    Inventory playerInventory;
    int maxInventorySlots;
    CharacterStats stats;
    int weaponlessAttackDamage = 5; //default unarmed attack damage

    void applyStatsFromVector(const vector<pair<string, int>>& statValuePairs);
    void equipHelm(Armor* helm);
    void equipChest(Armor* chest);
    void equipLegs(Armor* legs);
    void equipShoes(Armor* shoes);
    bool unequipHelm();
    bool unequipChest();
    bool unequipLegs();
    bool unequipShoes();    

    void swapArmor(Armor* newArmor);
    void swapWeapon(Weapon* newWeapon);
    // implement CharacterStats, Accessory, and Armor
    //equippedWeapon: Armor
    //headArmor: Armor
    //chestArmor: Armor
    //legArmor: Armor
    //feetArmor: Armor
    //equippedAccessories: vector<Accessory>
public:
    Player();
    Player(int, int, int, int, string, string, vector<int>, string, int, Inventory, int, CharacterStats);

    void processInput (const string&);
    void levelUp(int);
    void gainEXP(int);
    void adjustStatsForLevel();
    
    void printStats();
    void openInventory();
    void printEquipment();  // TO BE DEVELOPED


    void levelUp(int, CharacterStats&);
    void gainEXP(int, CharacterStats&);
    void adjustStatsForLevel(CharacterStats&);

    int getX();
    int getY();
    int getLevel();
    int getEXP();
    int getEXPToNextLevel();
    string getClass();
    string getClassSchool();
    vector<int> getGrowthRate();
    string getName();
    int getMaxAccessorySlots();

    void useItem(Item* item);
    void equipAccessory(Accessory* accessory);
    void unequipAccessory(int slotNumber);
    void equipArmor(Armor* armor);
    void unequipArmor(Armor::ArmorType armorType);
    void equipWeapon(Weapon* weapon);
    void unequipWeapon();

    void pickupItem(Item* item);
    void promptForItemPickup(Item* item);

    void attackEnemy(Enemy* enemy);

    // implement , CharacterStats
    //setStats(CharacterStats)
    //getStats(): CharacterStats
    Inventory& getInventory();
    int getMaxInventorySlots();
    CharacterStats& getPlayerStats();

    void setPosition(int x, int y);
    void setLevel(int);
    void setEXP(int);
    void setEXPToNextLevel(int);
    void setClass(string);
    void setClassSchool(string);
    void setGrowthRate(vector<int>);
    void setName(string);
    void setMaxAccessorySlots(int);
    void setInventory(Inventory);
    void setMaxInventorySlots(int);
    void setStats(CharacterStats);
};

#endif