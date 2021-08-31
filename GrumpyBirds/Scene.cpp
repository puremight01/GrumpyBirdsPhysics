#include "Scene.h"

Scene::Scene()
{
	World = nullptr;
	m_listener = nullptr;
}

Scene::~Scene()
{
}

void Scene::Update()
{
	if (World == nullptr)
	{
		return;
	}
	World->Step(1 / 60.f, 8, 3);
	for (auto i = SceneObjects.begin(); i != SceneObjects.end(); i++)
	{
		auto z = *i;
		z->Update();
	}

	// clear list of objects to delete by removing from scene then deleting - Naomi Wiggins
	while (m_objectsToDelete.size() > 0)
	{
		GameObject* tempObj = m_objectsToDelete[m_objectsToDelete.size() - 1];   // set element at back to temp object

		// find object in SceneObject list and get iterator to element
		std::list<GameObject*>::iterator iter = SceneObjects.begin();
		for (iter; iter != SceneObjects.end(); iter++)
		{
			if (iter._Ptr->_Myval == tempObj) { break; } 
		}

		// remove element at iter
		if (iter != SceneObjects.end())
		{
			SceneObjects.erase(iter);
		}

		m_objectsToDelete.pop_back();      // remove back element
	}
}

void Scene::Render(sf::RenderWindow *window)
{
	for (auto i = SceneObjects.begin(); i != SceneObjects.end(); i++)
	{
		auto z = *i;
		z->Render(window);
	}
}

void Scene::AddObjectToDeleteList(GameObject* _obj)
{
	m_objectsToDelete.push_back(_obj);
}
