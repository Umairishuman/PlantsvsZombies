#include"Repeater.h"
Repeater::Repeater(int price, Block* block, int health, float cooldownTime, string path):Shooters(price, block, health, cooldownTime, path){
    this->bullet = new Bullet*[2];
    for(int i = 0; i < 2; i++){
        this->bullet[i] = new Bullet("..\\assets\\Bullets\\PeaNormal\\pea.png", (int)block->getCoordinates().getX()+53,(int) block->getCoordinates().getY()+10);
    }
    this->image.setNoOfFrames(15);
    image.setWidth(71);
    image.setLength(71);
    image.setCurrentFrame(0);
    image.setAnimateSpeed(50);
    clocks[0] = clock;
    clocks[0].restart();
    clocks[1].restart();
    justMade = true;
    type =2;


}
void Repeater::shoot(){
    for(int i = 0; i < 2; i++){
        if(i == 1 && justMade ){
            if(clocks[i].getElapsedTime().asSeconds() < 2.3)
                return;
            else{
                justMade = false;
            }
        }
        if(bullet[i]->getExists() == false && clocks[i].getElapsedTime().asSeconds() > 2 && shouldShoot){
            shootSound.play();
            bullet[i]->reset();
            bullet[i]->setExists(true);
            clocks[i].restart();

        }
    }
}
void Repeater::CollisionControl(Zombie** zombie, int currentZombie){
    CheckLane(zombie, currentZombie);
    for(int i = 0; i < 2; i++){
        bullet[i]->CollisionControl(zombie, currentZombie);
    }
}
void Repeater::Draw(RenderWindow& window){
    if(health <= 0)
        Kill();
    for(int i = 0; i < 2; i++){
        bullet[i]->Draw(window);
    }
    image.animate(window);
    shoot();
}
void Repeater::serialize(ostream& file){
    Plants::serialize(file);
    file.write(reinterpret_cast<const char*>(&justMade), sizeof(justMade));
    for(int i = 0; i < 2; i++){
        bullet[i]->serialize(file);
    }
}
void Repeater::deserialize(istream& file){
    Plants::deserialize(file);
    file.read(reinterpret_cast<char*>(&justMade), sizeof(justMade));
    for(int i = 0; i < 2; i++){
        bullet[i]->deserialize(file);
    }
}
Repeater::~Repeater(){
    for(int i = 0; i < 2; i++){
        if(bullet[i] != nullptr){
            delete bullet[i];
        }
    }
    delete[] bullet;
}
