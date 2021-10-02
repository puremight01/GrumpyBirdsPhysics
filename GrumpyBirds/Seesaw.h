#pragma once

#ifndef __SEESAW_H__
#define __SEESAW_H__

#include "GameObject.h"

// forward declare
class Scene;

class Seesaw : public GameObject
{
public:
	// creates a seesaw object from two physics bodies and a anchor point. uses a revolute Joint - Naomi Wiggins
	Seesaw(GameObject* _objA, GameObject* _objB, b2Vec2 _point, Scene* _scene);
	// destroys the seesaw and the objects used to create the seesaw - Naomi Wiggins
	~Seesaw();

	// updates the joint overtime. handles null bodies destruction as well - Naomi Wiggins
	void Update();

	// this sets the angle limits for the revolute joint - Naomi Wiggins
	void setJointLimits(float _lower, float _upper);
	// returns the joint definition - Naomi Wiggins
	b2RevoluteJointDef* GetJointDef() { return(&m_jointDefinition); }

private:
	b2RevoluteJointDef m_jointDefinition;    // definition for seesaw revoluteJoint - Naomi Wiggins
	GameObject* m_objectA;                   // first object / body in joint - Naomi Wiggins
	GameObject* m_objectB;                   // second object / body in joint - Naomi Wiggins
	Scene* m_ownerScene;                     // scene that contains and controls the seesaw - Naomi Wiggins
};

#endif  // __SEESAW_H__
