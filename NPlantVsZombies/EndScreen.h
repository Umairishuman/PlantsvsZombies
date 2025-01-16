#pragma once
#ifndef ENDSCREEN_H
#define ENDSCREEN_H
#include"Screen.h"

class EndScreen: public Screen{
protected:
    Clock EndClock;
public:
    EndScreen(string backgroundPath = "", bool visible = false);
    ~EndScreen();
    int handleInput(Event e, RenderWindow& window);
    void Draw(RenderWindow& window);

};
#endif

