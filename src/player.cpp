#include <string>
#include <vector>
#include "../header/player.h"
#include "../header/Item.hpp"
#include "../header/IUsable.h"
#include "../header/Accessory.h"
#include "../header/CharacterStats.h"
#include "../header/Armor.h"
#include "../header/Weapon.h"
#include "../header/Enemy.h"
using namespace std;

Player::Player() : playerInventory(0) {
    X = 0;
    Y = 0;
    level = 0;
    previousLevel = 0;
    EXP = 0;
    EXPToNextLevel = 0;
    playerClass = "";
    classSchool = "";
    name = "";
    maxAccesorySlots = 0;
    maxInventorySlots = 0;
}
Player::Player(int X, int Y, int level, int EXP, string playerClass, string classSchool, vector<int> growthRate,
    string name, int maxAccesorySlots, Inventory playerInventory, int maxInventorySlots, CharacterStats stats):
    X(X), Y(Y), level(level), EXP(EXP), playerClass(playerClass), classSchool(classSchool), growthRate(growthRate),
    name(name), maxAccesorySlots(maxAccesorySlots), playerInventory(playerInventory), maxInventorySlots(maxInventorySlots), stats(stats) {
        previousLevel = 0;
        EXPToNextLevel = 0;
    }

void Player::setPosition(int x, int y) {
    this->X = x;
    this->Y = y;
}
void Player::setLevel(int level) {
    this->level = level;
}
void Player::setEXP(int XP) {
    EXP = XP;
}
void Player::setEXPToNextLevel(int XP) {
    EXPToNextLevel = XP;
}
void Player::setClass(string playerClass) {
    this->playerClass = playerClass;
}
void Player::setClassSchool(string school) {
    classSchool = school;
}
void Player::setGrowthRate(vector<int> growthRate) {
    this->growthRate = growthRate;
}
void Player::setName(string name) {
    this->name = name;
}
void Player::setMaxAccessorySlots(int MaxAccSlots) {
    maxAccesorySlots = MaxAccSlots;
}
void Player::setInventory(Inventory playerInventory) {
    this->playerInventory = playerInventory;
}
void Player::setMaxInventorySlots(int MaxInvSlots) {
    maxInventorySlots = MaxInvSlots;
    playerInventory.setItemsSize(MaxInvSlots);
}
void Player::setStats(CharacterStats stats) {
    this->stats = stats;
}

int Player::getX() {
    return X;
}
int Player::getY() {
    return Y;
}
void Player::useItem(Item* item) {
    if (this->getInventory().hasItem(item->getName()) == false) {
        cout << "Item not found in inventory.\n";
        return;
    }
    
    IUsable* usable = dynamic_cast<IUsable*>(item);
    if (usable) {
        usable->use(this); //pass a pointer to the player
        if (item->getCount() <= 0) {
            playerInventory.removeItem(item);
        }
    } else {
        cout << "This item cannot be used.\n";
    }
}
void Player::equipAccessory(Accessory* accessory) {
    if (playerInventory.hasItem(accessory->getName()) == false) {
        cout << "Accessory not found in inventory.\n";
        return;
    }
    playerInventory.addAccessory(accessory);
    cout << "Equipping accessory: " << accessory->getName() << "\n";
    playerInventory.removeItem(accessory);
    
    if (accessory->statValuePairs.empty()) {
        cout << "Accessory has no stat modifications.\n";
        return;
    }
    this->applyStatsFromVector(accessory->statValuePairs);
}

void Player::unequipAccessory(int slotNumber) {
    vector<Accessory*>& accessories = playerInventory.getAccessories();

    if (accessories.size() <= 0) {
        cout << "No accessories are equipped.\n";
        return;
    }
    else if (playerInventory.itemsAreFull()) {
        cout << "Cannot unequip accessory because inventory is full.\n";
        return;
    }
    
    int vectorPosition = slotNumber - 1;
    Accessory* accessory = accessories[vectorPosition];
    playerInventory.removeAccessory(accessory);
    playerInventory.addItem(accessory);
    cout << accessory->getName() << " was unequipped and added to inventory.\n";

    //reverse the stat modifications
    vector<pair<string, int>> reversedStats;
    for (const auto& statPair : accessory->statValuePairs) {
        reversedStats.push_back({statPair.first, -statPair.second});
    }
    this->applyStatsFromVector(reversedStats);
}

void Player::equipWeapon(Weapon* weapon) {
    if (playerInventory.hasItem(weapon->getName()) == false) {
        cout << "Weapon not found in inventory.\n";
        return;
    }

    if (playerInventory.getWeapon()) {
        swapWeapon(weapon);
        return;
    }
    else {
        playerInventory.setWeapon(weapon);
        cout << "Equipping weapon: " << weapon->getName() << "\n";
        playerInventory.removeItem(weapon);
    }
}

void Player::unequipWeapon() {
    Weapon* weapon = playerInventory.getWeapon();
    
    if (weapon) {
        if (playerInventory.itemsAreFull()) {
            cout << "Cannot unequip weapon because inventory is full.\n";
        }
        else {
            playerInventory.addItem(weapon);
            playerInventory.setWeapon(nullptr);
            cout << "Weapon was unequipped and added to inventory.\n";
        }
    }
    else {
        cout << "No weapon is equipped.\n";
    }
}

void Player::swapWeapon(Weapon* newWeapon) {
    if (newWeapon) {
        Weapon* currentWeapon = playerInventory.getWeapon();

        if (currentWeapon) {
            //temporarily increase inventory size by 1 to allow swap
            int originalSize = playerInventory.getItemsSize();
            playerInventory.setItemsSize(originalSize + 1);
            
            unequipWeapon();
            equipWeapon(newWeapon);

            //restore original inventory size
            playerInventory.setItemsSize(originalSize);
            
            cout << "- Swapped out " << currentWeapon->getName() << " for " << newWeapon->getName() << ".\n";
        }
    }
}

void Player::equipArmor(Armor* armor) {
    if (armor == nullptr) {
        cout << "Invalid armor provided.\n";
        return;
    }

    cout << "Equipping armor: " << armor->getName() << "\n";
    bool successful = true;
    switch (armor->type) {
        case Armor::HELM:
            if (playerInventory.getHelm() == nullptr) 
                equipHelm(armor);
            else {
                swapArmor(armor);
                return;
            }
            break;
        case Armor::CHEST:
            if (playerInventory.getChest() == nullptr) 
                equipChest(armor);
            else {
                swapArmor(armor);
                return;
            }
            break;
        case Armor::LEGS:
            if (playerInventory.getLegs() == nullptr) 
                equipLegs(armor);
            else {
                swapArmor(armor);
                return;
            }
            break;
        case Armor::SHOES:
            if (playerInventory.getShoes() == nullptr) 
                equipShoes(armor);
            else {
                swapArmor(armor);
                return;
            }
            break;
        default:
            cout << "Unknown armor type.\n";
            successful = false;
            break;
    }
    if (successful) {
        if (armor->statValuePairs.empty()) {
            cout << armor->getName() << " has no stat modifications.\n";
            return; //need to figure out why when swapping the stats are applied twice
        }
            this->applyStatsFromVector(armor->statValuePairs);
    }
}

void Player::unequipArmor(Armor::ArmorType armorType) {    
    bool successful = true;
    Armor* armor = nullptr;
    switch (armorType) {
        case Armor::HELM:
            armor = playerInventory.getHelm();
            successful = unequipHelm();
            break;
        case Armor::CHEST:
            armor = playerInventory.getChest();
            successful = unequipChest();
            break;
        case Armor::LEGS:
            armor = playerInventory.getLegs();
            successful = unequipLegs();
            break;
        case Armor::SHOES:
            armor = playerInventory.getShoes();
            successful = unequipShoes();
            break;
        default:
            cout << "Unknown armor type.\n";
            successful = false;
            break;
    }
    if (successful && armor) {
        if (armor->statValuePairs.empty()) {
            cout << "Armor piece had no stat modifications.\n";
            return;
        }
        else {
            //reverse the stat modifications
            vector<pair<string, int>> reversedStats;
            for (const auto& statPair : armor->statValuePairs) {
                reversedStats.push_back({statPair.first, -statPair.second});
            }
            this->applyStatsFromVector(reversedStats);
        }            
    }
}

void Player::swapArmor(Armor* newArmor) {
    if (newArmor) {
        Armor* currentArmor = nullptr;
        switch (newArmor->type) {
            case Armor::HELM:
                currentArmor = playerInventory.getHelm();
                break;
            case Armor::CHEST:
                currentArmor = playerInventory.getChest();
                break;
            case Armor::LEGS:
                currentArmor = playerInventory.getLegs();
                break;
            case Armor::SHOES:
                currentArmor = playerInventory.getShoes();
                break;
            default:
                cout << "Unknown armor type for swapping.\n";
                return;
        }

        if (currentArmor) {
            //temporarily increase inventory size by 1 to allow swap
            int originalSize = playerInventory.getItemsSize();
            playerInventory.setItemsSize(originalSize + 1);
            
            unequipArmor(currentArmor->type);
            equipArmor(newArmor);

            //restore original inventory size
            playerInventory.setItemsSize(originalSize);
            
            cout << "- Swapped out " << currentArmor->getName() << " for " << newArmor->getName() << ".\n";
        }
    }
}

void Player::equipHelm(Armor* helm) {
if (playerInventory.hasItem(helm->getName()) == false) {
        cout << "Helm not found in inventory.\n";
        return;
    }
    playerInventory.setHelm(helm);
    playerInventory.removeItem(helm);
}
bool Player::unequipHelm() {
    Armor* armor = playerInventory.getHelm();
    if (armor) {
        if (playerInventory.itemsAreFull()) {
            cout << "Cannot unequip helm because inventory is full.\n";
            return false;
        }
        else {
            playerInventory.addItem(armor);
            playerInventory.setHelm(nullptr);
            cout << "Helm was unequipped and added to inventory.\n";
            return true;
        }
    }
    else {
        cout << "No helm is equipped.\n";
        return false;
    }
}
void Player::equipChest(Armor* chest) {
    if (playerInventory.hasItem(chest->getName()) == false) {
        cout << "Chest armor not found in inventory.\n";
        return;
    }
    playerInventory.setChest(chest);
    playerInventory.removeItem(chest);
}
bool Player::unequipChest() {
    Armor* armor = playerInventory.getChest();
    if (armor) {
        if (playerInventory.itemsAreFull()) {
            cout << "Cannot unequip chest because inventory is full.\n";
            return false;
        }
        else {
            playerInventory.addItem(armor);
            playerInventory.setChest(nullptr);
            cout << "Chest was unequipped and added to inventory.\n";
            return true;
        }
    }
    else {
        cout << "No chest is equipped.\n";
        return false;
    }
}
void Player::equipLegs(Armor* legs) {
    if (playerInventory.hasItem(legs->getName()) == false) {
        cout << "Leg armor not found in inventory.\n";
        return;
    }
    playerInventory.setLegs(legs);
    playerInventory.removeItem(legs);
}
bool Player::unequipLegs() {
    Armor* armor = playerInventory.getLegs();
    if (armor) {
        if (playerInventory.itemsAreFull()) {
            cout << "Cannot unequip legs because inventory is full.\n";
            return false;
        }
        else {
            playerInventory.addItem(armor);
            playerInventory.setLegs(nullptr);
            cout << "Legs were unequipped and added to inventory.\n";
            return true;
        }
    }
    else {
        cout << "No legs are equipped.\n";
        return false;
    }
}
void Player::equipShoes(Armor* shoes) {
    if (playerInventory.hasItem(shoes->getName()) == false) {
    cout << "Shoes not found in inventory.\n";
    return;
    }
    playerInventory.setShoes(shoes);
    playerInventory.removeItem(shoes);
}
bool Player::unequipShoes() {
    Armor* armor = playerInventory.getShoes();
    if (armor) {
        if (playerInventory.itemsAreFull()) {
            cout << "Cannot unequip shoes because inventory is full.\n";
            return false;
        }
        else {
            playerInventory.addItem(armor);
            playerInventory.setShoes(nullptr);
            cout << "Shoes were unequipped and added to inventory.\n";
            return true;
        }
    }
    else {
        cout << "No shoes are equipped.\n";
        return false;
    }
}
void Player::applyStatsFromVector(const vector<pair<string, int>>& statValuePairs) {
    for (const auto& statValuePair : statValuePairs) {
        const string& statName = statValuePair.first;
        int statValue = statValuePair.second;
        auto it = CharacterStats::statLookup.find(statName);
        if (it != CharacterStats::statLookup.end()) {
            stats.*(it->second) += statValue;
            cout << "Player's " << statName << " increased by " << statValue << ". New value: " << stats.*(it->second) << "\n";
        } else {
            cout << "Unknown stat: " << statName << "\n";
        }
    }
}

void Player::attackEnemy(Enemy* enemy) {
    if (enemy == nullptr) {
        cout << "No enemy to attack.\n";
        return;
    }
    Weapon* weapon = playerInventory.getWeapon();
    CharacterStats& enemyStats = enemy->getEnemyStats();

    cout << "Attacking enemy with " << (weapon ? weapon->getName() : "fists") << "!\n";
    if (!weapon) {
        enemyStats.currHealth -= this->weaponlessAttackDamage;
        cout <<"The " << enemy->getEnemyType() << "'s " << "current health" << " changed by " << -this->weaponlessAttackDamage << ". New value: " << enemyStats.currHealth << "\n";
    }
    else {
        weapon->applyAttack(enemy);
    }
    if(enemy->getEnemyStats().currHealth <= 0) {  // you killed the enemy, you can get the loot
        if(enemy->getMaterialDrop() != nullptr) {
            cout << "The enemy " << enemy->getEnemyType() << " has dropped an Item" << endl;
            Item* newItem = enemy->getMaterialDrop();
            promptForItemPickup(newItem);
        } else {
            cout << "Enemy had no drops" << endl;
        }
    }
}

void Player::pickupItem(Item* item) {
    if (item == nullptr) {
        cout << "No item to pick up.\n";
        return;
    }
    if (playerInventory.addItem(item)) {
        cout << "Picked up item: " << item->getName() << "\n";
    } else {
        cout << "Inventory full. Cannot pick up item: " << item->getName() << "\n";
    }
}

void Player::promptForItemPickup(Item* item) {
    int input;
    cout << "Would you like to pick up this item?\n";
    cout << "Name and count: " << item->getName() << " x" << item->getCount() << '\n';
    cout << "Description: " << item->getDescription() << '\n';
    cout << "1) Yes\n2) No\n\n Input: ";
    cin >> input;

    switch (input) {
        case 1:
            pickupItem(item);
            break;
        case 2:
            cout << "Moving on...\n";
            break;
        default:
            throw runtime_error("Invalid input");
            break;
    }
}


int Player::getLevel() {
    return level;
}
int Player::getEXP() {
    return EXP;
}
int Player::getEXPToNextLevel() {
    return EXPToNextLevel;
}
string Player::getClass() {
    return playerClass;
}
string Player::getClassSchool() {
    return classSchool;
}
vector<int> Player::getGrowthRate() {
    return growthRate;
}
string Player::getName() {
    return name;
}
int Player::getMaxAccessorySlots() {
    return maxAccesorySlots;
}
Inventory& Player::getInventory() {
    return this->playerInventory;
}
int Player::getMaxInventorySlots() {
    return maxInventorySlots;
}
CharacterStats& Player::getPlayerStats() {
    return stats;
}

void Player::processInput (const string& input) {
    if (input == "1") {
        cout << "Opening Inventory: " << endl;
        openInventory();
    } else if (input == "2") {
        cout << "Printing Stats: " << endl;
        printStats();
    } else if (input == "3") {
        cout << "Equiped Items: NOTE: printEquipment() is to be developed" << endl;
    }
}

void Player::levelUp(int levels) {
    level += levels;
    adjustStatsForLevel();
}
void Player::gainEXP(int XP) {
    EXP += XP;
    if(XP < EXPToNextLevel) {
        EXPToNextLevel -= XP;
    } else if(XP == EXPToNextLevel) {
        levelUp(1);
        EXPToNextLevel = level*100;  // this EXPToNextLevel is just temporary and up to change
    } else {
        while(XP > EXPToNextLevel) {
            levelUp(1);
            XP -= EXPToNextLevel;
            EXPToNextLevel = level*100;
        }
    }
}
void Player::adjustStatsForLevel() {
    int diff = level - previousLevel;
    if (diff == 0) return;  // if there is no level difference then there is no need to adjust stats;
    if(growthRate.size() < 29) {
        throw runtime_error("growth rate must have a value for all stats");
    }

    stats.setMaxHealth(stats.getMaxHealth() + (growthRate.at(0)*diff));
    stats.setCurrHealth(stats.getCurrHealth() + (growthRate.at(1)*diff));
    stats.setVigor(stats.getVigor() + (growthRate.at(2)*diff));
    stats.setPhysicalDef(stats.getPhysicalDef() + (growthRate.at(3)*diff));
    stats.setMagicalPower(stats.getMagicalPower() + (growthRate.at(4)*diff));
    stats.setMagicalDef(stats.getMagicalDef() + (growthRate.at(5)*diff));
    stats.setImmunity(stats.getImmunity() + (growthRate.at(6)*diff));
    stats.setAgility(stats.getAgility() + (growthRate.at(7)*diff));
    stats.setStrength(stats.getStrength() + (growthRate.at(8)*diff));
    stats.setStamina(stats.getStamina() + (growthRate.at(9)*diff));
    stats.setPierceResistance(stats.getPierceResistance() + (growthRate.at(10)*diff));
    stats.setBluntResistance(stats.getBluntResistance() + (growthRate.at(11)*diff));
    stats.setSlashResistance(stats.getSlashResistance() + (growthRate.at(12)*diff));
    stats.setFireAffinity(stats.getFireAffinity() + (growthRate.at(13)*diff));
    stats.setEarthAffinity(stats.getEarthAffinity() + (growthRate.at(14)*diff));
    stats.setWaterAffinity(stats.getWaterAffinity() + (growthRate.at(15)*diff));
    stats.setWindAffinity(stats.getWindAffinity() + (growthRate.at(16)*diff));
    stats.setLightningAffinity(stats.getLightningAffinity() + (growthRate.at(17)*diff));
    stats.setFireResistance(stats.getFireResistance() + (growthRate.at(18)*diff));
    stats.setEarthResistance(stats.getEarthResistance() + (growthRate.at(19)*diff));
    stats.setWaterResistance(stats.getWaterResistance() + (growthRate.at(20)*diff));
    stats.setWindResistance(stats.getWindResistance() + (growthRate.at(21)*diff));
    stats.setLightningResistance(stats.getLightningResistance() + (growthRate.at(22)*diff));
    stats.setPoisonResistance(stats.getPoisonResistance() + (growthRate.at(23)*diff));
    stats.setSleepResistance(stats.getSleepResistance() + (growthRate.at(24)*diff));
    stats.setParalysisResistance(stats.getParalysisResistance() + (growthRate.at(25)*diff));
    stats.setStatResistance(stats.getStatResistance() + (growthRate.at(26)*diff));
    stats.setDexterity(stats.getDexterity() + (growthRate.at(27)*diff));
    stats.setSpeed(stats.getSpeed() + (growthRate.at(28)*diff));

    previousLevel = level;
}


void Player::printStats() {
    cout << "Name: " << name << endl;
    cout << "Level: " << level << endl;
    cout << "Class: " << playerClass << endl;
    cout << "School: " << classSchool << endl;
    cout << "Health: " << stats.currHealth << "/" <<  stats.maxHealth << endl;
    cout << "XP: " << EXP << endl;
    cout << "XP to next level: " << EXPToNextLevel << endl;
    cout << "Vigor: " << stats.vigor << endl;
    cout << "Physical Def: " << stats.physicalDef << endl;
    cout << "Magical Power: " << stats.magicalPower << endl;
    cout << "Magical Def: " << stats.magicalDef << endl;
    cout << "Immunity: " << stats.immunity << endl;
    cout << "Agility: " << stats.agility << endl;
}
void Player::openInventory() {
    playerInventory.printInventory();
}










void Player::levelUp(int levels, CharacterStats& cSS) {
    level += levels;
    adjustStatsForLevel(cSS);
}
void Player::gainEXP(int XP, CharacterStats& cS) {
    EXP += XP;
    if(XP < EXPToNextLevel) {
        EXPToNextLevel -= XP;
    } else if(XP == EXPToNextLevel) {
        levelUp(1, cS);
        EXPToNextLevel = level*100;  // this EXPToNextLevel is just temporary and up to change
    } else {
        while(XP > EXPToNextLevel) {
            levelUp(1, cS);
            XP -= EXPToNextLevel;
            EXPToNextLevel = level*100;
        }
    }
}
void Player::adjustStatsForLevel(CharacterStats& stats) {
    int diff = level - previousLevel;
    if (diff == 0) return;  // if there is no level difference then there is no need to adjust stats;
    

    stats.setMaxHealth(stats.getMaxHealth() + diff);
    stats.setCurrHealth(stats.getCurrHealth() + diff);
    stats.setVigor(stats.getVigor() + diff);
    stats.setPhysicalDef(stats.getPhysicalDef() + diff);
    stats.setMagicalPower(stats.getMagicalPower() + diff);
    stats.setMagicalDef(stats.getMagicalDef() + diff);
    stats.setImmunity(stats.getImmunity() + diff);
    stats.setAgility(stats.getAgility() + diff);
    stats.setStrength(stats.getStrength() + diff);
    stats.setStamina(stats.getStamina() + diff);
    stats.setPierceResistance(stats.getPierceResistance() + diff);
    stats.setBluntResistance(stats.getBluntResistance() + diff);
    stats.setSlashResistance(stats.getSlashResistance() + diff);
    stats.setFireAffinity(stats.getFireAffinity() + diff);
    stats.setEarthAffinity(stats.getEarthAffinity() + diff);
    stats.setWaterAffinity(stats.getWaterAffinity() + diff);
    stats.setWindAffinity(stats.getWindAffinity() + diff);
    stats.setLightningAffinity(stats.getLightningAffinity() + diff);
    stats.setFireResistance(stats.getFireResistance() + diff);
    stats.setEarthResistance(stats.getEarthResistance() + diff);
    stats.setWaterResistance(stats.getWaterResistance() + diff);
    stats.setWindResistance(stats.getWindResistance() + diff);
    stats.setLightningResistance(stats.getLightningResistance() + diff);
    stats.setPoisonResistance(stats.getPoisonResistance() + diff);
    stats.setSleepResistance(stats.getSleepResistance() + diff);
    stats.setParalysisResistance(stats.getParalysisResistance() + diff);
    stats.setStatResistance(stats.getStatResistance() + diff);
    stats.setDexterity(stats.getDexterity() + diff);
    stats.setSpeed(stats.getSpeed() + diff);


    stats.setVigor(stats.getStrength() + stats.getStamina());
    stats.setPhysicalDef(stats.getPierceResistance() + stats.getBluntResistance() + stats.getSlashResistance());
    int tempSum = stats.getFireResistance() + stats.getEarthResistance() + stats.getWaterResistance() + stats.getWindResistance() + stats.getLightningResistance();
    stats.setMagicalDef(tempSum / 5);
    tempSum = stats.getPoisonResistance() + stats.getSleepResistance() + stats.getParalysisResistance() + stats.getStatResistance();
    stats.setImmunity(tempSum / 4);
    stats.setAgility((stats.getDexterity() + stats.getSpeed() ) / 2);
    tempSum = stats.getFireAffinity() + stats.getEarthAffinity() + stats.getWaterAffinity() + stats.getWindAffinity() + stats.getLightningAffinity();
    stats.setMagicalPower(tempSum / 2);
    

    previousLevel = level;
}

