#pragma once
#ifndef WALLNUT_H
#define WALLNUT_H
#include"Plants.h"
class Wallnut:public Plants{
protected:
public:
    Wallnut(int price = 0, Block *block = nullptr, int health = 0, float cooldownTime = 7.5, string path = "");
    ~Wallnut();
    void move();
    void CollisionControl(Zombie** zombie, int currentZombie);
    void Draw(RenderWindow& window);
};
#endif

