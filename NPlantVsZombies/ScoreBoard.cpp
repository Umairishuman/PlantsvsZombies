#include"ScoreBoard.h"
ScoreBoard::ScoreBoard(string name, int score):sprite("..\\assets\\backgrounds\\scoreboard.png", 500, 20){
    this->name = name;
    this->score = score;
    font.loadFromFile("..\\assets\\fonts\\VampireWars.ttf");
    text.setFont(font);
    text.setCharacterSize(20);
    text.setFillColor(Color::White);
    text.setPosition(1200, 20);
    
}
void ScoreBoard::setName(string name){
    this->name = name;
}
void ScoreBoard::setScore(int score){
    this->score = score;
}
string ScoreBoard::getName(){
    return name;
}

int ScoreBoard::getScore(){
    return score;
}
void ScoreBoard::Draw(RenderWindow& window){
    sprite.Draw(window);
    text.setString(name + " " + to_string(score));
    window.draw(text);
}
