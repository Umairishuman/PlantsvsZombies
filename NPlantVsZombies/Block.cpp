#include "Block.h"
Block::Block(int x, int y, int length, int width, bool available):P(x, y){
    this->length = length;
    this->width = width;
    this->available = available;
}
bool Block::checkHover(RenderWindow& window){
    int MouseX = Mouse::getPosition(window).x;
    int MouseY = Mouse::getPosition(window).y;
    if (MouseX >= P.getX() && MouseX <= P.getX() + length -1 && MouseY >= P.getY() && MouseY <= P.getY() + width -1) {
        return true;
    }
    return false;
}
void Block::setAvailable(bool available) {
    this->available = available;
}
bool Block::getAvailable() {
    return available;
}
Coordinates Block::getCoordinates(){
    return this->P;
}
void Block::serialize(ostream& file) {
    P.serialize(file);
    file.write(reinterpret_cast<const char*>(&length), sizeof(length));
    file.write(reinterpret_cast<const char*>(&width), sizeof(width));
    file.write(reinterpret_cast<const char*>(&available), sizeof(available));
}
void Block::deserialize(istream& file){
    P.deserialize(file);
    file.read(reinterpret_cast<char*>(&length), sizeof(length));
    file.read(reinterpret_cast<char*>(&width), sizeof(width));
    file.read(reinterpret_cast<char*>(&available), sizeof(available));
}