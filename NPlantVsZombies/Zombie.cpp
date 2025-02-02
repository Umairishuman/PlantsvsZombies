#include"Zombie.h"
Zombie::Zombie(string path, int x, int y, int noOfframes, int width, int length, int speed, int Killhits, int &score):ZombieSprite(path, x, y, noOfframes, width, length), Headfall("..\\assets\\Spritesheets\\ZombieHead.png",x,y,18,116,144),score(score){
    this->killHits = Killhits;
    this->hitOpacity = false;
    this->speed = speed;
    this->hits = 0;
    this->killed = false;
    type = 1;

    this->headfallen = false;
    this->headHasFallenOnce = false;
    this->falling = false;
    blasted = false;
    this->eating = false;
    this->hasReached = false;
    
    Headfall.setAnimateSpeed(100);
    ZombieSprite.setAnimateSpeed(50);
    ZombieSprite.setOpacity(0.9f);

    groanBuffer.loadFromFile("..\\assets\\music\\Voices groan.mp3");
    groan.setBuffer(groanBuffer);
    groan.setVolume(20);
    groan.play();

}
int Zombie::getHits(){
    return this->hits;
}
bool Zombie::getKilled(){
    return killed;
}
void Zombie::setKilled(bool killed){
    this->killed = killed;
}
bool Zombie::getBlasted(){
    return this->blasted;
}
bool Zombie::getFalling(){
    return this->falling;
}
bool Zombie::getHasReached(){
    return this->hasReached;
}
void Zombie::setHasReached(bool hasReached){
    this->hasReached = hasReached;
}
void Zombie::setHitOpacity(bool hitOpacity){
    this->ZombieSprite.setOpacity(1);
    HitClock.restart();
    this->hitOpacity = hitOpacity;
}
int Zombie::getKillHits(){
    return this->killHits;
}
int Zombie::getSpeed(){
    return speed;
}
void Zombie::setHits(int hits){
    this->hits = hits;
}
void Zombie::setSpeed(int speed){
    this->speed = speed;
}
Clock& Zombie::geteatingClock(){
    return this->eatingClock;
}
AnimateMySprite& Zombie::getZombieSprite(){
    return this->ZombieSprite;
}
Clock& Zombie::getClock(){
    return this->MovingClock;
}
Coordinates Zombie::getCoordinates(){
    return this->ZombieSprite.getCoordinates();
}
void Zombie::kill(){
    score += 100;
    killed = true;
}
void Zombie::headFall(){
    if(headfallen){
        ZombieSprite.setPath("..\\assets\\Spritesheets\\ZombieNohead.png");
        ZombieSprite.setNoOfFrames(18);
        ZombieSprite.setWidth(166);
        ZombieSprite.setLength(144);
        ZombieSprite.setAnimateSpeed(50);
    }
}
void Zombie::BodyFall(){
    ZombieSprite.setPath("..\\assets\\Spritesheets\\ZomvbieDie.png");
    ZombieSprite.setNoOfFrames(16);
    ZombieSprite.setWidth(166);
    ZombieSprite.setLength(144);
    ZombieSprite.setAnimateSpeed(80);
}
void Zombie::blast(){
    ZombieSprite.setPath("..\\assets\\Spritesheets\\Burnt.png");
    ZombieSprite.setNoOfFrames(25);
    ZombieSprite.setWidth(166);
    ZombieSprite.setLength(144);
    blasted = true;
    ZombieSprite.setAnimateSpeed(90);
}
void Zombie::eat(){
    if(!eating){
        ZombieSprite.setPath("..\\assets\\Spritesheets\\nZombEat.png");
        ZombieSprite.setNoOfFrames(21);
    
        eating = true;
        eatingClock.restart();
        ZombieSprite.setAnimateSpeed(50);
    }
    
}
bool Zombie::summonZombies(){
    return false;
}
void Zombie::stopeat(){
    if(eating){
        ZombieSprite.setPath("..\\assets\\Spritesheets\\nZombWalk.png");
        ZombieSprite.setNoOfFrames(18);

        eating = false;
        ZombieSprite.setAnimateSpeed(50);
    }

}
void Zombie::move(){
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
    if (this->hits == killHits - 1 && headfallen == false && headHasFallenOnce == false) {
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
    if(!eating)
        ZombieSprite.setCoordinates((int)ZombieSprite.getCoordinates().getX() - 1 , (int)ZombieSprite.getCoordinates().getY());

}
void Zombie::Draw(RenderWindow& window){
    if(groanClock.getElapsedTime().asSeconds() > 5){
        groan.play();
        groanClock.restart();
    }
    if(MovingClock.getElapsedTime().asMilliseconds() > speed){
        move();
        MovingClock.restart();
    }
    if(!killed)
        ZombieSprite.animate(window);
    if(headfallen){
        if(Headfall.getCurrentFrame() == Headfall.getNoOfFrames()-1){
            headfallen = false;
            headHasFallenOnce = true;
        }
        Headfall.animate(window);
    }
    if(falling || blasted){
        if(ZombieSprite.getCurrentFrame() == ZombieSprite.getNoOfFrames()-1 || ZombieSprite.getCurrentFrame() == ZombieSprite.getNoOfFrames()-2 || ZombieSprite.getCurrentFrame() == ZombieSprite.getNoOfFrames()){
            falling = false;
            kill();
        }
    }
}
void Zombie::serialize(ostream& file){
    file.write(reinterpret_cast<const char*>(&score), sizeof(score));  
    ZombieSprite.serialize(file);
    file.write(reinterpret_cast<const char*>(&hits), sizeof(hits));
    file.write(reinterpret_cast<const char*>(&speed), sizeof(speed));
    file.write(reinterpret_cast<const char*>(&killHits), sizeof(killHits));
    file.write(reinterpret_cast<const char*>(&hitOpacity), sizeof(hitOpacity));
    file.write(reinterpret_cast<const char*>(&falling), sizeof(falling));
    file.write(reinterpret_cast<const char*>(&killed), sizeof(killed));
    file.write(reinterpret_cast<const char*>(&blasted), sizeof(blasted));
    file.write(reinterpret_cast<const char*>(&eating), sizeof(eating));
    file.write(reinterpret_cast<const char*>(&headfallen), sizeof(headfallen));
    Headfall.serialize(file);
    file.write(reinterpret_cast<const char*>(&hasReached), sizeof(hasReached));
    file.write(reinterpret_cast<const char*>(&type), sizeof(type));
}
void Zombie::deserialize(istream& file){
    file.read(reinterpret_cast<char*>(&score), sizeof(score));  
    ZombieSprite.deserialize(file);
    file.read(reinterpret_cast<char*>(&hits), sizeof(hits));
    file.read(reinterpret_cast<char*>(&speed), sizeof(speed));
    file.read(reinterpret_cast<char*>(&killHits), sizeof(killHits));
    file.read(reinterpret_cast<char*>(&hitOpacity), sizeof(hitOpacity));
    file.read(reinterpret_cast<char*>(&falling), sizeof(falling));
    file.read(reinterpret_cast<char*>(&killed), sizeof(killed));
    file.read(reinterpret_cast<char*>(&blasted), sizeof(blasted));
    file.read(reinterpret_cast<char*>(&eating), sizeof(eating));
    file.read(reinterpret_cast<char*>(&headfallen), sizeof(headfallen));
    Headfall.deserialize(file);
    file.read(reinterpret_cast<char*>(&hasReached), sizeof(hasReached));
    file.read(reinterpret_cast<char*>(&type), sizeof(type));
    groanBuffer.loadFromFile("..\\assets\\music\\Voices groan.mp3");
    groan.setBuffer(groanBuffer);
}



Zombie::~Zombie(){
}