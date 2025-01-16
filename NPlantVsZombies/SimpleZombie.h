#pragma once
#ifndef SIMPLEZOMBIE_H
#define SIMPLEZOMBIE_H
#include"Zombie.h"

class SimpleZombie: public Zombie{
protected:
public:
    SimpleZombie(string path, int x, int y, int noOfframes, int width, int length, int speed, int hits, int &score);
    ~SimpleZombie();
};
#endif

