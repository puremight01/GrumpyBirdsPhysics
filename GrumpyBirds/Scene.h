#ifndef __Scene__
#define __Scene__

//includes needed in this class

#include<list>
#include"GameObject.h"


class Scene
{
public:
	//creates an empty scene
	Scene();

	//destroys whatever is in the scene
	~Scene();

	//updates all of the scene objects
	void Update();

	//renders all of the scene objects
	void Render(sf::RenderWindow *window);

private:
	//All of the objects in this scene 
	std::list<GameObject*> SceneObjects;

	//The Box2d physics
	b2World* World;

};
#endif

