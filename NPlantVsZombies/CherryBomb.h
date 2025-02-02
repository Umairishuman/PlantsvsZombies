#pragma once
#ifndef CHERRYBOMB_H
#define CHERRYBOMB_H
#include"Shooters.h"
class CherryBomb: public Plants{
protected:
    int blastRadius;
public:
    CherryBomb(int price = 0, Block* block = nullptr, int health = 0, float cooldownTime = 0, string path = "");
    ~CherryBomb();
    virtual void CollisionControl(Zombie** zombie, int currentZombie) ;
    void Draw(RenderWindow& window);
    Clock* blastClock;

    Sound soundBlast;
    SoundBuffer bufferBlast;
};
#endif

