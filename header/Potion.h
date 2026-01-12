#ifndef POTION_H
#define POTION_H

#include "IUsable.h"
#include "Item.hpp"

class Potion : public IUsable, public Item {
private:
    int healAmount;

public:
    Potion(int healAmount, int count);
    void use(Player* player) override;
    int getHealAmount() const;
};

#endif