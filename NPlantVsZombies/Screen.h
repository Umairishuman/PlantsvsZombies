#pragma once
#ifndef SCREEN_H
#define SCREEN_H
#include"MySprite.h"
class Screen {
protected:
    Coordinates P;
    MySprite Background;
    bool visible;

public:

    Screen(string backgroundPath = "", bool visible = false);
    virtual ~Screen();
    void setVisible(bool visible);
    bool getVisible();

    virtual int handleInput(Event e, RenderWindow& window) = 0;
    virtual void Draw(RenderWindow& window) = 0;

    virtual void storeToFile(string filename);

};
#endif

