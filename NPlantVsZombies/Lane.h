#pragma once
#ifndef LANE_H
#define LANE_H
#include"Block.h"
class Lane{
protected:
    int noOfBlocks;
    int laneNo;
    Coordinates P;
    Block** blocks;
    int width;
    int blockWidth;
    bool isWater;

public:
    Lane(int noOfBlocks = 0, int laneNo = 0, int x = 0, int y = 0, int width = 0, int blockWidth = 0,bool isWater = true);
    ~Lane();
    void setNoOfBlocks(int x);
    int getNoOfBlocks();

    void setIsWater(bool isWater);
    bool getIsWater();

    void setBlocks(Block** blocks);
    Block** getBlocks();

    void serialize(ostream& file);
    void deserialize(istream& file);
};
#endif

