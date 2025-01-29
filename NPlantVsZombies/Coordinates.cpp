#include "Coordinates.h"
Coordinates::Coordinates(float x, float y) : x(x), y(y) {}

void Coordinates::setX(float x) {
	this->x = x;
}
void Coordinates::setY(float y) {
	this->y = y;
}
float Coordinates::getX() {
	return this->x;
}
float Coordinates::getY() {
	return this->y;
}
void Coordinates::serialize(ostream& file) {
	file.write(reinterpret_cast<const char*>(&x), sizeof(x));
    file.write(reinterpret_cast<const char*>(&y), sizeof(y));
}
void Coordinates::deserialize(istream& file) {
	file.read(reinterpret_cast<char*>(&x), sizeof(x));
	file.read(reinterpret_cast<char*>(&y), sizeof(y));
}