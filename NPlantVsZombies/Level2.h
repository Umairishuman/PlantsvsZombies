#pragma once
#ifndef LEVEL2_H
#define LEVEL2_H
#include"Level.h"
class Level2: public Level{
protected:
public: 
    Level2(string backgroundPath, int noOfZombies = 0, int noOfWaves = 0,  int allowedPlants = 0, int noOflanes = 0, int allowedZombies = 4);
    ~Level2();

    int handleInput(Event e, RenderWindow& window);
    void Draw(RenderWindow& window);

};
#endif

