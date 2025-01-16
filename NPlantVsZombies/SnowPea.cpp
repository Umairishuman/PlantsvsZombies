#include"SnowPea.h"
SnowPea::SnowPea(int price, Block* block, int health, float cooldownTime, string path):Shooters(price, block, health, cooldownTime, path){
    bullet = new Bullet*[1];
    bullet[0] = new Bullet("..\\assets\\Bullets\\PeaIce\\icepea.png", (int)block->getCoordinates().getX()+53, (int)block->getCoordinates().getY()+10);
    bullet[0]->setSnow(true);

    image.setNoOfFrames(15); 
    image.setWidth(71);
    image.setLength(71);
    image.setCurrentFrame(0);
    image.setAnimateSpeed(50);
    type = 4;
}
void SnowPea::shoot(){
    if(bullet[0]->getExists() == false && clock.getElapsedTime().asSeconds() > 2 && shouldShoot){
        shootSound.play();
        bullet[0]->reset();
        bullet[0]->setExists(true);
        clock.restart();
    }
}
void SnowPea::CollisionControl(Zombie** zombie, int currentZombie){
    CheckLane(zombie, currentZombie);
    bullet[0]->CollisionControl(zombie, currentZombie);
}   
void SnowPea::Draw(RenderWindow& window){
    if(health <= 0)
        Kill();
    bullet[0]->Draw(window);
    image.animate(window);
    shoot();
}
void SnowPea::serialize(ostream& file){
    Plants::serialize(file);
    bullet[0]->serialize(file);
}
void SnowPea::deserialize(istream& file){
    Plants::deserialize(file);
    bullet[0]->deserialize(file);
}
SnowPea::~SnowPea(){
    if(bullet[0] != nullptr){
        delete bullet[0];
        delete[] bullet;
    }
}

