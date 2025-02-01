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

    if (!StartBuffer.loadFromFile(START_SOUND_PATH)) {
        cout << "Error loading sound" << endl;
    }


    LogoClock = nullptr;
    StartSound.setBuffer(StartBuffer);
    StartSound.setVolume(50);
    StartSound.setLoop(false);
    if(StartSound.getStatus() != Sound::Status::Playing){
        StartSound.play();
    }
    logoDisplayed = false;
}
StartScreen::~StartScreen() {
    if (flickerClock)
        delete this->flickerClock;
}
int StartScreen::handleInput(Event event, RenderWindow& window) {
    if (event.key.code == Keyboard::Key::Return) {
        StartSound.stop();
        this->setVisible(false);
        return 1;
    }
    return -1;
}
void StartScreen::DisplayLogo(RenderWindow& window) {
    MySprite logo("..\\assets\\Background\\Logo.png", 0, 0);
    LogoClock = new Clock();
    while (LogoClock->getElapsedTime().asSeconds() < 4) {
        float opacity = LogoClock->getElapsedTime().asSeconds() / 4.0f;
        logo.setOpacity(opacity);
        logo.Draw(window);
        window.display();
        window.clear();
    }
    while (LogoClock->getElapsedTime().asSeconds() < 8) {
        float opacity = 1.0f - (LogoClock->getElapsedTime().asSeconds() - 4.0f) / 4.0f;
        logo.setOpacity(opacity);
        logo.Draw(window);
        window.display();
        window.clear();
    }
    if (LogoClock)
        delete LogoClock;

}
void StartScreen::Draw(RenderWindow& window) {
    if(!logoDisplayed){
        DisplayLogo(window);
        logoDisplayed = true;
    }
    this->Background.Draw(window);
    if(flickerClock->getElapsedTime().asSeconds() > flickerTime){
        this->visible = !this->visible;
        flickerClock->restart();
    }
    if(this->visible){
        window.draw(textContinue);
    }
}