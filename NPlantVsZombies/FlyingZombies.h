#pragma once
#ifndef FLYINGZOMBIES_H
#define FLYINGZOMBIES_H
#include"Zombie.h"
class FlyingZombies: public Zombie{
protected:
public:
    FlyingZombies(string path , int x , int y, int noOfframes, int width, int length, int speed, int hits, int &score);
    ~FlyingZombies();
    void eat();
};
#endif

    