#include"StartScreen.h"
StartScreen::StartScreen(string backgroundPath) :Screen(backgroundPath, true) {
    Background.setOpacity(0.5);
    if (!font.loadFromFile(FONT_PATH)) {
        cout << "Error loading font" << endl;
    }
    textContinue.setFont(font);
    textContinue.setString("PRESS ENTER TO CONTINUE!!");
    textContinue.setCharacterSize(50);
    textContinue.setFillColor(Color::Green);
    textContinue.setPosition(250, 250);

    this->flickerClock = new Clock();
    this->flickerTime = 0.5;
}
StartScreen::~StartScreen() {
    if (flickerClock)
        delete this->flickerClock;
}
int StartScreen::handleInput(Event event, RenderWindow& window) {
    if (event.key.code == Keyboard::Key::Return) {
        this->setVisible(false);
        return 1;
    }
    return -1;
}
void StartScreen::Draw(RenderWindow& window) {
    this->Background.Draw(window);
    if(flickerClock->getElapsedTime().asSeconds() > flickerTime){
        this->visible = !this->visible;
        flickerClock->restart();
    }
    if(this->visible){
        window.draw(textContinue);
    }
}