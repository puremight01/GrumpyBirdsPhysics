#include "Pig.h"
#include"Textures.h"

int Pig::PigCount = 0;

Pig::Pig(sf::Drawable* Renderable, b2Body* Body, float _strength, float _health, Scene* _scene)
{
	// destructable data
	m_strength = _strength;
	m_maxHealth = _health;
	m_currentHealth = _health;

	// texture
	for (int ele = 0; ele < 4; ele++)
	{
		m_textureArray[ele] = Textures::GetTextures()->m_pig[ele];
	}

	// scene
	m_owningScene = _scene;

	// box 2d body
	Body->GetUserData().pointer = reinterpret_cast<uintptr_t>(this);
	PhysicsBody = Body;

	// rendering sfml
	MyRenderable = Renderable;
	dynamic_cast<sf::RectangleShape*>(MyRenderable)->setTexture(m_textureArray[0]);

	//std::cout << "mass = " << PhysicsBody->GetMass() << std::endl;

	//increase pig count 
	PigCount++;
}

Pig::~Pig()
{
	//decrease pig count
	std::cout << "DONE";
	PigCount--;
}

int Pig::GetPigCount()
{
	return PigCount;
}

void Pig::Update()
{
	Destructable::Update();
	//if off the map
	if (PhysicsBody->GetPosition().y > 30)
	{
		m_currentHealth = 0;
	}
}

