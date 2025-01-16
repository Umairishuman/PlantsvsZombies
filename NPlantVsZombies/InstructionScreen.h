#pragma once
#ifndef INSTRUCTIONSCREEN_H
#define INSTRUCTIONSCREEN_H
#include"Screen.h"
class InstructionScreen: public Screen{
    Font font;
    Text text;
    Text Instructions[6];
protected:
public:
    InstructionScreen(string backgroundPath = "", bool visible = false);
    ~InstructionScreen();
    int handleInput(Event e, RenderWindow& window);
    void Draw(RenderWindow& window);

};
#endif

