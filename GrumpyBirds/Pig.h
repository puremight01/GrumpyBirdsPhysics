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

    static int GetPigCount();

    void Update();
private:
    static int PigCount;
};

#endif // !__Pig__