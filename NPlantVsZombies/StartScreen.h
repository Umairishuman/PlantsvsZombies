#pragma once
#ifndef STARTSCREEN_H
#define STARTSCREEN_H
#include"Screen.h"
class StartScreen : public Screen {
    Text textContinue;
    Font font;
    const string FONT_PATH = "..\\assets\\fonts\\HouseofTerror Regular.ttf";

    Clock* flickerClock;
    float flickerTime;
    bool visible = true;
public:
    StartScreen(string backgroundPath);
    ~StartScreen();

    virtual int handleInput(Event event, RenderWindow& window);
    virtual void Draw(RenderWindow& window);
};
#endif

