#pragma once
#ifndef ZOMBIEFACTORY_H
#define ZOMBIEFACTORY_H
#include<ctime>
#include"Zombie.h"
#include"Grid.h"
#include"SimpleZombie.h"
#include"Football.h"
#include"FlyingZombies.h"
#include"DancingZombie.h"
class ZombieFactory{
protected:
    int &score;
    int allowedZombies;
    int currentZombie;
    int noOfZombies;
    int ZombiesSpawned;
    Zombie** zombies;
    Clock ZombieSpawnClock;
    Grid* grid;

    int aliveZombies;
public:
    ZombieFactory(int noOfZombies ,int allowedZombies , Grid*& grid, int &score);
    ~ZombieFactory();
    void setCurrentZombie(int currentZombie);
    
    Zombie** getZombies();
    int getCurrentZombie();
    int getZombiesSpawned();
    int selectLane();
    int selectZombie();
    void AddZombie(Zombie* zombie);

    void SpawnZombie(bool SummonZombie = false);
    void Draw(RenderWindow& window);

    void serialize(ostream& file);
    void deserialize(istream& file);
};
#endif

