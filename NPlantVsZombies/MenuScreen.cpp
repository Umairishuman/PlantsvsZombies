#include "MenuScreen.h"
MenuScreen::MenuScreen(string backgroundPath, string fontPath, string togglerPath) :Screen(backgroundPath, true), Toggler(togglerPath, 300, 100), NO_OF_OPTIONS(4) {
    this->currentSelection = 1;

    

    this->Background.setOpacity(0.5);
    if (!font.loadFromFile(fontPath)) {
        cout << "Error loading font" << endl;
    }
    int StartGameX = 400;
    int StartGameY = 100;
    
    StartGame.setFont(font);
    StartGame.setString("START GAME");
    StartGame.setCharacterSize(60);
    StartGame.setPosition(StartGameX, StartGameY);
    StartGame.setFillColor(Color::Green);

    Instructions.setFont(font);
    Instructions.setString("INSTRUCTIONS");
    Instructions.setCharacterSize(60);
    Instructions.setPosition(StartGameX, StartGameY*2);
    Instructions.setFillColor(Color(27, 131, 27));

    HighScore.setFont(font);
    HighScore.setString("HIGH SCORE");
    HighScore.setCharacterSize(60);
    HighScore.setPosition(StartGameX, StartGameY*3);
    HighScore.setFillColor(Color(27, 131, 27));

    ExitGame.setFont(font);
    ExitGame.setString("EXIT GAME");
    ExitGame.setCharacterSize(60);
    ExitGame.setPosition(StartGameX, StartGameY*4);
    ExitGame.setFillColor(Color(27, 131, 27));

    //setting sound
    togglebuffer.loadFromFile("..\\assets\\music\\toggle.wav");
    for(int i = 0; i < 5; i++){
        toggleSound[i].setBuffer(togglebuffer);
        toggleSound[i].setVolume(50);
        toggleSound[i].setLoop(false);
    }
}
void MenuScreen::setSelection(int selection) {
    if (selection <= 0) {
        selection = NO_OF_OPTIONS;
    }
    else if (selection >= NO_OF_OPTIONS + 1) {
        selection = 1;
    }
    this->currentSelection = selection;
    if(selection == 1){
        StartGame.setFillColor(Color::Green);
        Instructions.setFillColor(Color(27, 131, 27));
        HighScore.setFillColor(Color(27, 131, 27));
        ExitGame.setFillColor(Color(27, 131, 27));
    }
    else if(selection == 2){
        StartGame.setFillColor(Color(27, 131, 27));
        Instructions.setFillColor(Color::Green);
        HighScore.setFillColor(Color(27, 131, 27));
        ExitGame.setFillColor(Color(27, 131, 27));
    }
    else if(selection == 3){
        StartGame.setFillColor(Color(27, 131, 27));
        HighScore.setFillColor(Color::Green);
        Instructions.setFillColor(Color(27, 131, 27));
        ExitGame.setFillColor(Color(27, 131, 27));
    }
    else if(selection == 4){
        StartGame.setFillColor(Color(27, 131, 27));
        Instructions.setFillColor(Color(27, 131, 27));
        HighScore.setFillColor(Color(27, 131, 27));
        ExitGame.setFillColor(Color::Green);
    }
}
int MenuScreen::getSelection() {
    return this->currentSelection;
}

int MenuScreen::handleInput(Event event, RenderWindow& window) {
    if (event.type == Event::KeyPressed) {
        if (event.key.code == Keyboard::Key::Up) {
            setSelection(currentSelection - 1);
            Toggler.setCoordinates(Toggler.getCoordinates().getX(), currentSelection * 100);
            
            for(int i = 0; i < SOUND_POOL_SIZE; i++){
                if(toggleSound[i].getStatus() != Sound::Status::Playing){
                    toggleSound[i].play();
                    break;
                }
            }
        }
        else if (event.key.code == Keyboard::Key::Down) {
            setSelection(currentSelection + 1);
            Toggler.setCoordinates(Toggler.getCoordinates().getX(), currentSelection * 100);
            for(int i = 0; i < SOUND_POOL_SIZE; i++){
                if(toggleSound[i].getStatus() != Sound::Status::Playing){
                    toggleSound[i].play();
                    break;
                }
            }
            
        }
        else if (event.key.code == Keyboard::Key::Return) {
            this->visible = false;
            return currentSelection + 1;
        }
        return 0;


    }
    return 0;
}
void MenuScreen::Draw(RenderWindow& window) {

    Background.Draw(window);
    window.draw(StartGame);
    window.draw(ResumeGame);
    window.draw(Instructions);
    window.draw(HighScore);
    window.draw(ExitGame);
    Toggler.Draw(window);
}
MenuScreen::~MenuScreen() {

}