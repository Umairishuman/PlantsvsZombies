#include"Sun.h"
Sun::Sun(int x, int y, int width, int length):SunSprite("..\\assets\\Spritesheets\\sun.png", x, y, 22, width, length){
    this->exists = false;
    this->sunToTop = false;
    this->startX = x;
    this->endY = 0;
    this->endY2 = y;
    this->UnitVectorX = 0;
    this->UnitVectorY = 0;
    plantGenerated = false;
    srand(time(0));
}
void Sun::setPlantGenerated(bool plantGenerated){
    this->plantGenerated = plantGenerated;
}
bool Sun::getPlantGenerated(){
    return this->plantGenerated;
}
void Sun::SpawnSun(){
    if(!exists){
        SuncreationClock.restart();
        exists = true;
        if(!plantGenerated){
            this->startX = rand() % 400 + 255 ;
            this->endY = rand() % 500 + 100;
            SunSprite.setCoordinates(startX, 0);
        }
        else{
            SunSprite.setCoordinates(startX, endY2);
        }
    }
    
}
void Sun::CalculateUnitVector(){
    float Magnitude = (float)sqrt(pow(SunSprite.getCoordinates().getX(),2)+pow(SunSprite.getCoordinates().getY(),2));
    UnitVectorX = SunSprite.getCoordinates().getX()/Magnitude;
    UnitVectorY = SunSprite.getCoordinates().getY()/Magnitude; 
}
void Sun::MoveSunTowardsTop(){
    if(sunClock.getElapsedTime().asMilliseconds() > 0.5) {
        //if(SunSprite.getCoordinates().getX() > 0)
        SunSprite.setCoordinates(SunSprite.getCoordinates().getX()-UnitVectorX, SunSprite.getCoordinates().getY()- UnitVectorY);
        sunClock.restart();
    }
}
void Sun::MoveSun(){
    if(SuncreationClock.getElapsedTime().asSeconds() > 20){
        exists = false;
        if(plantGenerated){   
            SunSprite.setCoordinates(SunSprite.getCoordinates().getX(), SunSprite.getCoordinates().getY() -endY2);
        }
        else {
            SunSprite.setCoordinates(SunSprite.getCoordinates().getX(), SunSprite.getCoordinates().getY() -endY);
        }
    }
    if(SunSprite.getCoordinates().getY() <= 0 && SunSprite.getCoordinates().getX() <=0 && sunToTop == true){
        exists = false;
        sunToTop = false;
        sunClock.restart();
        return;
    }
    if(sunClock.getElapsedTime().asMilliseconds() > 5  && sunToTop == false) {
        if(!plantGenerated && SunSprite.getCoordinates().getY() < endY){
            SunSprite.setCoordinates((int)SunSprite.getCoordinates().getX(), (int)SunSprite.getCoordinates().getY()+1);
            sunClock.restart();
        }
        if(plantGenerated && SunSprite.getCoordinates().getY() < endY2 + 15){
            SunSprite.setCoordinates((int)SunSprite.getCoordinates().getX(), (int)SunSprite.getCoordinates().getY()+1);
            sunClock.restart();
        }
    }
    if(sunToTop){
        MoveSunTowardsTop();
    }
}
bool Sun::handleInput(Event e, RenderWindow& window){
    if(e.type == Event::MouseButtonPressed){
        int MouseX = Mouse::getPosition(window).x;
        int MouseY = Mouse::getPosition(window).y;
        if(MouseX >= SunSprite.getCoordinates().getX() && MouseX <= SunSprite.getCoordinates().getX() + SunSprite.getWidth() && MouseY >= SunSprite.getCoordinates().getY() && MouseY <= SunSprite.getCoordinates().getY() + SunSprite.getLength()){
            CalculateUnitVector();
            sunToTop = true;
            return true;
            
        }
    }
    return false;
}
void Sun::serialize(ostream& file){
    SunSprite.serialize(file);
    file.write(reinterpret_cast<const char*>(&startX), sizeof(startX));
    file.write(reinterpret_cast<const char*>(&endY), sizeof(endY));
    file.write(reinterpret_cast<const char*>(&endY2), sizeof(endY2));
    file.write(reinterpret_cast<const char*>(&UnitVectorX), sizeof(UnitVectorX));
    file.write(reinterpret_cast<const char*>(&UnitVectorY), sizeof(UnitVectorY));
    file.write(reinterpret_cast<const char*>(&sunToTop), sizeof(sunToTop));
    file.write(reinterpret_cast<const char*>(&exists), sizeof(exists));
    file.write(reinterpret_cast<const char*>(&plantGenerated), sizeof(plantGenerated));
}
void Sun::deserialize(istream& file){
    SunSprite.deserialize(file);
    file.read(reinterpret_cast<char*>(&startX), sizeof(startX));
    file.read(reinterpret_cast<char*>(&endY), sizeof(endY));
    file.read(reinterpret_cast<char*>(&endY2), sizeof(endY2));
    file.read(reinterpret_cast<char*>(&UnitVectorX), sizeof(UnitVectorX));
    file.read(reinterpret_cast<char*>(&UnitVectorY), sizeof(UnitVectorY));
    file.read(reinterpret_cast<char*>(sunToTop), sizeof(sunToTop));
    file.read(reinterpret_cast<char*>(&exists), sizeof(exists));
    file.read(reinterpret_cast<char*>(&plantGenerated), sizeof(plantGenerated));
}
void Sun::Draw(RenderWindow& window){
    if(exists){
        MoveSun();
        SunSprite.animate(window);

    }
}