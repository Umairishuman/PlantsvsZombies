#pragma once
#ifndef GAMESCREEN_H
#define GAMESCREEN_H
#include"Screen.h"
#include"Level1.h"
#include"Level2.h"
#include"Level3.h"
#include"Level4.h"
#include"Level5.h"
#include"Level6.h"
#include"Player.h"
#include"ScoreBoard.h"
class GameScreen : public Screen{
protected:

    int noOflevels;
    int currentLevel;
    Level** levels;
    string levelBackgrounds[6];
    bool previousState;
    bool paused;
    bool entpressed;
    Player players[5];
    int playerCountIndex;
    Player currentPlayer;
    ScoreBoard scoreBoard;
    int topPlayer;
    MySprite NameBack;
    MySprite Badge;

    Font font;
    Text PlayerText;
public:
    GameScreen(string backgroundPath, int noOfLevels = 6, bool previousState = false);
    ~GameScreen();

    void AddLevel(int level);
    void setPaused(bool paused);
    bool getPaused();
    void setCurrentLevel(int level);
    int getCurrentLevel();
    void setEntPressed(bool entpressed);
    void LoadPlayers();
    void SortPlayers();
    void start();
    virtual int handleInput(Event e, RenderWindow& window);
    virtual void Draw(RenderWindow& window);    

    void serialize(ostream& file);
    void deserialize(istream& file);
    void saveToFile(string filename);
    void loadFromFile(string filename);

};
#endif
