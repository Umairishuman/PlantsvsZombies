#pragma once
#ifndef MENUSCREEN_H
#define MENUSCREEN_H
#include"Screen.h"
class MenuScreen : public Screen {
protected:
    Text StartGame;
    Text ResumeGame;
    Text Instructions;
    Text HighScore;
    Text ExitGame;
    MySprite Toggler;
    int currentSelection;
    Font font;

    const int NO_OF_OPTIONS;
    const int SOUND_POOL_SIZE = 20;
    Sound toggleSound[20];
    SoundBuffer togglebuffer;
public:
    MenuScreen(string backgroundPath, string fontPath, string togglerPath);
    ~MenuScreen();

    void setSelection(int selection);
    int getSelection();
    
    virtual int handleInput(Event event, RenderWindow& window);
    virtual void Draw(RenderWindow& window);


};
#endif
