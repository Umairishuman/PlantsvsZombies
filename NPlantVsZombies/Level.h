#pragma once
#ifndef LEVEL_H
#define LEVEL_H
#include"MySprite.h"
#include"Grid.h"  
#include"PlantFactory.h"
#include"ZombieFactory.h"
#include"Sun.h"
#include"LawnMower.h"
class Level{
protected:
    Clock levelIntro;
    Clock levelClock;
    MySprite Background;
    Grid *grid;
    bool isOn;
    Sun sun;
    int noOfZombies;
    int allowedPlants;
    int selector;
    int noOflanes;
    int sunAmount;
    bool selection;
    int allowedZombies;
    int lives;
    int score;
    bool GameOver;
    bool levelCleared;

    LawnMower** lawnMower;
    PlantFactory* plantFactory;
    ZombieFactory* zombieFactory;
    
    Font font;
    Text sunText;
    Text livesText;
    Text scoreText;
    Text LevelText;
    Text GameOverText;
    Text LevelUpText;

    Music soundLevelUp;
public:
    Level(string backPath = 0, int noOfZombies = 0, int noOfWaves = 0, int allowedPlants = 0, bool isOn = true, int noOflanes = 0, int allowedZombies = 5);
    virtual ~Level();
    
    void setOn(bool isOn);
    void setNoOfZombies(int noOfZombies);
    void setAllowedPlants(int allowedPlants);
    void setSunAmount(int sunAmount);
    void setLives(int lives);
    void setScore(int score);
    int getScore();
    int getLives();
    int getSunAmount();
    int getNoOfZombies();
    int getAllowedPlants();
    bool getOn();
    bool CheckForSelection(RenderWindow& window);
    bool getGameOver();
    bool getLevelCleared();
    void CheckZombiePlantCollision();
    void CollsionControl();
    virtual int handleInput(Event e, RenderWindow& window);
    virtual void Draw(RenderWindow& window) = 0 ;

    virtual  void serialize(ostream& file);
    virtual void deserialize(istream& file);
};
#endif

