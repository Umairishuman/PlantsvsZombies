#pragma once
#ifndef COORDINATES_H
#define COORDINATES_H
#include<iostream>
using namespace std;
class Coordinates
{
protected:
	float x, y;
public:
	Coordinates(float x = 0, float y = 0);  


	void setX(float x);
	void setY(float  y);

	float getX();
	float getY();

	void serialize(ostream& file );
	void deserialize(istream& file);

};
#endif

