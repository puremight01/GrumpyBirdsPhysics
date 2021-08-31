// C++ Standard Library Includes
#include <iostream>
#include <typeinfo>

// Project Dependencies Includes
#include <Box2D/b2_contact.h>
#include <Box2D/b2_settings.h>

// Local Includes
#include "Destructable.h"

// this header file include
#include "ContactListener.h"

// forward declare

// determins what happens when two fixtures begin to overlap - Naomi Wiggins
void ContactListener::BeginContact(b2Contact* _contact)
{
	// user data - pointer to custom object type
	auto userDataA = _contact->GetFixtureA()->GetBody()->GetUserData().pointer;
	auto userDataB = _contact->GetFixtureB()->GetBody()->GetUserData().pointer;

	// momentum of objects
	b2Vec2 momentumA = _contact->GetFixtureA()->GetBody()->GetMass() * _contact->GetFixtureA()->GetBody()->GetLinearVelocity();
	b2Vec2 momentumB = _contact->GetFixtureB()->GetBody()->GetMass() * _contact->GetFixtureB()->GetBody()->GetLinearVelocity();

	// check if Object A is destructable
	if (userDataA != 0)
	{
		// calculate force of impact on object A
		float force = b2Vec2(momentumA - momentumB).Length();

		std::cout << "force on A = " << force << std::endl;
		
		// cast userData to Destructable and apply force
		reinterpret_cast<Destructable*>(userDataA)->OnImpact(force);
	}

	// check if Object B is destructable
	if (userDataB != 0)
	{
		// calculate force of impact on object B
		float force = b2Vec2(momentumB - momentumA).Length();

		std::cout << "force on B = " << force << std::endl;

		// cast userData to Destructable and apply force
		reinterpret_cast<Destructable*>(userDataB)->OnImpact(force);
	}
}

void ContactListener::EndContact(b2Contact* _contact)
{

}

void ContactListener::PreSolve(b2Contact* _contact, const b2Manifold* _oldManifold)
{

}

void ContactListener::PostSolve(b2Contact* _contact, const b2ContactImpulse* _impulse)
{

}

