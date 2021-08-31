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
	sf::Texture* SolidWoodCube1;
	sf::Texture* SolidWoodCube2;
	sf::Texture* SolidWoodCube3;
	sf::Texture* SolidWoodCube4;

	sf::Texture* m_solidWoodSphere[4];    // array of solid wood sphere and its damage states - Naomi Wiggins
	sf::Texture* m_hollowWoodTriangle[4]; // array of hollow wood triangles and its damage states - Naomi Wiggins

	//red Grumpy bird and its other faces
	//created by Jacob Sullivan
	sf::Texture* RedGrumpyBird1;

	//Slingshot texture
	//created by Jacob Sullivan
	sf::Texture* SlingShot;

};

