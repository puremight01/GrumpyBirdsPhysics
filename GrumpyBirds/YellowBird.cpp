#include "YellowBird.h"

YellowBird::YellowBird(sf::Drawable* Renderable, b2Body* Body, b2World& World, b2Body* SlingShotBody)
{
	WorldRef = &World;
	SlingShotRef = SlingShotBody;
	MouseJoint = nullptr;
	SlingshotJoint = nullptr;
	MyRenderable = Renderable;
	PhysicsBody = Body;
	dynamic_cast<sf::RectangleShape*>(MyRenderable)->setTexture(Textures::GetTextures()->YellowGrumpyBird, true);
}

void YellowBird::ClickFunction()
{
	std::cout << "Yellow Birds Flight Activation";
	PhysicsBody->SetLinearVelocity(3 * PhysicsBody->GetLinearVelocity());
	
}
