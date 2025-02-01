#include "AnimatMySprite.h"
AnimateMySprite::AnimateMySprite(string path, int x, int y, int noOfframes, int width, int length, int AnimateSpeed):MySprite(path, x, y), currentPosition(0, 0){
    this->currentframe = 0;
    this->noOfframes = noOfframes;
    this->width = width;    
    this->length = length;
    this->AnimateSpeed = AnimateSpeed;

}

void AnimateMySprite::setNoOfFrames(int noOfframes){
    this->noOfframes = noOfframes;
}
void AnimateMySprite::setWidth(int width){
    this->width = width;
}
void AnimateMySprite::setLength(int length){
    this->length = length;
}
void AnimateMySprite::setCurrentFrame(int currentframe){
    this->currentframe = currentframe;
}
void AnimateMySprite::setAnimateSpeed(int AnimateSpeed){
    this->AnimateSpeed = AnimateSpeed;
}
int AnimateMySprite::getNoOfFrames(){
    return this->noOfframes;
}
int AnimateMySprite::getWidth(){
    return this->width;
}
int AnimateMySprite::getLength(){
    return this->length;
}
int AnimateMySprite::getCurrentFrame(){
    return this->currentframe;
}
int AnimateMySprite::getAnimateSpeed(){
    return this->AnimateSpeed;
}


void AnimateMySprite::animate(RenderWindow &window){
    if(this->currentframe >= this->noOfframes){
        this->currentframe = 0;
        currentPosition.setX(0);
    }
    this->image.setTextureRect(IntRect(currentPosition.getX(), currentPosition.getY(), width, length));
    this->Draw(window);
    if(animationClock.getElapsedTime().asMilliseconds() > AnimateSpeed){
        animationClock.restart();
        currentPosition.setX(currentPosition.getX() + width);
        currentframe++;
    }
}
// void AnimateMySprite::serialize(ostream& file){
//     MySprite::serialize(file);
//     file.write(reinterpret_cast<const char*>(&noOfframes), sizeof(noOfframes));
//     file.write(reinterpret_cast<const char*>(&width), sizeof(width));
//     file.write(reinterpret_cast<const char*>(&length), sizeof(length));
//     file.write(reinterpret_cast<const char*>(&currentframe), sizeof(currentframe));
//     file.write(reinterpret_cast<const char*>(&AnimateSpeed), sizeof(AnimateSpeed));
//     currentPosition.serialize(file);
// }
// void AnimateMySprite::deserialize(istream& file){
//     MySprite::deserialize(file);
//     file.read(reinterpret_cast<char*>(&noOfframes), sizeof(noOfframes));
//     file.read(reinterpret_cast<char*>(&width), sizeof(width));
//     file.read(reinterpret_cast<char*>(&length), sizeof(length));
//     file.read(reinterpret_cast<char*>(&currentframe), sizeof(currentframe));
//     file.read(reinterpret_cast<char*>(&AnimateSpeed), sizeof(AnimateSpeed));
//     currentPosition.deserialize(file);
// }
