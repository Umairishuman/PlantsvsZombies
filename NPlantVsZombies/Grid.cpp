#include "Grid.h"
Grid::Grid(int noOfLanes, int x, int y, int LaneWidth) :P(x, y) {
    this->noOfLanes = noOfLanes;
    if(noOfLanes == 0){
        lanes = nullptr;
        return;
    }
    lanes = new Lane* [noOfLanes];
    for (int i = 0; i < noOfLanes; i++) {
        lanes[i] = new Lane(9, i, x, y + i*LaneWidth, LaneWidth, 82,true);
    }
}
void Grid::setNoOfLanes(int x) {
    noOfLanes = x;
}
void Grid::setLanes(Lane** lanes) {
    this->lanes = lanes;
}
Lane** Grid::getLanes() {
    return lanes;
}
int Grid::getNoOfLanes() {
    return noOfLanes;
}
Grid::~Grid() {
    for (int i = 0; i < noOfLanes; i++) {
        if (lanes[i] != nullptr) {
            delete lanes[i];
        }
    }
    if (lanes != nullptr)
        delete lanes;
}
void Grid::serialize(ostream& file) {
    P.serialize(file);
    file.write(reinterpret_cast<const char*>(&noOfLanes), sizeof(noOfLanes));
    for (int i = 0; i < noOfLanes; i++) {
        lanes[i]->serialize(file);
    }
}
void Grid::deserialize(istream& file) {
    P.deserialize(file);
    file.read(reinterpret_cast<char*>(&noOfLanes), sizeof(noOfLanes));
    lanes = new Lane * [noOfLanes];
    for (int i = 0; i < noOfLanes; i++) {
        lanes[i] = new Lane();
        lanes[i]->deserialize(file);
    }
}