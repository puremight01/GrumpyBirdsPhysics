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
		return (Scene*)new Level1();//ExampleScene();
	case 2:
		return (Scene*)new LevelTwo();
	default:
		break;
	}
	return nullptr;
}

//Scene* GameManager::GetScene()
//{
//	// returns the current scene
//	return(CurrentScene);
//}
