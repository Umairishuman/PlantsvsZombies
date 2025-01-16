#pragma once
#ifndef LEVEL1_H
#define LEVEL1_H
#include"Level.h"
class Level1: public Level{
protected:
public: 
    Level1(string backgroundPath, int noOfZombies = 0, int noOfWaves = 0,  int allowedPlants = 0, int noOflanes = 0, int allowedZombies = 1);
    ~Level1();


    int handleInput(Event e, RenderWindow& window);
    void Draw(RenderWindow& window);



};
#endif
