#include"ZombieFactory.h"
ZombieFactory::ZombieFactory(int noOfZombies ,int allowedZombies, Grid*& grid, int &score):score(score){
    this->grid = grid;
    this->allowedZombies = allowedZombies;
    this->noOfZombies = noOfZombies;
    currentZombie = 0;
    zombies = new Zombie*[noOfZombies];
    for (int i = 0; i < noOfZombies; i++){
        zombies[i] = nullptr;
    }
    aliveZombies = 0;
    ZombiesSpawned = 0;

    spawningTime = 10;

}

void ZombieFactory::decrementSpawnTime() {
   /* if (this->spawningTime <= 2) {
        spawningTime = 1;
    }
    else
        this->spawningTime = this->spawningTime - 1;*/

    if (spawningTime > 2) {
        // Reduce spawning time by a small, controlled amount
        spawningTime -= 0.5;
    }
    else {
        // Set a minimum spawn time to avoid excessive spawning
        spawningTime = 2;
    }

}

void ZombieFactory::setCurrentZombie(int currentZombie){
    this->currentZombie = currentZombie;
}
int ZombieFactory::getZombiesSpawned(){
    return ZombiesSpawned;
}
int ZombieFactory::getCurrentZombie(){
    return currentZombie;
}
int ZombieFactory::selectLane(){
    srand(time(0));
    int random = rand() % 5;
    return random;
}
int ZombieFactory::selectZombie(){
    srand(time(0));
    int random = rand() % allowedZombies;
    return random;
}
void ZombieFactory::SpawnZombie(bool Summon){
    int Lane = selectLane();
    int zombieNo = selectZombie();
   /* if((ZombieSpawnClock.getElapsedTime().asSeconds() > spawningTime || Summon) && currentZombie < noOfZombies && ZombiesSpawned < noOfZombies){
        Zombie* zombie = nullptr;
        ZombiesSpawned++;
        int y = (int)grid->getLanes()[Lane]->getBlocks()[0]->getCoordinates().getY();
        if(zombieNo == 0)
            zombie = new SimpleZombie("..\\assets\\Spritesheets\\nZombWalk.png",Summon?800:900, y - 45, 22, 166, 144, 120, 5, score);
        if(zombieNo ==1 )
            zombie = new FootballZombie("..\\assets\\Spritesheets\\Conehead.png", Summon?800:900, y - 45, 21, 166, 144, 120, 22, score);
        if(zombieNo >= 2){
            zombie = new DancingZombie("..\\assets\\Spritesheets\\zombiedance.png",Summon?800:900, y - 45, 10, 166, 144, 140, 7, score);
        }
        if(zombieNo == 3){
            zombie = new FlyingZombies("..\\assets\\Spritesheets\\FlyingZOmbe.png", Summon?800:900, y - 45, 8, 106, 144, 170, 11, score);
        }

        this->AddZombie(zombie);  
        if(SpawnTimeClock.getElapsedTime().asSeconds() > 3)
            decrementSpawnTime();
        ZombieSpawnClock.restart();
    }*/

    if ((ZombieSpawnClock.getElapsedTime().asSeconds() > spawningTime || Summon) && currentZombie < noOfZombies && ZombiesSpawned < noOfZombies) {
        Zombie* zombie = nullptr;
        ZombiesSpawned++;
        int y = (int)grid->getLanes()[Lane]->getBlocks()[0]->getCoordinates().getY();

        switch (zombieNo) {
        case 0:
            zombie = new SimpleZombie("..\\assets\\Spritesheets\\nZombWalk.png", Summon ? 800 : 900, y - 45, 22, 166, 144, 120, 5, score);
            break;
        case 1:
            zombie = new FootballZombie("..\\assets\\Spritesheets\\Conehead.png", Summon ? 800 : 900, y - 45, 21, 166, 144, 120, 22, score);
            break;
        case 2:
            zombie = new DancingZombie("..\\assets\\Spritesheets\\zombiedance.png", Summon ? 800 : 900, y - 45, 10, 166, 144, 140, 7, score);
            break;
        case 3:
            zombie = new FlyingZombies("..\\assets\\Spritesheets\\FlyingZOmbe.png", Summon ? 800 : 900, y - 45, 8, 106, 144, 170, 11, score);
            break;
        }

        this->AddZombie(zombie);

        if (SpawnTimeClock.getElapsedTime().asSeconds() > 10) {
            decrementSpawnTime();
            SpawnTimeClock.restart();
        }

        ZombieSpawnClock.restart();
    }

}
void ZombieFactory::AddZombie(Zombie* zombie){
    for(int i = 0; i < currentZombie; i++){
        if(zombies[i] == nullptr){
            zombies[i] = zombie;
            return;
        }
    }
    zombies[currentZombie] = zombie;
    currentZombie++;
}
Zombie** ZombieFactory::getZombies(){
    return zombies;
}
void ZombieFactory::Draw(RenderWindow& window){
    SpawnZombie();
    aliveZombies = 0;
    for(int i = 0; i < currentZombie; i++){
        if(zombies[i] != nullptr){
            aliveZombies++;
        }
    }
    for(int i = 0; i < currentZombie; i++){
        if(zombies[i] != nullptr ){
            if(zombies[i]->summonZombies()){
                SpawnZombie(true);SpawnZombie(true);
            }
        }
    }
    for(int i = 0; i < currentZombie; i++){
        if(zombies[i] != nullptr && zombies[i]->getKilled() ){
            delete zombies[i];
            zombies[i] = nullptr; 
        }
        if(zombies[i] != nullptr)
            zombies[i]->Draw(window);
    }
}

void ZombieFactory::serialize(ostream& file){
    file.write(reinterpret_cast<const char*>(&score), sizeof(score));
    file.write(reinterpret_cast<const char*>(&allowedZombies), sizeof(allowedZombies));
    file.write(reinterpret_cast<const char*>(&currentZombie), sizeof(currentZombie));
    file.write(reinterpret_cast<const char*>(&noOfZombies), sizeof(noOfZombies));
    file.write(reinterpret_cast<const char*>(&ZombiesSpawned), sizeof(ZombiesSpawned));
    file.write(reinterpret_cast<const char*>(&aliveZombies), sizeof(aliveZombies));
    
    for(int i = 0; i < noOfZombies; i++){
        if(zombies[i] != nullptr){
            zombies[i]->serialize(file);
        }
    }
}
void ZombieFactory::deserialize(istream& file){
    file.read(reinterpret_cast<char*>(&score), sizeof(score));
    file.read(reinterpret_cast<char*>(&allowedZombies), sizeof(allowedZombies));
    file.read(reinterpret_cast<char*>(&currentZombie), sizeof(currentZombie));
    file.read(reinterpret_cast<char*>(&noOfZombies), sizeof(noOfZombies));
    file.read(reinterpret_cast<char*>(&ZombiesSpawned), sizeof(ZombiesSpawned));
    file.read(reinterpret_cast<char*>(&aliveZombies), sizeof(aliveZombies));

    for(int i = 0; i < aliveZombies; i++){
        int type;
        file.read(reinterpret_cast<char*>(&type), sizeof(type));
        if(type == 1){
            zombies[i] = new SimpleZombie("..\\assets\\Spritesheets\\nZombWalk.png",1000, 237, 22, 166, 144, 170, 11, score);
            zombies[i]->deserialize(file);
        }
        if(type == 2){
            zombies[i] = new FootballZombie("..\\assets\\Spritesheets\\Conehead.png", 1000, 237, 21, 166, 144, 170, 22, score);
            zombies[i]->deserialize(file);
        }
        if(type == 3){
            zombies[i] = new DancingZombie("..\\assets\\Spritesheets\\zombiedance.png", 1000, 237, 10, 166, 144, 140, 7, score);
            zombies[i]->deserialize(file);
        }
        if(type == 4){
            zombies[i] = new FlyingZombies("..\\assets\\Spritesheets\\FlyingZOmbe.png", 1000, 237, 8, 106, 144, 170, 11, score);
            zombies[i]->deserialize(file);
        }

    }
}
ZombieFactory::~ZombieFactory(){
    for(int i = 0; i < noOfZombies; i++){
        if(zombies[i] != nullptr){
            delete zombies[i];
        }
    }
    if(zombies != nullptr)
        delete zombies;
}