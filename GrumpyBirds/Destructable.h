#pragma once

#ifndef __DESTRUCTABLE_H__
#define __DESTRUCTABLE_H__

// C++ Standard Library Includes
// Project Dependencies Includes
// Local Includes
#include "GameObject.h"

// forward declare
class Scene;

class Destructable : public GameObject
{
public:
	// creates a destrucable object - Naomi Wiggins
	Destructable(sf::Drawable* Renderable, b2Body* Body, float _strength, float _health, sf::Texture* _textures[4], Scene* _scene);
	//creates an empty destructable object for inheritance - Jacob Sullivan
	Destructable();
	// destructable object destructor - Naomi Wiggins
	~Destructable() {};

	// updates drawables and physics components - Naomi Wiggins
	virtual void Update();
	// handles impact - Naomi Wiggins
	void OnImpact(float _force);

protected:
	float m_strength;                // how strong the object is - Naomi Wiggins
	float m_maxHealth;               // the maximum health the object has - Naomi Wiggins
	float m_currentHealth;           // current health of object - how close to death - Naomi Wiggins
	sf::Texture* m_textureArray[4];  // array of textures this object will use - Naomi Wiggins
	Scene* m_owningScene;            // the scene this object belongs to - Naomi Wiggins
};

#endif  // __DESTRUCTABLE_H__
