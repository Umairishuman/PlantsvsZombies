#pragma once
#ifndef ANIMATEMYSPRITE_H
#define ANIMATEMYSPRITE_H
#include"MySprite.h"
class AnimateMySprite:public MySprite{
protected:
    int noOfframes;
    int width;
    int length;
    int currentframe;
    int AnimateSpeed;
    Coordinates currentPosition;
    Clock animationClock;

public:
    AnimateMySprite(string path = "", int x = 0, int y = 0, int noOfframes = 0, int width = 0, int length = 0);
    void animate(RenderWindow &window);

    void setNoOfFrames(int noOfframes);
    void setWidth(int width);
    void setLength(int length);
    void setCurrentFrame(int currentframe);
    void setAnimateSpeed(int AnimateSpeed);
    int getNoOfFrames();
    int getWidth();
    int getLength();
    int getCurrentFrame();
    int getAnimateSpeed();

    void serialize(ostream& file);
    void deserialize(istream& file);
};
#endif
