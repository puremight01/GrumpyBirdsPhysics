#include "Scene.h"

Scene::Scene()
{
	World = nullptr;
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
}

void Scene::Render(sf::RenderWindow *window)
{
	for (auto i = SceneObjects.begin(); i != SceneObjects.end(); i++)
	{
		auto z = *i;
		z->Render(window);
	}
}
