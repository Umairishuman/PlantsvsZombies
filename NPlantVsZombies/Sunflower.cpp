#include"Sunflower.h"
Sunflower::Sunflower(int price, Block* block, int health, float cooldownTime, string path):Plants(price, block, health, cooldownTime, path), sun((int)block->getCoordinates().getX(), (int)block->getCoordinates().getY(),71,71){
    sun.setPlantGenerated(true);
    image.setNoOfFrames(18); 
    image.setWidth(71);
    image.setLength(71);
    image.setCurrentFrame(0);
    image.setAnimateSpeed(50);

    type =5;
}
void Sunflower::CollisionControl(Zombie** zombie, int currentZombie){
    return;
}
bool Sunflower::handleInput(Event e, RenderWindow& window){
    if(sun.handleInput(e, window)){
        return true;
    }
    return false;
}
void Sunflower::Draw(RenderWindow& window){
    if(sunSpawnClock.getElapsedTime().asSeconds() > 10){
        sun.SpawnSun();
        sunSpawnClock.restart();
    }
    if(health<=0){
        Kill();
    }
    this->image.animate(window);
    sun.Draw(window);
}
void Sunflower::serialize(ostream& file){
    Plants::serialize(file);
    sun.serialize(file);
}
void Sunflower::deserialize(istream& file){
    Plants::deserialize(file);
    sun.deserialize(file);
}

Sunflower::~Sunflower(){
}