#pragma once
#include"Shooters.h"
class PuffShroom: public Shooters{
protected:
public:
    PuffShroom(int price = 0, Block* block = nullptr, int health = 0, float cooldownTime = 0, string path = "");
    ~PuffShroom();
    void shoot();
    bool CheckLane(Zombie** zombie, int currentZombie);
    virtual void CollisionControl(Zombie** zombie, int currentZombie) ;
    void Draw(RenderWindow& window);

    void serialize(ostream& file);
    void deserialize(istream& file);
};

