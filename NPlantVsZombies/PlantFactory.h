#pragma once
#ifndef PLANTFACTORY_H
#define PLANTFACTORY_H
#include"Grid.h"
#include"AnimatMySprite.h"
#include"Plants.h"
#include"Peashooter.h"
#include"Repeater.h"
#include"CherryBomb.h"
#include"SnowPea.h"
#include"PuffShroom.h"
#include"Wallnut.h"
#include"InventPlant.h"
#include"Sunflower.h"
#include<iostream>
using namespace std;
class PlantFactory{
protected:
    int allowedPlants;
    int currentPlant;
    int currentNoOfplants;

    MySprite SelectorSprite;
    MySprite InventoryBack;
    Lane* lane;
    InventPlant** Cards;
    Plants** plants;
    Grid* grid;
public:
    PlantFactory(int allowedPlants, Grid*& grid );
    ~PlantFactory();


    void setAllowedPlants(int allowedPlants);
    void setLane(Lane* lane);
    void addPlant(int plantno, Block *block);

    MySprite& getSelectorSprite();
    int getAllowedPlants();
    Lane* getLane();
    InventPlant** getCards();
    Plants** getPlants();
    int getCurrentPlant();
    void CollisionControl(Zombie** zombies, int currentZombies);
    void setUpCards();
    int handleInput(Event e, RenderWindow& window, int sunCount);
    void Draw(RenderWindow& window);

    void serialize(ostream& file);
    void deserialize(istream& file);    

};
#endif

