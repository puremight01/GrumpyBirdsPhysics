#ifndef __GameObject__
#define __GameObject__

#include<Box2D/box2d.h>
#include<SFML/Graphics.hpp>

class GameObject
{
public:

	//Creates this object
	GameObject(b2World* World);

	//Constructor for game object used by factory
	GameObject(sf::Drawable* Renderable, b2Body* Body);

	//Destroys this object
	~GameObject();
	
	//Updates this object
	void Update();

	//Renders this object
	void Render(sf::RenderWindow* window);

private:
	//this holds the drawable part of the object 
	sf::Drawable* MyRenderable;
	
	//The Physics body of this object 
	b2Body* PhysicsBody;
};

#endif // !__GameObject__

