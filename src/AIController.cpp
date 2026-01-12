#include "../header/AIController.h"

AIController::AIController(Enemy* controlledEnemy, Player* playerCharacter, vector<Enemy*> enemyList):
controlledEnemy(controlledEnemy), playerCharacter(playerCharacter), enemyList(enemyList) {}

int AIController::chooseTarget() {
    int r = rand() % 100;
    /*
    if(r < 80) {
        return -1;
    } else {
        for(int i = 0; i < enemyList.size(); i++) {
            if(enemyList.at(i)->getFamily() != controlledEnemy->getFamily()) {
                return i;
            }
        }
    }
        */
    return -1;
}

void AIController::attackTarget() {
    int target = chooseTarget();
    if(target == -1) {
        cout << "----Enemy is attacking you----" << endl;
        playerCharacter->getPlayerStats().currHealth -= controlledEnemy->getStats().strength;
        cout << "----You took " << controlledEnemy->getStats().strength << " damage----" << endl;
    } else {
        cout << "----Enemy is attacking " << enemyList.at(target)->getEnemyType() << "----" << endl;
        enemyList.at(target)->getEnemyStats().currHealth -= controlledEnemy->getEnemyStats().strength;
        cout << "----" << enemyList.at(target)->getEnemyType() << " took " << controlledEnemy->getStats().strength << " damage----" << endl;
    }
}
