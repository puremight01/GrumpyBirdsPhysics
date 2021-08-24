#ifndef __Globals__
#define __Globals__

#include<SFML/Graphics.hpp>

//Holds the variables that are needed in multiple classes
//created by Jacob Sullivan
class Globals
{
public:
	Globals();

	//the reference to the game window so we can get mouse position 
	//created by Jacob Sullivan
	static sf::RenderWindow* window;
};

#endif // !__Globals__