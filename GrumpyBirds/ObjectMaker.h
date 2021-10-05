#pragma once

#ifndef __ObjectMaker__
#define __ObjectMaker__

#include"Destructable.h"
#include "Bird.h"

enum class ObjectType { Cube, Triangle, Circle};
enum class ObjectMat { Glass, Wood, Stone };
enum class BirdShape {Circle, Triangle };

class ObjectMaker
{
public:
	//constructor
	ObjectMaker();

	//creates and returns a pointer to a destructable game object - Jacob Sullivan
	GameObject* DesObj(ObjectType type, ObjectMat mat, Scene* scene, sf::Vector2f position, sf::Vector2f size);

	// create and returns a pointer to a static game object - Naomi Wiggins
	GameObject* StaticObj(ObjectType type, sf::Texture* texture, Scene* scene, sf::Vector2f position, sf::Vector2f size);

	// creates and returns a pointer to a bird object - Naomi Wiggins
	GameObject* BirdObj(BirdShape shape, Scene* scene, sf::Vector2f position, GameObject* SlingShotObject);
	GameObject* EnemyObject();


};

#endif

