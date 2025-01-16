#include "DancingZombie.h"
DancingZombie::DancingZombie(string path, int x, int y, int noOfframes, int width, int length, int speed, int Killhits, int &score):Zombie(path, x, y, noOfframes, width, length, speed, Killhits, score){
    ZombieSprite.setAnimateSpeed(100);
    type = 3;
}
DancingZombie::~DancingZombie(){
}
bool DancingZombie::summonZombies(){
    if(ZombieSummoning.getElapsedTime().asSeconds() > 20 ){
        ZombieSummoning.restart();
        return true;
    }
    else
        return false;
}
void DancingZombie::stopeat(){
    ZombieSprite.setPath("..\\assets\\Spritesheets\\DancingZombie.png");
    ZombieSprite.setNoOfFrames(10);

    eating = false;
    ZombieSprite.setAnimateSpeed(100);
} 
void DancingZombie::move(){
    if(this->ZombieSprite.getCoordinates().getX() <= 60){
        if(ZombieSprite.getCoordinates().getY() > 280)
            ZombieSprite.setCoordinates((int)ZombieSprite.getCoordinates().getX()  , (int)ZombieSprite.getCoordinates().getY()- 1);
        else if(ZombieSprite.getCoordinates().getY() < 280)
            ZombieSprite.setCoordinates((int)ZombieSprite.getCoordinates().getX()  , (int)ZombieSprite.getCoordinates().getY()+ 1);
        if(ZombieSprite.getCoordinates().getY() == 280)
            hasReached = true;
        return;
    }
    if(this->hitOpacity && this->HitClock.getElapsedTime().asSeconds() > 1){
        this->hitOpacity = false;
        this->ZombieSprite.setOpacity(0.9f);
    }
    if(this->hits == killHits && headfallen == false){
        Headfall.setCoordinates((int)ZombieSprite.getCoordinates().getX()+30, (int)ZombieSprite.getCoordinates().getY());
        headfallen = true;
        headFall();
        return;
    }
    if(this->hits >= killHits && falling == false){
        falling = true;
        BodyFall();
        return;
    }
    if(blasted){
        return;
    }
    if(!eating){
        if(ZombieSprite.getCoordinates().getY() > 237)
            ZombieSprite.setCoordinates((int)ZombieSprite.getCoordinates().getX() - 1 , (int)ZombieSprite.getCoordinates().getY() - 1);
        if(ZombieSprite.getCoordinates().getY() < 237)
            ZombieSprite.setCoordinates((int)ZombieSprite.getCoordinates().getX() - 1 , (int)ZombieSprite.getCoordinates().getY()+1);
        if(ZombieSprite.getCoordinates().getY() == 237)
            ZombieSprite.setCoordinates((int)ZombieSprite.getCoordinates().getX() - 1 , (int)ZombieSprite.getCoordinates().getY());
    }
}