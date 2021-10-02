#pragma once
#ifndef __ObjectMaker__
#define __ObjectMaker__

#include"Destructable.h"

enum ObjectType { Cube, Triangle, Circle};
enum ObjectMat { Glass, Wood, Stone };

class ObjectMaker
{
public:
	//constructor
	ObjectMaker();

	//creates and returns a pointer to a destructable game object
	GameObject* DesObj(ObjectType type, ObjectMat mat, Scene* scene, sf::Vector2f position, sf::Vector2f size);


};

#endif

