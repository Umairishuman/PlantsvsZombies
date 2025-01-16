#pragma once
#ifndef EXECUTOR_H
#define EXECUTOR_H
#include"MenuScreen.h"
#include"GameScreen.h"    
#include"HighScore.h"
#include"InstructionScreen.h"
#include"EndScreen.h"
class Executor {
protected:
    Screen** screens;
    int noOfScreens;
    int currentScreen;
    Music music;
public:
    Executor();
    ~Executor();
    void Run(RenderWindow& window);
    void handleInput(Event e, RenderWindow& window);

};
#endif

