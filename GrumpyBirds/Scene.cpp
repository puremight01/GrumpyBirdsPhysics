#include "Scene.h"

Scene::Scene()
{
	
	
	b2Vec2 gravity(0.0, 10.f);
	World = new b2World(gravity);
	SceneObjects.push_back(new GameObject(World));
}

Scene::~Scene()
{
}

void Scene::Update()
{
	World->Step(1 / 60.f, 8, 3);
	for (auto i = SceneObjects.begin(); i != SceneObjects.end(); i++)
	{
		auto z = *i;
		z->Update();
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
