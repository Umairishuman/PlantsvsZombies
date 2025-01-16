#pragma once
#ifndef BULLET_H
#define BULLET_H
#include"MySprite.h"
#include"Coordinates.h"
#include"Zombie.h"
class Bullet{
protected:
    Coordinates shooterPoint;
    MySprite bullet;
    Clock bulletClock;
    bool exists;
    bool isSnow;

    Sound hitSound;
    SoundBuffer hitBuffer;

public:
    Bullet(string path = "", int x = 0, int y = 0);
    void setCoordinates(int x, int y);
    void setExists(bool exists);
    Coordinates getCoordinates();
    bool getExists();
    void reset();
    void setSnow(bool isSnow);
    bool getSnow();
    bool CollisionControl(Zombie** zombie, int currentZombie);
    void move();
    void Draw(RenderWindow& window);

    void serialize(ostream& file);
    void deserialize(istream& file);
};
#endif

