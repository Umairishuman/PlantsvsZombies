#pragma once
#ifndef LAWNMOWER_H
#define LAWNMOWER_H
#include"MySprite.h"
#include"Zombie.h"
class LawnMower{
protected:
    MySprite LawnMowerSprite;
    Clock clock;
    bool used;
    bool active;

    Sound soundMower;
    SoundBuffer bufferMower;

public:
    LawnMower(int x = 0, int y = 0, string path = "");
    ~LawnMower();

    void setActive(bool active);
    void setUsed(bool used);
    bool getActive();
    bool getUsed();

    void move();
    void CollisionControl(Zombie** zombie, int currentZombie);
    void Draw(RenderWindow& window);

    void serialize(ostream& file);
    void deserialize(istream& file);
};
#endif

