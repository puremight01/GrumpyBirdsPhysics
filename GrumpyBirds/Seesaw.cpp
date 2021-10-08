#include "Scene.h"
#include "Seesaw.h"

Seesaw::Seesaw(GameObject* _objA, GameObject* _objB, b2Vec2 _point, Scene* _scene)
{
	m_jointDefinition.Initialize(_objA->GetPhysicsBody(), _objB->GetPhysicsBody(), _point);
	//_world.CreateJoint(&m_jointDefinition);

	m_objectA = _objA;
	m_objectB = _objB;

	m_ownerScene = _scene;
}

Seesaw::~Seesaw()
{
}

void Seesaw::Update()
{
	if (m_objectA == nullptr || m_objectB == nullptr)
	{
		//m_ownerScene->AddObjectToDeleteList(m_objectA);
		//m_ownerScene->AddObjectToDeleteList(m_objectB);
		m_ownerScene->AddObjectToDeleteList(this);
	}

	/*if (m_objectB == nullptr)
	{
		m_ownerScene->AddObjectToDeleteList(m_objectA);
		this->~Seesaw();
		return;
	}*/
}

void Seesaw::setJointLimits(float _lower, float _upper)
{
	m_jointDefinition.lowerAngle = _lower;
	m_jointDefinition.upperAngle = _upper;
	m_jointDefinition.enableLimit = true;
}

