#pragma once
#ifndef __CONTACT_LISTENDER_H__
#define __CONTACT_LISTENDER_H__

// C++ Standard Library Includes
// Project Dependencies Includes
#include "Include/Box2D/b2_world_callbacks.h"

// Local Includes
// forward declare

// this class handles collisions between GameObjects by listening for contact between GameObject Fixtures - Naomi Wiggins
class ContactListener : public b2ContactListener
{
public:
	void BeginContact(b2Contact* _contact); // this is called when two fixtures begin to overlap
	void EndContact(b2Contact* _contact);   // this is called when two fixtures cease to overlap
	void PreSolve(b2Contact* _contact, const b2Manifold* _oldManifold);  // this is called after collision detection but before collision relsolution
	void PostSolve(b2Contact* _contact, const b2ContactImpulse* _impulse);  // this is called to gather collision impulse results
};

#endif  //  __CONTACT_LISTENDER_H__
