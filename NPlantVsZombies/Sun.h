#pragma once
#ifndef SUN_H
#define SUN_H
#include<ctime>
#include<cmath>
#include"AnimatMySprite.h"
class Sun{
protected:
	AnimateMySprite SunSprite;
	Clock sunClock;
    Clock SuncreationClock;
    int startX;
    int endY;
    int endY2;
    float UnitVectorX;
    float UnitVectorY;
    bool sunToTop;
    bool exists;
    bool plantGenerated;
public:
    Sun(int x = 0, int y = 0, int width = 0, int length = 0);
    
    void setPlantGenerated(bool plantGenerated);
    bool getPlantGenerated();
    
    void CalculateUnitVector();
    void SpawnSun();
    void MoveSun();
    void MoveSunTowardsTop();
    bool handleInput(Event e, RenderWindow& window);
    void Draw(RenderWindow& window);

    void serialize(ostream& file);
    void deserialize(istream& file);

};
#endif

