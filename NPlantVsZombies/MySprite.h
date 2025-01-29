#pragma once
#ifndef MYSPRITE_H
#define MYSPRITE_H
#include<iostream>
#include"Coordinates.h"
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
using namespace sf;
using namespace std;
class MySprite
{
protected:
	Sprite image;
	Texture texture;
	string path;
	Coordinates P1;

public:
	MySprite(string path = "", float x = 0, float y = 0);

	void setPath(string path);
	void setCoordinates(float x, float y);
	void setOpacity(float opacity);
	void scale(float x, float y);

	Coordinates getCoordinates();
	string getPath();

	void Draw(RenderWindow& Window);

	void serialize(ostream& file);
	void deserialize(std::istream& file);


};
#endif

