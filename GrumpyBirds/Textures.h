#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>

//holds all of the textures used in the program so they only need to be created once 
//created by Jacob Sullivan
class Textures
{
private:
	//creates all of the textures in the game when made
	//this is a very heavy object so it is only made once
	//created by Jacob Sullivan
	Textures();

	//holds the refference to this object 
	//created by Jacob Sullivan
	static Textures* SingleTexture;
public:
	//deletes all of the texture pointers created by this class 
	//created by Jacob Sullivan
	~Textures();

	//creates the only instance of this class if none exists otherwise returns the one instance 
	//created by Jacob Sullivan
	static Textures* GetTextures();
	
	//Solid wood cube and its damaged states
	//created by Jacob Sullivan
	sf::Texture* m_woodCube[4];       
	sf::Texture* m_woodSphere[4];      // array of solid wood sphere and its damage states - Naomi Wiggins
	sf::Texture* m_woodTriangle[4];    // array of wood triangle and its damage states - Naomi Wiggins
	sf::Texture* m_glassCube[4];        // array of solid glass cube and its damage states - Naomi Wiggins
	sf::Texture* m_glassSphere[4];      // array of solid glass sphere and its damage states - Naomi Wiggins
	sf::Texture* m_glassTriangle[4];    // array of glass triangle and its damage states - Naomi Wiggins
	sf::Texture* m_stoneCube[4];        // array of solid stone cube and its damage states - Naomi Wiggins
	sf::Texture* m_stoneSphere[4];      // array of solid stone sphere and its damage states - Naomi Wiggins
	sf::Texture* m_stoneTriangle[4];    // array of solid stone triangle and its damage states - Naomi Wiggins

	//red Grumpy bird and its other faces
	//created by Jacob Sullivan
	sf::Texture* RedGrumpyBird1;

	// yellow / triangle grumpy bird texture - Naomi Wiggins
	sf::Texture* YellowGrumpyBird;

	//Slingshot texture
	//created by Jacob Sullivan
	sf::Texture* SlingShot;

};

