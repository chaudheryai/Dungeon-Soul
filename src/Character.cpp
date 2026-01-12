#include "../header/Character.h"


using namespace std;

Character::Character(): level(1), previousLevel(1) {}
Character::Character(int level, vector<int> growth, CharacterStats stats): 
Actor(), level(level), previousLevel(1), growthRate(growth), stats(stats) {}
Character::Character(int level, vector<int> growth, CharacterStats stats, int x, int y): 
Actor(x,y), level(level), previousLevel(1), growthRate(growth), stats(stats){}

void Character::setStats(CharacterStats stats) {
    this->stats = stats;
}
void Character::setGrowthRate(vector<int> growthRate) {
    this->growthRate = growthRate;
}
void Character::setLevel(int level) {
    this->previousLevel = this->level;  // in case a character levels up more than once
    this->level = level;
    adjustStatsForLevel();
}

int Character::getLevel() const {
    return level;
}
const CharacterStats& Character::getStats() const {
    return stats;
}

void Character::adjustStatsForLevel() {
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
