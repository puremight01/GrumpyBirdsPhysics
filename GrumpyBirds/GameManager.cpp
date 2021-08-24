#include "GameManager.h"

GameManager::GameManager()
{
	//creates a empty scene 
	CurrentScene = (Scene*)new ExampleScene();
}

GameManager::~GameManager()
{
	//delete the current scene off of the heap before deleting self
	delete CurrentScene;
}

void GameManager::Update()
{
	//tells the current scene to update
	CurrentScene->Update();
}

void GameManager::Render(sf::RenderWindow *window)
{
	//tells the current scene to render
	CurrentScene->Render(window);
}

void GameManager::SetScene(Scene* NewScene)
{
	//delete the old scene from the heap moving the pointer to the new one
	delete CurrentScene;
	CurrentScene = NewScene;
}
