#include"Level6.h"
Level6::Level6(string backgroundPath, int noOfZombies, int noOfWaves, int allowedPlants, int noOflanes, int allowedZombies):Level(backgroundPath, noOfZombies, noOfWaves, allowedPlants, true, noOflanes, allowedZombies){
    LevelText.setFont(font);
    LevelText.setString("Level 2");
    LevelText.setCharacterSize(60);
    LevelText.setFillColor(Color::Black);
    LevelText.setPosition(500, 250);

    GameOverText.setFont(font);
    GameOverText.setString("Game Over");
    GameOverText.setCharacterSize(60);
    GameOverText.setFillColor(Color::Red);
    GameOverText.setPosition(400, 250);

}
int Level6::handleInput(Event e, RenderWindow& window){
    if(GameOver){
        return -1;
    }
    Level::handleInput(e, window);
    if(sun.handleInput(e, window)){
        sunAmount += 25;
    }
    return 0;
}
void Level6::Draw(RenderWindow& window){
    if(zombieFactory->getZombiesSpawned() == noOfZombies && !levelCleared){
        bool flag = false;
        for(int i = 0 ;i < zombieFactory->getCurrentZombie(); i++){
            if(zombieFactory->getZombies()[i] != nullptr){
                flag = true;
                break;
            }
            else {
                flag = false;
            }
        }
        if(!flag){
            levelCleared = true;
            levelIntro.restart();
            return;
        }

    }
    if(GameOver){
        window.draw(GameOverText);
        return;
    }
    CollsionControl();
    if(levelClock.getElapsedTime().asSeconds() > 10){
        //sun.SpawnSun();
        levelClock.restart();
    }
    Background.Draw(window);
    plantFactory->Draw(window);
    if(CheckForSelection(window)){
        plantFactory->getCards()[selector]->getPlantimage().Draw(window);
    }
    if(selection)
        plantFactory->getSelectorSprite().Draw(window);
    sunText.setString(to_string(sunAmount));
    window.draw(sunText);
    zombieFactory->Draw(window);
    for(int i = 0; i < noOflanes; i++){
        if(lawnMower[i]->getUsed() == false){
            lawnMower[i]->Draw(window);
        }
    }
    livesText.setString("Lives: " + to_string(lives));  
    window.draw(livesText);
    scoreText.setString("Scores: " + to_string(score));
    window.draw(scoreText);
    sun.Draw(window);
    if(levelIntro.getElapsedTime().asSeconds() < 3 && !levelCleared){
        window.draw(LevelText);
    }
    if(levelCleared && levelIntro.getElapsedTime().asSeconds() < 3){
        window.draw(LevelUpText);
    }
    if(levelCleared && levelIntro.getElapsedTime().asSeconds() > 3){
        isOn = false;
    }
}
Level6::~Level6(){
    
}
