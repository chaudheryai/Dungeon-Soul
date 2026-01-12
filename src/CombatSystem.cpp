#include "../header/CombatSystem.h"

CombatSystem::CombatSystem(vector<Enemy*> enemyList, Player* playerCharacter):
enemyList(enemyList), playerCharacter(playerCharacter) {}

vector<int> CombatSystem::determineTurnOrder() {
    vector<int> turnOrder;
    vector<SpeedEntry> speeds;
    SpeedEntry input;
    input.speed = playerCharacter->getPlayerStats().speed;  // fills speed vector with player and enemy information
    input.id = -1;
    speeds.push_back(input);
    for (int i = 0; i < enemyList.size(); i++) {
        input.speed = enemyList.at(i)->getEnemyStats().speed;
        input.id = i;
        speeds.push_back(input);
    }
    for (int i = 0; i < speeds.size() - 1; i++) {  // sorts the speed vector in descending order
        int maxIndex = i;
        for (int j = i + 1; j < speeds.size(); j++) {
            if (speeds.at(j).speed > speeds.at(maxIndex).speed) {
                maxIndex = j;
            }
        }
        SpeedEntry temp = speeds.at(i);
        speeds.at(i) = speeds.at(maxIndex);
        speeds.at(maxIndex) = temp;
    }
    for(int i = 0; i < speeds.size(); i++) {
        turnOrder.push_back(speeds.at(i).id);
    }
    return turnOrder;
}
bool CombatSystem::combatValid() {
    if(playerCharacter->getPlayerStats().currHealth <= 0) {
        return false;
    }
    for(int i = 0; i < enemyList.size(); i++) {
        if(allEnemiesDefeated()) {
            return false;
        }
    }
    return true;
}
bool CombatSystem::allEnemiesDefeated() {
    for(int i = 0; i < enemyList.size(); i++) {
        if(enemyList.at(i)->getEnemyStats().currHealth > 0) {
            return false;
        }
    }
    return true;
}
void CombatSystem::printEncounter() {
    cout << "\nEnemies:" << endl;
    for(int i = 0; i < enemyList.size(); i++) {
        int currHP = enemyList.at(i)->getEnemyStats().currHealth;
        if(currHP < 0) currHP = 0;
        cout << i << ") " << enemyList.at(i)->getEnemyType() << ", HP: " << currHP << "/" << enemyList.at(i)->getEnemyStats().maxHealth;
        if(currHP == 0) cout << " DEAD";
        cout << endl;
    }
    cout << endl;
}
void CombatSystem::resolvePlayerAction(string input) {
    if(input == "1") {  // 1 is attack
        int target;
        cout << "Select Target: " << endl;
        cin >> target;
        while (target < 0 || target >= enemyList.size() || enemyList.at(target)->getEnemyStats().currHealth <= 0) {
            cout << "Invalid choice" << endl;
            cout << "Select Target: " << endl;
            cin >> target;
        }
        cout << "----Attacking " << enemyList.at(target)->getEnemyType() << "----" << endl;
        playerCharacter->attackEnemy(enemyList.at(target));
    } else if (input == "2") {  // 2 is use item
        string itemName;
        cout << "Select Item: " << endl;
        cin >> itemName;
        while (!playerCharacter->getInventory().hasItem(itemName)) {
            cout << "You don't have this item" << endl;
            cout << "Select Item: " << endl;
            cin >> itemName;
        }
        playerCharacter->useItem(playerCharacter->getInventory().getItem(itemName));
    } else {  // invalid input
        throw runtime_error("Invalid input");
    }
}
void CombatSystem::resolveEnemyAction(Enemy* actingEnemy) {
    AIController ai(actingEnemy, playerCharacter, enemyList);
    int target = ai.chooseTarget();
    ai.attackTarget();
}
void CombatSystem::startCombat() {
    vector<int> turnOrder = determineTurnOrder();
    while(combatValid()) {
        printEncounter();
        for(int i = 0; i < turnOrder.size(); i++) {
            if (turnOrder.at(i) == -1) {  // it is the player's turn
                printEncounter();
                cout << "--- PLAYER TURN ---" << endl;
                cout << "1) Attack\n2) Use Item" << endl;
                string input;
                cin >> input;
                resolvePlayerAction(input);
            } else {  // it is one of the enemy's turn
                resolveEnemyAction(enemyList.at(turnOrder.at(i)));
            }
            if(!combatValid()) {
                cout << "Combat Over" << endl;
                if(playerCharacter->getPlayerStats().currHealth <= 0) {
                    cout << "You Lose" << endl;
                } else {
                    cout << "You Win This Battle" << endl;
                    for(unsigned int i = 0; i < enemyList.size(); i++){
                        playerCharacter->gainEXP(enemyList.at(i)->getEXPDrop());
                    }
                }
                return;
            }
        }
    }
}
