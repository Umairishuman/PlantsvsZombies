#include "Lane.h"
Lane::Lane(int noOfBlocks, int laneNo, int x, int y, int width, int blockWidth,bool isWater) :noOfBlocks(noOfBlocks), laneNo(laneNo), width(width), blockWidth(blockWidth),P(x, y), isWater(isWater){
    if (noOfBlocks == 0) {
        blocks = nullptr;
        return;
    }
    blocks = new Block * [noOfBlocks];
    for (int i = 0; i < noOfBlocks; i++) {
        blocks[i] = new Block(x + i*blockWidth, y, blockWidth, width, true);
    }
}
void Lane::setNoOfBlocks(int x) {
    noOfBlocks = x;
}
int Lane::getNoOfBlocks() {
    return noOfBlocks;
}

void Lane::setIsWater(bool isWater) {
    this->isWater = isWater;
}
bool Lane::getIsWater() {
    return isWater;
}
void Lane::setBlocks(Block** blocks) {
    this->blocks = blocks;
}
Block** Lane::getBlocks() {
    return blocks;
}
Lane::~Lane() {
    for (int i = 0; i < noOfBlocks; i++) {
        if (blocks[i] != nullptr) {
            delete blocks[i];
        }
    }
    if (blocks != nullptr)
        delete blocks;
}
void Lane::serialize(ostream& file) {
    P.serialize(file);
    file.write(reinterpret_cast<const char*>(&noOfBlocks), sizeof(noOfBlocks));
    file.write(reinterpret_cast<const char*>(&laneNo), sizeof(laneNo));
    file.write(reinterpret_cast<const char*>(&width), sizeof(width));
    file.write(reinterpret_cast<const char*>(&blockWidth), sizeof(blockWidth));
    file.write(reinterpret_cast<const char*>(&isWater), sizeof(isWater));
    for (int i = 0; i < noOfBlocks; i++) {
        blocks[i]->serialize(file);
    }
}
void Lane::deserialize(istream& file) {
    P.deserialize(file);
    file.read(reinterpret_cast<char*>(&noOfBlocks), sizeof(noOfBlocks));
    file.read(reinterpret_cast<char*>(&laneNo), sizeof(laneNo));
    file.read(reinterpret_cast<char*>(&width), sizeof(width));
    file.read(reinterpret_cast<char*>(&blockWidth), sizeof(blockWidth));
    file.read(reinterpret_cast<char*>(&isWater), sizeof(isWater));
    blocks = new Block * [noOfBlocks];
    for (int i = 0; i < noOfBlocks; i++) {
        blocks[i] = new Block();
        blocks[i]->deserialize(file);
    }
}
