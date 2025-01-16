#include "Plants.h"
Plants::Plants(int price, Block* block, int health, float cooldownTime, string path):image(path, (int)block->getCoordinates().getX(), (int)block->getCoordinates().getY(), 1, 50, 50) {
    this->price = price;
    this->block = block;
    this->health = health;
    this->type = 0;
    killed = false;
    beingEaten = false;
}
void Plants::Kill(){
    killed = true;
    block->setAvailable(true);
}
bool Plants::getKilled(){
    return killed;
}
void Plants::setPrice(int price){
    this->price = price;
}
void Plants::setBlock(Block* block){
    this->block = block; 
}
void Plants::setHealth(int health){
    this->health = health;
}
Coordinates Plants::getCoordinates(){
    return image.getCoordinates();
}

int Plants::getHealth(){
    return this->health;
}
int Plants::getPrice(){
    return this->price;
}
Block* Plants::getBlock(){
    return this->block;
}
bool Plants::handleInput(Event e, RenderWindow& window){
    return false;
}
void Plants::serialize(ostream& file){
    image.serialize(file);
    block->serialize(file);
    file.write(reinterpret_cast<const char*>(&price), sizeof(price));
    file.write(reinterpret_cast<const char*>(&health), sizeof(health));
    file.write(reinterpret_cast<const char*>(&killed), sizeof(killed));
    file.write(reinterpret_cast<const char*>(&beingEaten), sizeof(beingEaten));
    file.write(reinterpret_cast<const char*>(&type), sizeof(type));
}
void Plants::deserialize(istream& file){
    image.deserialize(file);
    block->deserialize(file);
    file.read(reinterpret_cast<char*>(&price), sizeof(price));
    file.read(reinterpret_cast<char*>(&health), sizeof(health));
    file.read(reinterpret_cast<char*>(&killed), sizeof(killed));
    file.read(reinterpret_cast<char*>(&beingEaten), sizeof(beingEaten));
    file.read(reinterpret_cast<char*>(&type), sizeof(type));
}
Plants::~Plants(){
}

