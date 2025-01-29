#include "MenuScreen.h"
MenuScreen::MenuScreen(string backgroundPath, string fontPath, string togglerPath) :Screen(backgroundPath, true), Toggler(togglerPath, 400, 100), NO_OF_OPTIONS(4) {
    this->currentSelection = 1;

    if (!font.loadFromFile(fontPath)) {
        cout << "Error loading font" << endl;
    }
    int StartGameX = 400;
    int StartGameY = 100;
    
    StartGame.setFont(font);
    StartGame.setString("Start Game");
    StartGame.setCharacterSize(50);
    StartGame.setFillColor(Color::Red);
    StartGame.setPosition(StartGameX, StartGameY);

    Instructions.setFont(font);
    Instructions.setString("Instructions");
    Instructions.setCharacterSize(50);
    Instructions.setFillColor(Color::Red);
    Instructions.setPosition(StartGameX, StartGameY*2);

    HighScore.setFont(font);
    HighScore.setString("High Score");
    HighScore.setCharacterSize(50);
    HighScore.setFillColor(Color::Red);
    HighScore.setPosition(StartGameX, StartGameY*3);

    ExitGame.setFont(font);
    ExitGame.setString("Exit Game");
    ExitGame.setCharacterSize(50);
    ExitGame.setFillColor(Color::Red);
    ExitGame.setPosition(StartGameX, StartGameY*4);


}
void MenuScreen::setSelection(int selection) {
    if (selection <= 0) {
        selection = NO_OF_OPTIONS   ;
    }
    else if (selection >= NO_OF_OPTIONS + 1) {
        selection = 1;
    }
    this->currentSelection = selection;
}
int MenuScreen::getSelection() {
    return this->currentSelection;
}

int MenuScreen::handleInput(Event event, RenderWindow& window) {
    if (event.type == Event::KeyPressed) {
        if (event.key.code == Keyboard::Key::Up) {
            setSelection(currentSelection - 1);
            Toggler.setCoordinates(Toggler.getCoordinates().getX(), currentSelection * 100);
        }
        else if (event.key.code == Keyboard::Key::Down) {
            setSelection(currentSelection + 1);
            Toggler.setCoordinates(Toggler.getCoordinates().getX(), currentSelection * 100);
        }
        else if (event.key.code == Keyboard::Key::Return) {
            this->visible = false;
            return currentSelection;
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