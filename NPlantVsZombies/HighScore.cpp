#include"HighScore.h"
HighScore::HighScore(string path, bool visible):Screen(path, false){
    font.loadFromFile("..\\assets\\fonts\\VampireWars.ttf");
    text.setFont(font);
    text.setString("High Scores");
    text.setCharacterSize(60);
    text.setFillColor(Color::Red);
    text.setPosition(400, 30);

    Player1.setFont(font);
    Player2.setFont(font);
    Player3.setFont(font);
    Player4.setFont(font);
    Player5.setFont(font);

    Player1.setCharacterSize(36);
    Player2.setCharacterSize(36);
    Player3.setCharacterSize(36);
    Player4.setCharacterSize(36);
    Player5.setCharacterSize(36);

    Player1.setFillColor(Color::White);
    Player2.setFillColor(Color::White);
    Player3.setFillColor(Color::White);
    Player4.setFillColor(Color::White);
    Player5.setFillColor(Color::White);

}
HighScore::~HighScore(){}
void HighScore::getHighScores(){
    ifstream inFile("players.txt", std::ios::in);
    if (!inFile.is_open()) {
        cout << "Failed to open the file." << endl;
        return;
    }
    string name;
    int score = 0;
    int i = 0;
    while(inFile >> name >> score){
        players[i].setName(name); players[i].setScore(score);
        i++;
    }
    inFile.close();

    Player1.setString("1. " + players[0].getName() + " " + to_string(players[0].getScore()));
    Player1.setPosition(200, 200);
    Player2.setString("2. " + players[1].getName() + " " + to_string(players[1].getScore()));
    Player2.setPosition(200, 250);
    Player3.setString("3. " + players[2].getName() + " " + to_string(players[2].getScore()));
    Player3.setPosition(200, 300);
    Player4.setString("4. " + players[3].getName() + " " + to_string(players[3].getScore()));
    Player4.setPosition(200, 350);
    Player5.setString("5. " + players[4].getName() + " " + to_string(players[4].getScore()));
    Player5.setPosition(200, 400);
}
int HighScore::handleInput(Event event, RenderWindow& window){
    if(event.type == Event::KeyPressed){
        if(event.key.code == Keyboard::Key::Escape){
            this->setVisible(false);
            return 0;
        }
    }
    return -1;
}
void HighScore::Draw(RenderWindow& window){
    getHighScores();
    Background.Draw(window);
    window.draw(text);
    window.draw(Player1);
    window.draw(Player2);
    window.draw(Player3);
    window.draw(Player4);
    window.draw(Player5);
}