#pragma once
#ifndef LEVEL6_H
#define LEVEL6_H
#include"Level.h"
class Level6: public Level{
protected:
public:
    Level6(string backgroundPath, int noOfZombies = 0, int noOfWaves = 0,  int allowedPlants = 0, int noOflanes = 0, int allowedZombies = 4);
    ~Level6();

    int handleInput(Event e, RenderWindow& window);
    void Draw(RenderWindow& window);

};
#endif

