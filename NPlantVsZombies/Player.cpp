#include "Player.h"
Player::Player(string name, int score) :name(name), score(score) {
    font.loadFromFile("..\\assets\\fonts\\HouseofTerror Regular.ttf");
    text.setFont(font);
    text.setCharacterSize(40);
    text.setFillColor(Color(99, 224, 99));
    text.setPosition(260, 230);
    text.setString("ENTER YOUR NAME: ");
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
    text.setString("ENTER YOUR NAME: " + name);
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