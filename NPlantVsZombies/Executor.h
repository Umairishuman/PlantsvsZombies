#pragma once
#ifndef EXECUTOR_H
#define EXECUTOR_H
#include"MenuScreen.h"
#include"GameScreen.h"    
#include"HighScore.h"
#include"InstructionScreen.h"
#include"EndScreen.h"
#include"StartScreen.h"
class Executor {
protected:
    Screen** screens;
    int noOfScreens;
    int currentScreen;
    Music music;
    //start screen constants
    const string START_BACKGROUND_PATH = "..\\assets\\Background\\StartScreen-background.png";
    const string START_FONT_PATH = "..\\assets\\fonts\\VampireWars.ttf";

    //Menu screen constants
    const string MENU_BACKGROUND_PATH = "..\\assets\\Background\\StartScreen-background.png";
    const string MENU_FONT_PATH = "..\\assets\\fonts\\HouseofTerror Regular.ttf";
    const string MENU_TOGGLER_PATH = "..\\assets\\Plants\\Peashooter\\Peashooter_0.png";
    const string GAME_MUSIC_PATH = "..\\assets\\music\\Main.wav";
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

