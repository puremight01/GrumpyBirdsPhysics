#include "ExampleScene.h"

ExampleScene::ExampleScene()
{
	b2Vec2 gravity(0.0, 10.f);
	World = new b2World(gravity);

	//tests that the factory can work
	auto temp = new sf::RectangleShape;
	dynamic_cast<sf::RectangleShape*>(temp)->setSize(sf::Vector2f(100, 100));
	//falling object physics
	b2BodyDef BodyDef;

	// creates a body in the world with the position scaled to the world 
	BodyDef.position = b2Vec2(100 / 30.0, 100 / 30.0);
	BodyDef.type = b2_dynamicBody;
	auto temp2 = World->CreateBody(&BodyDef);

	b2PolygonShape Shape;
	Shape.SetAsBox((100.f / 2) / 30.0, (100.f / 2) / 30.0);
	b2FixtureDef FixtureDef;
	FixtureDef.density = 1.f;
	FixtureDef.shape = &Shape;
	temp2->CreateFixture(&FixtureDef);

	SceneObjects.push_back(new GameObject(temp, temp2));

	//ground
	sf::RectangleShape* Gshape = new sf::RectangleShape;
	Gshape->setSize(sf::Vector2f(800, 100));
	Gshape->setFillColor(sf::Color::Green);
	//ground physics
	b2BodyDef gBodyDef;
	gBodyDef.position = b2Vec2(0 / 30.0, 600 / 30.0);
	gBodyDef.type = b2_staticBody;
	b2Body* gBody = World->CreateBody(&gBodyDef);

	b2PolygonShape gShape;
	gShape.SetAsBox((800 / 2) / 30.0, (100 / 2) / 30.0);
	b2FixtureDef gFixtureDef;
	gFixtureDef.density = 0.f;
	gFixtureDef.shape = &gShape;
	gBody->CreateFixture(&gFixtureDef);

	SceneObjects.push_back(new GameObject(Gshape, gBody));
}
