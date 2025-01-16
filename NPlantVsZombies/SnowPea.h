#pragma once
#ifndef SNOWPEA_H
#define SNOWPEA_H
#include"Shooters.h"
class SnowPea: public Shooters{
protected:
public:
    SnowPea(int price = 0, Block* block = nullptr, int health = 0, float cooldownTime = 0, string path = "");
    ~SnowPea();
    void shoot();
    virtual void CollisionControl(Zombie** zombie, int currentZombie) ;
    void Draw(RenderWindow& window);

    void serialize(ostream& file);
    void deserialize(istream& file);
};
#endif
