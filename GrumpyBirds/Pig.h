#pragma once

#ifndef __Pig__
#define __Pig__

#include "Destructable.h"

class Pig :
    public Destructable
{
public:
    Pig(sf::Drawable* Renderable, b2Body* Body, float _strength, float _health, Scene* _scene);
    ~Pig();

    int GetPigCount();
private:
    static int PigCount;
};

#endif // !__Pig__