#include"PuffShroom.h"
PuffShroom::PuffShroom(int price, Block* block, int health, float cooldownTime, string path):Shooters(price, block, health, cooldownTime, path){
    bullet = new Bullet*[1];
    bullet[0] = new Bullet("..\\assets\\Bullets\\PeaNormal\\pea.png", (int)block->getCoordinates().getX()+50, (int)block->getCoordinates().getY()+15);
    image.setNoOfFrames(15); 
    image.setWidth(79);
    image.setLength(70);
    image.setCurrentFrame(0);
    image.setAnimateSpeed(50);

    type = 3;
}
bool PuffShroom::CheckLane(Zombie** zombie, int currentZombie){
    int blockY = (int)this->block->getCoordinates().getY();
    for(int i = 0; i < currentZombie; i++){
        if(zombie[i] != nullptr && !zombie[i]->getBlasted() && !zombie[i]->getFalling()){
            if(blockY >= zombie[i]->getZombieSprite().getCoordinates().getY() + 45 && blockY < zombie[i]->getCoordinates().getY() + 144 && zombie[i]->getZombieSprite().getCoordinates().getX() < block->getCoordinates().getX() + 82*4 ){
                shouldShoot = true;
                return true;
            }
        }
    }
    shouldShoot = false;
    return false;
}
void PuffShroom::shoot(){
    if(bullet[0]->getExists() == false && clock.getElapsedTime().asSeconds() > 2 && shouldShoot){
        shootSound.play();
        
        bullet[0]->reset();
        bullet[0]->setExists(true);
        clock.restart();
    }
}
void PuffShroom::CollisionControl(Zombie** zombie, int currentZombie){
    this->CheckLane(zombie, currentZombie);
    bullet[0]->CollisionControl(zombie, currentZombie);
}
void PuffShroom::Draw(RenderWindow& window){
    if(health <= 0)
        Kill();
    bullet[0]->Draw(window);
    image.animate(window);
    shoot();
}
void PuffShroom::serialize(ostream& file){
    Plants::serialize(file);
    bullet[0]->serialize(file);
}
void PuffShroom::deserialize(istream& file){
    Plants::deserialize(file);
    bullet[0]->deserialize(file);
}
PuffShroom::~PuffShroom(){
    if(bullet[0] != nullptr){
        delete bullet[0];
        delete[] bullet;
    }
}
