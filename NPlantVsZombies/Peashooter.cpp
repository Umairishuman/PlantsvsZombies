#include"Peashooter.h"
Peashooter::Peashooter(int price, Block* block, int health, float cooldownTime, string path):Shooters(price, block, health, cooldownTime, path){
bullet = new Bullet*[1];
    bullet[0] = new Bullet("..\\assets\\Bullets\\PeaNormal\\pea.png", (int)block->getCoordinates().getX()+53, (int)block->getCoordinates().getY()+10);
    image.setNoOfFrames(77); 
    image.setWidth(71);
    image.setLength(71);
    image.setCurrentFrame(0);
    srand(time(0));    
    type = 1;
    random = rand()%3 + 2;
}
void Peashooter::shoot(){

    if(bullet[0]->getExists() == false && clock.getElapsedTime().asSeconds() > random && shouldShoot){
        shootSound.play();
        
        bullet[0]->reset();
        bullet[0]->setExists(true);
        clock.restart();
    }
}
void Peashooter::CollisionControl(Zombie** zombie, int currentZombie){
    CheckLane(zombie, currentZombie);
    bullet[0]->CollisionControl(zombie, currentZombie);
}
void Peashooter::Draw(RenderWindow& window){
    if(health <= 0)
        Kill();
    bullet[0]->Draw(window);
    image.animate(window);
    shoot();

}
void Peashooter::serialize(ostream& file){
    Plants::serialize(file);
    file.write(reinterpret_cast<const char*>(&random), sizeof(random));
    bullet[0]->serialize(file);
}  
void Peashooter::deserialize(istream& file){
    Plants::deserialize(file);
    file.read(reinterpret_cast<char*>(&random), sizeof(random));
    bullet[0]->deserialize(file);
}
Peashooter::~Peashooter(){
    if(bullet[0] != nullptr){
        delete bullet[0];
        delete[] bullet;
    }
}
