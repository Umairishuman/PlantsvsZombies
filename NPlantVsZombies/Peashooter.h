#pragma once
#ifndef PEASHOOTER_H
#define PEASHOOTER_H
#include"Shooters.h"
class Peashooter: public Shooters{
protected:
public:
    Peashooter(int price = 0, Block* block = nullptr, int health = 0, float cooldownTime = 0, string path = "");
    ~Peashooter();
    void shoot();
    int random;
    virtual void CollisionControl(Zombie** zombie, int currentZombie) ;
    void Draw(RenderWindow& window);

    void serialize(ostream& file);
    void deserialize(istream& file);
};
#endif

