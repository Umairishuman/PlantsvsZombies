#include "MySprite.h"
MySprite::MySprite(string path, int x, int y) :path(path), P1(x, y) {
	if (!this->texture.loadFromFile(this->path)) {
		cout << "Error loading image1" << endl;
	}
	this->image.setTexture(texture);
	this->image.setPosition((float)P1.getX(), (float)P1.getY());
}
void MySprite::setPath(string path) {
	this->path = path;
	if (!this->texture.loadFromFile(this->path)) {
		cout << "Error loading image" << endl;
	}
	this->image.setTexture(texture);
	this->image.setPosition((float)P1.getX(), (float)P1.getY());
}
void MySprite::setCoordinates(int x, int y) {
	this->P1.setX(x);
	this->P1.setY(y);
	this->image.setPosition((float)P1.getX(), (float)P1.getY());
}
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