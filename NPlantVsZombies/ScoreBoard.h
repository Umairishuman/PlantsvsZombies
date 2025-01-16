#pragma once
#ifndef SCOREBOARD_H
#define SCOREBOARD_H
#include"MySprite.h"
class ScoreBoard{
protected:
    string name;
    int score;
    Font font;
    Text text;
    MySprite sprite;
public:
    ScoreBoard(string name = "", int score = 0);
    void setName(string name);
    void setScore(int score);
    string getName();
    int getScore();
    void Draw(RenderWindow& window);
};
#endif
