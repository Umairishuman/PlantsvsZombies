#include"FlyingZombies.h"
FlyingZombies::FlyingZombies(string path, int x, int y, int noOfframes, int width, int length, int speed, int Killhits, int &score):Zombie(path, x, y, noOfframes, width, length, speed, Killhits, score){
    ZombieSprite.setAnimateSpeed(100);
    type = 4;
}
FlyingZombies::~FlyingZombies(){}

void FlyingZombies::eat(){
    
}
