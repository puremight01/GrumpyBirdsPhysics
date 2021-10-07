#include "ObjectMaker.h"
#include "Level1.h"

Level1::Level1()
{
	// box2d world physics setup
	b2Vec2 gravity(0.0, 10.f);
	World = new b2World(gravity);

	// contact listener setup - to check for contact - Naomi Wiggins
	m_listener = new ContactListener;
	World->SetContactListener(m_listener);

	//ground
	//sf::RectangleShape* Gshape = new sf::RectangleShape;
	//Gshape->setSize(sf::Vector2f(1600, 100));
	//Gshape->setFillColor(sf::Color::Green);
	//Gshape->setOrigin(sf::Vector2f(800, 50));
	//b2BodyDef gBodyDef;
	//gBodyDef.position = b2Vec2(800.f / 30.f, 800.f / 30.f);
	//gBodyDef.type = b2_staticBody;
	//b2Body* gBody = World->CreateBody(&gBodyDef);
	//b2PolygonShape gShape;
	//gShape.SetAsBox(800.f / 30.f, 50.f / 30.f);
	//b2FixtureDef gFixtureDef;
	//gFixtureDef.density = 0.f;
	//gFixtureDef.shape = &gShape;
	//gBody->CreateFixture(&gFixtureDef);
	//SceneObjects.push_back(new GameObject(Gshape, gBody));

	ObjectMaker GameObjectCreator;
	SceneObjects.push_back(GameObjectCreator.StaticObj(ObjectType::Cube, sf::Color::Green, this, sf::Vector2f(800, 850), sf::Vector2f(1600, 100)));  //Ground
	//SceneObjects.push_back(GameObjectCreator.StaticObj(ObjectType::Cube))
}
