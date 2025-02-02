#include "PlantFactory.h"
PlantFactory::PlantFactory(int allowedPlants, Grid*& grid):InventoryBack("..\\assets\\Inventory-GameScreen\\ChooserBackground.png", 0, 0),SelectorSprite("..\\assets\\Spritesheets\\SelectionFrame1.png", 70, 5){
    this->grid = grid;
    this->allowedPlants = allowedPlants;
    //intializing lane
    int NO_OF_BLOCKS = 8;
    int LANE_NO = 0;
    int LANE_START_X = 70;
    int LANE_START_Y = 5;
    int LANE_WIDTH = 69;
    int LANE_HEIGHT = 50;
    int LANE_BLOCK_WIDTH = 69;
    bool isWater = false;
    this->lane = new Lane(NO_OF_BLOCKS, LANE_NO, LANE_START_X, LANE_START_Y, LANE_WIDTH, LANE_HEIGHT, isWater);
    
    Cards = new InventPlant*[allowedPlants];
    
    const int MAX_NO_OF_PLANTS = 45;
    plants = new Plants*[MAX_NO_OF_PLANTS];
    for (int i = 0; i < MAX_NO_OF_PLANTS; i++){
        plants[i] = nullptr;
    }
    currentPlant = 0;
    setUpCards();
}

void PlantFactory::addPlant(int plantno, Block *block){
    for(int i = 0; i < currentPlant; i++){
        if(plants[i] == nullptr){
            if(plantno == 0){
                plants[currentPlant] = new Peashooter(100, block, 100, 7.5, "..\\assets\\Spritesheets\\peashooter1.png");
            }
            if(plantno == 6){
                plants[currentPlant] = new CherryBomb(150, block, 300, 7.5, "..\\assets\\Spritesheets\\cherrybomb1.png");
            }
            if(plantno == 2){
                plants[currentPlant] = new Repeater(200, block, 100, 7.5, "..\\assets\\Spritesheets\\Repeater.png");
            }
            if(plantno == 3){
                plants[currentPlant] = new SnowPea(175, block, 100, 7.5, "..\\assets\\Spritesheets\\snowpea.png");
            }
            if(plantno == 4){
                plants[currentPlant] = new Wallnut(50, block, 100, 7.5, "..\\assets\\Spritesheets\\Wallnut1.png");
            }
            if(plantno ==5){
                plants[currentPlant] = new PuffShroom(200, block, 100, 7.5, "..\\assets\\Spritesheets\\FumeShroom.png");
            }
            if(plantno == 1){
                plants[currentPlant] = new Sunflower(50, block, 100, 3, "..\\assets\\Spritesheets\\sunflower.png");
            }
            currentPlant++;
            currentNoOfplants++;
            return;
        }
    }
    if(plantno == 0){
        plants[currentPlant] = new Peashooter(100, block, 100, 7.5, "..\\assets\\Spritesheets\\peashooter1.png");
    }
    if(plantno == 6){
        plants[currentPlant] = new CherryBomb(150, block, 200, 7.5, "..\\assets\\Spritesheets\\cherrybomb1.png");
    }
    if(plantno == 2){
        plants[currentPlant] = new Repeater(200, block, 100, 7.5, "..\\assets\\Spritesheets\\Repeater.png");
    }
    if(plantno == 3){
        plants[currentPlant] = new SnowPea(175, block, 100, 7.5, "..\\assets\\Spritesheets\\snowpea.png");
    }
    if(plantno == 4){
        plants[currentPlant] = new Wallnut(50, block, 100, 7.5, "..\\assets\\Spritesheets\\Wallnut1.png");
    }
    if(plantno ==5){
        plants[currentPlant] = new PuffShroom(50, block, 100, 7.5, "..\\assets\\Spritesheets\\FumeShroom.png");
    }
    if(plantno == 1){
        plants[currentPlant] = new Sunflower(100, block, 100, 3, "..\\assets\\Spritesheets\\sunflower.png");
    }
    currentPlant++;

}
void PlantFactory::setUpCards(){
     for(int i = 0; i < allowedPlants; i++){
        string path = "..\\assets\\Plants\\";
        string path2 = "..\\assets\\Inventory-GameScreen\\Cards\\";
        if(i==0){
            Cards[i] = new InventPlant(path2+"PeashooterCard.png", path+"Peashooter\\Peashooter_0.png", 70 + i*50, 5, 7.5, 0, 0, 100);
        }
        if(i == 6){
            Cards[i] = new InventPlant(path2+"CherryBomb.png", path+"CherryBomb\\CherryBomb_0.png", 70 + i*50, 5, 10, 0, 0, 150);
        }
        if(i==2){
            Cards[i] = new InventPlant(path2+"Repeater.png", path+"RepeaterPea\\RepeaterPea_0.png", 70 + i*50, 5, 7.5, 0, 0, 200);
        }
            
        if(i == 3){
            Cards[i] = new InventPlant(path2+"SnowPea.png", path+"SnowPea\\SnowPea_0.png", 70 + i*50, 5, 7.5, 0, 0, 175);
        }
        if(i == 4){
            Cards[i] = new InventPlant(path2+"Wallnut.png", path+"WallNut\\WallNut\\WallNut_0.png", 70 + i*50, 5, 7.5, 0, 0, 50);
        }
        if(i == 5){
            Cards[i] = new InventPlant(path2+"PuffShroom.png", path+"PuffShroom\\PuffShroom\\PuffShroom_0.png", 70 + i*50, 5, 7.5, 0, 0, 50);
        }
        if(i == 1){
            Cards[i] = new InventPlant(path2+"Sunflower.png", path+"SunFlower\\SunFlower_0.png", 70 + i*50, 5, 7.5, 100 , 100, 100);
        }
    }
}
int PlantFactory::getCurrentPlant(){
   return this->currentPlant; 
}
Plants** PlantFactory::getPlants(){
    return this->plants;
}
void PlantFactory::setAllowedPlants(int allowedPlants){
    this->allowedPlants = allowedPlants;
}
void PlantFactory::setLane(Lane* lane){
    this->lane = lane;
}

int PlantFactory::getAllowedPlants(){
    return allowedPlants;
}
Lane* PlantFactory::getLane(){
    return lane;
}
void PlantFactory::CollisionControl(Zombie** zombies, int currentZombies){
    for(int i = 0; i < currentPlant; i++){
        if(plants[i] != nullptr){
            plants[i]->CollisionControl(zombies, currentZombies);
        }
    }
}

int PlantFactory::handleInput(Event e, RenderWindow& window, int sunCount){
    if(e.type == Event::MouseButtonPressed){
        for(int i = 0; i < allowedPlants; i++){
            if(lane->getBlocks()[i]->checkHover(window)){
                if(Cards[i]->getCooldownClock().getElapsedTime().asSeconds() > Cards[i]->getCooldownTime() || Cards[i]->getGameStart() && sunCount >= Cards[i]->getPrice()){
                    Cards[i]->setGameStart(false);
                    return i;
                }
            }
        }
        for(int i = 0; i < currentPlant; i++){
            if(plants[i] != nullptr){
                if(plants[i]->handleInput(e, window)){
                    return -2;
                }
            }
        }
    }
    return -1;   
}
InventPlant** PlantFactory::getCards(){
    return Cards;
}
MySprite& PlantFactory::getSelectorSprite(){
    return this->SelectorSprite;
}

void PlantFactory::Draw(RenderWindow& window){
    InventoryBack.Draw(window);
    for(int i = 0; i < allowedPlants; i++){
        Cards[i]->Draw(window);
    }
    for(int i = 0; i < currentPlant; i++){
        if(plants[i] != nullptr && plants[i]->getKilled() ){
            currentNoOfplants--;
            delete plants[i];
            plants[i] = nullptr; 
        }
        if(plants[i] != nullptr)
            plants[i]->Draw(window);
    }
}

// void PlantFactory::serialize(ostream& file){
//     file.write(reinterpret_cast<const char*>(&allowedPlants), sizeof(allowedPlants));
//     file.write(reinterpret_cast<const char*>(&currentPlant), sizeof(currentPlant));
//     file.write(reinterpret_cast<const char*>(&currentNoOfplants), sizeof(currentNoOfplants));
//     SelectorSprite.serialize(file);
//     InventoryBack.serialize(file);
//     lane->serialize(file);
//     for(int i = 0; i < allowedPlants; i++){
//         Cards[i]->serialize(file);
//     }
//     for(int i = 0; i < currentPlant; i++){
//         if(plants[i] != nullptr){
//             plants[i]->serialize(file);
//         }
//     }

// }
// void PlantFactory::deserialize(istream& file){
//     file.read(reinterpret_cast<char*>(&allowedPlants), sizeof(allowedPlants));
//     file.read(reinterpret_cast<char*>(&currentPlant), sizeof(currentPlant));
//     file.read(reinterpret_cast<char*>(&currentNoOfplants), sizeof(currentNoOfplants));
//     SelectorSprite.deserialize(file);
//     InventoryBack.deserialize(file);
//     Lane *lane = new Lane(8, 0, 70, 5, 69, 50,false);
//     lane->deserialize(file);
//     Cards = new InventPlant*[allowedPlants];
//     for(int i = 0; i < allowedPlants; i++){
//         Cards[i] = new InventPlant("..\\assets\\Inventory-GameScreen\\ChooserBackground.png", "..\\assets\\Inventory-GameScreen\\ChooserBackground.png", 0, 0, 0, 0, 0, 0);
//         Cards[i]->deserialize(file);
//     }
//     plants = new Plants*[45];
//     for(int i = 0; i < currentNoOfplants; i++){
//         int type;
//         file.read(reinterpret_cast<char*>(&type), sizeof(type));
//         switch (type){
//         case 1:
//             plants[i] = new Peashooter(100, nullptr, 100, 3, "..\\assets\\Spritesheets\\peashooter1.png");
//             break;
//         case 2:
//             plants[i] = new Repeater(200, nullptr, 100, 7.5, "..\\assets\\Spritesheets\\Repeater.png");
//             break;
//         case 3:
//             plants[i] = new PuffShroom(175, nullptr, 100, 7.5, "..\\assets\\Spritesheets\\FumeShroom.png");
//             break;
//         case 4:
//             plants[i] = new SnowPea(175, nullptr, 100, 7.5, "..\\assets\\Spritesheets\\snowpea.png");
//             break;
//         case 5:
//             plants[i] = new Sunflower(50, nullptr, 100, 7.5, "..\\assets\\Spritesheets\\sunflower.png");
//             break;
//         case 6:
//             plants[i] = new Wallnut(200, nullptr, 100, 7.5, "..\\assets\\Spritesheets\\Wallnut1.png");
//             break;
//         case 7:
//             plants[i] = new CherryBomb(150, nullptr, 100, 7.5, "..\\assets\\Spritesheets\\cherrybomb1.png");
//             break;
//         default:
//             break;
//         }
//         plants[i]->deserialize(file);
//     }
// }


PlantFactory::~PlantFactory(){
    for(int i = 0; i < currentPlant; i++){
        if(plants[i] != nullptr){
            delete plants[i];
        }
    }
    if(plants != nullptr){
        delete plants;
        plants = nullptr;
    }

    delete lane;
    for(int i = 0; i < allowedPlants; i++){
        if(Cards[i] != nullptr){
            delete Cards[i];
        }
    }
    if(Cards != nullptr){
        delete Cards;
        Cards = nullptr;
    }
    
}
