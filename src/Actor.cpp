#include "../header/Actor.h"

Actor::Actor(): x(0), y(0), isAlive(true) {}
Actor::Actor(int a, int b): x(a), y(b), isAlive(true) {}

bool Actor::getIsAlive() const {
    return isAlive;
}
int Actor::getX() const {
    return x;
}
int Actor::getY() const {
    return y;
}
void Actor::kill() {
    this->isAlive = false;
}
void Actor::setPosition(int x, int y) {
    this->x = x;
    this->y = y;
}
