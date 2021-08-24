#include "GameObject.h"

GameObject::GameObject(b2World* World)
{
	//tests that the renderable works
	MyRenderable = new sf::RectangleShape;
	dynamic_cast<sf::RectangleShape*>(MyRenderable)->setSize(sf::Vector2f(100, 100));
	//falling object physics
	b2BodyDef BodyDef;

	// creates a body in the world with the position scaled to the world 
	BodyDef.position = b2Vec2(100 / 30.0, 100 / 30.0);
	BodyDef.type = b2_dynamicBody;
	PhysicsBody = World->CreateBody(&BodyDef);

	b2PolygonShape Shape;
	Shape.SetAsBox((100.f / 2) / 30.0, (100.f / 2) / 30.0);
	b2FixtureDef FixtureDef;
	FixtureDef.density = 1.f;
	FixtureDef.shape = &Shape;
	PhysicsBody->CreateFixture(&FixtureDef);
	
}

GameObject::GameObject(sf::Drawable* Renderable, b2Body* Body)
{
	MyRenderable = Renderable;
	PhysicsBody = Body;
}

GameObject::~GameObject()
{
	delete MyRenderable;
}

void GameObject::Update()
{
	//this is an exanple of how to update the object
	dynamic_cast<sf::RectangleShape*>(MyRenderable)->setOrigin(dynamic_cast<sf::RectangleShape*>(MyRenderable)->getSize().x/2, dynamic_cast<sf::RectangleShape*>(MyRenderable)->getSize().y/2);
	dynamic_cast<sf::RectangleShape*>(MyRenderable)->setPosition(PhysicsBody->GetPosition().x * 30, PhysicsBody->GetPosition().y * 30);
	dynamic_cast<sf::RectangleShape*>(MyRenderable)->setRotation(PhysicsBody->GetAngle() * 180 / b2_pi);
}

void GameObject::Render(sf::RenderWindow* window)
{
	//draws the renderable component
	window->draw(*this->MyRenderable);
}
