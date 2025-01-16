#pragma once
#ifndef LEVEL3_H
#define LEVEL3_H
#include"Level.h"
class Level3: public Level{
protected:
public:
    Level3(string backgroundPath, int noOfZombies = 0, int noOfWaves = 0,  int allowedPlants = 0, int noOflanes = 0, int allowedZombies = 4);
    ~Level3();

    int handleInput(Event e, RenderWindow& window);
    void Draw(RenderWindow& window);
};
#endif

