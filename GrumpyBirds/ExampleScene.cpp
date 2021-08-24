#include "ExampleScene.h"


ExampleScene::ExampleScene()
{
	b2Vec2 gravity(0.0, 10.f);
	World = new b2World(gravity);


	sf::Texture *SolidWoodCube1 = new sf::Texture;

	if (!SolidWoodCube1->loadFromFile("Resources/MapSprites/ANGRY_BIRDS_RIO_INGAME_BLOCKS_WOOD_1.png", sf::IntRect(4, 177, 80, 82)))
	{
		// error...
	}
	SolidWoodCube1->setSmooth(true);

	//tests that the factory can work
	auto temp = new sf::RectangleShape;
	dynamic_cast<sf::RectangleShape*>(temp)->setSize(sf::Vector2f(50, 50));
	dynamic_cast<sf::RectangleShape*>(temp)->setTexture(SolidWoodCube1);

	//falling object physics
	b2BodyDef BodyDef;

	// creates a body in the world with the position scaled to the world 
	BodyDef.position = b2Vec2(50 / 30.0, 750 / 30.0);
	BodyDef.type = b2_dynamicBody;
	auto temp2 = World->CreateBody(&BodyDef);

	b2PolygonShape Shape;
	Shape.SetAsBox((50.f / 2) / 30.0, (50.f / 2) / 30.0);
	b2FixtureDef FixtureDef;
	FixtureDef.density = 1.f;
	FixtureDef.shape = &Shape;
	temp2->CreateFixture(&FixtureDef);
	temp2->SetAngularVelocity(0.0f);

	SceneObjects.push_back(new GameObject(temp, temp2));

	//tests that the factory can work
	auto temp3 = new sf::RectangleShape;
	dynamic_cast<sf::RectangleShape*>(temp3)->setSize(sf::Vector2f(50, 50));
	dynamic_cast<sf::RectangleShape*>(temp3)->setTexture(SolidWoodCube1);

	//falling object physics
	b2BodyDef BodyDef2;

	// creates a body in the world with the position scaled to the world 
	BodyDef2.position = b2Vec2(70 / 30.0, 675 / 30.0);
	BodyDef2.type = b2_dynamicBody;
	auto temp4 = World->CreateBody(&BodyDef2);

	b2PolygonShape Shape2;
	Shape2.SetAsBox((50.f / 2) / 30.0, (50.f / 2) / 30.0);
	b2FixtureDef FixtureDef2;
	FixtureDef2.density = 1.f;
	FixtureDef2.shape = &Shape2;
	temp4->CreateFixture(&FixtureDef2);
	temp4->SetAngularVelocity(0.0f);

	SceneObjects.push_back(new GameObject(temp3, temp4));

	//ground
	sf::RectangleShape* Gshape = new sf::RectangleShape;
	Gshape->setSize(sf::Vector2f(1600, 100));
	Gshape->setFillColor(sf::Color::Green);
	//ground physics
	b2BodyDef gBodyDef;
	gBodyDef.position = b2Vec2(800/ 30.0, 800 / 30.0);
	gBodyDef.type = b2_staticBody;
	b2Body* gBody = World->CreateBody(&gBodyDef);

	b2PolygonShape gShape;
	gShape.SetAsBox((1600 / 2) / 30.0, (100 / 2) / 30.0);
	b2FixtureDef gFixtureDef;
	gFixtureDef.density = 0.f;
	gFixtureDef.shape = &gShape;
	gBody->CreateFixture(&gFixtureDef);
	

	SceneObjects.push_back(new GameObject(Gshape, gBody));
}