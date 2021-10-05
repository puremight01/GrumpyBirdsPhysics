#pragma once
#include "Bird.h"
class YellowBird :
    public Bird
{
public:
    YellowBird(sf::Drawable* Renderable, b2Body* Body, b2World& World, b2Body* SlingShotBody);

private:
    //holds the logic unique to this bird 
    // created by Jacob Sullivan 
    void ClickFunction();
};
