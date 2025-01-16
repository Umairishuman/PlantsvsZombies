#include "Screen.h"
Screen::Screen(string path, bool visible) :P(0, 0), Background(path, P.getX(), P.getY()),visible(visible) {}
void Screen::setVisible(bool visible) {
    this->visible = visible;
}
bool Screen::getVisible() {
    return visible;
}
void Screen::storeToFile(string filename) {}
Screen::~Screen() {
}

