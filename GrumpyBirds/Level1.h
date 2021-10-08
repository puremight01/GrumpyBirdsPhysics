#pragma once
#ifndef __LEVEL1_H__
#define __LEVEL1_H__

#include "Scene.h"

// this scene was created by Naomi Wiggins and is the first level of the game
class Level1 : public Scene
{
public:
	// this is the constructor for level1. this is all that is needed as the derrived scene class just creates the
	// object that will be in the scene. the Scene Base class handles updating, rendering and deleting of objects 
	// by Naomi Wiggins
	Level1();
};

#endif  // __LEVEL1_H__
