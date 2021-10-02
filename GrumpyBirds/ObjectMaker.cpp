#include "ObjectMaker.h"
#include "Scene.h"

ObjectMaker::ObjectMaker()
{
}

GameObject* ObjectMaker::DesObj(ObjectType type, ObjectMat mat, Scene* scene, sf::Vector2f position, sf::Vector2f size)
{
    switch (type)
    {
    case Circle:
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
		case Glass:
			return nullptr;
		case Wood:
			return new Destructable(ObjImage, Body, 10.0f, 100.0f, Textures::GetTextures()->m_solidWoodSphere, scene);
		case Stone:
			return nullptr;
		default:
			return nullptr;
		}
	}
        
	case Triangle:
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
		b2Vec2 points[3] = { b2Vec2(-50.0f / 30.0f, -50.0f / 30.0f), b2Vec2(0.0f, 50.0f / 30.0f), b2Vec2(50.0f / 30.0f, -50.0f / 30.0f) };
		Shape.Set(points, 3);

		b2FixtureDef FixtureDef;
		FixtureDef.density = 1.f;
		FixtureDef.shape = &Shape;
		Body->CreateFixture(&FixtureDef);
		Body->SetAngularVelocity(0.0f);
		switch (mat)
		{
		case Glass:
			return nullptr;
		case Wood:
			return new Destructable(ObjImage, Body, 10.0f, 100.0f, Textures::GetTextures()->m_hollowWoodTriangle, scene);
		case Stone:
			return nullptr;
		default:
			return nullptr;
		}
	}

	case Cube:
		switch (mat)
		{
		case Glass:
			return nullptr;
		case Wood:
			return nullptr;
		case Stone:
			return nullptr;
		default:
			return nullptr;
		}
	
	default:

		return nullptr;

    
	}


}
