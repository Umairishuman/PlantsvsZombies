#include"LawnMower.h"
LawnMower::LawnMower(int x, int y, string path) :LawnMowerSprite(path, x, y) {
    used = false;
    active = false;
}   
LawnMower::~LawnMower() {
}
void LawnMower::setActive(bool active) {
    this->active = active;
}
bool LawnMower::getActive() {
    return active;
}
void LawnMower::setUsed(bool used){
    this->used = used;
}
bool LawnMower::getUsed(){
    return this->used;
}
void LawnMower::move() {
    if (active) {
        if(LawnMowerSprite.getCoordinates().getX()> 1000){
            used = true;

        }
    if(clock.getElapsedTime().asMilliseconds() > 30)
        LawnMowerSprite.setCoordinates((int)LawnMowerSprite.getCoordinates().getX() + 1, (int)LawnMowerSprite.getCoordinates().getY());
    }
}
void LawnMower::CollisionControl(Zombie** zombies, int currentZombie) {
    for (int i = 0; i < currentZombie; i++) {
        if (zombies[i] != nullptr && !zombies[i]->getBlasted() && !zombies[i]->getFalling()) {
            int x = (int)zombies[i]->getZombieSprite().getCoordinates().getX();
            int y = (int)zombies[i]->getZombieSprite().getCoordinates().getY();
            if (x == LawnMowerSprite.getCoordinates().getX() + 10 && y == LawnMowerSprite.getCoordinates().getY() - 45) {
                this->active = true;
                zombies[i]->setHits(zombies[i]->getKillHits() + 1);
            }
        }
    }
}
void LawnMower::serialize(ostream& file){
    LawnMowerSprite.serialize(file);
    file.write(reinterpret_cast<const char*>(&used), sizeof(used));
    file.write(reinterpret_cast<const char*>(&active), sizeof(active));
}
void LawnMower::deserialize(istream& file){
    LawnMowerSprite.deserialize(file);
    file.read(reinterpret_cast<char*>(&used), sizeof(used));
    file.read(reinterpret_cast<char*>(&active), sizeof(active));
}
void LawnMower::Draw(RenderWindow& window) {
    move();
    if (!used)
        this->LawnMowerSprite.Draw(window);
}