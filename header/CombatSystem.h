#ifndef COMBATSYSTEM_H
#define COMBATSYSTEM_H

#include "AIController.h"

class CombatSystem {
    public:
        CombatSystem(vector<Enemy*>, Player*);
        vector<int> determineTurnOrder();
        bool combatValid();
        bool allEnemiesDefeated();
        void printEncounter();
        void startCombat();
    private:
        vector<Enemy*> enemyList;
        Player* playerCharacter;
        vector<int> turnOrder;
        void resolveEnemyAction(Enemy*);
        void resolvePlayerAction(string);
};

struct SpeedEntry {
    int speed;
    int id;  // enemy index OR -1 for player
};

#endif