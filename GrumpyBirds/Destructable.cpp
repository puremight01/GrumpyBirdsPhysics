// C++ Standard Library Includes
// Project Dependencies Includes
// Local Includes
// this header Include
#include "Destructable.h"

Destructable::Destructable(sf::Drawable* Renderable, b2Body* Body, float _strength, float _health, sf::Texture* _textures[4], Scene* _scene)
{
	m_strength = _strength;
	m_maxHealth = _health;
	m_currentHealth = _health;

	for (int ele = 0; ele < 4; ele++)
	{
		m_textureArray[ele] = _textures[ele];
	}

	m_owningScene = _scene;
	PhysicsBody = Body;

	MyRenderable = Renderable;
	dynamic_cast<sf::RectangleShape*>(MyRenderable)->setTexture(m_textureArray[0]);
}

Destructable::~Destructable()
{

}

void Destructable::Update()
{

}

