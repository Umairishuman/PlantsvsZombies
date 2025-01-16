#pragma once
#ifndef GRID_H
#define GRID_H
#include"Lane.h"
class Grid
{
protected: 
    int noOfLanes;
    Lane** lanes;
    Coordinates P;
    int laneWidth;

public:
    Grid(int noOfLanes = 0, int x = 0, int y = 0, int laneWidth = 0);
    ~Grid();
    void setNoOfLanes(int x);
    void setLanes(Lane** lanes);
    
    Lane** getLanes();
    int getNoOfLanes();

    void serialize(ostream& file);
    void deserialize(istream& file);
};
#endif

