#pragma once
#ifndef SUNFLOWER_H
#define SUNFLOWER_H
#include"Sun.h"
#include"Plants.h"
class Sunflower: public Plants{
protected:
    Sun sun;
    Clock sunSpawnClock;
public:
    Sunflower(int price = 0, Block* block = nullptr, int health = 0, float cooldownTime = 0, string path = "");
    ~Sunflower();
    bool handleInput(Event e, RenderWindow& window);
    void CollisionControl(Zombie** zombie, int currentZombie);
    void Draw(RenderWindow& window);
    void serialize(ostream& file);
    void deserialize(istream& file);
};
#endif
