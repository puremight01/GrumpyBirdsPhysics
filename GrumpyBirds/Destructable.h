#pragma once

#ifndef __DESTRUCTABLE_H__
#define __DESTRUCTABLE_H__

// C++ Standard Library Includes
// Project Dependencies Includes
// Local Includes
#include "GameObject.h"
#include "Scene.h"

class Destructable : public GameObject
{
	Destructable(sf::Drawable* Renderable, b2Body* Body, float _strength, float _health, sf::Texture* _textures[4], Scene* _scene);
	~Destructable();

	void Update();

private:
	float m_strength;                // how strong the object is - Naomi Wiggins
	float m_maxHealth;               // the maximum health the object has - Naomi Wiggins
	float m_currentHealth;           // current health of object - how close to death - Naomi Wiggins
	sf::Texture* m_textureArray[4];  // array of textures this object will use - Naomi Wiggins
	Scene* m_owningScene;            // the scene this object belongs to - Naomi Wiggins
};

#endif  // __DESTRUCTABLE_H__
