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
    int topPlayer;
    
    // ScoreBoard scoreBoard;
    
    const string NAME_ENTRY_PATH = "..\\assets\\Background\\ForNameEntry1.png";
    MySprite NameBack;  //Background for name entry
    MySprite Badge;    //Badge for top 3 players

    Font font;
    Text PlayerText;
public:
    GameScreen(string backgroundPath, int noOfLevels, bool previousState = false);
    ~GameScreen();

    void AddLevel(int level);
    void start();   //function to manage start and end of levels
    
    void setPaused(bool paused);
    bool getPaused();
    void setCurrentLevel(int level);
    int getCurrentLevel();
    void setEntPressed(bool entpressed);

    void LoadPlayers();
    void SortPlayers();
    
    virtual int handleInput(Event e, RenderWindow& window);
    virtual void Draw(RenderWindow& window);    

    // void serialize(ostream& file);
    // void deserialize(istream& file);
    // void saveToFile(string filename);
    // void loadFromFile(string filename);

};
#endif
