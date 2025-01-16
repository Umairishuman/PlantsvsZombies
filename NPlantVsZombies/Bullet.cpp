#include"Bullet.h"
Bullet::Bullet(string path,int x, int y):bullet(path, x, y),shooterPoint(x, y){
    exists = false;
    isSnow = false;
    hitBuffer.loadFromFile("..\\assets\\music\\hit.mp3");
    hitSound.setBuffer(hitBuffer);
    hitSound.setVolume(90);
    hitSound.play();
}
void Bullet::setCoordinates(int x, int y){
    bullet.setCoordinates(x, y);
}
void Bullet::setExists(bool exists){
    this->exists = exists;
}
Coordinates Bullet::getCoordinates(){
    return bullet.getCoordinates();
}
bool Bullet::getExists(){
    return exists;
}
void Bullet::reset(){
    bullet.setCoordinates((int)shooterPoint.getX(),(int) shooterPoint.getY());
    if(isSnow){
        bullet.setPath("..\\assets\\Bullets\\PeaIce\\icepea.png");
    }
    else
        bullet.setPath("..\\assets\\Bullets\\PeaNormal\\pea.png");
}
void Bullet::setSnow(bool isSnow){
    this->isSnow = isSnow;
}
bool Bullet::getSnow(){
    return isSnow;
}
void Bullet:: move(){
    if(bullet.getCoordinates().getX() > 1000){
        exists = false;
        return;
    }
    if(exists){
        if(bulletClock.getElapsedTime().asMilliseconds() > 1){
            bullet.setCoordinates((int)bullet.getCoordinates().getX() + 1,(int) bullet.getCoordinates().getY());
            bulletClock.restart();
        }
    }
    return;
}
bool Bullet::CollisionControl(Zombie** zombies, int currentZombie){
    if(getExists()){
        for(int i = 0; i < currentZombie; i++){
            if(zombies[i] != nullptr && !zombies[i]->getBlasted() && !zombies[i]->getFalling()){
                int x = (int)zombies[i]->getZombieSprite().getCoordinates().getX();
                int y = (int)zombies[i]->getZombieSprite().getCoordinates().getY();
                if((getCoordinates().getX() - 45 == x || getCoordinates().getX() - 46 == x ) && getCoordinates().getY() - 55 >= y && getCoordinates().getY() <= y + 144){
                    zombies[i]->setHits(zombies[i]->getHits() + 1);
                    zombies[i]->setHitOpacity(true);
                    hitSound.play();
                    exists = false;
                    if(isSnow){
                        zombies[i]->setSpeed(zombies[i]->getSpeed() + 70);
                    }
                    return true;
                }
            }
        }
    }
    return false;
}

void Bullet::Draw(RenderWindow& window){
    if(exists){
        bullet.Draw(window);
        this->move();
    }
}
void Bullet::serialize(ostream& file){
    shooterPoint.serialize(file);
    bullet.serialize(file);
    file.write(reinterpret_cast<const char*>(&exists), sizeof(exists));
    file.write(reinterpret_cast<const char*>(&isSnow), sizeof(isSnow));
}

void Bullet::deserialize(istream& file){
    shooterPoint.deserialize(file);
    bullet.deserialize(file);
    file.read(reinterpret_cast<char*>(&exists), sizeof(exists));
    file.read(reinterpret_cast<char*>(&isSnow), sizeof(isSnow));
    hitBuffer.loadFromFile("..\\assets\\music\\hit.mp3");
    hitSound.setBuffer(hitBuffer);
}