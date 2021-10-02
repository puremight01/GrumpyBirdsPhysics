#ifndef __Bird__
#define __Bird__


#include"GameObject.h"
#include"Globals.h"
#include"Textures.h"

//This is the games flingable bird class
//created by Jacob Sullivan
class Bird :public GameObject
{
public:
	//creates a bird
	//created by Jacob Sullivan
	Bird(sf::Drawable* Renderable, b2Body* Body, b2World& World, b2Body* SlingShotBody);

	//creates a blank bird for child classes
	//created by Jacob Sullivan
	Bird();

	//destroys the bird
	~Bird();

	//firing accessor functions
	//created by Jacob Sullivan
	void SetFiring(bool value) { Firing = value; };
	bool GetFiring() {return Firing; };

	//adds on to the update funtionality 
	//created by Jacob Sullivan
	void Update();

protected:
	//local variables 
	//created by Jacob Sullivan
	b2Body* SlingShotRef;
	b2World* WorldRef;

	b2MouseJoint* MouseJoint;
	b2DistanceJoint* SlingshotJoint;

	bool Firing = false;
	bool Fired = false;
	bool Activated = false;

	float DeathTimer = 0;

	//triggers the bird logic unique to this bird 
	// created by Jacob Sullivan 
	void InAirClick();

	//holds the logic unique to this bird 
	// created by Jacob Sullivan 
	virtual void ClickFunction();

	//creates a mouse joint at the x,y position 
	//created by Jacob Sullivan
	void CreateMouseJoint(float x, float y);

	//creates a slingshot joing attached to SlingShotRef
	//created by Jacob Sullivan
	void CreateSlingshotJoint();
};

#endif // !__Bird__