#ifndef __GameObject__
#define __GameObject__

#include<Box2D/box2d.h>
#include<SFML/Graphics.hpp>

//Holds all of the information about an object
//created by Jacob Sullivan
class GameObject
{
public:

	//Creates this object
	//created by Jacob Sullivan
	GameObject(b2World* World);

	//Constructor for game object used by factory
	//created by Jacob Sullivan
	GameObject(sf::Drawable* Renderable, b2Body* Body);

	//Destroys this object
	//created by Jacob Sullivan
	~GameObject();
	
	//Updates this object
	//created by Jacob Sullivan
	void Update();

	//Renders this object
	//created by Jacob Sullivan
	void Render(sf::RenderWindow* window);

private:
	//this holds the drawable part of the object 
	//created by Jacob Sullivan
	sf::Drawable* MyRenderable;
	
	//The Physics body of this object 
	//created by Jacob Sullivan
	b2Body* PhysicsBody;
};

#endif // !__GameObject__

