#pragma once
#ifndef FOOTBALL_H
#define FOOTBALL_H
#include"Zombie.h"
class FootballZombie: public Zombie{
protected:
bool headfallen;
    AnimateMySprite Headfall;
public:
    FootballZombie(string path, int x, int y , int noOfframes , int width , int length, int speed, int hits, int &score);
    ~FootballZombie();
    bool direction;
    void eat();
    void stopeat();
    void move();

};
#endif

