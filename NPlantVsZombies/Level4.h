#pragma once
#ifndef LEVEL4_H    
#define LEVEL4_H
#include"Level.h"
class Level4: public Level{
protected:
public:
    Level4(string backgroundPath, int noOfZombies = 0, int noOfWaves = 0,  int allowedPlants = 0, int noOflanes = 0, int allowedZombies = 4);
    ~Level4();

    int handleInput(Event e, RenderWindow& window);
    void Draw(RenderWindow& window);
};
#endif

