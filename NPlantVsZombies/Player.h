#pragma once

#ifndef PLAYER_H
#define PLAYER_H
#include<fstream>
#include<iostream>
#include<SFML/Graphics.hpp>
using namespace std;
using namespace sf;
class Player{
protected:
    string name;
    int score;

    Font font;
    Text text;
    

public:
    Player(string name = "", int score = 0);
    void setName(string name);
    void setScore(int score);
    string getName();
    int getScore();
    
    void EnterName(Event &e);
    void Draw(RenderWindow& window);

    void serialize(ostream& file);
    void deserialize(istream& file);
};
#endif

