#include <iostream>
#include "../header/dungeon.h"
#include "../header/Inventory.hpp"
#include "../header/CharacterStats.h"
#include "../header/Enemy.h"
#include "../header/AIController.h"
#include "../header/CombatSystem.h"
#include "../header/Item.hpp"
#include <vector>

#include <ctime>
#include <cstdlib>
// bring std names (cout, endl) into the global namespace
using namespace std;
//Chat gpt made chatbot
void brock(){
    string userIn;
    cout << "------------------------------------------------------" << endl;
    cout << "Yo random Civilian I haven't met before, my name is Random Villager." << endl;
    cout << "Type something to talk to me! (type 'bye' to leave)" << endl;
    cout << "------------------------------------------------------" << endl;

    while (true) {
        cout << "You: ";
        getline(cin, userIn);

        // If user typed nothing, just keep asking
        if (userIn.empty()) {
            cout << "Random Villager: Say something, don't be shy." << endl;
            continue;
        }

        // Exit condition
        if (userIn == "bye" || userIn == "Bye" || userIn == "exit") {
            cout << "Random Villager: Aight, see you later!" << endl;
           
            break;
        }

        // Very basic responses
        if (userIn.find("hello") != string::npos || userIn.find("hi") != string::npos) {
            cout << "Random Villager: Yo, what's good?" << endl;
        } else if (userIn.find("how are you") != string::npos) {
            cout << "Random Villager: I'm just vibing in this dungeon, you?" << endl;
        } else if (userIn.find("name") != string::npos) {
            cout << "Random Villager: I told you, it's Random Villager. Kinda fire, right?" << endl;
        } else {
            // Default echo-ish reply
            cout << "Random Villager: That's crazy, you said: \"" << userIn << "\"." << endl;
        }
    }
    return;
}
CharacterStats makeHumaniodBaseStats() {
            CharacterStats HumaniodBaseStats;
            // main stats
            HumaniodBaseStats.setMaxHealth(3);
            HumaniodBaseStats.setCurrHealth(3);
            HumaniodBaseStats.setVigor(8);
            HumaniodBaseStats.setPhysicalDef(12);
            HumaniodBaseStats.setMagicalPower(10);
            HumaniodBaseStats.setMagicalDef(15);
            HumaniodBaseStats.setImmunity(8);
            HumaniodBaseStats.setAgility(14);
            // makes up vigor
            HumaniodBaseStats.setStrength(2);
            HumaniodBaseStats.setStamina(6);
            // makes up physDef
            HumaniodBaseStats.setPierceResistance(4);
            HumaniodBaseStats.setBluntResistance(5);
            HumaniodBaseStats.setSlashResistance(3);
            // makes up magPow
            HumaniodBaseStats.setFireAffinity(0);
            HumaniodBaseStats.setEarthAffinity(4);
            HumaniodBaseStats.setWaterAffinity(2);
            HumaniodBaseStats.setWindAffinity(4);
            HumaniodBaseStats.setLightningAffinity(0);
            // makes up magDef
            HumaniodBaseStats.setFireResistance(2);
            HumaniodBaseStats.setEarthResistance(5);
            HumaniodBaseStats.setWaterResistance(3);
            HumaniodBaseStats.setWindResistance(3);
            HumaniodBaseStats.setLightningResistance(2);
            // makes up immunity
            HumaniodBaseStats.setPoisonResistance(4);
            HumaniodBaseStats.setParalysisResistance(4);
            HumaniodBaseStats.setSleepResistance(0);
            HumaniodBaseStats.setStatResistance(0);
            // makes up agility
            HumaniodBaseStats.setDexterity(6);
            HumaniodBaseStats.setSpeed(8);

            return HumaniodBaseStats;
}
CharacterStats makeZombieBaseStats() {
    CharacterStats zombiBaseStats;
    // main stats
    zombiBaseStats.setMaxHealth(10);
    zombiBaseStats.setCurrHealth(10);
    zombiBaseStats.setVigor(4);
    zombiBaseStats.setPhysicalDef(4);
    zombiBaseStats.setMagicalPower(2);
    zombiBaseStats.setMagicalDef(3);
    zombiBaseStats.setImmunity(2);
    zombiBaseStats.setAgility(7);
    // makes up vigor
            zombiBaseStats.setStrength(2);
            zombiBaseStats.setStamina(6);
            // makes up physDef
            zombiBaseStats.setPierceResistance(4);
            zombiBaseStats.setBluntResistance(5);
            zombiBaseStats.setSlashResistance(3);
            // makes up magPow
            zombiBaseStats.setFireAffinity(0);
            zombiBaseStats.setEarthAffinity(4);
            zombiBaseStats.setWaterAffinity(2);
            zombiBaseStats.setWindAffinity(4);
            zombiBaseStats.setLightningAffinity(0);
            // makes up magDef
            zombiBaseStats.setFireResistance(2);
            zombiBaseStats.setEarthResistance(5);
            zombiBaseStats.setWaterResistance(3);
            zombiBaseStats.setWindResistance(3);
            zombiBaseStats.setLightningResistance(2);
            // makes up immunity
            zombiBaseStats.setPoisonResistance(4);
            zombiBaseStats.setParalysisResistance(4);
            zombiBaseStats.setSleepResistance(0);
            zombiBaseStats.setStatResistance(0);
            // makes up agility
            zombiBaseStats.setDexterity(6);
            zombiBaseStats.setSpeed(1);

    return zombiBaseStats;
}
CharacterStats makePlayerBaseStats() {
    CharacterStats playerBaseStats;
        playerBaseStats.setMaxHealth(5);
        playerBaseStats.setCurrHealth(5);

        playerBaseStats.setStrength(4);
        playerBaseStats.setStamina(5);

        playerBaseStats.setPierceResistance(3);
        playerBaseStats.setBluntResistance(3);
        playerBaseStats.setSlashResistance(3);

        playerBaseStats.setFireResistance(3);
        playerBaseStats.setEarthResistance(5);
        playerBaseStats.setWaterResistance(3);
        playerBaseStats.setWindResistance(3);
        playerBaseStats.setLightningResistance(2);

        playerBaseStats.setFireAffinity(0);
        playerBaseStats.setEarthAffinity(0);
        playerBaseStats.setWaterAffinity(0);
        playerBaseStats.setWindAffinity(0);
        playerBaseStats.setLightningAffinity(0);

        playerBaseStats.setPoisonResistance(3);
        playerBaseStats.setSleepResistance(3);
        playerBaseStats.setParalysisResistance(3);
        playerBaseStats.setStatResistance(3);

        playerBaseStats.setMagicalPower(3);
        playerBaseStats.setMagicalDef(3);
        playerBaseStats.setImmunity(3);
        playerBaseStats.setAgility(3);
        playerBaseStats.setDexterity(3);
        playerBaseStats.setSpeed(3);

            return playerBaseStats;
        }


        void gameOverLoss(){
    cout << "------------------------------------------------------" << endl;
    cout << "Game Over" << endl;
    cout << "You fall in the depths of the Dungeon." << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "Restart Game to Start again" << endl;
    cout << "------------------------------------------------------" << endl;

}

void trapScreen(CharacterStats& playerSSIn){
    int rC = (rand() % 100) + 1; // 1 - 100
    rC += playerSSIn.getAgility();

    if(rC <= 50){
        cout << "------------------------------------------------------" << endl; 
        cout << "Trap Tile: Random Bad Output" << endl;
        cout << "------------------------------------------------------" << endl;
        rC = (rand() % 4) + 1;
        if(rC == 1){
            playerSSIn.setSpeed(playerSSIn.getSpeed() - 2);
        }else if(rC == 2){
            playerSSIn.setDexterity(playerSSIn.getDexterity() - 2);
        }else if(rC == 3){
            playerSSIn.setStrength(playerSSIn.getStrength() - 2);
        }else if(rC == 4){
            playerSSIn.setMaxHealth(playerSSIn.getMaxHealth() - 2);
        }
       
    }
    else if(rC <= 75){
        cout << "------------------------------------------------------" << endl;
        cout << "Trap Tile: Random Okay Output" << endl;
        cout << "------------------------------------------------------" << endl;
        rC = (rand() % 4) + 1;
        if(rC == 1){
            playerSSIn.setSpeed(playerSSIn.getSpeed() + 1);
        }else if(rC == 2){
            playerSSIn.setDexterity(playerSSIn.getDexterity() + 1);
        }else if(rC == 3){
            playerSSIn.setStrength(playerSSIn.getStrength() + 1);
        }else if(rC == 4){
            playerSSIn.setCurrHealth(playerSSIn.getCurrHealth() + 1);
        }
    }
    else if(rC <= 100){
        cout << "------------------------------------------------------" << endl;
        cout << "Trap Tile: Random Good Output" << endl;
        cout << "------------------------------------------------------" << endl;
        rC = (rand() % 4) + 1;
        if(rC == 1){
            playerSSIn.setSpeed(playerSSIn.getSpeed() + 2);
        }else if(rC == 2){
            playerSSIn.setDexterity(playerSSIn.getDexterity() + 2);
        }else if(rC == 3){
            playerSSIn.setStrength(playerSSIn.getStrength() + 2);
        }else if(rC == 4){
            playerSSIn.setCurrHealth(playerSSIn.getCurrHealth() + 2);
        }
    }else{
        cout << "------------------------------------------------------" << endl;
        cout << "Trap Tile: Random AMAZING output" << endl;
        playerSSIn.setMaxHealth(playerSSIn.getMaxHealth() + 10);
        playerSSIn.setCurrHealth(playerSSIn.getMaxHealth());
        playerSSIn.setStrength(playerSSIn.getStrength() + 5);
        playerSSIn.setSpeed(playerSSIn.getSpeed() + 5);
        cout << "------------------------------------------------------" << endl;
        
    }
    cout << " 0) Continue" << endl;
    cout << "------------------------------------------------------" << endl;
    cout << " Input: ";
    char wait;
    cin >> wait;

}

void battleEncScr(CharacterStats& playerSSIn, Player& playerIn){
    char wait;
    bool battleOver = false;
    


    //std::vector<Enemy*> enemyList; 
    //AIController goblinAI(&enemyIn, &playerIn, enemyList);

    cout << "------------------------------------------------------" << endl;
    cout << " Encounter!" << endl;
    cout << " An Enemy ambushes you! (Humanoid family)" << endl;
    //cout << " Traits: High Agility; average defenses." << endl;
    cout << "" << endl;
    cout << " What will you do?" << endl;
    cout << "------------------------------------------------------" << endl;
    cout << " 1) Fight" << endl;
    cout << " 2) Attempt to Flee (Agility check)" << endl;
    cout << " 3) Use Item" << endl;
    cout << "------------------------------------------------------" << endl;
    cout << " Input: ";
    cin >> wait;
    
    if(wait == '2'){
        int rC = (rand() % 100) + 1; // 1 - 100
        rC += playerSSIn.getAgility();
        if(rC >= 50){
            cout << "------------------------------------------------------" << endl;
            cout << "You were able to flee Let's go" << endl;
            cout << "------------------------------------------------------" << endl;
            cout << " 0) Continue" << endl;
            cout << "------------------------------------------------------" << endl;
            cout << " Input: ";
            cin >> wait;
            return;
        }
        

    }else if(wait == '3'){
        cout << "------------------------------------------------------" << endl;
        cout << " 3) Use Item Screen In progress" << endl;
        cout << "------------------------------------------------------" << endl;
        cout << " 0) Continue" << endl;
        cout << "------------------------------------------------------" << endl;
        cout << " Input: ";
        //ask about how items work
        cin >> wait;

    }
    //CharacterStats zombieStats = makeZombieBaseStats();
    vector<int> humaniodGrowthRate(29, 1);
    //vector<int> zombieGrowthRate(29, 1);
    CharacterStats humaniodOneStats = makeHumaniodBaseStats();
    CharacterStats humaniodTwoStats = makeHumaniodBaseStats();
    CharacterStats humaniodThreeStats = makeHumaniodBaseStats();

    
    // makes up vigor
    humaniodOneStats.setStrength(2 + (rand() % 4));
    humaniodOneStats.setStamina(6 + (rand() % 4));
    // makes up physDef
    humaniodOneStats.setPierceResistance(4 + (rand() % 4));
    humaniodOneStats.setBluntResistance(5 + (rand() % 4));
    humaniodOneStats.setSlashResistance(3 + (rand() % 4));
    // makes up magPow
    humaniodOneStats.setFireAffinity(0 + (rand() % 4));
    humaniodOneStats.setEarthAffinity(4 + (rand() % 4));
    humaniodOneStats.setWaterAffinity(2 + (rand() % 4));
    humaniodOneStats.setWindAffinity(4 + (rand() % 4));
    humaniodOneStats.setLightningAffinity(0 + (rand() % 4));
    // makes up magDef
    humaniodOneStats.setFireResistance(2 + (rand() % 4));
    humaniodOneStats.setEarthResistance(5 + (rand() % 4));
    humaniodOneStats.setWaterResistance(3 + (rand() % 4));
    humaniodOneStats.setWindResistance(3 + (rand() % 4));
    humaniodOneStats.setLightningResistance(2 + (rand() % 4));
    // makes up immunity
    humaniodOneStats.setPoisonResistance(4 + (rand() % 4));
    humaniodOneStats.setParalysisResistance(4 + (rand() % 4));
    humaniodOneStats.setSleepResistance(0 + (rand() % 4));
    humaniodOneStats.setStatResistance(0 + (rand() % 4));
    // makes up agility
    humaniodOneStats.setDexterity(6 + (rand() % 4));
    humaniodOneStats.setSpeed(1 + (rand() % 4));

    humaniodOneStats.setMaxHealth(3 + (rand() % 4));
    humaniodOneStats.setCurrHealth(humaniodOneStats.getMaxHealth());
    humaniodOneStats.setVigor(humaniodOneStats.getStrength() + humaniodOneStats.getStamina());
    humaniodOneStats.setPhysicalDef(humaniodOneStats.getPierceResistance() + humaniodOneStats.getBluntResistance() + humaniodOneStats.getSlashResistance());
    humaniodOneStats.setMagicalPower(humaniodOneStats.getFireAffinity() + humaniodOneStats.getEarthAffinity()  + humaniodOneStats.getWaterAffinity()  + humaniodOneStats.getWindAffinity() + humaniodOneStats.getLightningAffinity() );
    humaniodOneStats.setMagicalDef(humaniodOneStats.getFireResistance() + humaniodOneStats.getEarthResistance()  + humaniodOneStats.getWaterResistance()  + humaniodOneStats.getWindResistance() + humaniodOneStats.getLightningResistance());
    humaniodOneStats.setImmunity(humaniodOneStats.getPoisonResistance() + humaniodOneStats.getParalysisResistance()  + humaniodOneStats.getSleepResistance()  + humaniodOneStats.getStatResistance());
    humaniodOneStats.setAgility(humaniodOneStats.getDexterity() + humaniodOneStats.getSpeed() );
    

    //Human2

    // makes up vigor
    humaniodTwoStats.setStrength(2 + (rand() % 4));
    humaniodTwoStats.setStamina(6 + (rand() % 4));
    // makes up physDef
    humaniodTwoStats.setPierceResistance(4 + (rand() % 4));
    humaniodTwoStats.setBluntResistance(5 + (rand() % 4));
    humaniodTwoStats.setSlashResistance(3 + (rand() % 4));
    // makes up magPow
    humaniodTwoStats.setFireAffinity(0 + (rand() % 4));
    humaniodTwoStats.setEarthAffinity(4 + (rand() % 4));
    humaniodTwoStats.setWaterAffinity(2 + (rand() % 4));
    humaniodTwoStats.setWindAffinity(4 + (rand() % 4));
    humaniodTwoStats.setLightningAffinity(0 + (rand() % 4));
    // makes up magDef
    humaniodTwoStats.setFireResistance(2 + (rand() % 4));
    humaniodTwoStats.setEarthResistance(5 + (rand() % 4));
    humaniodTwoStats.setWaterResistance(3 + (rand() % 4));
    humaniodTwoStats.setWindResistance(3 + (rand() % 4));
    humaniodTwoStats.setLightningResistance(2 + (rand() % 4));
    // makes up immunity
    humaniodTwoStats.setPoisonResistance(4 + (rand() % 4));
    humaniodTwoStats.setParalysisResistance(4 + (rand() % 4));
    humaniodTwoStats.setSleepResistance(0 + (rand() % 4));
    humaniodTwoStats.setStatResistance(0 + (rand() % 4));
    // makes up agility
    humaniodTwoStats.setDexterity(6 + (rand() % 4));
    humaniodTwoStats.setSpeed(1 + (rand() % 4));

    humaniodTwoStats.setMaxHealth(3 + (rand() % 4));
    humaniodTwoStats.setCurrHealth(humaniodTwoStats.getMaxHealth());
    humaniodTwoStats.setVigor(humaniodTwoStats.getStrength() + humaniodTwoStats.getStamina());
    humaniodTwoStats.setPhysicalDef(humaniodTwoStats.getPierceResistance() + humaniodTwoStats.getBluntResistance() + humaniodTwoStats.getSlashResistance());
    humaniodTwoStats.setMagicalPower(humaniodTwoStats.getFireAffinity() + humaniodTwoStats.getEarthAffinity()  + humaniodTwoStats.getWaterAffinity()  + humaniodTwoStats.getWindAffinity() + humaniodTwoStats.getLightningAffinity() );
    humaniodTwoStats.setMagicalDef(humaniodTwoStats.getFireResistance() + humaniodTwoStats.getEarthResistance()  + humaniodTwoStats.getWaterResistance()  + humaniodTwoStats.getWindResistance() + humaniodTwoStats.getLightningResistance());
    humaniodTwoStats.setImmunity(humaniodTwoStats.getPoisonResistance() + humaniodTwoStats.getParalysisResistance()  + humaniodTwoStats.getSleepResistance()  + humaniodTwoStats.getStatResistance());
    humaniodTwoStats.setAgility(humaniodTwoStats.getDexterity() + humaniodTwoStats.getSpeed() );

    //Human3

    // makes up vigor
    humaniodThreeStats.setStrength(2 + (rand() % 4));
    humaniodThreeStats.setStamina(6 + (rand() % 4));
    // makes up physDef
    humaniodThreeStats.setPierceResistance(4 + (rand() % 4));
    humaniodThreeStats.setBluntResistance(5 + (rand() % 4));
    humaniodThreeStats.setSlashResistance(3 + (rand() % 4));
    // makes up magPow
    humaniodThreeStats.setFireAffinity(0 + (rand() % 4));
    humaniodThreeStats.setEarthAffinity(4 + (rand() % 4));
    humaniodThreeStats.setWaterAffinity(2 + (rand() % 4));
    humaniodThreeStats.setWindAffinity(4 + (rand() % 4));
    humaniodThreeStats.setLightningAffinity(0 + (rand() % 4));
    // makes up magDef
    humaniodThreeStats.setFireResistance(2 + (rand() % 4));
    humaniodThreeStats.setEarthResistance(5 + (rand() % 4));
    humaniodThreeStats.setWaterResistance(3 + (rand() % 4));
    humaniodThreeStats.setWindResistance(3 + (rand() % 4));
    humaniodThreeStats.setLightningResistance(2 + (rand() % 4));
    // makes up immunity
    humaniodThreeStats.setPoisonResistance(4 + (rand() % 4));
    humaniodThreeStats.setParalysisResistance(4 + (rand() % 4));
    humaniodThreeStats.setSleepResistance(0 + (rand() % 4));
    humaniodThreeStats.setStatResistance(0 + (rand() % 4));
    // makes up agility
    humaniodThreeStats.setDexterity(6 + (rand() % 4));
    humaniodThreeStats.setSpeed(1 + (rand() % 4));

    humaniodThreeStats.setMaxHealth(3 + (rand() % 4));
    humaniodThreeStats.setCurrHealth(humaniodThreeStats.getMaxHealth());
    humaniodThreeStats.setVigor(humaniodThreeStats.getStrength() + humaniodThreeStats.getStamina());
    humaniodThreeStats.setPhysicalDef(humaniodThreeStats.getPierceResistance() + humaniodThreeStats.getBluntResistance() + humaniodThreeStats.getSlashResistance());
    humaniodThreeStats.setMagicalPower(humaniodThreeStats.getFireAffinity() + humaniodThreeStats.getEarthAffinity()  + humaniodThreeStats.getWaterAffinity()  + humaniodThreeStats.getWindAffinity() + humaniodThreeStats.getLightningAffinity() );
    humaniodThreeStats.setMagicalDef(humaniodThreeStats.getFireResistance() + humaniodThreeStats.getEarthResistance()  + humaniodThreeStats.getWaterResistance()  + humaniodThreeStats.getWindResistance() + humaniodThreeStats.getLightningResistance());
    humaniodThreeStats.setImmunity(humaniodThreeStats.getPoisonResistance() + humaniodThreeStats.getParalysisResistance()  + humaniodThreeStats.getSleepResistance()  + humaniodThreeStats.getStatResistance());
    humaniodThreeStats.setAgility(humaniodThreeStats.getDexterity() + humaniodThreeStats.getSpeed() );

    //Create an if statement to channge enemy type to 
    
    Enemy e1 = Enemy("Humanoid", 100, "Goblin", false, false, 3, humaniodGrowthRate, humaniodOneStats);
    Enemy e2 = Enemy("Humanoid", 100, "Goblin", false, false, 3, humaniodGrowthRate, humaniodTwoStats);
    Enemy e3 = Enemy("Humanoid", 100, "Goblin", false, false, 3, humaniodGrowthRate, humaniodThreeStats);

    int numEnemies = rand() % 5 + 1;
    vector<Enemy*> encounter;
    if(numEnemies == 1 || numEnemies == 2 || numEnemies == 3){
        encounter.push_back(&e1);
    }else if(numEnemies == 4) {
        encounter.push_back(&e1);
        encounter.push_back(&e2);
    //encounter.push_back(&e3);
    }else if(numEnemies == 5){
        encounter.push_back(&e1);
        encounter.push_back(&e2);
        encounter.push_back(&e3);
    }
    CombatSystem simulation = CombatSystem(encounter, &playerIn);

    if(numEnemies == 1 || numEnemies == 2 || numEnemies == 3){
        cout << "enemy One speed " << e1.getEnemyStats().speed << endl;
    }else if(numEnemies == 4) {
        cout << "enemy One speed " << e1.getEnemyStats().speed << endl;
        cout << "enemy Two speed " << e2.getEnemyStats().speed << endl;
    //encounter.push_back(&e3);
    }else if(numEnemies == 5){
        cout << "enemy One speed " << e1.getEnemyStats().speed << endl;
        cout << "enemy Two speed " << e2.getEnemyStats().speed << endl;
        cout << "enemy Three speed " << e3.getEnemyStats().speed << endl;
    }
    cout << "player speed " << playerIn.getPlayerStats().speed << endl;

    simulation.startCombat();
    if(playerIn.getPlayerStats().currHealth <= 0){
        cout << "Game Over" << endl;
        exit(0);
    }
}


void screenImp(Dungeon& dungeonIn, int colIn, int rowIn, CharacterStats& playerStatIn, Player& playerIn){
    FloorTile* tile = dungeonIn.getCurrentFloor().getTileAt(rowIn, colIn);
    char currSymbol = tile->getSymbol();
    char wait;
    if(currSymbol == 'T'){
        //cout << "Trap Tile" << endl;
        trapScreen(playerStatIn);
    }
    else if(currSymbol == 'X'){
        //cout << "Enemy Tile" << endl;
        battleEncScr(playerStatIn, playerIn);
        //nOW IMPLEMENT A battle scene here 

        
    }
    else if(currSymbol == 'M'){
        char wait;
        cout << "------------------------------------------------------" << endl;
        cout << " 0) Continue" << endl;
        cout << "------------------------------------------------------" << endl;
        cout << " Input: ";
        cin >> wait;
}
    else if(currSymbol == 'N'){
        brock();
    }
    else if(currSymbol == 'B'){
        cout << "PortalTile" << endl;
        cout << "------------------------------------------------------" << endl;
        cout << " 0) Continue" << endl;
        cout << "------------------------------------------------------" << endl;
        cout << " Input: ";
        cin >> wait;
        if(!dungeonIn.isLastFloor()){
            cout << "go to next floor" << endl;
            dungeonIn.goToNextFloor();
        }else{
            // go to win screen
            cout << "Last Floor" << endl;
        }
    }
    else if(currSymbol == 'O'){
        //emptyTile
        cout << "------------------------------------------------------" << endl;
        cout << "You Just found a whole lot of nothing." << endl;
        cout << "Hint: get better at the game" << endl;
        cout << "------------------------------------------------------" << endl;
        cout << " 0) Continue" << endl;
        cout << "------------------------------------------------------" << endl;
        cout << " Input: ";
        cin >> wait;
    }
    else{
         cout << "------------------------------------------------------" << endl;
        cout << "You Just found a whole lot of nothing." << endl;
        cout << "Hint: get better at the game" << endl;
        cout << "------------------------------------------------------" << endl;
        cout << " 0) Continue" << endl;
        cout << "------------------------------------------------------" << endl;
        cout << " Input: ";
        cin >> wait;
    }
    

}



int main() {

//Welcome Screen Text
    srand(time(0));
    int begin = 1;
    int classSchoolDone = 1;
    int userInput;
    int classChoice;
    int schoolChoice;
    //Player player = Player();
   
    CharacterStats playerStatStruct = makePlayerBaseStats();
    
    Inventory playerInventory(10);
    vector<int> playerGrowthRate(29, 1);
    Player player = Player(0, 0, 1, 0, "Swordsman", "Swift Sword", playerGrowthRate, "The Player", 0, playerInventory, 0, playerStatStruct);
    player.getInventory().setAccessoriesSize(10);
    player.getInventory().setItemsSize(10);
    
    
    
    //Player player;
    player.setClass("Null");
    player.setClassSchool("Null");

    player.setLevel(1);
    player.setEXP(0);
    player.setEXPToNextLevel(100); // adjust later if needed
        
    do{
    cout << "------------------------------------------------------" << endl;
    cout << "Welcome to Dungeon Soul." << endl << endl;

    cout << "Enter 0 to begin your journey." << endl << endl;
 
    cout << "How to play (summary): " << endl;
    cout <<" - Turn-based battles; explore floors to reach the throne room. " << endl;
    cout <<" - Classes + Schools define your style (physical, magic, stealth…). " << endl;
    cout <<" - Manage stats, resistances, and items; prepare for bosses. " << endl << endl;
 
    cout << "Press [1] for full “How to Play” or choose another option below. " << endl;
    cout << "------------------------------------------------------" << endl;
    cout << " 0) Begin " << endl;
    cout << " 1) How to Play (detailed) " << endl;
    cout << " 2) Lore (prologue) " << endl;
    cout << " 3) Quit " << endl;
    cout << "------------------------------------------------------" << endl;
    cout << " Input: ";
    cin >> userInput;
    if(userInput == 0){
        do{
            classSchoolDone = 1;
            cout << "------------------------------------------------------" << endl;
            cout << " Choose Your Character" << endl;
            cout << endl;
            cout << " Select your Class:" << endl;
            cout << " 1) Swordsman - Strong single hits; balanced gear." << endl;
            cout << " 2) Mage      - Elemental casting; varied resistances." << endl;
            cout << " 3) Assassin  - Speed, crits, and status focus." << endl;
            cout << " 4) Tank      - High defenses, frontline control." << endl;
            cout << endl;
            cout << " (You will pick a School next.)" << endl;
            cout << "------------------------------------------------------" << endl;
            cout << " 0) Back" << endl;
            cout << "------------------------------------------------------" << endl;
            cout << " Input: ";
            cin >> classChoice;
            if(classChoice == 0){
                classSchoolDone = 0;
            }
            else if(classChoice == 1){
                player.setClass("Swordsman");
                cout << "------------------------------------------------------" << endl;
                cout << " 1) School of Strength - Big single-hit damage (high Vigor)." << endl;
                cout << " 2) School of Agility  - Multi-hit strings (high Agility)." << endl;
                cout << " 3) School of Balance  - Mix of power and speed." << endl;
                cout << "------------------------------------------------------" << endl;
                cout << " 0) Back" << endl;
                cout << "------------------------------------------------------" << endl;
                cout << " Input: ";
                cin >> schoolChoice;
                if(schoolChoice == 0){

                }
                else if(schoolChoice == 1){
                    //Player.setSchool("Strength");
                    player.setClassSchool("Strength");
                    classSchoolDone = 0;
                    
                }
                else if(schoolChoice == 2){
                    //Player.setSchool("Agility");
                    player.setClassSchool("Agility");
                    classSchoolDone = 0;
                }
                else if(schoolChoice == 3){
                    //Player.setSchool("Balance");
                    player.setClassSchool("Balance");
                    classSchoolDone = 0;
                }
            }
            else if(classChoice == 2){
                //Player.setClass("Mage");
                player.setClass("Mage");
                cout << "------------------------------------------------------" << endl;
                cout << " 1) Red & Purple  - Fire + Lightning." << endl;
                cout << " 2) Blue & Brown  - Water + Earth." << endl;
                cout << " 3) Change        - Wind + status/healing." << endl;
                cout << "------------------------------------------------------" << endl;
                cout << " 0) Back" << endl;
                cout << "------------------------------------------------------" << endl;
                cout << " Input: ";
                cin >> schoolChoice;
                if(schoolChoice == 0){

                }
                else if(schoolChoice == 1){
                    //Player.setSchool("redAndPurple");
                    player.setClassSchool("redAndPurple");
                    classSchoolDone = 0;
                    
                }
                else if(schoolChoice == 2){
                    //Player.setSchool("blueAndBrown");
                    player.setClassSchool("blueAndBrown");
                    classSchoolDone = 0;
                }
                else if(schoolChoice == 3){
                    //Player.setSchool("change");
                    player.setClassSchool("change");
                    classSchoolDone = 0;
                }
            }
            else if(classChoice == 3){
                //Player.setClass("Assassin");
                player.setClass("Assassin");
                cout << "------------------------------------------------------" << endl;
                cout << " 1) Unseen   - Extreme speed, early turn order." << endl;
                cout << " 2) Unwanted - Status application specialist." << endl;
                cout << " 3) Hatred   - High Dex: crit and dodge focus." << endl;
                cout << "------------------------------------------------------" << endl;
                cout << " 0) Back" << endl;
                cout << "------------------------------------------------------" << endl;
                cout << " Input: ";
                cin >> schoolChoice;
                if(schoolChoice == 0){

                }
                else if(schoolChoice == 1){
                    //Player.setSchool("Unseen");
                    player.setClassSchool("Unseen");
                    classSchoolDone = 0;
                    
                }
                else if(schoolChoice == 2){
                    //Player.setSchool("Unwanted");
                    player.setClassSchool("Unwanted");
                    classSchoolDone = 0;
                }
                else if(schoolChoice == 3){
                    //Player.setSchool("Hatred");
                    player.setClassSchool("Hatred");
                    classSchoolDone = 0;
                }
            }
            else if(classChoice == 4){
                //Player.setClass("Tank");
                player.setClass("Tank");
                cout << "------------------------------------------------------" << endl;
                cout << " 1) Wall      - Physical defense specialist." << endl;
                cout << " 2) Mysteries - Elemental defense specialist." << endl;
                cout << " 3) Protector - Balanced defenses." << endl;
                cout << "------------------------------------------------------" << endl;
                cout << " 0) Back" << endl;
                cout << "------------------------------------------------------" << endl;
                cout << " Input: ";
                cin >> schoolChoice;
                if(schoolChoice == 0){
                    
                }
                else if(schoolChoice == 1){
                    //Player.setSchool("Wall");
                    player.setClassSchool("Wall");
                    classSchoolDone = 0;
                    
                }
                else if(schoolChoice == 2){
                    //Player.setSchool("Mysteries");
                    player.setClassSchool("Mysteries");
                    classSchoolDone = 0;
                }
                else if(schoolChoice == 3){
                    //Player.setSchool("Protector");
                    player.setClassSchool("Protector");
                    classSchoolDone = 0;
                }
            }else{
                cout << "invalid input" << endl;
            }


        }while(classSchoolDone != 0);
        //Have the confirm screen here / or go back
        //cout << "test / complete" << endl;
        cout << "------------------------------------------------------" << endl;
        cout << " Confirm Entry to the Dungeon" << endl;
        cout << "------------------------------------------------------" << endl;
        cout << " You have chosen:" << endl;
        cout << "   Class : " << player.getClass() << endl;
        cout << "   School: " << player.getClassSchool() << endl;
        cout << endl;
        cout << " Enter the dungeon?" << endl;
        cout << "------------------------------------------------------" << endl;
        cout << " 0) Yes, begin Floor 1" << endl;
        cout << " 1) No, change my choices" << endl;
        cout << "------------------------------------------------------" << endl;
        cout << " Input: ";
        cin >> begin;
    
    }
    else if(userInput == 1){
        cout << "------------------------------------------------------" << endl;
        cout << " How to Play (Detailed)" << endl;
        cout << " - Stats: Health, Physical Def, Vigor, Magical Def, Magic Power," << endl;
        cout << "   Immunity, Agility." << endl;
        cout << " - Specific stats feed main stats (e.g., Strength+Stamina = Vigor)." << endl;
        cout << " - Damage = Base + Modifiers − Resistances." << endl;
        cout << " - Crits: chance from Dexterity; crit doubles post-calc damage." << endl;
        cout << " - Dodge: Full (Dex+Speed) small cap; Partial reduces damage by 20%." << endl;
        cout << " - Status (Poison/Paralysis/Sleep/Stat↓) and healing are fixed power." << endl;
        cout << " - Movement: choose directions; reach portals; fight bosses." << endl;
        cout << " - Inventory: limited slots; equip armor/weapons/accessory(ies)." << endl;
        cout << "" << endl;
        cout << " Tip: Schools specialize your tools (e.g., fire/lightning vs water…)." << endl;
        cout << "------------------------------------------------------" << endl;
        cout << " 0) Back to Start" << endl;
        cout << "" << endl;
        cout << "------------------------------------------------------" << endl;
        cout << " Input: ";
        cin >> userInput;
        if(userInput == 0){

        }else{
            cout << "Doesn't Matter We are still going back HAHHAHA" << endl;
        }
    }
    else if(userInput == 2){
        cout << "------------------------------------------------------" << endl;
        cout << "Lore (Prologue)" << endl;
        cout << " [Story text… paginated if long.]" << endl;
        cout << "" << endl;
        cout << " “Five floors divide the path to the throne. Families rival, yet all" << endl;
        cout << " will heed the King’s call…”" << endl;
        cout << "" << endl;
        cout << "------------------------------------------------------" << endl;
        cout << " 0) Back to Start" << endl;
        cout << "" << endl;
        cout << "------------------------------------------------------" << endl;
        cout << " Input: ";
        cin >> userInput;
        if(userInput == 0){

        }else{
            cout << "Doesn't Matter We are still going back HAHHAHA" << endl;
        }
    }
    else if(userInput == 3){
        return 0;
        begin = 0;
    }else{
        cout << "invalid input" << endl;
        
    }
    } while(begin != 0);
    cout << endl;
    
    //Here we are going to do a bunch of if else's to set the stats of the user
    
    //Player Base stats without school input and class input
        /*
        playerStatStruct.setMaxHealth(5);
        playerStatStruct.setCurrHealth(5);

        playerStatStruct.setStrength(4);
        playerStatStruct.setStamina(5);

        playerStatStruct.setPierceResistance(3);
        playerStatStruct.setBluntResistance(3);
        playerStatStruct.setSlashResistance(3);

        playerStatStruct.setFireResistance(3);
        playerStatStruct.setEarthResistance(5);
        playerStatStruct.setWaterResistance(3);
        playerStatStruct.setWindResistance(3);
        playerStatStruct.setLightningResistance(2);

        playerStatStruct.setFireAffinity(0);
        playerStatStruct.setEarthAffinity(0);
        playerStatStruct.setWaterAffinity(0);
        playerStatStruct.setWindAffinity(0);
        playerStatStruct.setLightningAffinity(0);

        playerStatStruct.setPoisonResistance(3);
        playerStatStruct.setSleepResistance(3);
        playerStatStruct.setParalysisResistance(3);
        playerStatStruct.setStatResistance(3);

        playerStatStruct.setMagicalPower(3);
        playerStatStruct.setMagicalDef(3);
        playerStatStruct.setImmunity(3);
        playerStatStruct.setAgility(3);
        playerStatStruct.setDexterity(3);
        playerStatStruct.setSpeed(3);
*/

    if(player.getClass() == "Swordsman"){
        if(player.getClassSchool() == "Strength"){
            // +15: 2 HP, 5 STR, 2 STA, 2 pierce, 2 blunt, 2 slash
            playerStatStruct.setMaxHealth(playerStatStruct.getMaxHealth() + 2);
            playerStatStruct.setCurrHealth(playerStatStruct.getMaxHealth());

            playerStatStruct.setStrength(playerStatStruct.getStrength() + 5);
            playerStatStruct.setStamina(playerStatStruct.getStamina() + 2);

            playerStatStruct.setPierceResistance(playerStatStruct.getPierceResistance() + 2);
            playerStatStruct.setBluntResistance(playerStatStruct.getBluntResistance() + 2);
            playerStatStruct.setSlashResistance(playerStatStruct.getSlashResistance() + 2);


        }
        else if(player.getClassSchool() == "Agility"){
            // +15: 1 HP, 1 STR, 3 STA, 3 SPD, 3 DEX, 2 slash, 2 wind
            playerStatStruct.setMaxHealth(playerStatStruct.getMaxHealth() + 1);
            playerStatStruct.setCurrHealth(playerStatStruct.getMaxHealth());

            playerStatStruct.setStrength(playerStatStruct.getStrength() + 1);
            playerStatStruct.setStamina(playerStatStruct.getStamina() + 3);

            playerStatStruct.setSpeed(playerStatStruct.getSpeed() + 3);
            playerStatStruct.setDexterity(playerStatStruct.getDexterity() + 3);

            playerStatStruct.setSlashResistance(playerStatStruct.getSlashResistance() + 2);
            playerStatStruct.setWindResistance(playerStatStruct.getWindResistance() + 2);   
        }
        else if(player.getClassSchool() == "Balance"){
            // +15: 1 HP, 2 STR, 2 STA, +1 to each phys resist (3), +2 DEX, +2 SPD, +2 earth, +1 water
            playerStatStruct.setMaxHealth(playerStatStruct.getMaxHealth() + 1);
            playerStatStruct.setCurrHealth(playerStatStruct.getMaxHealth());

            playerStatStruct.setStrength(playerStatStruct.getStrength() + 2);
            playerStatStruct.setStamina(playerStatStruct.getStamina() + 2);

            playerStatStruct.setPierceResistance(playerStatStruct.getPierceResistance() + 1);
            playerStatStruct.setBluntResistance(playerStatStruct.getBluntResistance() + 1);
            playerStatStruct.setSlashResistance(playerStatStruct.getSlashResistance() + 1);

            playerStatStruct.setSpeed(playerStatStruct.getSpeed() + 2);
            playerStatStruct.setDexterity(playerStatStruct.getDexterity() + 2);

            playerStatStruct.setEarthResistance(playerStatStruct.getEarthResistance() + 2);
            playerStatStruct.setWaterResistance(playerStatStruct.getWaterResistance() + 1);   
        }
    }else if(player.getClass() == "Mage"){
        if(player.getClassSchool() == "redAndPurple"){
            // +15: 4 FireAff, 4 LightningAff, 2 FireRes, 2 LightningRes, 2 SPD, 1 DEX
            playerStatStruct.setFireAffinity(playerStatStruct.getFireAffinity() + 4);
            playerStatStruct.setLightningAffinity(playerStatStruct.getLightningAffinity() + 4);

            playerStatStruct.setFireResistance(playerStatStruct.getFireResistance() + 2);
            playerStatStruct.setLightningResistance(playerStatStruct.getLightningResistance() + 2);   

            playerStatStruct.setSpeed(playerStatStruct.getSpeed() + 2);
            playerStatStruct.setDexterity(playerStatStruct.getDexterity() + 1);
        }
        else if(player.getClassSchool() == "blueAndBrown"){
            // +15: 4 EarthAff, 4 WaterAff, 2 EarthRes, 2 WaterRes, 2 STA, 1 HP

            playerStatStruct.setEarthAffinity(playerStatStruct.getEarthAffinity() + 4);
            playerStatStruct.setWaterAffinity(playerStatStruct.getWaterAffinity() + 4);

            playerStatStruct.setEarthResistance(playerStatStruct.getEarthResistance() + 2);
            playerStatStruct.setWaterResistance(playerStatStruct.getWaterResistance() + 2);   

            playerStatStruct.setMaxHealth(playerStatStruct.getMaxHealth() + 1);
            playerStatStruct.setCurrHealth(playerStatStruct.getMaxHealth());

            
            playerStatStruct.setStamina(playerStatStruct.getStamina() + 2);

        }
        else if(player.getClassSchool() == "change"){
            // +15: 4 WindAff, 3 WindRes, 2 PoisonRes  2 DEX, 2 SPD, 2 STA, 

            playerStatStruct.setWindAffinity(playerStatStruct.getWindAffinity() + 4);

            playerStatStruct.setWindResistance(playerStatStruct.getWindResistance() + 3);
            playerStatStruct.setPoisonResistance(playerStatStruct.getPoisonResistance() + 2);   

            playerStatStruct.setDexterity(playerStatStruct.getDexterity() + 2);
            playerStatStruct.setSpeed(playerStatStruct.getSpeed() + 2);    
            playerStatStruct.setStamina(playerStatStruct.getStamina() + 2);
        }
        


    }else if(player.getClass() == "Assassin"){
        if(player.getClassSchool() == "Unseen"){
            // +15: 1 STR, 3 STA, 4 SPD, 4 DEX, 3 PierceRe
            
            

             playerStatStruct.setStrength(playerStatStruct.getStrength() + 1);
             playerStatStruct.setStamina(playerStatStruct.getStamina() + 3);
             playerStatStruct.setSpeed(playerStatStruct.getSpeed() + 4);  
             playerStatStruct.setDexterity(playerStatStruct.getDexterity() + 4);
             playerStatStruct.setPierceResistance(playerStatStruct.getPierceResistance() + 3);




        }
        else if(player.getClassSchool() == "Unwanted"){
            // +15: 2 STA, 3 PoisonRes, 3 SleepRes, 3 ParalysisRes, 2 StatRes, 2 DEX

            playerStatStruct.setStamina(playerStatStruct.getStamina() + 2);
            playerStatStruct.setPoisonResistance(playerStatStruct.getPoisonResistance() + 3);
            playerStatStruct.setSleepResistance(playerStatStruct.getSleepResistance() + 3);
            playerStatStruct.setParalysisResistance(playerStatStruct.getParalysisResistance() + 3);
            playerStatStruct.setStatResistance(playerStatStruct.getStatResistance() + 2);
            playerStatStruct.setDexterity(playerStatStruct.getDexterity() + 2);

        }   
        else if(player.getClassSchool() == "Hatred"){
            // +15: 3 STR, 2 STA, 4 DEX, 3 SPD, 3 SlashRes
            playerStatStruct.setStrength(playerStatStruct.getStrength() + 3);
            playerStatStruct.setStamina(playerStatStruct.getStamina() + 2);
            playerStatStruct.setDexterity(playerStatStruct.getDexterity() + 4);
            playerStatStruct.setSpeed(playerStatStruct.getSpeed() + 3);  
            playerStatStruct.setSlashResistance(playerStatStruct.getSlashResistance() + 3);
           


        }




    }else if(player.getClass() == "Tank"){
        if(player.getClassSchool() == "Wall"){
            // +15: 4 HP, 3 STA, 2 STR, 2 pierce, 2 blunt, 2 slash
            playerStatStruct.setMaxHealth(playerStatStruct.getMaxHealth() + 4);
            playerStatStruct.setCurrHealth(playerStatStruct.getMaxHealth());

            playerStatStruct.setStrength(playerStatStruct.getStrength() + 2);
            playerStatStruct.setStamina(playerStatStruct.getStamina() + 3);

            playerStatStruct.setPierceResistance(playerStatStruct.getPierceResistance() + 2);
            playerStatStruct.setBluntResistance(playerStatStruct.getBluntResistance() + 2);
            playerStatStruct.setSlashResistance(playerStatStruct.getSlashResistance() + 2);
        }
        else if(player.getClassSchool() == "Mysteries"){
            // +15: 2 HP, 2 STA, 3 FireRes, 3 EarthRes, 3 WaterRes, 2 LightningRes
            playerStatStruct.setMaxHealth(playerStatStruct.getMaxHealth() + 2);
            playerStatStruct.setCurrHealth(playerStatStruct.getMaxHealth());

            playerStatStruct.setEarthResistance(playerStatStruct.getEarthResistance() + 3);
            playerStatStruct.setWaterResistance(playerStatStruct.getWaterResistance() + 3);   
            playerStatStruct.setFireResistance(playerStatStruct.getFireResistance() + 3);
            playerStatStruct.setLightningResistance(playerStatStruct.getLightningResistance() + 2);  

            playerStatStruct.setStamina(playerStatStruct.getStamina() + 2);
        }
        else if(player.getClassSchool() == "Protector"){
            // +15: 3 HP, 2 STR, 2 STA, 2 pierce, 2 slash, 2 earth, 2 water
            playerStatStruct.setMaxHealth(playerStatStruct.getMaxHealth() + 3);
            playerStatStruct.setCurrHealth(playerStatStruct.getMaxHealth());

            playerStatStruct.setStrength(playerStatStruct.getStrength() + 2);
            playerStatStruct.setStamina(playerStatStruct.getStamina() + 2);

            playerStatStruct.setPierceResistance(playerStatStruct.getPierceResistance() + 2);
            playerStatStruct.setSlashResistance(playerStatStruct.getSlashResistance() + 2);

            playerStatStruct.setWaterResistance(playerStatStruct.getWaterResistance() + 2);   
        }
    }
    //Make sure those combined stats are proper
        playerStatStruct.setVigor(playerStatStruct.getStrength() + playerStatStruct.getStamina());
        playerStatStruct.setPhysicalDef(playerStatStruct.getPierceResistance() + playerStatStruct.getBluntResistance() + playerStatStruct.getSlashResistance());
        int tempSum = playerStatStruct.getFireResistance() + playerStatStruct.getEarthResistance() + playerStatStruct.getWaterResistance() + playerStatStruct.getWindResistance() + playerStatStruct.getLightningResistance();
        playerStatStruct.setMagicalDef(tempSum / 5);
        tempSum = playerStatStruct.getPoisonResistance() + playerStatStruct.getSleepResistance() + playerStatStruct.getParalysisResistance() + playerStatStruct.getStatResistance();
        playerStatStruct.setImmunity(tempSum / 4);
        playerStatStruct.setAgility((playerStatStruct.getDexterity() + playerStatStruct.getSpeed() ) / 2);
        tempSum = playerStatStruct.getFireAffinity() + playerStatStruct.getEarthAffinity() + playerStatStruct.getWaterAffinity() + playerStatStruct.getWindAffinity() + playerStatStruct.getLightningAffinity();
        playerStatStruct.setMagicalPower(tempSum / 2);
    
        Armor helmStarter(Armor::ArmorType::HELM, {{"maxHealth", 1}}, "Starter Helmet", "Increases max health by 1.", 1);
        player.getInventory().addItem(&helmStarter);    
        player.equipArmor(&helmStarter);
        Armor chestStarter(Armor::ArmorType::CHEST, {{"maxHealth", 1}}, "Starter Chest", "Increases max health by 1.", 1);
        player.getInventory().addItem(&chestStarter);    
        player.equipArmor(&chestStarter);
        Armor legsStarter(Armor::ArmorType::LEGS, {{"maxHealth", 1}}, "Starter Leggins", "Increases max health by 1.", 1);
        player.getInventory().addItem(&legsStarter);    
        player.equipArmor(&legsStarter);
        Armor shoesStarter(Armor::ArmorType::SHOES, {{"maxHealth", 1}}, "Starter Boots", "Increases max health by 1.", 1);
        player.getInventory().addItem(&shoesStarter);    
        player.equipArmor(&shoesStarter);

        Armor helmSecret(Armor::ArmorType::HELM, {{"maxHealth", 15}, {"speed", 15}}, "Secret Super Helmet", "Increases max health by 15 and Speed by 15.", 1);
        player.getInventory().addItem(&helmSecret);    
        
       

    if(player.getClass() == "Swordsman"){

    }else if(player.getClass() == "Mage"){

    }else if(player.getClass() == "Assassin"){

    }else if(player.getClass() == "Tank"){

    }
    
    

    //Next screen View the Dungeon screen (in which the user can select where they want to go then do a do while loop to make sure we check to see if we had beaten the dungeon)

    bool dungeonWon = 0;
    
    Dungeon dungeon = Dungeon(5);
    dungeon.generateDungeon(9,9,player);
    //Inventory playerInventory = (3,3);
    
    char userInChar;
    
    //Goblin enemy stats
    /*
    CharacterStats goblinStats;
    goblinStats.setMaxHealth(8);
    goblinStats.setCurrHealth(8);
    goblinStats.setPhysicalDef(4);
    goblinStats.setVigor(4);
    goblinStats.setMagicalDef(3);
    goblinStats.setMagicalPower(2);
    goblinStats.setImmunity(2);
    goblinStats.setAgility(7);
    goblinStats.setStrength(5);
    goblinStats.setStamina(2);
    goblinStats.setSpeed(30);

    std::vector<int> goblinGrowth(29,0);
    Enemy goblin("Humanoid", 10, "Goblin", false, false, 1, goblinGrowth, goblinStats);
*/
    



    do{
        //dungeon.printFloor(player);
        cout << "------------------------------------------------------" << endl;
        cout << "Floor " << dungeon.getCurrentFloorIndex() << ": " << endl;
        cout << "" << endl;
        cout << " Mini-Map (9x13) — @=You, X=Battle, M=Mini-boss, B=Boss" << endl;
        cout << " O=Empty, N=NPC, T=Trap, #=Wall" << endl;
        cout << "" << endl;
        for(int i = 0; i < dungeon.getCurrentFloor().getHeight(); i++){
            if(i == 0){
                cout << "│   x→   0 ";
                for(int k = 1; k < dungeon.getCurrentFloor().getWidth(); k++){
                    cout << k << " ";
                }
                cout << endl << "│ y=0    ";
            }else{
                cout << endl << "│ y=" << i << "    ";
            }
            for(int j = 0; j < dungeon.getCurrentFloor().getWidth(); j++){
                if(player.getX() == j && player.getY() == i){
                    cout << "@ ";
                }else{
                    cout << dungeon.getCurrentFloor().getTileAt(i,j)->getSymbol() << " ";
                }
            }
        }
        cout << endl;
        cout << "" << endl;
        //cout << " Status: HP " << "" << " | Vigor " << "" << " | PhysDef " << 8 << " | MagDef " << " | Agility"  << "" << endl;
        //cout << "         Immunity "<< ""<< " | Magic " << "" << " | Inventory: " << "" << endl;
        cout << " ------------------------------------------------------" << endl;
        cout << " Movement:" << endl;
        cout << "  w) Up   s) Down   a) Left   d) Right" << endl;
        cout << "" << endl;
        cout << "  E) Open Inventory         Q) View Character            P) Pause/Save             L) Leave Game" << endl;
        cout << "------------------------------------------------------" << endl;
        cout << " Input: ";

        cin >> userInChar;
        userInChar = toupper(userInChar);
        if(userInChar == 'E'){
            //E) Open Inventory
            player.getInventory().printInventory();

           
            
            cin >> userInChar;
            if(userInChar == 'a'){
                //implement Use Item Screen
                string itemName;
                cout << "Select Item: " << endl;
                cin >> itemName;
                while (!player.getInventory().hasItem(itemName)) {
                cout << "You don't have this item" << endl;
                cout << "Select Item: " << endl;
                cin >> itemName;
            }
            player.useItem(player.getInventory().getItem(itemName));

            }else if(userInChar == 'b'){
                 //implement Use Equip/Unequip Armor Screen
                 cout << "Not avaliable Work in progress " << endl;
            }

        }else if(userInChar == 'Q'){
            //Q) View Character
            
            cout << "------------------------------------------------------" << endl;
            cout << " Character Sheet (Detailed)" << endl;
            cout << " Class/School: " << player.getClass() << "/" << player.getClassSchool() << " Level: " << player.getLevel() << endl;
            cout << " Main Stats:" << endl;
            cout << " - Health: " << playerStatStruct.getCurrHealth() << "/" << playerStatStruct.getMaxHealth() << endl;
            cout << " - Physical Def: " << playerStatStruct.getPhysicalDef() << " (Pierce " << playerStatStruct.getPierceResistance() << " | Blunt " << playerStatStruct.getBluntResistance()  << " | Slash " << playerStatStruct.getSlashResistance() << ")" << endl;
            cout << " - Vigor: " << playerStatStruct.getVigor() << " (Strength " << playerStatStruct.getStrength() << " | Stamina " << playerStatStruct.getStamina() << ")" << endl;
            cout << " - Magical Def: " << playerStatStruct.getMagicalDef() << " (Fire " << playerStatStruct.getFireResistance() << " | Water " << playerStatStruct.getWaterResistance() << " | Earth " << playerStatStruct.getEarthResistance() << " | Wind " << playerStatStruct.getWindResistance() << " | Lightning " << playerStatStruct.getLightningResistance() << ")"<< endl; 
            cout << " - Magical Power: " << playerStatStruct.getMagicalPower() << " (FireAff " << playerStatStruct.getFireAffinity() << " | WaterAff " << playerStatStruct.getWaterAffinity() << " | EarthAff " << playerStatStruct.getEarthAffinity() << " | WindAff " << playerStatStruct.getWindAffinity() << " | LightningAff " << playerStatStruct.getLightningAffinity() << ")"<< endl; 
            cout << " - Immunity: " << playerStatStruct.getImmunity() << " (Poison " << playerStatStruct.getPoisonResistance() << " | Paralysis " << playerStatStruct.getParalysisResistance() << " | Sleep " << playerStatStruct.getSleepResistance() << " | StatRes " << playerStatStruct.getStatResistance() << ")"<< endl;
            cout << " - Agility: " << playerStatStruct.getAgility() << " (Dex " << playerStatStruct.getDexterity() << " | Speed " << playerStatStruct.getSpeed() << ")" << endl;

            cout << " Crit chance = ceil(Dex/10)%" << endl;
            cout << " Full Dodge = ceil((Dex+Speed)/100)%" << endl;
            cout << " Partial Dodge = ceil((Dex + Speed/2)/10)%" << endl;
            cout << "" << endl;
            cout << "------------------------------------------------------" << endl;
            cout << " 0) Back" << endl;
            cout << "" << endl;
            cout << "------------------------------------------------------" << endl;
            cout << " Input: ";

            cin >> userInChar;
            

            


        }
        else if(userInChar == 'P'){
            //P) Pause/Save
            cout << "------------------------------------------------------" << endl;
            cout << "               Game Paused" << endl;
            cout << "   Enter Any Key to get back to the fun" << endl;
            cout << "------------------------------------------------------" << endl;
            cout << " Input: ";
            cin >> userInChar;

        }else if(userInChar == 'L'){
            dungeonWon = 1;
        }else if(userInChar == 'W'){
            if(dungeon.getCurrentFloor().isValidTile(player.getX(),player.getY() - 1)){
                if(dungeon.getCurrentFloor().getTileAt(player.getX(),player.getY() - 1)->isWalkable()){
                    player.setPosition(player.getX(),player.getY() - 1);


                    screenImp(dungeon, player.getX(), player.getY(), playerStatStruct, player);
                    //screenImp(dungeon, player.getX(), player.getY(), playerStatStruct, player);
                    if(dungeon.getCurrentFloor().getTileAt(player.getY(), player.getX())->getSymbol() != 'B'){
                    dungeon.getCurrentFloor().setTileEmpty(player.getX(),player.getY());
                    }
                }else{
                    cout << "Can't go there" << endl;
                }
            }else{
                cout << "Invalid Tile" << endl;
            }
        }else if(userInChar == 'A'){
            if(dungeon.getCurrentFloor().isValidTile(player.getX() - 1,player.getY())){
                if(dungeon.getCurrentFloor().getTileAt(player.getX() - 1,player.getY())->isWalkable()){
                    player.setPosition(player.getX() - 1,player.getY());

                    screenImp(dungeon, player.getX(), player.getY(), playerStatStruct, player);
                    //screenImp(dungeon, player.getX(), player.getY(), playerStatStruct, player);
                    if(dungeon.getCurrentFloor().getTileAt(player.getY(), player.getX())->getSymbol() != 'B'){
                    dungeon.getCurrentFloor().setTileEmpty(player.getX(),player.getY());
                    }
                }else{
                    cout << "Can't go there" << endl;
                }
            }else{
                cout << "Invalid Tile" << endl;
            }
        }else if(userInChar == 'S'){
            if(dungeon.getCurrentFloor().isValidTile(player.getX(),player.getY() + 1)){
                if(dungeon.getCurrentFloor().getTileAt(player.getX(),player.getY() + 1)->isWalkable()){
                    player.setPosition(player.getX(),player.getY() + 1);


                    screenImp(dungeon, player.getX(), player.getY(), playerStatStruct, player);
                    //screenImp(dungeon, player.getX(), player.getY(), playerStatStruct, player);
                    if(dungeon.getCurrentFloor().getTileAt(player.getY(), player.getX())->getSymbol() != 'B'){
                    dungeon.getCurrentFloor().setTileEmpty(player.getX(),player.getY());
                    }
                }else{
                    cout << "Can't go there" << endl;
                }
            }else{
                cout << "Invalid Tile" << endl;
            }
        }else if(userInChar == 'D'){
            if(dungeon.getCurrentFloor().isValidTile(player.getX() + 1,player.getY())){
                if(dungeon.getCurrentFloor().getTileAt(player.getX() + 1,player.getY())->isWalkable()){
                    player.setPosition(player.getX() + 1,player.getY());


                    screenImp(dungeon, player.getX(), player.getY(), playerStatStruct, player);
                    //screenImp(dungeon, player.getX(), player.getY(), playerStatStruct, player);

                    if(dungeon.getCurrentFloor().getTileAt(player.getY(), player.getX())->getSymbol() != 'B'){
                    dungeon.getCurrentFloor().setTileEmpty(player.getX(),player.getY());
                    }
                    
                }else{
                    cout << "Can't go there" << endl;
                }
            }else{
                cout << "Invalid Tile" << endl;
            }
        }else{
            cout << "Invalid Input" << endl;
        }
    }while(dungeonWon == 0);
    
//Need to figure out how to check to see if the userInput would result in which square



    /*
    //NOW WE WILL DO THE BEGIN GAME PART
    Player player = Player();
    Dungeon dungeon = Dungeon(1); // 1 floor for now
    dungeon.generateDungeon(3,3,player); // 3x3 for now
    //Assuming that minibosses are on treasure tiles and bosses are on portal tiles
    dungeon.printFloor(player);
    */

    return 0; 
}