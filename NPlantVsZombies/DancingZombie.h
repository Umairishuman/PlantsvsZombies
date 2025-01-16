#pragma once
#ifndef DANCINGZOMBIE_H
#define DANCINGZOMBIE_H
#include"Zombie.h"
class DancingZombie: public Zombie{
protected:
    Clock ZombieSummoning;
public:
    DancingZombie(string path, int, int y, int noOfframes, int width, int length, int speed, int hits, int &score);
    ~DancingZombie();

    void stopeat();
    bool summonZombies();
    void move();

};
#endif

