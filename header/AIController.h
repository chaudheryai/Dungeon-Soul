#ifndef AICONTROLLER_H
#define AICONTROLLER_H

#include "Enemy.h"
#include "player.h"

class AIController {
    public:
        AIController(Enemy*, Player*, vector<Enemy*>);
        int chooseTarget();
        void attackTarget();
    private:
        Enemy* controlledEnemy;
        Player* playerCharacter;
        vector<Enemy*> enemyList;
};

#endif