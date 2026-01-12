#ifndef CHARACTERSTATS_H
#define CHARACTERSTATS_H

#include <string>
#include <unordered_map>
using namespace std;

struct CharacterStats {
    int maxHealth;  // health stats, determines how close to death you are
    int currHealth;

    int vigor;  // major stats, these are the ones that players will usually see
    int physicalDef;
    int magicalPower;
    int magicalDef;
    int immunity;
    int agility;

    int strength;  // these are made up into vigor
    int stamina;

    int pierceResistance;  // these are made up into physicalDef
    int bluntResistance;
    int slashResistance;

    int fireAffinity;  // these are made up into magicalPower
    int earthAffinity;
    int waterAffinity;
    int windAffinity;
    int lightningAffinity;

    int fireResistance;  // these are made up into magicalDef
    int earthResistance;
    int waterResistance;
    int windResistance;
    int lightningResistance;

    int poisonResistance;  // these are made up into immunity
    int sleepResistance;
    int paralysisResistance;
    int statResistance;

    int dexterity;  // these are made up into agility
    int speed;

    ///////////////////////////////////////////////// the second type in here is a pointer to an int member in the struct
    static const std::unordered_map<std::string, int CharacterStats::*> statLookup; // lookup table for stats
    /////////////////////////////////////////////////
    
    int getMaxHealth() const {return maxHealth;}  // getters
    int getCurrHealth() const {return currHealth;}
    int getVigor() const {return vigor;}
    int getPhysicalDef() const {return physicalDef;}
    int getMagicalPower() const {return magicalPower;}
    int getMagicalDef() const {return magicalDef;}
    int getImmunity() const {return immunity;}
    int getAgility() const {return agility;}
    int getStrength() const {return strength;}
    int getStamina() const {return stamina;}
    int getPierceResistance() const {return pierceResistance;}
    int getBluntResistance() const {return bluntResistance;}
    int getSlashResistance() const {return slashResistance;}
    int getFireAffinity() const {return fireAffinity;}
    int getEarthAffinity() const {return earthAffinity;}
    int getWaterAffinity() const {return waterAffinity;}
    int getWindAffinity() const {return windAffinity;}
    int getLightningAffinity() const {return lightningAffinity;}
    int getFireResistance() const {return fireResistance;}
    int getEarthResistance() const {return earthResistance;}
    int getWaterResistance() const {return waterResistance;}
    int getWindResistance() const {return windResistance;}
    int getLightningResistance() const {return lightningResistance;}
    int getPoisonResistance() const {return poisonResistance;}
    int getSleepResistance() const {return sleepResistance;}
    int getParalysisResistance() const {return paralysisResistance;}
    int getStatResistance() const {return statResistance;}
    int getDexterity() const {return dexterity;}
    int getSpeed() const {return speed;}

    void setMaxHealth(int num) {maxHealth = num;}  // setters
    void setCurrHealth(int num) {currHealth = num;}
    void setVigor(int num) {vigor = num;}
    void setPhysicalDef(int num) {physicalDef = num;}
    void setMagicalPower(int num) {magicalPower = num;}
    void setMagicalDef(int num) {magicalDef = num;}
    void setImmunity(int num) {immunity = num;}
    void setAgility(int num) {agility = num;}
    void setStrength(int num) {strength = num;}
    void setStamina(int num) {stamina = num;}
    void setPierceResistance(int num) {pierceResistance = num;}
    void setBluntResistance(int num) {bluntResistance = num;}
    void setSlashResistance(int num) {slashResistance = num;}
    void setFireAffinity(int num) {fireAffinity = num;}
    void setEarthAffinity(int num) {earthAffinity = num;}
    void setWaterAffinity(int num) {waterAffinity = num;}
    void setWindAffinity(int num) {windAffinity = num;}
    void setLightningAffinity(int num) {lightningAffinity = num;}
    void setFireResistance(int num) {fireResistance = num;}
    void setEarthResistance(int num) {earthResistance = num;}
    void setWaterResistance(int num) {waterResistance = num;}
    void setWindResistance(int num) {windResistance = num;}
    void setLightningResistance(int num) {lightningResistance = num;}
    void setPoisonResistance(int num) {poisonResistance = num;}
    void setSleepResistance(int num) {sleepResistance = num;}
    void setParalysisResistance(int num) {paralysisResistance = num;}
    void setStatResistance(int num) {statResistance = num;}
    void setDexterity(int num) {dexterity = num;}
    void setSpeed(int num) {speed = num;}
};

#endif