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
	PhysicsBody->SetAngularDamping(9.0);

}

Bird::Bird()
{
	WorldRef = nullptr;
	SlingShotRef = nullptr;
	MouseJoint = nullptr;
	SlingshotJoint = nullptr;
	MyRenderable = nullptr;
	PhysicsBody = nullptr;
}

Bird::~Bird()
{
}

void Bird::Update()
{
	if (Fired)
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		{
			InAirClick();
		}
		if (PhysicsBody->GetLinearVelocity().LengthSquared() < 0.01f)
		{
			if (DeathTimer == 0)
			{
				DeathTimer = clock();
			}
			else if (DeathTimer != 0 && (clock() - DeathTimer) / CLOCKS_PER_SEC > 2)
			{
				Firing = false;
			}
		}
		//if off the map
		if (PhysicsBody->GetPosition().y > 30)
		{
			Firing = false;
		}
	}
	else if (Firing)
	{

		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		{
			CreateMouseJoint((float)sf::Mouse::getPosition(*Globals::window).x / 30.0f, (float)sf::Mouse::getPosition(*Globals::window).y / 30.0f);
			CreateSlingshotJoint();
			PhysicsBody->GetPosition();

			sf::CircleShape* LineProjection[5];
			auto position = sf::Vector2f(SlingShotRef->GetPosition().x * 30, SlingShotRef->GetPosition().y * 30);
			auto velocity = sf::Vector2f(SlingShotRef->GetPosition().x - PhysicsBody->GetPosition().x, SlingShotRef->GetPosition().y - PhysicsBody->GetPosition().y);
			for (int i = 0; i < 10; i++)
			{
				Globals::lineProjection[i] = new sf::CircleShape();
				velocity = velocity + sf::Vector2f(0, 0.03f);
				position = position + velocity * 20.0f;
				Globals::lineProjection[i]->setPosition(position);
				Globals::lineProjection[i]->setRadius(10-i/2);
				Globals::lineProjection[i]->setFillColor(sf::Color::White);
				Globals::lineProjection[i]->setOutlineThickness(1);
			}
			
		}
		else if (MouseJoint != nullptr)
		{
			PhysicsBody->SetGravityScale(1);
			WorldRef->DestroyJoint(MouseJoint);
			WorldRef->DestroyJoint(SlingshotJoint);
			MouseJoint = nullptr;
			SlingshotJoint = nullptr;
			PhysicsBody->ApplyForceToCenter(b2Vec2((SlingShotRef->GetTransform().p.x - PhysicsBody->GetTransform().p.x) * 2000, (SlingShotRef->GetTransform().p.y - PhysicsBody->GetTransform().p.y) * 2000), true);
			Fired = true;
		}
		else
		{
			//move to the slingshot
			PhysicsBody->SetGravityScale(0);
			PhysicsBody->SetTransform(PhysicsBody->GetPosition() + 0.01 * (SlingShotRef->GetPosition() - PhysicsBody->GetPosition()), 0);
		}
	}
	GameObject::Update();
}

void Bird::InAirClick()
{
	if (!Activated)
	{
		ClickFunction();
		Activated = true;
	}
}

void Bird::ClickFunction()
{
	std::cout << "Flight Activation";
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
		SlingshotJointDef->length = 1.5f;
		SlingshotJointDef->maxLength = 3.0f;

		//SlingshotJointDef->damping = 10;
		//SlingshotJointDef->stiffness = 75.0f;
		SlingshotJointDef->collideConnected = false;


		SlingshotJoint = static_cast<b2DistanceJoint*>(WorldRef->CreateJoint(SlingshotJointDef));
	}
}
