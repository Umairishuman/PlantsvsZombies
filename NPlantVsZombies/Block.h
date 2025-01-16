#pragma once
#ifndef BLOCK_H
#define BLOCK_H
#include<SFML/Graphics.hpp>
#include"Coordinates.h"
using namespace sf;
class Block{
protected:
    Coordinates P;
    int length;
    int width;
    bool available;
public:
    Block(int x = 0, int y = 0, int length = 0, int width = 0, bool available = true);

    void setAvailable(bool available);
    bool getAvailable();

    Coordinates getCoordinates();
    bool checkHover(RenderWindow& window);

    void serialize(ostream& file);
    void deserialize(istream& file);
};
#endif

