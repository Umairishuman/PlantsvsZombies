#include "Level.h"
Level::Level(string backPath, int noOfZombies, int noOfWaves, int allowedPlants, bool isOn, int noOflanes, int allowedZombies) :Background(backPath), noOfZombies(noOfZombies), allowedPlants(allowedPlants), isOn(isOn),noOflanes(noOflanes), sun(0, 0,71, 71){
    levelCleared = false;
    this->noOfZombies = noOfZombies;
    this->lives = 3;
    this->score = 0;
    this->allowedZombies = allowedZombies;
    grid = new Grid(5, 255, 80, 101);
    selection = false;
    selector = -1;
    plantFactory = new PlantFactory(allowedPlants, grid);
    zombieFactory = new ZombieFactory(noOfZombies, allowedZombies, grid, score);
    lawnMower = new LawnMower*[noOflanes];
    this->sunAmount = 100;
    GameOver = false;


    if (!font.loadFromFile("..\\assets\\fonts\\VampireWars.ttf")) {
        cout << "Error loading font" << endl;
    }
    sunText.setFont(font);
    sunText.setString(to_string(sunAmount));
    sunText.setCharacterSize(25);
    sunText.setFillColor(Color::Black);
    sunText.setPosition(25, 50);  

    livesText.setFont(font);
    livesText.setString("Lives: " + to_string(lives));
    livesText.setCharacterSize(25);
    livesText.setFillColor(Color::Black);
    livesText.setPosition(500, 25);

    scoreText.setFont(font);
    scoreText.setString("Score: " + to_string(score));
    scoreText.setCharacterSize(25);
    scoreText.setFillColor(Color::Black);
    scoreText.setPosition(500, 50);

    LevelUpText.setFont(font);
    LevelUpText.setString("Level UP!!");
    LevelUpText.setCharacterSize(60);
    LevelUpText.setFillColor(Color::Black);
    LevelUpText.setPosition(400, 250);

    if(!soundLevelUp.openFromFile("..\\assets\\music\\levelup.mp3")){
        cout << "Error loading sound" << endl;
    }
    soundLevelUp.setVolume(50);
    soundLevelUp.setLoop(false);


    for(int i = 0; i < noOflanes; i++){
        lawnMower[i] = new LawnMower(160, 80 + i*101, "..\\assets\\Spritesheets\\lawnmower.png");
    }
}

void Level::setOn(bool isOn) {
    this->isOn = isOn;
}
void Level::setNoOfZombies(int noOfZombies) {
    this->noOfZombies = noOfZombies;
}

bool Level::getGameOver() {
    return GameOver;
}
void Level::setAllowedPlants(int allowedPlants) {
    this->allowedPlants = allowedPlants;
}
int Level::getNoOfZombies() {
    return noOfZombies;
}
bool Level::getLevelCleared() {
    return levelCleared;
}

int Level::getAllowedPlants() {
    return allowedPlants;
}
bool Level::getOn() {
    return isOn;
}
void Level::setSunAmount(int sunAmount) {
    this->sunAmount = sunAmount;
}
int Level::getScore(){
    return this->score;
}
int Level::getSunAmount() {
    return sunAmount;
}
int Level::getLives() {
    return lives;
}
void Level::setLives(int lives) {
    this->lives = lives;
}
void Level::setScore(int score) {
    this->score = score;
}
void Level::CheckZombiePlantCollision(){
    for(int i = 0; i < zombieFactory->getCurrentZombie(); i++){
        if(zombieFactory->getZombies()[i] != nullptr){
            for(int j = 0; j < plantFactory->getCurrentPlant(); j++){
                if(plantFactory->getPlants()[j] != nullptr){
                    if(zombieFactory->getZombies()[i]->getCoordinates().getX() == plantFactory->getPlants()[j]->getCoordinates().getX() && zombieFactory->getZombies()[i]->getCoordinates().getY() == plantFactory->getPlants()[j]->getCoordinates().getY()-45){
                        zombieFactory->getZombies()[i]->eat();
                        if(zombieFactory->getZombies()[i]->geteatingClock().getElapsedTime().asSeconds() > 1)
                            plantFactory->getPlants()[j]->setHealth(plantFactory->getPlants()[j]->getHealth() - 1);
                        if(plantFactory->getPlants()[j]->getHealth() <= 0){
                            zombieFactory->getZombies()[i]->stopeat();
                        }
                    }
                        
                }
            }
        }
    }
}
void Level::CollsionControl(){
    CheckZombiePlantCollision();
    plantFactory->CollisionControl(zombieFactory->getZombies(), zombieFactory->getCurrentZombie());
    for(int i = 0; i < zombieFactory->getCurrentZombie(); i++){
        if(zombieFactory->getZombies()[i] != nullptr){
            if(zombieFactory->getZombies()[i]->getHasReached() == true){

                lives--;
                if(lives == 0)
                    GameOver = true;
                delete zombieFactory->getZombies()[i];
                zombieFactory->getZombies()[i] = nullptr;
            }
        }
    }
    for(int i = 0; i < noOflanes; i++){
        lawnMower[i]->CollisionControl(zombieFactory->getZombies(), zombieFactory->getCurrentZombie());
    }
}

int Level::handleInput(Event e, RenderWindow& window){
    int temp = plantFactory->handleInput(e, window, sunAmount);
    if(temp == -2){
        sunAmount += 25;
    }
    if(temp >= 0 && temp < allowedPlants && plantFactory->getCards()[temp]->getPrice() <= sunAmount){
        selector = temp;
        this->selection = true;
    }
    //when user clicks on the block the selected plant will be planted on that block
    if(selection == true){
        int x1 = (int)plantFactory->getCards()[selector]->getPlantCard().getCoordinates().getX();
        int y1 = (int)plantFactory->getCards()[selector]->getPlantCard().getCoordinates().getY();
        plantFactory->getSelectorSprite().setCoordinates(x1 , y1);
        if(e.type == Event::MouseButtonPressed){
            for(int i = 0 ; i < noOflanes; i++){
                for (int j = 0; j < 9; j++){
                    if(grid->getLanes()[i]->getBlocks()[j]->checkHover(window)){
                        int x = (int)grid->getLanes()[i]->getBlocks()[j]->getCoordinates().getX();
                        int y = (int)grid->getLanes()[i]->getBlocks()[j]->getCoordinates().getY();
                        selection = false;
                        if(grid->getLanes()[i]->getBlocks()[j]->getAvailable() == true){
                            plantFactory->addPlant(selector, grid->getLanes()[i]->getBlocks()[j]);
                            sunAmount -= plantFactory->getCards()[selector]->getPrice();
                            plantFactory->getCards()[selector]->getCooldownClock().restart();

                            grid->getLanes()[i]->getBlocks()[j]->setAvailable(false);
                        }
                        selector = -1;
                    }
                }
            }
        }   
    }
    return 0;
}
bool Level::CheckForSelection(RenderWindow& window){
    if(selection){
        for(int i = 0 ; i < noOflanes; i++){
            for (int j = 0; j < 9; j++){
                if(grid->getLanes()[i]->getBlocks()[j]->checkHover(window) && grid->getLanes()[i]->getBlocks()[j]->getAvailable() == true){
                    int x = (int)grid->getLanes()[i]->getBlocks()[j]->getCoordinates().getX();
                    int y = (int)grid->getLanes()[i]->getBlocks()[j]->getCoordinates().getY();

                    plantFactory->getCards()[selector]->getPlantimage().setCoordinates(x, y);

                    return true;
                }
            }
        }
    }
    return false;
}

void Level::serialize(ostream& file){
    Background.serialize(file);
    file.write(reinterpret_cast<const char*>(&isOn), sizeof(isOn));
    sun.serialize(file);
    file.write(reinterpret_cast<const char*>(&noOfZombies), sizeof(noOfZombies));
    file.write(reinterpret_cast<const char*>(&allowedPlants), sizeof(allowedPlants));
    file.write(reinterpret_cast<const char*>(&selector), sizeof(selector));
    file.write(reinterpret_cast<const char*>(&selection), sizeof(selection));
    file.write(reinterpret_cast<const char*>(&sunAmount), sizeof(sunAmount));
    file.write(reinterpret_cast<const char*>(&lives), sizeof(lives));
    file.write(reinterpret_cast<const char*>(&score), sizeof(score));
    file.write(reinterpret_cast<const char*>(&levelCleared), sizeof(levelCleared));
    file.write(reinterpret_cast<const char*>(&noOflanes), sizeof(noOflanes));
    file.write(reinterpret_cast<const char*>(&allowedZombies), sizeof(allowedZombies));
    grid->serialize(file);
    sun.serialize(file);
    plantFactory->serialize(file);
    zombieFactory->serialize(file);
    for(int i = 0; i < noOflanes; i++){
        lawnMower[i]->serialize(file);
    }
}
void Level::deserialize(istream& file){
    Background.deserialize(file);
    file.read(reinterpret_cast<char*>(&isOn), sizeof(isOn));
    sun.deserialize(file);
    cout << "Loading level" << endl;
    file.read(reinterpret_cast<char*>(&noOfZombies), sizeof(noOfZombies));
    file.read(reinterpret_cast<char*>(&allowedPlants), sizeof(allowedPlants));
    file.read(reinterpret_cast<char*>(&selector), sizeof(selector));
    file.read(reinterpret_cast<char*>(&selection), sizeof(selection));
    file.read(reinterpret_cast<char*>(&sunAmount), sizeof(sunAmount));
    file.read(reinterpret_cast<char*>(&lives), sizeof(lives));
    file.read(reinterpret_cast<char*>(&score), sizeof(score));
    file.read(reinterpret_cast<char*>(&levelCleared), sizeof(levelCleared));
    file.read(reinterpret_cast<char*>(&noOflanes), sizeof(noOflanes));
    file.read(reinterpret_cast<char*>(&allowedZombies), sizeof(allowedZombies));
    grid->deserialize(file);
    sun.deserialize(file);
    plantFactory->deserialize(file);
    zombieFactory->deserialize(file);
    lawnMower = new LawnMower*[noOflanes];
    for(int i = 0; i < noOflanes; i++){
        lawnMower[i] = new LawnMower(160, 80 + i*101, "..\\assets\\Spritesheets\\lawnmower.png");
        lawnMower[i]->deserialize(file);
    }
    font.loadFromFile("..\\assets\\fonts\\VampireWars.ttf");
}

Level::~Level() {
    delete grid;
    delete plantFactory;
    delete zombieFactory;
    for(int i = 0; i < noOflanes; i++){
        delete lawnMower[i];
    }
    delete lawnMower;
    lawnMower = nullptr;
}