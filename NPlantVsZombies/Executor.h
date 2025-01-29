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
    //Menu screen constants
    const string MENU_BACKGROUND_PATH = "..\\assets\\Background\\MenuBackground1.png";
    const string MENU_FONT_PATH = "..\\assets\\fonts\\VampireWars.ttf";
    const string MENU_TOGGLER_PATH = "..\\assets\\Plants\\Peashooter\\Peashooter_0.png";
    const string GAME_MUSIC_PATH = "..\\assets\\music\\Main.mp3";
    //Game screen constants
    const string GAME_SCREEN_PATH = "..\\assets\\Background\\Frontyard.jpg";
    const int NO_OF_LEVELS = 5;
    //instruction screen constants
    const string INSTRUCTION_BACKGROUND_PATH = "..\\assets\\Background\\MenuBackground.jpg";
    //highscore screen constants
    const string HIGHSCORE_BACKGROUND_PATH = "..\\assets\\Background\\MenuBackground.jpg";
    //end screen constants
    const string EXIT_BACKGROUND_PATH = "..\\assets\\Background\\ExitBackground.png";


public:
    Executor();
    ~Executor();
    void Run(RenderWindow& window);
    void handleInput(Event e, RenderWindow& window);

};
#endif

