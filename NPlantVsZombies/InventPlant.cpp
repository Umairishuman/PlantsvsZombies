#include"InventPlant.h"
InventPlant::InventPlant(string PlantCardPath, string PlantimagePath, int CardX, int CardY, float cooldownTime, int imageX, int imageY, int price) :cooldownTime(cooldownTime),PlantCard(PlantCardPath, CardX, CardY), Plantimage(PlantimagePath, imageX, imageY), price(price){
    Plantimage.setOpacity(0.4f);
    font.loadFromFile("..\\assets\\fonts\\VampireWars.ttf");
    text.setFont(font);
    gameStart = true;
}
void InventPlant::setCooldownTime(float cooldownTime){
    this->cooldownTime = cooldownTime;
}
void InventPlant::setGameStart(bool gameStart){
    this->gameStart = gameStart;
}
void InventPlant::setPrice(int price){
    this->price = price;
}
int InventPlant::getPrice(){
    return price;
}
float InventPlant::getCooldownTime(){
    return cooldownTime;
}
MySprite& InventPlant::getPlantCard(){
    return PlantCard;
}
MySprite& InventPlant::getPlantimage(){
    return Plantimage;
}
Clock& InventPlant::getCooldownClock(){
    return cooldownClock;
}
bool InventPlant::getGameStart(){
    return gameStart;
}
void InventPlant::Draw(RenderWindow& window){
    if(cooldownClock.getElapsedTime().asSeconds() < cooldownTime && !gameStart){
        PlantCard.setOpacity(0.6f);
    }
    else    
        PlantCard.setOpacity(1);

    PlantCard.Draw(window);
    if(cooldownClock.getElapsedTime().asSeconds() < cooldownTime && !gameStart){
        float f = round((cooldownTime - cooldownClock.getElapsedTime().asSeconds())*10)/10;
        
        string s = to_string((int)f);
        text.setString(s);
        text.setCharacterSize(20);
        text.setFillColor(Color::White);
        text.setPosition(PlantCard.getCoordinates().getX() + 10.0, PlantCard.getCoordinates().getY() + 10.0);
        window.draw(text);
    }
}

void InventPlant::serialize(ostream& file){
    PlantCard.serialize(file);
    Plantimage.serialize(file);
    file.write(reinterpret_cast<const char*>(&price), sizeof(price));
    file.write(reinterpret_cast<const char*>(&cooldownTime), sizeof(cooldownTime));
    file.write(reinterpret_cast<const char*>(&gameStart), sizeof(gameStart));
}  
void InventPlant::deserialize(istream& file){
    PlantCard.deserialize(file);
    Plantimage.deserialize(file);
    file.read(reinterpret_cast<char*>(&price), sizeof(price));
    file.read(reinterpret_cast<char*>(&cooldownTime), sizeof(cooldownTime));
    file.read(reinterpret_cast<char*>(&gameStart), sizeof(gameStart));
    font.loadFromFile("..\\assets\\fonts\\VampireWars.ttf");
}

InventPlant::~InventPlant(){
}

