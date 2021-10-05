#pragma once
#ifndef __ObjectMaker__
#define __ObjectMaker__

#include"Destructable.h"
#include "Bird.h"

enum class ObjectType { Cube, Triangle, Circle};
enum class ObjectMat { Glass, Wood, Stone };

class ObjectMaker
{
public:
	//constructor
	ObjectMaker();

	//creates and returns a pointer to a destructable game object - Jacob Sullivan
	GameObject* DesObj(ObjectType type, ObjectMat mat, Scene* scene, sf::Vector2f position, sf::Vector2f size);

	// create and returns a pointer to a static game object - Naomi Wiggins
	GameObject* StaticObj(ObjectType type, sf::Texture* texture, Scene* scene, sf::Vector2f position, sf::Vector2f size);
	GameObject* BirdObj();
	GameObject* EnemyObject();


};

#endif

