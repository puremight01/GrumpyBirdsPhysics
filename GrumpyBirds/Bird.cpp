#include "Bird.h"
#include<iostream>

Bird::Bird(sf::Drawable* Renderable, b2Body* Body, b2World& World, b2Body* SlingShotBody)
{
	WorldRef = &World;
	SlingShotRef = SlingShotBody;
	MouseJoint = nullptr;
	SlingshotJoint = nullptr;
	MyRenderable = Renderable;
	PhysicsBody = Body;
	dynamic_cast<sf::RectangleShape*>(MyRenderable)->setTexture(Textures::GetTextures()->RedGrumpyBird1, true);

}

void Bird::Update()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		//std::cout << "X: " << sf::Mouse::getPosition(*Globals::window).x << "   Y: " << sf::Mouse::getPosition(*Globals::window).y << std::endl;
		CreateMouseJoint((float)sf::Mouse::getPosition(*Globals::window).x / 30.0f, (float)sf::Mouse::getPosition(*Globals::window).y / 30.0f);
		CreateSlingshotJoint();
		PhysicsBody->GetPosition();
	}
	else if (MouseJoint != nullptr)
	{
		WorldRef->DestroyJoint(MouseJoint);
		WorldRef->DestroyJoint(SlingshotJoint);
		MouseJoint = nullptr;
		SlingshotJoint = nullptr;
		PhysicsBody->ApplyForceToCenter(b2Vec2((SlingShotRef->GetTransform().p.x - PhysicsBody->GetTransform().p.x) * 2000, (SlingShotRef->GetTransform().p.y - PhysicsBody->GetTransform().p.y) * 2000), true);
	}
	GameObject::Update();
}

void Bird::CreateMouseJoint(float x, float y)
{
	if (MouseJoint == nullptr)
	{
		b2MouseJointDef* MouseJointDef = new b2MouseJointDef();

		MouseJointDef->bodyA = SlingShotRef;
		MouseJointDef->bodyB = PhysicsBody;
		
		MouseJointDef->target.Set(PhysicsBody->GetTransform().p.x, PhysicsBody->GetTransform().p.y);

		MouseJointDef->maxForce = 50000.0f * PhysicsBody->GetMass() * 10;
		MouseJointDef->damping = 10.0f;

		MouseJointDef->collideConnected = false;
		MouseJointDef->stiffness = 75.0f;

		MouseJoint = static_cast<b2MouseJoint*>(WorldRef->CreateJoint(MouseJointDef));
	}
	else
	{
		MouseJoint->SetTarget(b2Vec2(x, y));
	}
}

void Bird::CreateSlingshotJoint()
{
	if (SlingshotJoint == nullptr)
	{
		b2DistanceJointDef* SlingshotJointDef = new b2DistanceJointDef();
		SlingshotJointDef->Initialize(PhysicsBody, SlingShotRef, PhysicsBody->GetTransform().p, SlingShotRef->GetTransform().p);

		SlingshotJointDef->minLength = 0.1f;
		SlingshotJointDef->length = 1.0f;
		SlingshotJointDef->maxLength = 2.0f;

		//SlingshotJointDef->damping = 10;
		//SlingshotJointDef->stiffness = 75.0f;
		SlingshotJointDef->collideConnected = false;


		SlingshotJoint = static_cast<b2DistanceJoint*>(WorldRef->CreateJoint(SlingshotJointDef));
	}
}
