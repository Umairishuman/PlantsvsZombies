#pragma once
#ifndef HIGHSCORE_H
#define HIGHSCORE_H
#include"Screen.h"
#include"Player.h"
class HighScore: public Screen{
protected:
    Font font;
    Text text;
    Text Player1;
    Text Player2;
    Text Player3;
    Text Player4;
    Text Player5;
    Player players[5];
public:
    HighScore(string backgroundPath = "", bool visible = false);
    ~HighScore();
    void getHighScores();
    int handleInput(Event e, RenderWindow& window);
    void Draw(RenderWindow& window);

};
#endif

