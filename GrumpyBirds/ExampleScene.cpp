#include "ExampleScene.h"


ExampleScene::ExampleScene()
{
	b2Vec2 gravity(0.0, 10.f);
	World = new b2World(gravity);
	
	// contact listener setup - to check for contact - Naomi Wiggins
	m_listener = new ContactListener;
	World->SetContactListener(m_listener);
	
	
	//tests that the factory can work
	auto temp = new sf::RectangleShape;
	dynamic_cast<sf::RectangleShape*>(temp)->setSize(sf::Vector2f(50, 50));
	dynamic_cast<sf::RectangleShape*>(temp)->setTexture(Textures::GetTextures()->SolidWoodCube3);

	//falling object physics
	b2BodyDef BodyDef;

	// creates a body in the world with the position scaled to the world 
	BodyDef.position = b2Vec2(50 / 30.0, 750 / 30.0);
	BodyDef.type = b2_dynamicBody;
	auto temp2 = World->CreateBody(&BodyDef);

	b2PolygonShape Shape;
	Shape.SetAsBox((50.f / 2) / 30.0, (50.f / 2) / 30.0);
	b2FixtureDef FixtureDef;
	FixtureDef.density = 1.0f;
	FixtureDef.shape = &Shape;
	temp2->CreateFixture(&FixtureDef);
	temp2->SetAngularVelocity(0.0f);

	//tests that the factory can work
	auto temp3 = new sf::RectangleShape;
	dynamic_cast<sf::RectangleShape*>(temp3)->setSize(sf::Vector2f(50, 50));

	//falling object physics
	b2BodyDef BodyDef2;

	// creates a body in the world with the position scaled to the world 
	BodyDef2.position = b2Vec2(1500.0f / 30.0f, 675.0f / 30.0f);
	BodyDef2.type = b2_dynamicBody;
	auto temp4 = World->CreateBody(&BodyDef2);

	b2CircleShape Shape2;
	Shape2.m_radius = 25.0f / 30.0f;

	b2FixtureDef FixtureDef2;
	FixtureDef2.density = 1.f;
	FixtureDef2.shape = &Shape2;
	temp4->CreateFixture(&FixtureDef2);
	temp4->SetAngularVelocity(0.0f);

	SceneObjects.push_back(new Destructable(temp3, temp4, 10.0f, 100.0f, Textures::GetTextures()->m_solidWoodSphere, this));

	// destructable 2
	//tests that the factory can work
	auto sfDestruct2 = new sf::RectangleShape;
	dynamic_cast<sf::RectangleShape*>(sfDestruct2)->setSize(sf::Vector2f(100, 100));
	//falling object physics
	b2BodyDef BodyDefDestruct2;
	// creates a body in the world with the position scaled to the world 
	BodyDefDestruct2.position = b2Vec2(850.0f / 30.0f, 350.0f / 30.0f);
	BodyDefDestruct2.type = b2_dynamicBody;
	auto Destruct2 = World->CreateBody(&BodyDefDestruct2);

	b2PolygonShape ShapeDestruct2;
	b2Vec2 points[3] = { b2Vec2(-50.0f/30.0f, -50.0f/30.0f), b2Vec2(0.0f, 50.0f/30.0f), b2Vec2(50.0f/30.0f, -50.0f/30.0f) };
	ShapeDestruct2.Set(points, 3);

	b2FixtureDef FixtureDefDestruct2;
	FixtureDefDestruct2.density = 1.f;
	FixtureDefDestruct2.shape = &ShapeDestruct2;
	Destruct2->CreateFixture(&FixtureDefDestruct2);
	Destruct2->SetAngularVelocity(0.0f);

	SceneObjects.push_back(new Destructable(sfDestruct2, Destruct2, 10.0f, 100.0f, Textures::GetTextures()->m_hollowWoodTriangle, this));


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

	//sling shot
	sf::RectangleShape* Sshape = new sf::RectangleShape;
	Sshape->setSize(sf::Vector2f(100, 200));
	Sshape->setTexture(Textures::GetTextures()->SlingShot);
	//slingshot physics
	b2BodyDef sBodyDef;
	sBodyDef.position = b2Vec2(100 / 30.0, 650 / 30.0);
	sBodyDef.type = b2_staticBody;
	b2Body* sBody = World->CreateBody(&sBodyDef);

	b2PolygonShape sShape;
	sShape.SetAsBox((200 / 2) / 30.0, (200 / 2) / 30.0);
	b2FixtureDef sFixtureDef;
	sFixtureDef.density = 0.f;
	sFixtureDef.shape = &sShape;
	sFixtureDef.isSensor = true;
	sBody->CreateFixture(&sFixtureDef);


	SceneObjects.push_back(new GameObject(Sshape, sBody));
	SceneObjects.push_back(new Bird(temp, temp2, *World, sBody));
}
