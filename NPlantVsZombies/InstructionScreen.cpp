#include"InstructionScreen.h"
InstructionScreen::InstructionScreen(string backgroundPath, bool visible): Screen(backgroundPath, visible){
    font.loadFromFile("..\\assets\\fonts\\VampireWars.ttf");
    text.setFont(font);
    text.setString("Instructions");
    text.setCharacterSize(60);
    text.setFillColor(Color::Red);
    text.setPosition(400, 30);

    for(int i = 0; i < 6; i++){
        Instructions[i].setFont(font);
        Instructions[i].setCharacterSize(25);
        Instructions[i].setFillColor(Color::White);
    }

    Instructions[0].setString("1. Plant various types of plants strategically to defend your house.");
    Instructions[1].setString("2. Collect suns to buy plants.");
    Instructions[2].setString("3. Different plants have different abilities and costs; choose wisely!!");
    Instructions[3].setString("4. You have 3 lives. If a zombie reaches your house, you lose a life.");
    Instructions[4].setString("5. Defend your house from all the zombies to win the game.");
    Instructions[5].setString("6. Press 'Esc' to go back to the main menu.");

    for(int i = 0; i < 6; i++){
        Instructions[i].setPosition(50, 200 + i*50);
    }
    
}
InstructionScreen::~InstructionScreen(){}
int InstructionScreen::handleInput(Event event, RenderWindow& window){
    if(event.type == Event::KeyPressed){
        if(event.key.code == Keyboard::Key::Escape){
            this->setVisible(false);
            return 1;
        }
    }
    return -1;
}
void InstructionScreen::Draw(RenderWindow& window){
    Background.Draw(window);
    window.draw(text);
    for(int i = 0; i < 6; i++){
        window.draw(Instructions[i]);
    }
}