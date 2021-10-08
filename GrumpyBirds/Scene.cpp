#include "Pig.h"
#include "Scene.h"

Scene::Scene()
{
	World = nullptr;
	m_listener = nullptr;
}

Scene::~Scene()
{
	for (auto i = SceneObjects.begin(); i != SceneObjects.end(); i++)
	{
		if (nullptr != dynamic_cast<Pig*>(*i))
		{
			delete dynamic_cast<Pig*>(*i);
		}
	}
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

	if (BirdsToFire.size() > 0 && !dynamic_cast<Bird*>(BirdsToFire.front())->GetFiring())
	{
		m_objectsToDelete.push_back(BirdsToFire.front());
		BirdsToFire.pop();
		if (BirdsToFire.size() > 0)
		{
			dynamic_cast<Bird*>(BirdsToFire.front())->SetFiring(true);
		}
		else
		{
			std::cout << "Out of Birds";
		}
		
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
			if (nullptr != dynamic_cast<Pig*>(iter._Ptr->_Myval))
			{
				delete dynamic_cast<Pig*>(iter._Ptr->_Myval);
			}
			else
			{
				iter._Ptr->_Myval->~GameObject();
			}
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
	for (int i = 0; i < 10; i++)
	{
		if (Globals::lineProjection[i] != nullptr)
		{
			window->draw(*Globals::lineProjection[i]);
			auto temp = Globals::lineProjection[i];
			Globals::lineProjection[i] = nullptr;
			delete temp;
		}
	}
		
}

void Scene::AddObjectToDeleteList(GameObject* _obj)
{
	m_objectsToDelete.push_back(_obj);
}
