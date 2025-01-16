#include"Shooters.h"
Shooters::Shooters(int price, Block* block, int health, float cooldownTime, string path):Plants(price, block, health, cooldownTime, path){
    shouldShoot = false;
    bullet = nullptr;

    shootBuffer.loadFromFile("..\\assets\\music\\shoot.mp3");
    shootSound.setBuffer(shootBuffer);
    shootSound.setVolume(20);
    
}
void Shooters::setBullet(Bullet** bullet){
    this->bullet = bullet;
}
Bullet** Shooters::getBullet(){
    return bullet;
}
bool Shooters::CheckLane(Zombie** zombies, int currentZombies){
    int blockY = (int)this->block->getCoordinates().getY();
    for(int i = 0; i < currentZombies; i++){
        if(zombies[i] != nullptr && !zombies[i]->getBlasted() && !zombies[i]->getFalling()){
            if(blockY >= zombies[i]->getZombieSprite().getCoordinates().getY() + 45 && blockY < zombies[i]->getCoordinates().getY() + 144){
                shouldShoot = true;
                return true;
            }
        }
    }
    shouldShoot = false;
    return false;
}
Shooters::~Shooters(){  
}