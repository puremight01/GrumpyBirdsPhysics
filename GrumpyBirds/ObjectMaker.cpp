#include "ObjectMaker.h"
#include "Scene.h"

ObjectMaker::ObjectMaker()
{
}

GameObject* ObjectMaker::DesObj(ObjectType type, ObjectMat mat, Scene* scene, sf::Vector2f position, sf::Vector2f size)
{
    switch (type)
    {
	case ObjectType::Circle:
	{
		auto ObjImage = new sf::RectangleShape;
		ObjImage->setSize(size);

		//falling object physics
		b2BodyDef BodyDef;

		// creates a body in the world with the position scaled to the world 
		BodyDef.position = b2Vec2(position.x / 30.0f, position.y / 30.0f);
		BodyDef.type = b2_dynamicBody;
		auto Body = scene->World->CreateBody(&BodyDef);

		b2CircleShape Shape;
		Shape.m_radius = size.x / 2.0f / 30.0f;

		b2FixtureDef FixtureDef;
		FixtureDef.density = 1.f;
		FixtureDef.shape = &Shape;
		Body->CreateFixture(&FixtureDef);
		Body->SetAngularVelocity(0.0f);
		switch (mat)
		{
		case ObjectMat::Glass:
			return new Destructable(ObjImage, Body, 5.0f, 100.0f, Textures::GetTextures()->m_glassSphere, scene);
		case ObjectMat::Wood:
			return new Destructable(ObjImage, Body, 10.0f, 100.0f, Textures::GetTextures()->m_woodSphere, scene);
		case ObjectMat::Stone:
			return new Destructable(ObjImage, Body, 20.0f, 100.0f, Textures::GetTextures()->m_stoneSphere, scene);
		default:
			return nullptr;
		}
	}

	case ObjectType::Triangle:
	{
		auto ObjImage = new sf::RectangleShape;
		ObjImage->setSize(size);

		//falling object physics
		b2BodyDef BodyDef;

		// creates a body in the world with the position scaled to the world 
		BodyDef.position = b2Vec2(position.x / 30.0f, position.y / 30.0f);
		BodyDef.type = b2_dynamicBody;
		auto Body = scene->World->CreateBody(&BodyDef);

		b2PolygonShape Shape;
		b2Vec2 points[3] = { b2Vec2(size.x / -2.f / 30.0f, size.y / 2.f / 30.0f), b2Vec2(0.0f, size.y / -2.f / 30.0f), b2Vec2(size.x / 2.f / 30.0f, size.y / 2.f / 30.0f) };
		Shape.Set(points, 3);

		b2FixtureDef FixtureDef;
		FixtureDef.density = 1.f;
		FixtureDef.shape = &Shape;
		Body->CreateFixture(&FixtureDef);
		Body->SetAngularVelocity(0.0f);
		switch (mat)
		{
		case ObjectMat::Glass:
			return new Destructable(ObjImage, Body, 5.0f, 100.0f, Textures::GetTextures()->m_glassTriangle, scene);
		case ObjectMat::Wood:
			return new Destructable(ObjImage, Body, 10.0f, 100.0f, Textures::GetTextures()->m_woodTriangle, scene);
		case ObjectMat::Stone:
			return new Destructable(ObjImage, Body, 20.0f, 100.0f, Textures::GetTextures()->m_stoneTriangle, scene);
		default:
			return nullptr;
		}
	}

	case ObjectType::Cube:
	{
		auto ObjImage = new sf::RectangleShape;
		ObjImage->setSize(size);

		//falling object physics
		b2BodyDef BodyDef;

		// creates a body in the world with the position scaled to the world 
		BodyDef.position = b2Vec2(position.x / 30.0f, position.y / 30.0f);
		BodyDef.type = b2_dynamicBody;
		auto Body = scene->World->CreateBody(&BodyDef);

		b2PolygonShape Shape;
		Shape.SetAsBox(size.x / 2.0f / 30.0f, size.y / 2.f / 30.f);

		b2FixtureDef FixtureDef;
		FixtureDef.density = 1.f;
		FixtureDef.shape = &Shape;
		Body->CreateFixture(&FixtureDef);
		Body->SetAngularVelocity(0.0f);
		switch (mat)
		{
		case ObjectMat::Glass:
			return new Destructable(ObjImage, Body, 5.0f, 100.0f, Textures::GetTextures()->m_glassCube, scene);
		case ObjectMat::Wood:
			return new Destructable(ObjImage, Body, 10.0f, 100.0f, Textures::GetTextures()->m_woodCube, scene);
		case ObjectMat::Stone:
			return new Destructable(ObjImage, Body, 20.0f, 100.0f, Textures::GetTextures()->m_stoneCube, scene);
		default:
			return nullptr;
		}
	}
	
	default:

		return nullptr;

    
	}


}


GameObject* ObjectMaker::StaticObj(ObjectType type, sf::Texture* texture, Scene* scene, sf::Vector2f position, sf::Vector2f size)
{
	// drawable / display setup
	auto objSprite = new sf::RectangleShape;
	dynamic_cast<sf::RectangleShape*>(objSprite)->setSize(size);
	dynamic_cast<sf::RectangleShape*>(objSprite)->setTexture(texture);

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


GameObject* ObjectMaker::BirdObj(BirdShape shape, Scene* scene, sf::Vector2f position, GameObject* SlingShotObject)
{
	// drawable / display general setup
	auto birdSprite = new sf::RectangleShape;
	dynamic_cast<sf::RectangleShape*>(birdSprite)->setSize(sf::Vector2f(50.f, 50.f));

	// physics body general setup
	b2BodyDef birdBodyDef;
	birdBodyDef.position = b2Vec2(position.x / 30.f, position.y / 30.f);
	birdBodyDef.type = b2_dynamicBody;
	auto birdBody = scene->World->CreateBody(&birdBodyDef);
	birdBody->SetAngularVelocity(0.f);

	b2FixtureDef birdFixtureDef;
	birdFixtureDef.density = 1.f;

	switch (shape)
	{
	case BirdShape::Circle:
	{
		// drawable shape setup
		dynamic_cast<sf::RectangleShape*>(birdSprite)->setTexture(Textures::GetTextures()->RedGrumpyBird1);

		// physics body shape setup
		b2CircleShape birdBodyShape;
		birdBodyShape.m_radius = 25.f / 30.f;
		birdFixtureDef.shape = &birdBodyShape;
		birdBody->CreateFixture(&birdFixtureDef);

		return(new Bird(birdSprite, birdBody, *scene->World, SlingShotObject->GetPhysicsBody()));
	}
	case BirdShape::Triangle:
	{
		// drawable shape setup
		dynamic_cast<sf::RectangleShape*>(birdSprite)->setTexture(Textures::GetTextures()->YellowGrumpyBird);

		// physics body shape setup
		b2PolygonShape birdBodyShape;
		b2Vec2 points[3] = { b2Vec2(-25.f / 30.f, 25.f / 30.f), b2Vec2(0.f, -25.f / 30.f), b2Vec2(25.f / 30.f, 25.f / 30.f) };
		birdBodyShape.Set(points, 3);
		birdFixtureDef.shape = &birdBodyShape;
		birdBody->CreateFixture(&birdFixtureDef);

		return(new Bird(birdSprite, birdBody, *scene->World, SlingShotObject->GetPhysicsBody()));
	}
	default:
	{
		scene->World->DestroyBody(birdBody);
		return(nullptr);
	}
	}
}


GameObject* ObjectMaker::PigObj(Scene* scene, sf::Vector2f position, sf::Vector2f size, float strength, float health)
{
	// drawable / display general setup
	auto pigSprite = new sf::RectangleShape;
	dynamic_cast<sf::RectangleShape*>(pigSprite)->setSize(size);

	// physics body setup
	b2BodyDef pigBodyDef;
	pigBodyDef.position = b2Vec2(position.x / 30.f, position.y / 30.f);
	pigBodyDef.type = b2_dynamicBody;
	auto pigBody = scene->World->CreateBody(&pigBodyDef);
	pigBody->SetAngularVelocity(0.f);

	b2CircleShape pigBodyShape;
	pigBodyShape.m_radius = (size.x > size.y ? size.x / 2.f / 30.f : size.y / 2.f / 30.f);

	b2FixtureDef pigFixtureDef;
	pigFixtureDef.shape = &pigBodyShape;
	pigFixtureDef.density = 1.f;
	pigBody->CreateFixture(&pigFixtureDef);

	return(new Pig(pigSprite, pigBody, strength, health, scene));
}
