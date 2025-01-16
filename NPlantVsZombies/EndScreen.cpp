#include"EndScreen.h"
EndScreen::EndScreen(string backgroundPath, bool visible):Screen(backgroundPath, visible){
    EndClock.restart();
}
EndScreen::~EndScreen(){
}
int EndScreen::handleInput(Event e, RenderWindow& window){
    if(e.type == Event::KeyPressed){
        if(e.key.code == Keyboard::Enter){
            return 5;
        }
    }
    return 5;
}
void EndScreen::Draw(RenderWindow& window){
    if(EndClock.getElapsedTime().asSeconds() < 3){
        Background.Draw(window);
    }
    else{
        setVisible(false);
        window.close();
    }
}