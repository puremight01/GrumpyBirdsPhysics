#ifndef __GameManager__
#define __GameManager__

//includes needed in this class
#include"Scene.h"
#include"ExampleScene.h"
#include"Level1.h"
#include"LevelTwo.h"

//This is the game instance 
//created by Jacob Sullivan
class GameManager
{
public:
    //creates an empty game instance
    //created by Jacob Sullivan
    GameManager();
    
    //shuts down the game instance
    //created by Jacob Sullivan
    ~GameManager();

    //updates the scene
    //created by Jacob Sullivan
    void Update();

    //renders the scene
    //created by Jacob Sullivan
    void Render(sf::RenderWindow *window);

    //changes the scene
    //created by Jacob Sullivan
    void SetScene(Scene* NewScene);

    //// returns pointer to current scene
    //// created by Naomi Wiggins
    //Scene* GetScene();

private:
    //holds the current scene
    //created by Jacob Sullivan
    Scene* CurrentScene;

    //Gets the next scene
    //created by Jacob Sullivan
    Scene* NextScene();

    //Gets a new copy of current
    //created by Jacob Sullivan
    Scene* SameScene();

    //what scene it is 
    //created by Jacob Sullivan
    int SceneNumber;

};
#endif // !__GameManager__
