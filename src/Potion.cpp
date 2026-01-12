#include "../header/Potion.h"
#include <iostream>
using namespace std;

Potion::Potion(int healAmount, int count) : Item("Potion", "Heals the player's health.", count){
    this->healAmount = healAmount;
}

void Potion::use(Player* player) {
    CharacterStats* playerStats = &(player->getPlayerStats());
    cout << "\nPlayer uses potion and heals for " << this->healAmount << " health...\n";

    int potentialHealAmount = playerStats->maxHealth - playerStats->currHealth;
    if (potentialHealAmount < this->healAmount) {
        playerStats->currHealth += potentialHealAmount;
    }
    else {
        playerStats->currHealth += this->healAmount;
    }

    this->setCount(this->getCount() - 1);
}

int Potion::getHealAmount() const {
    return this->healAmount;
}