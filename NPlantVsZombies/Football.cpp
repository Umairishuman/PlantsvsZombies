#include "Football.h"
FootballZombie::FootballZombie(string path, int x, int y, int noOfframes, int width, int length, int speed, int Killhits, int &score):Zombie(path, x, y, noOfframes, width, length, speed, Killhits, score){
    direction = false;
    type = 2;
}
FootballZombie::~FootballZombie(){
}
void FootballZombie::eat(){
    Zombie::eat();
    if(!eating){
        ZombieSprite.setPath("..\\assets\\Spritesheets\\Coneheadeat.png");
        ZombieSprite.setNoOfFrames(11);
        
    }
}
void FootballZombie::stopeat(){
    if(eating){
        ZombieSprite.setPath("..\\assets\\Spritesheets\\Conehead.png");
        ZombieSprite.setNoOfFrames(18);
        eating = false;
        ZombieSprite.setAnimateSpeed(50);
    }
}
void FootballZombie::move(){
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
    if(this->hits == killHits-1 && headfallen == false){
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
        if(ZombieSprite.getCoordinates().getX() == 280)
            direction = true;
        if(ZombieSprite.getCoordinates().getX() == 450)
            direction = false;
        if(!direction)
            ZombieSprite.setCoordinates((int)ZombieSprite.getCoordinates().getX() - 1 , (int)ZombieSprite.getCoordinates().getY());
        else
            ZombieSprite.setCoordinates((int)ZombieSprite.getCoordinates().getX() + 1 , (int)ZombieSprite.getCoordinates().getY());
    }
}
