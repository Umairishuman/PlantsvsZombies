#pragma once
#ifndef ZOMBIE_H
#define ZOMBIE_H
#include"AnimatMySprite.h"
class Zombie{
protected: 
    int &score;
    AnimateMySprite ZombieSprite;
    int hits;
    int speed;
    int killHits;
    Clock HitClock;
    Clock MovingClock;
    bool hitOpacity;
    bool falling;
    bool killed;
    bool blasted;
    bool eating;
    Clock eatingClock;

    bool headfallen;
    AnimateMySprite Headfall;
    bool hasReached;

    SoundBuffer groanBuffer;
    Sound groan;
    Clock groanClock;

    int type;

public:
    Zombie(string path, int x, int y, int noOfframes, int width, int length, int speed, int killhits, int &score);
    virtual ~Zombie();
    void setHitOpacity(bool hitOpacity);
    void setSpeed(int speed);
    void setHits(int hits);
    void setKilled(bool killed);
    void setHasReached(bool hasReached);
    bool getHasReached();

    int getSpeed();
    int getHits();
    bool getKilled();
    int getKillHits();
    Clock& geteatingClock();
    bool getFalling();
    bool getBlasted();

    virtual void headFall();
    virtual void BodyFall();

    Coordinates getCoordinates();
    virtual void kill();
    virtual void blast();
    virtual void eat();
    virtual void stopeat();
    virtual void move() ;
    virtual bool summonZombies();
    AnimateMySprite& getZombieSprite();
    Clock& getClock();    

    virtual void Draw(RenderWindow& window);

    virtual void serialize(ostream& file);
    virtual void deserialize(istream& file);

};
#endif

