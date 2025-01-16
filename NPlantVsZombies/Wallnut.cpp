#include"Wallnut.h"
Wallnut::Wallnut(int price,  Block* block, int health, float cooldownTime, string path):Plants(price, block, health, cooldownTime, path){
    image.setNoOfFrames(37);
    image.setWidth(65);
    image.setLength(73);
    image.setCurrentFrame(0);
    image.setAnimateSpeed(20);

    type = 6;
}
void Wallnut::move(){
    if(image.getCoordinates().getX()> 1000){
        killed = true;
        this->block->setAvailable(true);

    }
    if(clock.getElapsedTime().asMilliseconds() > 30)
        image.setCoordinates((int)image.getCoordinates().getX() + 1, (int)image.getCoordinates().getY());
}
void Wallnut::CollisionControl(Zombie** zombies, int currentZombie){
    for(int i = 0; i < currentZombie; i++){
        if(zombies[i] != nullptr && !zombies[i]->getBlasted() && !zombies[i]->getFalling()){
            int x = (int)zombies[i]->getZombieSprite().getCoordinates().getX();
            int y = (int)zombies[i]->getZombieSprite().getCoordinates().getY();
            if(x == image.getCoordinates().getX() && y == image.getCoordinates().getY()-45){
                zombies[i]->setHits(zombies[i]->getKillHits()+ 1);
            }
        }
    }
}
void Wallnut::Draw(RenderWindow& window){
    move();
    if(!killed)
        this->image.animate(window);
}
Wallnut::~Wallnut(){
}