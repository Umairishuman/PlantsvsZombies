#include "Executor.h"
Executor::Executor() :screens(nullptr), noOfScreens(6), currentScreen(0) {
    screens = new Screen * [noOfScreens];
    for(int i = 0; i < noOfScreens; i++){
        screens[i] = nullptr;
    }
    "../Images/Plants/Frontyard.jpg";
    MenuScreen* menuScreen = new MenuScreen("..\\assets\\Background\\MenuBackground1.png", "..\\assets\\fonts\\VampireWars.ttf", "..\\assets\\Plants\\Peashooter\\Peashooter_0.png");

    screens[0] = menuScreen;
    screens[0]->setVisible(true);
    if(music.openFromFile("..\\assets\\music\\Main.mp3")){
        music.setVolume(20);
        music.setLoop(true);
        music.play();
    }
}
void Executor::handleInput(Event e, RenderWindow& window) {
    int nextScreen = -1;
    for (int i = 0; i < noOfScreens; i++) {
        if (screens[i] != nullptr && screens[i]->getVisible() == true)
            nextScreen = screens[i]->handleInput(e, window);
        
        if(nextScreen == 0){
            screens[0]->setVisible(true);
        }
        if(nextScreen == 1){
            if(screens[1] != nullptr){
                screens[1]->setVisible(true);
            }
            else{
                screens[1] = new GameScreen("..\\assets\\Background\\Frontyard.jpg", 6);
                screens[1]->setVisible(true);
            }
        }
        else if(nextScreen == 2){
            if(screens[2] != nullptr){
                screens[2]->setVisible(true);
            }
            else{
                GameScreen *game = new GameScreen("..\\assets\\Background\\Frontyard.jpg", 6, true);
                game->loadFromFile("data.dat");
                screens[2] = game;
                screens[2]->setVisible(true);
            }
        }
        else if(nextScreen == 3){
            if(screens[3] != nullptr){
                screens[3]->setVisible(true);
            }
            else{
                screens[3] = new InstructionScreen("..\\assets\\Background\\MenuBackground.jpg", true);
                screens[3]->setVisible(true);
            }
        }
        else if(nextScreen == 4){
            if(screens[4] != nullptr){
                screens[4]->setVisible(true);
            }
            else{
                screens[4] = new HighScore("..\\assets\\Background\\MenuBackground.jpg", true);
                screens[4]->setVisible(true);
            }

        }
        else if(nextScreen == 5){
            if(screens[5] != nullptr){
                
                screens[5]->setVisible(true);
            }
            else{
                screens[5] = new EndScreen("..\\assets\\Background\\ExitBackground.png", true);
                if(screens[2] != nullptr)
                    screens[2]->storeToFile("data.dat");
                screens[5]->setVisible(true);
            }
        }
    }
}

void Executor::Run(RenderWindow& window) {
    for (int i = 0; i < noOfScreens; i++) {
        if (screens[i] != nullptr && screens[i]->getVisible() == true)
            screens[i]->Draw(window);
    }
}

Executor::~Executor() {
    for (int i = 0; i < noOfScreens; i++) {
        delete screens[i];
    }
    delete[] screens;
}