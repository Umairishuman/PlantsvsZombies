#include"CherryBomb.h"
#include<cmath>
CherryBomb::CherryBomb(int price, Block* block, int health, float cooldownTime, string path):Plants(price, block, health,cooldownTime, path){
    this->blastRadius = 150;
    this->image.setNoOfFrames(27);
    image.setWidth(112);
    image.setLength(81);
    image.setCurrentFrame(0);
    image.setAnimateSpeed(100);

    type = 7;

    if(!bufferBlast.loadFromFile("..\\assets\\music\\cherrybomb.wav")){
        cout << "Error loading cherry bomb sound" << endl;
    }
    soundBlast.setBuffer(bufferBlast);
    soundBlast.setVolume(50);
    soundBlast.setLoop(false);
    blastClock = nullptr;
}

void CherryBomb::CollisionControl(Zombie** zombie, int currentZombie){
    if(this->clock.getElapsedTime().asMilliseconds() > 1000 && killed == false ){
        for(int i = 0; i < currentZombie; i++){
            if(zombie[i]!= nullptr && this->killed == false){
                int x1 = (int)zombie[i]->getZombieSprite().getCoordinates().getX();
                int y1 = (int)zombie[i]->getZombieSprite().getCoordinates().getY();
                int x2 = (int)this->image.getCoordinates().getX();
                int y2 = (int)this->image.getCoordinates().getY();
                int xDistance = abs(x1-x2);
                int yDistance = abs(y1-y2);
                if(xDistance < blastRadius && yDistance < blastRadius){
                    zombie[i]->blast();
                }
            }
        }
        if(soundBlast.getStatus() != Sound::Status::Playing){
            soundBlast.play();
        }
        if(!blastClock){
            blastClock = new Clock();
        }
       
        if(blastClock->getElapsedTime().asMilliseconds() > 300 ){
            this->killed = true;
            this->block->setAvailable(true);
        }
    }
}
void CherryBomb::Draw(RenderWindow& window){
    if(!killed)
        image.animate(window);

}
CherryBomb::~CherryBomb(){
    if(blastClock)
        delete blastClock;
}