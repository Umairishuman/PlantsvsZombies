#include "GameScreen.h"
GameScreen::GameScreen(string backgroundPath, int noOfLevels, bool previousState) :Screen(backgroundPath, false), noOflevels(noOfLevels), currentLevel(0),Badge("..\\assets\\Spritesheets\\1st Position.png", 800, 25), NameBack("..\\assets\\Background\\ForNameEntry.jpg", 100, 100), scoreBoard(currentPlayer.getName(), currentPlayer.getScore()){
    levels = new Level* [noOfLevels];
    entpressed = false;
    this->playerCountIndex =0;
    paused = false;
    this->topPlayer = -1;
    this->previousState = previousState;
    for(int i = 0; i < noOfLevels; i++){
        paused = false;
        levels[i] = nullptr;
    }
    for(int i = 0; i < noOfLevels; i++){
        if(i == 0)
            levelBackgrounds[i] = "..\\assets\\Background\\Frontyard.jpg";
        else if(i == 1)
            levelBackgrounds[i] = "..\\assets\\Background\\Frontyard.jpg";
        else if(i == 2)
            levelBackgrounds[i] = "..\\assets\\Background\\Frontyard.jpg";
        else if(i == 3)
            levelBackgrounds[i] = "..\\assets\\Background\\Frontyard4.jpg";
        else if(i == 4)
            levelBackgrounds[i] = "..\\assets\\Background\\Frontyard4.jpg";
        else if(i == 5)
            levelBackgrounds[i] = "..\\assets\\Background\\Frontyard5.png";
    }

    font.loadFromFile("..\\assets\\fonts\\VampireWars.ttf");
    PlayerText.setFont(font);
    PlayerText.setString("");
    PlayerText.setCharacterSize(24);
    PlayerText.setFillColor(Color::Black);
    PlayerText.setPosition(700, 25);

    LoadPlayers();

}
void GameScreen::start() {
    if(currentLevel==6){
        return;
    }
    if(currentLevel == 0){
        AddLevel(1);
        return;
    }
    else if(currentLevel > 0 && currentLevel < noOflevels){
        for(int i = 0; i < currentLevel; i++){
            if(levels[i] != nullptr && levels[i]->getOn() == false){
                cout << currentLevel << endl;
                currentPlayer.setScore(levels[i]->getScore());
                AddLevel(currentLevel + 1);
                if(players[4].getScore() < currentPlayer.getScore()){
                    bool found = false;
                    for(int i = 0; i < 5; i++){
                        if(players[i].getName() == currentPlayer.getName()){
                            players[i].setScore(currentPlayer.getScore());
                            found = true;
                            break;
                        }
                    }
                    if(!found){
                        players[4] = currentPlayer;
                    }
                    SortPlayers();
                }

                delete levels[i];
                levels[i] = nullptr;    
            }
        }
    }
}
void GameScreen::setEntPressed(bool entpressed) {
    this->entpressed = entpressed;
}
void GameScreen::SortPlayers(){
    for(int i = 0; i < playerCountIndex; i++){
        for(int j = 0; j < playerCountIndex - i - 1; j++){
            if(players[j].getScore() < players[j+1].getScore()){
                Player temp = players[j];
                players[j] = players[j+1];
                players[j+1] = temp;
            }
        }
    }
    ofstream outFile("players.txt", std::ios::trunc);
    for(int i = 0; i < 5; i++){
        outFile << players[i].getName() << " " << to_string(players[i].getScore()) << endl;
    }
}
void GameScreen::LoadPlayers(){
    std::ifstream inFile("players.txt", std::ios::in);
    if (inFile.is_open()) {
        std::string name;
        int score;
        while (inFile >> name >> score) {
            players[playerCountIndex].setName(name);players[playerCountIndex].setScore(score);
            playerCountIndex++;
        }
        inFile.close();
    }
    SortPlayers();
}
void GameScreen::AddLevel(int level) {
    if (level == 1) {
        levels[0] = new Level1(levelBackgrounds[0], 6, 0, 1, 5, 1);
        levels[0]->setOn(true);
    }
    else if (level == 2) {
        levels[1] = new Level2(levelBackgrounds[1], 10, 0, 2, 5, 4);
        levels[1]->setOn(true);
    }
    else if (level == 3) {
        levels[2] = new Level3(levelBackgrounds[2], 10, 0, 3, 5, 4);
        levels[2]->setOn(true);
    }
    else if (level == 4) {
        levels[3] = new Level4(levelBackgrounds[3], 15, 0, 5, 5, 4);
        levels[3]->setOn(true);
    }
    else if (level == 5) {
        levels[4] = new Level5(levelBackgrounds[4], 15, 0, 6, 5, 4);
        levels[4]->setOn(true);
    }
    else if (level == 6) {
        levels[5] = new Level6(levelBackgrounds[5], 15, 0, 7, 5, 4);
        levels[5]->setOn(true);
    }
    levels[level - 1]->setScore(currentPlayer.getScore());
    currentLevel++;
}
void GameScreen::setCurrentLevel(int level) {
    currentLevel = level;
}
int GameScreen::getCurrentLevel() {
    return currentLevel;
}
void GameScreen::setPaused(bool paused) {
    this->paused = paused;
}
bool GameScreen::getPaused() {
    return paused;
}
int GameScreen::handleInput(Event e, RenderWindow& window) {
    if(e.type == Event::KeyPressed ){
        if(e.key.code == Keyboard::Key::Escape){
            visible = false;
            return 0;
        }
    }


    if(!previousState){
        if(e.type == Event::KeyPressed && e.key.code == Keyboard::Enter){
            if(!entpressed){
                entpressed = true;
                return -1;
            }
            for(int i = 0; i < playerCountIndex; i++){
                if(currentPlayer.getName() == players[i].getName()){
                    if(i <= 2)
                        topPlayer = i;
                    break;
                }
            }
            previousState = true;
            currentPlayer.setScore(0);
            return -1;
        }
        currentPlayer.EnterName(e);
        return -1;
    }
    for (int i = 0; i < currentLevel; i++) {
        if(levels[i] != nullptr && levels[i]->getOn() == true){
            levels[i]->handleInput(e, window);
        }
    }
    return -1;
}
void GameScreen::Draw(RenderWindow& window) {
    if(!previousState){
        Background.Draw(window);
        NameBack.Draw(window);
        currentPlayer.Draw(window);
        return;
        scoreBoard.Draw(window);
    }
    start();
    for (int i = 0; i < currentLevel; i++) {
        if (levels[i] != nullptr && levels[i]->getOn() == true)
            levels[i]->Draw(window);
    }
    PlayerText.setString("Player: " + currentPlayer.getName());
    window.draw(PlayerText);
    if(topPlayer == 0){
        Badge.setPath("..\\assets\\Spritesheets\\1st Position.png");
        Badge.setCoordinates(900, 25);
        Badge.Draw(window);
    }
    else if(topPlayer == 1){
        Badge.setPath("..\\assets\\Spritesheets\\2nd Position.png");
        Badge.setCoordinates(900, 25);
        Badge.Draw(window);
    }
    else if(topPlayer == 2){
        Badge.setPath("..\\assets\\Spritesheets\\3rd Position.png");
        Badge.setCoordinates(900, 25);
        Badge.Draw(window);
    }
}

void GameScreen::serialize(ostream& file) {
    cout << "GameScreen serializing\n";
    
    file.write(reinterpret_cast<const char*>(&noOflevels), sizeof(noOflevels));
    file.write(reinterpret_cast<const char*>(&currentLevel), sizeof(currentLevel));
    for (int i = 0; i < noOflevels; i++) {
        if (levels[i] != nullptr ) {
            levels[i]->serialize(file);
        }
    }
    file.write(reinterpret_cast<const char*>(&previousState), sizeof(previousState));
    file.write(reinterpret_cast<const char*>(&paused), sizeof(paused));
    file.write(reinterpret_cast<const char*>(&entpressed), sizeof(entpressed));
    NameBack.serialize(file);
    Badge.serialize(file);
    currentPlayer.serialize(file);
    cout << "GameScreen serialized\n";
}
void GameScreen::deserialize(istream& file) {
    file.read(reinterpret_cast<char*>(&noOflevels), sizeof(noOflevels));
    file.read(reinterpret_cast<char*>(&currentLevel), sizeof(currentLevel));
    if(currentLevel - 1 == 0){
        AddLevel(1);
    }
    else if(currentLevel - 1 == 1){
        AddLevel(2);
    }
    else if(currentLevel - 1 == 2){
        AddLevel(3);
    }
    else if(currentLevel - 1 == 3){
        AddLevel(4);
    }
    else if(currentLevel - 1 == 4){
        AddLevel(5);
    }
    else if(currentLevel - 1 == 5){
        AddLevel(6);
    }
        levels[currentLevel-1]->deserialize(file);
    file.read(reinterpret_cast<char*>(&previousState), sizeof(previousState));
    file.read(reinterpret_cast<char*>(&paused), sizeof(paused));
    file.read(reinterpret_cast<char*>(&entpressed), sizeof(entpressed));
    NameBack.deserialize(file);
    Badge.deserialize(file);
    currentPlayer.deserialize(file);
}

void GameScreen::saveToFile(string filename) {
    ofstream outFile(filename, std::ios::binary);
    if(!outFile.is_open()){
        cout << "File not opened\n";
        ofstream newfile(filename, std::ios::binary);
       serialize(newfile);
        newfile.close();
    }
    else 
        serialize(outFile);
    outFile.close();
}
void GameScreen::loadFromFile(string filename) {
    ifstream inFile(filename, std::ios::binary);
    cout << "Loading from file\n";
    deserialize(inFile);
    inFile.close();
}

GameScreen::~GameScreen(){
    for (int i = 0 ; i < currentLevel; i++){
        if(this->levels[i] != nullptr){
            delete levels[i];
        }
    }
    if(levels!= nullptr)
        delete levels;

}
