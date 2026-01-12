#ifndef ACTOR_H
#define ACTOR_H

class Actor {  // Actor keeps track of where the character is and whether they are alive or not
    public:
        Actor();
        Actor(int, int);
        bool getIsAlive() const;
        int getX() const;
        int getY() const;
        void kill();
        void setPosition(int, int);
    protected:
        int x;
        int y;
        bool isAlive;
};

#endif