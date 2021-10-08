#pragma once

#ifndef __Pig__
#define __Pig__

#include "Destructable.h"

class Pig :
    public Destructable
{
public:
    //creates the pig and increases the pig count - Jacob Sullivan
    Pig(sf::Drawable* Renderable, b2Body* Body, float _strength, float _health, Scene* _scene);
    //decriment the pig count - Jacob Sullivan
    ~Pig();

    //used to know when the player wins - Jacob Sullivan
    static int GetPigCount();

    //updates the object - Jacob Sullivan
    void Update();
private:
    //stores how many pigs exist - Jacob Sullivan
    static int PigCount;
};

#endif // !__Pig__