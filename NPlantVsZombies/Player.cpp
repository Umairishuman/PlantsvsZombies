#include "Player.h"
Player::Player(string name, int score) :name(name), score(score) {
    font.loadFromFile("..\\assets\\fonts\\VampireWars.ttf");
    text.setFont(font);
    text.setCharacterSize(30);
    text.setFillColor(Color::Black);
    text.setPosition(300, 250);
    text.setString("Enter your name: ");
}
void Player::setName(string name) {
    this->name = name;
}
void Player::setScore(int score) {
    this->score = score;
}
string Player::getName() {
    return name;
}
int Player::getScore() {
    return score;
}
void Player::EnterName(Event &e) {
    if (e.type == Event::TextEntered) {
        if (e.text.unicode == 8) {
            if (name.size() > 0) {
                name.pop_back();
            }
        }
        else if (e.text.unicode == 13) {
            return;
        }
        else {
            name += e.text.unicode;
        }
    }
    text.setString("Enter your name: " + name);
}
void Player::Draw(RenderWindow& window) {
    window.draw(text);
}
void Player::serialize(ostream& file) {
    file.write(reinterpret_cast<char*>(&name), sizeof(name));
    file.write(reinterpret_cast<char*>(&score), sizeof(score));
}
void Player::deserialize(istream& file) {
    file.read(reinterpret_cast<char*>(&name), sizeof(name));
    file.read(reinterpret_cast<char*>(&score), sizeof(score));
    font.loadFromFile("..\\assets\\fonts\\VampireWars.ttf");
}