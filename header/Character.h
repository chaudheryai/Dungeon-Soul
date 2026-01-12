#ifndef CHARACTER_H
#define CHARACTER_H

#include "Actor.h"
#include "CharacterStats.h"
#include <stdexcept>
#include <vector>

class Character : public Actor {  // character keeps track of basic info like stats, level, and growthRate
    public:
        Character();
        Character(int, std::vector<int>, CharacterStats);  // uses basic Actor()
        Character(int, std::vector<int>, CharacterStats, int, int);  // uses parameterized Actor(int, int)
        void setStats(CharacterStats);
        void setGrowthRate(std::vector<int>);
        void setLevel(int);
        int getLevel() const;
        const CharacterStats& getStats() const;
        void adjustStatsForLevel();
    protected:
        int level;
        int previousLevel;
        std::vector<int> growthRate;
        CharacterStats stats;
};

#endif