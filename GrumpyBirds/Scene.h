#ifndef __Scene__
#define __Scene__

//includes needed in this class
#include<list>
//#include"GameObject.h"
#include"Bird.h"
#include"Textures.h"
#include "ContactListener.h"
#include "Destructable.h"
#include "ObjectMaker.h"

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

	// adds object to list of objects to be deleted - created by Naomi Wiggins
	void AddObjectToDeleteList(GameObject* _obj);

	//The Box2d physics
	//created by Jacob Sullivan
	b2World* World;

protected:
	//All of the objects in this scene 
	//created by Jacob Sullivan
	std::list<GameObject*> SceneObjects;

	// vector of objects to be removed from scene - Naomi Wiggins
	std::vector<GameObject*> m_objectsToDelete;

	// the contact listener - Naomi Wiggins
	ContactListener* m_listener;
};
#endif

