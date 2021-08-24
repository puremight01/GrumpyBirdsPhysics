#ifndef __Scene__
#define __Scene__

//includes needed in this class

#include<list>
#include"GameObject.h"
#include"Textures.h"

//holds all of the information in the scene 
//created by Jacob Sullivan
class Scene
{
public:
	//creates an empty scene
	//created by Jacob Sullivan
	Scene();

	//destroys whatever is in the scene
	//created by Jacob Sullivan
	~Scene();

	//updates all of the scene objects
	//created by Jacob Sullivan
	void Update();

	//renders all of the scene objects
	//created by Jacob Sullivan
	void Render(sf::RenderWindow *window);

protected:
	//All of the objects in this scene 
	//created by Jacob Sullivan
	std::list<GameObject*> SceneObjects;

	//The Box2d physics
	//created by Jacob Sullivan
	b2World* World;

};
#endif

