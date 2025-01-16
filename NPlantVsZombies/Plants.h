#pragma once
#ifndef PLANT_H
#define PLANT_H
#include"Block.h"
#include"AnimatMySprite.h"
#include"Zombie.h"
class Plants{
protected:
    AnimateMySprite image;
    Block* block;
    int price;
    int health;
    Clock clock;
    bool killed;
    bool beingEaten;
    int type;
public:
    Plants(int price = 0, Block *block = nullptr, int health = 0, float cooldownTime = 7.5, string path = "");
    virtual ~Plants();

    void setPrice(int price);
    void setBlock(Block* block);
    void setHealth(int health);
    int getPrice();
    Coordinates getCoordinates();
    Block* getBlock();
    int getHealth();
    bool getKilled();

    virtual bool handleInput(Event e, RenderWindow& window);
    virtual void CollisionControl(Zombie** zombie, int currentZombie) = 0;
    void Kill();
    virtual void Draw(RenderWindow& window) = 0;

    virtual void serialize(ostream& file);
    virtual void deserialize(istream& file);
};

#endif

