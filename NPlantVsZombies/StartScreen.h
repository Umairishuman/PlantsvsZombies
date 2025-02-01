#pragma once
#ifndef STARTSCREEN_H
#define STARTSCREEN_H
#include"Screen.h"
class StartScreen : public Screen {
    Text textContinue;
    Font font;
    const string FONT_PATH = "..\\assets\\fonts\\HouseofTerror Regular.ttf";
    const string START_SOUND_PATH = "..\\assets\\music\\Riser.wav";

    Clock* flickerClock;
    float flickerTime;
    bool visible = true;

    Sound StartSound;
    SoundBuffer StartBuffer;
    Clock* LogoClock;
    bool logoDisplayed;
public:
    StartScreen(string backgroundPath);
    ~StartScreen();

    void DisplayLogo(RenderWindow& window);

    virtual int handleInput(Event event, RenderWindow& window);
    virtual void Draw(RenderWindow& window);
};
#endif

