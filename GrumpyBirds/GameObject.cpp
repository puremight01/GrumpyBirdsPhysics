#include "Globals.h"
#include "GameObject.h"

GameObject::GameObject()
{
	//makes an empty object
	MyRenderable = nullptr;
	PhysicsBody = nullptr;
}

GameObject::GameObject(sf::Drawable* Renderable, b2Body* Body)
{
	MyRenderable = Renderable;
	PhysicsBody = Body;
}

GameObject::~GameObject()
{
	delete MyRenderable;
	b2World* gameObjectWorld = PhysicsBody->GetWorld();
	gameObjectWorld->DestroyBody(PhysicsBody);
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
