#pragma once
#ifndef SHOOTERS_H
#define SHOOTERS_H
#include"Bullet.h"
#include"Zombie.h"
#include"Plants.h"
class Shooters: public Plants{
protected:
    Bullet** bullet;
    Sound shootSound;
    SoundBuffer shootBuffer;
public:
    Shooters(int price = 0, Block* block = nullptr, int health = 0, float cooldownTime = 0, string path = "");
    ~Shooters();
    void setBullet(Bullet** bullet);
    Bullet** getBullet();
    bool shouldShoot;
    virtual bool CheckLane(Zombie** zombie, int currentZombies);
    virtual void CollisionControl(Zombie** zombie, int currentZombie) = 0;
    virtual void shoot() = 0;
    virtual void Draw(RenderWindow& window) = 0;

    virtual void serialize(ostream& file) = 0;
    virtual void deserialize(istream& file) = 0;
};
#endif

