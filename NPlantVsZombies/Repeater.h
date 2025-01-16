#pragma once
#ifndef REPEATER_H
#define REPEATER_H
#include"Shooters.h"

class Repeater: public Shooters{
protected:
    Clock clocks[2];
    bool justMade;
public: 
    Repeater(int price = 0, Block* block = nullptr, int health = 0, float cooldownTime = 0, string path = "");
    ~Repeater();
    void shoot();
    virtual void CollisionControl(Zombie** zombie, int currentZombie);
    void Draw(RenderWindow& window);

    void serialize(ostream& file);
    void deserialize(istream& file);
};
#endif
