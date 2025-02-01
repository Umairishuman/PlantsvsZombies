#include "Executor.h"
Executor::Executor() :screens(nullptr), noOfScreens(6), currentScreen(0) {
    screens = new Screen * [noOfScreens];
    for(int i = 0; i < noOfScreens; i++){
        screens[i] = nullptr;
    }    
    StartScreen* startScreen = new StartScreen(START_BACKGROUND_PATH);    
    screens[0] = startScreen;
    screens[0]->setVisible(true);

    if(music.openFromFile(GAME_MUSIC_PATH)){
        music.setVolume(20);
        music.setLoop(true);
        music.play();
    }
}
void Executor::handleInput(Event e, RenderWindow& window) {
    int nextScreen = -1;

    //GAME INDEX CONSTANTS
    const int START_SCREEN = 0;
    const int MENU_SCREEN = 1;
    const int GAME_SCREEN = 2;
    const int INSTRUCTION_SCREEN = 3;
    const int HIGHSCORE_SCREEN = 4;
    const int EXIT_SCREEN = 5;


    for (int i = 0; i < noOfScreens; i++) {
        if (screens[i] != nullptr && screens[i]->getVisible() == true)
            nextScreen = screens[i]->handleInput(e, window);
        
        if(nextScreen == MENU_SCREEN){
            if(screens[MENU_SCREEN] != nullptr){
                screens[MENU_SCREEN]->setVisible(true);
            }
            else{
                screens[MENU_SCREEN] = new MenuScreen(MENU_BACKGROUND_PATH, MENU_FONT_PATH, MENU_TOGGLER_PATH);
                screens[MENU_SCREEN]->setVisible(true);
                return;
            }
        }
        else if(nextScreen == GAME_SCREEN){
            if(screens[GAME_SCREEN] != nullptr){
                screens[GAME_SCREEN]->setVisible(true);
            }
            else{
                
                screens[GAME_SCREEN] = new GameScreen(GAME_SCREEN_PATH, NO_OF_LEVELS);
                screens[GAME_SCREEN]->setVisible(true);
            }
        }
        else if(nextScreen == INSTRUCTION_SCREEN){
            if(screens[INSTRUCTION_SCREEN] != nullptr){
                screens[INSTRUCTION_SCREEN]->setVisible(true);
            }
            else{
                screens[INSTRUCTION_SCREEN] = new InstructionScreen(INSTRUCTION_BACKGROUND_PATH, true);
                screens[INSTRUCTION_SCREEN]->setVisible(true);
            }
        }
        else if(nextScreen == HIGHSCORE_SCREEN){
            if(screens[HIGHSCORE_SCREEN] != nullptr){
                screens[HIGHSCORE_SCREEN]->setVisible(true);
            }
            else{
                screens[HIGHSCORE_SCREEN] = new HighScore(HIGHSCORE_BACKGROUND_PATH, true);
                screens[HIGHSCORE_SCREEN]->setVisible(true);
            }

        }
        else if(nextScreen == EXIT_SCREEN){
            if(screens[EXIT_SCREEN] != nullptr){
                screens[EXIT_SCREEN]->setVisible(true);
            }
            else{
                screens[EXIT_SCREEN] = new EndScreen(EXIT_BACKGROUND_PATH, true);
                screens[EXIT_SCREEN]->setVisible(true);
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