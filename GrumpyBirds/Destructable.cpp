// C++ Standard Library Includes
// Project Dependencies Includes
#include <Box2D/b2_settings.h>
#include <Box2D/b2_body.h>

// Local Includes
#include "Scene.h"

// this header Include
#include "Destructable.h"

Destructable::Destructable(sf::Drawable* Renderable, b2Body* Body, float _strength, float _health, sf::Texture* _textures[4], Scene* _scene)
{
	// destructable data
	m_strength = _strength;
	m_maxHealth = _health;
	m_currentHealth = _health;

	// texture
	for (int ele = 0; ele < 4; ele++)
	{
		m_textureArray[ele] = _textures[ele];
	}

	// scene
	m_owningScene = _scene;

	// box 2d body
	Body->GetUserData().pointer = reinterpret_cast<uintptr_t>(this);
	PhysicsBody = Body;

	// rendering sfml
	MyRenderable = Renderable;
	dynamic_cast<sf::RectangleShape*>(MyRenderable)->setTexture(m_textureArray[0]);
}

Destructable::~Destructable()
{

}

// handles texture setting and adding object to delete list if nessicary - Naomi Wiggins
void Destructable::Update()
{
	
	if (m_currentHealth > 0.75f * m_maxHealth)
	{
		dynamic_cast<sf::RectangleShape*>(MyRenderable)->setTexture(m_textureArray[0]);
	}
	else if (m_currentHealth > 0.5f * m_maxHealth)
	{
		dynamic_cast<sf::RectangleShape*>(MyRenderable)->setTexture(m_textureArray[1]);
	}
	else if (m_currentHealth > 0.25f * m_maxHealth)
	{
		dynamic_cast<sf::RectangleShape*>(MyRenderable)->setTexture(m_textureArray[2]);
	}
	else  // < 0.25f of max health
	{
		dynamic_cast<sf::RectangleShape*>(MyRenderable)->setTexture(m_textureArray[3]);
	}
	

	GameObject::Update();
}

void Destructable::OnImpact(float _force)
{
	// checks if force is greater than the strength of the object and if so damage the object
	if (_force > m_strength)
	{
		m_currentHealth -= _force - m_strength;

		// if object has no health, set object to be deleted
		if (m_currentHealth <= 0.0f)
		{
			m_owningScene->AddObjectToDeleteList(dynamic_cast<GameObject*>(this));
		}
		else  // change the strength threshold as object is now "weaker"
		{
			m_strength *= 0.9f;
		}
	}
}

