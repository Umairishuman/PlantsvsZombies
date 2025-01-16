#include"SimpleZombie.h"
SimpleZombie::SimpleZombie(string path, int x, int y, int noOfframes, int width, int length, int speed, int Killhits, int &score):Zombie(path, x, y, noOfframes, width, length, speed, Killhits, score){
    type =1;
}
SimpleZombie::~SimpleZombie(){
}

