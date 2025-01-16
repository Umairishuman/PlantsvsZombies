#pragma once
#ifndef INVENTPLANT_H
#define INVENTPLANT_H
#include"MySprite.h"
#include<cmath>
class InventPlant{
protected:
    MySprite PlantCard;
    MySprite Plantimage;
    int price;
    float cooldownTime;
    Clock cooldownClock;
    Font font;
    Text text;
    bool gameStart;

public:
    InventPlant(string PlantCardPath, string PlantimagePath , int CardX , int CardY,float cooldownTime, int imageX, int imageY, int price = 0);
    ~InventPlant();
    void setCooldownTime(float cooldownTime);
    void setGameStart(bool gameStart);
    void setPrice(int price);
    int getPrice();

    float getCooldownTime();
    MySprite& getPlantCard();
    MySprite& getPlantimage();
    Clock& getCooldownClock();
    bool getGameStart();
    void Draw(RenderWindow& window);

    void serialize(ostream& file);
    void deserialize(istream& file); 
};
#endif
