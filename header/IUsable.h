#ifndef IUSABLE_H
#define IUSABLE_H
#include "player.h"

//interface
class IUsable {
public:
    virtual void use(Player* player) = 0;
};

#endif