#pragma once
#ifndef LEVEL5_H
#define LEVEL5_H
#include"Level.h"
class Level5: public Level{
protected:
public:
    Level5(string backgroundPath, int noOfZombies = 0, int noOfWaves = 0,  int allowedPlants = 0, int noOflanes = 0, int allowedZombies = 4);
    ~Level5();

    int handleInput(Event e, RenderWindow& window);
    void Draw(RenderWindow& window);

};
#endif