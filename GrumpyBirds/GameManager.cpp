#include "Pig.h"
#include "GameManager.h"

GameManager::GameManager()
{
	//creates a empty scene 
	SceneNumber = 0;
	CurrentScene = nullptr;

}

GameManager::~GameManager()
{
	//delete the current scene off of the heap before deleting self
	delete CurrentScene;
}

void GameManager::Update()
{
	if (Pig::GetPigCount() == 0)
	{
		SetScene(NextScene());
	}
	if (CurrentScene->BirdsToFire.size() == 0)
	{
		SetScene(SameScene());
	}
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

Scene* GameManager::NextScene()
{
	SceneNumber++;
	switch (SceneNumber)
	{
	case 1:
		return (Scene*)new Level1();
	case 2:
		SceneNumber = 0;
		return (Scene*)new LevelTwo();
	default:
		break;
	}
}

Scene* GameManager::SameScene()
{
	
	switch (SceneNumber)
	{
	case 1:
		return (Scene*)new Level1();
	case 0:
		return (Scene*)new LevelTwo();
	default:
		break;
	}
}

//Scene* GameManager::GetScene()
//{
//	// returns the current scene
//	return(CurrentScene);
//}
