#pragma once

#ifndef __ObjectMaker__
#define __ObjectMaker__

#include"Destructable.h"
#include "Bird.h"
#include "Pig.h"
#include "Scene.h"

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
	template<typename ObjSprite>
	GameObject* StaticObj(ObjectType type, ObjSprite sprite, Scene* scene, sf::Vector2f position, sf::Vector2f size)
	{
		// drawable / display setup
		auto objSprite = new sf::RectangleShape(CreateSprite(sprite, size));

		// physics body general setup
		b2BodyDef objBodyDef;
		objBodyDef.position = b2Vec2(position.x / 30.f, position.y / 30.f);
		objBodyDef.type = b2_staticBody;
		auto objBody = scene->World->CreateBody(&objBodyDef);

		b2FixtureDef objFixtureDef;
		objFixtureDef.density = 0.f;

		switch (type)
		{
		case ObjectType::Cube:
		{
			// physics body shape setup
			b2PolygonShape objBodyShape;
			objBodyShape.SetAsBox(size.x / 2.f / 30.f, size.y / 2.f / 30.f);
			objFixtureDef.shape = &objBodyShape;
			objBody->CreateFixture(&objFixtureDef);
			objBody->SetAngularVelocity(0.f);

			return(new GameObject(objSprite, objBody));
		}
		case ObjectType::Triangle:
		{
			// physics body shape setup
			b2PolygonShape objBodyShape;
			b2Vec2 points[3] = { b2Vec2(size.x / -2.f / 30.f, size.y / 2.f / 30.f), b2Vec2(0.f, size.y / -2.f / 30.f), b2Vec2(size.x / 2.f / 30.f, size.y / 2.f / 30.f) };
			objBodyShape.Set(points, 3);
			objFixtureDef.shape = &objBodyShape;
			objBody->CreateFixture(&objFixtureDef);
			objBody->SetAngularVelocity(0.f);

			return(new GameObject(objSprite, objBody));
		}
		case ObjectType::Circle:
		{
			// physics body shape setup
			b2CircleShape objBodyShape;
			objBodyShape.m_radius = (size.x > size.y ? size.x / 2.f / 30.f : size.y / 2.f / 30.f);
			objFixtureDef.shape = &objBodyShape;
			objBody->CreateFixture(&objFixtureDef);
			objBody->SetAngularVelocity(0.f);

			return(new GameObject(objSprite, objBody));
		}
		default:
		{
			scene->World->DestroyBody(objBody);
			return(nullptr);
		}
		}
	}

	// creates and returns a pointer to a bird object - Naomi Wiggins
	GameObject* BirdObj(BirdShape shape, Scene* scene, sf::Vector2f position, GameObject* SlingShotObject);
	
	// creates and returns a pointer to a pig object - Naomi Wiggins
	GameObject* PigObj(Scene* scene, sf::Vector2f position, sf::Vector2f size, float strength, float health);

protected:
	// creates and return a sfml retangle shape object using a size vector2 and a texture - Naomi Wiggins
	sf::RectangleShape CreateSprite(sf::Texture* sprite, sf::Vector2f size);
	// creates and return a sfml retangle shape object using a size vector2 and a colour - Naomi Wiggins
	sf::RectangleShape CreateSprite(sf::Color sprite, sf::Vector2f size);
};

#endif

