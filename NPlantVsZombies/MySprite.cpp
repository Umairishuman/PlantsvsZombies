#include "MySprite.h"
//coordinates and texture are set and loaded when a sprite is created
MySprite::MySprite(string path, float x, float y) :path(path), P1(x, y) {
	if (!this->texture.loadFromFile(this->path)) {
		cout << "Error loading image" << endl;
	}
	this->image.setTexture(texture);
	this->image.setPosition(P1.getX(), P1.getY());
}
//just to set texture
void MySprite::setPath(string path) {
	this->path = path;
	if (!this->texture.loadFromFile(this->path)) {
		cout << "Error loading image" << endl;
	}
	this->image.setTexture(texture);
	this->image.setPosition(P1.getX(), P1.getY());
}
//setting coordinates
void MySprite::setCoordinates(float x, float y) {
	this->P1.setX(x);
	this->P1.setY(y);
	this->image.setPosition(P1.getX(), P1.getY());
}
//getting coordinates
Coordinates MySprite::getCoordinates() {
	return this->P1;
}
void MySprite::scale(float x, float y){
	this->image.setScale(x, y);
}
void MySprite::setOpacity(float opacity){
	Color c(255, 255, 255, opacity*255);
	image.setColor(c);
}
string MySprite::getPath() {
	return this->path;
}
void MySprite::Draw(RenderWindow& window) {
	window.draw(this->image);
}
void MySprite::serialize(ostream& file) {
	file.write(reinterpret_cast<char*>(&path), sizeof(path));
	P1.serialize(file);

}
void MySprite::deserialize(istream& file) {
	file.read(reinterpret_cast<char*>(&path), sizeof(path));
	P1.deserialize(file);
	setPath(path);
}